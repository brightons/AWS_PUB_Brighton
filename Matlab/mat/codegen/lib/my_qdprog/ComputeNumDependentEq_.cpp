//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeNumDependentEq_.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "ComputeNumDependentEq_.h"
#include "computeQ_.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : d_struct_T &qrmanager
//                const double beqf[243]
//                int mConstr
//                int nVar
// Return Type  : int
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int ComputeNumDependentEq_(d_struct_T &qrmanager, const double beqf[243],
                           int mConstr, int nVar)
{
  double tol;
  int numDependent;
  int totalRank;
  numDependent = mConstr - nVar;
  if (numDependent <= 0) {
    numDependent = 0;
  }
  totalRank = static_cast<unsigned char>(nVar);
  std::memset(&qrmanager.jpvt[0], 0,
              static_cast<unsigned int>(totalRank) * sizeof(int));
  if (mConstr * nVar == 0) {
    qrmanager.mrows = mConstr;
    qrmanager.ncols = nVar;
    qrmanager.minRowCol = 0;
  } else {
    qrmanager.usedPivoting = true;
    qrmanager.mrows = mConstr;
    qrmanager.ncols = nVar;
    if (mConstr <= nVar) {
      totalRank = mConstr;
    } else {
      totalRank = nVar;
    }
    qrmanager.minRowCol = totalRank;
    internal::lapack::xgeqp3(qrmanager.QR, mConstr, nVar, qrmanager.jpvt,
                             qrmanager.tau);
  }
  if (mConstr >= nVar) {
    totalRank = mConstr;
  } else {
    totalRank = nVar;
  }
  tol = std::fmin(1.4901161193847656E-8,
                  2.2204460492503131E-15 * static_cast<double>(totalRank));
  if (nVar <= mConstr) {
    totalRank = nVar;
  } else {
    totalRank = mConstr;
  }
  totalRank += 120 * (totalRank - 1);
  while ((totalRank > 0) && (std::abs(qrmanager.QR[totalRank - 1]) <
                             tol * std::abs(qrmanager.QR[0]))) {
    totalRank -= 121;
    numDependent++;
  }
  if (numDependent > 0) {
    boolean_T exitg1;
    QRManager::computeQ_(qrmanager, qrmanager.mrows);
    totalRank = 0;
    exitg1 = false;
    while ((!exitg1) && (totalRank <= numDependent - 1)) {
      double qtb;
      int ix;
      ix = 120 * ((mConstr - totalRank) - 1);
      qtb = 0.0;
      for (int k{0}; k < mConstr; k++) {
        qtb += qrmanager.Q[ix + k] * beqf[k];
      }
      if (std::abs(qtb) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        totalRank++;
      }
    }
  }
  return numDependent;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for ComputeNumDependentEq_.cpp
//
// [EOF]
//
