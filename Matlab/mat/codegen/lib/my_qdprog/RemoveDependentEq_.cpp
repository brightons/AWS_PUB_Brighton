//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: RemoveDependentEq_.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "RemoveDependentEq_.h"
#include "ComputeNumDependentEq_.h"
#include "countsort.h"
#include "my_qdprog_internal_types.h"
#include "removeEqConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <cstring>

// Function Definitions
//
// Arguments    : e_struct_T &memspace
//                c_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : int
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int RemoveDependentEq_(e_struct_T &memspace, c_struct_T &workingset,
                       d_struct_T &qrmanager)
{
  int i;
  int idx_row;
  int nCols;
  int nDepInd;
  qrmanager.ldq = 120;
  std::memset(&qrmanager.QR[0], 0, 29160U * sizeof(double));
  std::memset(&qrmanager.Q[0], 0, 14400U * sizeof(double));
  std::memset(&qrmanager.jpvt[0], 0, 243U * sizeof(int));
  qrmanager.mrows = 0;
  qrmanager.ncols = 0;
  std::memset(&qrmanager.tau[0], 0, 120U * sizeof(double));
  qrmanager.minRowCol = 0;
  qrmanager.usedPivoting = false;
  i = static_cast<unsigned char>(workingset.nWConstr[0] + 24);
  nCols = static_cast<unsigned char>(workingset.nVar);
  for (idx_row = 0; idx_row < i; idx_row++) {
    for (int idx_col{0}; idx_col < nCols; idx_col++) {
      qrmanager.QR[idx_row + 120 * idx_col] =
          workingset.ATwset[idx_col + 97 * idx_row];
    }
  }
  nDepInd =
      ComputeNumDependentEq_(qrmanager, workingset.bwset,
                             workingset.nWConstr[0] + 24, workingset.nVar);
  if (nDepInd > 0) {
    int ix0;
    for (int idx_col{0}; idx_col < i; idx_col++) {
      idx_row = 120 * idx_col;
      ix0 = 97 * idx_col;
      for (int k{0}; k < nCols; k++) {
        qrmanager.QR[idx_row + k] = workingset.ATwset[ix0 + k];
      }
    }
    idx_row = workingset.nWConstr[0];
    nCols = workingset.nWConstr[0] + 24;
    for (ix0 = 0; ix0 < idx_row; ix0++) {
      qrmanager.jpvt[ix0] = 1;
    }
    i = workingset.nWConstr[0] + 1;
    if (i <= nCols) {
      std::memset(&qrmanager.jpvt[i + -1], 0,
                  static_cast<unsigned int>((nCols - i) + 1) * sizeof(int));
    }
    if (workingset.nVar * (workingset.nWConstr[0] + 24) == 0) {
      qrmanager.mrows = workingset.nVar;
      qrmanager.ncols = workingset.nWConstr[0] + 24;
      qrmanager.minRowCol = 0;
    } else {
      qrmanager.usedPivoting = true;
      qrmanager.mrows = workingset.nVar;
      qrmanager.ncols = workingset.nWConstr[0] + 24;
      idx_row = workingset.nVar;
      ix0 = workingset.nWConstr[0] + 24;
      if (idx_row <= ix0) {
        ix0 = idx_row;
      }
      qrmanager.minRowCol = ix0;
      internal::lapack::xgeqp3(qrmanager.QR, workingset.nVar,
                               workingset.nWConstr[0] + 24, qrmanager.jpvt,
                               qrmanager.tau);
    }
    for (ix0 = 0; ix0 < nDepInd; ix0++) {
      memspace.workspace_int[ix0] = qrmanager.jpvt[(nCols - nDepInd) + ix0];
    }
    utils::countsort(memspace.workspace_int, nDepInd, memspace.workspace_sort,
                     1, workingset.nWConstr[0] + 24);
    for (ix0 = nDepInd; ix0 >= 1; ix0--) {
      WorkingSet::removeEqConstr(workingset, memspace.workspace_int[ix0 - 1]);
    }
  }
  return nDepInd;
}

//
// Arguments    : e_struct_T &memspace
//                c_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : int
//
int b_RemoveDependentEq_(e_struct_T &memspace, c_struct_T &workingset,
                         d_struct_T &qrmanager)
{
  int mTotalWorkingEq;
  int nDepInd;
  mTotalWorkingEq = workingset.nWConstr[0] + workingset.nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq > 0) {
    int i;
    int idx_row;
    i = static_cast<unsigned char>(workingset.nVar);
    for (idx_row = 0; idx_row < mTotalWorkingEq; idx_row++) {
      for (int idx_col{0}; idx_col < i; idx_col++) {
        qrmanager.QR[idx_row + 120 * idx_col] =
            workingset.ATwset[idx_col + 97 * idx_row];
      }
    }
    nDepInd = ComputeNumDependentEq_(qrmanager, workingset.bwset,
                                     mTotalWorkingEq, workingset.nVar);
    if (nDepInd > 0) {
      int ix0;
      for (int idx_col{0}; idx_col < mTotalWorkingEq; idx_col++) {
        idx_row = 120 * idx_col;
        ix0 = 97 * idx_col;
        for (int k{0}; k < i; k++) {
          qrmanager.QR[idx_row + k] = workingset.ATwset[ix0 + k];
        }
      }
      idx_row = workingset.nWConstr[0];
      for (ix0 = 0; ix0 < idx_row; ix0++) {
        qrmanager.jpvt[ix0] = 1;
      }
      i = workingset.nWConstr[0] + 1;
      if (i <= mTotalWorkingEq) {
        std::memset(&qrmanager.jpvt[i + -1], 0,
                    static_cast<unsigned int>((mTotalWorkingEq - i) + 1) *
                        sizeof(int));
      }
      if (workingset.nVar * mTotalWorkingEq == 0) {
        qrmanager.mrows = workingset.nVar;
        qrmanager.ncols = mTotalWorkingEq;
        qrmanager.minRowCol = 0;
      } else {
        qrmanager.usedPivoting = true;
        qrmanager.mrows = workingset.nVar;
        qrmanager.ncols = mTotalWorkingEq;
        idx_row = workingset.nVar;
        if (idx_row > mTotalWorkingEq) {
          idx_row = mTotalWorkingEq;
        }
        qrmanager.minRowCol = idx_row;
        internal::lapack::xgeqp3(qrmanager.QR, workingset.nVar, mTotalWorkingEq,
                                 qrmanager.jpvt, qrmanager.tau);
      }
      for (ix0 = 0; ix0 < nDepInd; ix0++) {
        memspace.workspace_int[ix0] =
            qrmanager.jpvt[(mTotalWorkingEq - nDepInd) + ix0];
      }
      utils::countsort(memspace.workspace_int, nDepInd, memspace.workspace_sort,
                       1, mTotalWorkingEq);
      for (ix0 = nDepInd; ix0 >= 1; ix0--) {
        WorkingSet::removeEqConstr(workingset, memspace.workspace_int[ix0 - 1]);
      }
    }
  }
  return nDepInd;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for RemoveDependentEq_.cpp
//
// [EOF]
//
