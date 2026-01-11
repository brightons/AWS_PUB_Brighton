//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: RemoveDependentIneq_.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "my_qdprog_internal_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : c_struct_T &workingset
//                d_struct_T &qrmanager
//                e_struct_T &memspace
//                double tolfactor
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void RemoveDependentIneq_(c_struct_T &workingset, d_struct_T &qrmanager,
                          e_struct_T &memspace, double tolfactor)
{
  int nActiveConstr_tmp;
  int nFixedConstr;
  int nVar;
  nActiveConstr_tmp = workingset.nActiveConstr;
  nFixedConstr = workingset.nWConstr[0] + workingset.nWConstr[1];
  nVar = workingset.nVar;
  if ((workingset.nWConstr[2] + workingset.nWConstr[3]) +
          workingset.nWConstr[4] >
      0) {
    double maxDiag;
    double tol;
    int idx;
    int idxDiag;
    int nDepIneq;
    idxDiag = workingset.nVar;
    nDepIneq = workingset.nActiveConstr;
    if (idxDiag >= nDepIneq) {
      nDepIneq = idxDiag;
    }
    tol = tolfactor *
          std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * static_cast<double>(nDepIneq));
    for (idx = 0; idx < nFixedConstr; idx++) {
      qrmanager.jpvt[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    if (idxDiag <= nActiveConstr_tmp) {
      std::memset(&qrmanager.jpvt[idxDiag + -1], 0,
                  static_cast<unsigned int>((nActiveConstr_tmp - idxDiag) + 1) *
                      sizeof(int));
    }
    for (int idx_col{0}; idx_col < nActiveConstr_tmp; idx_col++) {
      nDepIneq = 120 * idx_col;
      idx = 97 * idx_col;
      idxDiag = static_cast<unsigned char>(nVar);
      for (int k{0}; k < idxDiag; k++) {
        qrmanager.QR[nDepIneq + k] = workingset.ATwset[idx + k];
      }
    }
    if (workingset.nVar * workingset.nActiveConstr == 0) {
      qrmanager.mrows = workingset.nVar;
      qrmanager.ncols = workingset.nActiveConstr;
      qrmanager.minRowCol = 0;
    } else {
      qrmanager.usedPivoting = true;
      qrmanager.mrows = workingset.nVar;
      qrmanager.ncols = workingset.nActiveConstr;
      idxDiag = workingset.nVar;
      nDepIneq = workingset.nActiveConstr;
      if (idxDiag <= nDepIneq) {
        nDepIneq = idxDiag;
      }
      qrmanager.minRowCol = nDepIneq;
      internal::lapack::xgeqp3(qrmanager.QR, workingset.nVar,
                               workingset.nActiveConstr, qrmanager.jpvt,
                               qrmanager.tau);
    }
    nDepIneq = 0;
    for (idx = workingset.nActiveConstr - 1; idx + 1 > nVar; idx--) {
      nDepIneq++;
      memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx];
    }
    maxDiag = std::abs(qrmanager.QR[0]);
    for (idxDiag = 0; idxDiag < idx; idxDiag++) {
      maxDiag = std::fmax(
          maxDiag, std::abs(qrmanager.QR[(120 * (idxDiag + 1) + idxDiag) + 1]));
    }
    if (idx + 1 <= workingset.nVar) {
      idxDiag = idx + 120 * idx;
      while ((idx + 1 > nFixedConstr) &&
             (std::abs(qrmanager.QR[idxDiag]) < tol * maxDiag)) {
        nDepIneq++;
        memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx];
        idx--;
        idxDiag -= 121;
      }
    }
    utils::countsort(memspace.workspace_int, nDepIneq, memspace.workspace_sort,
                     nFixedConstr + 1, workingset.nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      WorkingSet::removeConstr(workingset, memspace.workspace_int[idx - 1]);
    }
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for RemoveDependentIneq_.cpp
//
// [EOF]
//
