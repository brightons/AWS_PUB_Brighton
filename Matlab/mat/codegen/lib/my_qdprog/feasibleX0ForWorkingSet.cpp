//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleX0ForWorkingSet.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "maxConstraintViolation.h"
#include "my_qdprog_internal_types.h"
#include "my_qdprog_rtwutil.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : double workspace[23571]
//                double xCurrent[97]
//                c_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : boolean_T
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
boolean_T feasibleX0ForWorkingSet(double workspace[23571], double xCurrent[97],
                                  c_struct_T &workingset, d_struct_T &qrmanager)
{
  static double B[23571];
  int mWConstr;
  int nVar;
  boolean_T nonDegenerateWset;
  mWConstr = workingset.nActiveConstr;
  nVar = workingset.nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    __m128d r;
    __m128d r1;
    double constrViolation_basicX;
    double tol;
    int br;
    int i;
    int ix;
    int minmn;
    if (mWConstr >= nVar) {
      int ar;
      int i1;
      int i2;
      int rankQR;
      i = static_cast<unsigned char>(nVar);
      for (br = 0; br < i; br++) {
        minmn = 120 * br;
        for (ix = 0; ix < mWConstr; ix++) {
          qrmanager.QR[ix + minmn] = workingset.ATwset[br + 97 * ix];
        }
        qrmanager.jpvt[br] = 0;
      }
      if (mWConstr * nVar == 0) {
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        qrmanager.minRowCol = 0;
      } else {
        qrmanager.usedPivoting = true;
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        if (mWConstr <= nVar) {
          minmn = mWConstr;
        } else {
          minmn = nVar;
        }
        qrmanager.minRowCol = minmn;
        internal::lapack::xgeqp3(qrmanager.QR, mWConstr, nVar, qrmanager.jpvt,
                                 qrmanager.tau);
      }
      QRManager::computeQ_(qrmanager, qrmanager.mrows);
      rankQR = 0;
      if (qrmanager.mrows < qrmanager.ncols) {
        minmn = 96;
      } else {
        minmn = qrmanager.ncols;
      }
      if (minmn > 0) {
        ix = qrmanager.mrows;
        br = qrmanager.ncols;
        if (ix >= br) {
          br = ix;
        }
        tol = std::fmin(1.4901161193847656E-8,
                        2.2204460492503131E-15 * static_cast<double>(br)) *
              std::abs(qrmanager.QR[0]);
        while ((rankQR < minmn) &&
               (!(std::abs(qrmanager.QR[rankQR + 120 * rankQR]) <= tol))) {
          rankQR++;
        }
      }
      for (br = 0; br < mWConstr; br++) {
        constrViolation_basicX = workingset.bwset[br];
        workspace[br] = constrViolation_basicX;
        workspace[br + 243] = constrViolation_basicX;
      }
      i1 = 97 * (mWConstr - 1) + 1;
      for (minmn = 1; minmn <= i1; minmn += 97) {
        tol = 0.0;
        i2 = minmn + nVar;
        for (br = minmn; br < i2; br++) {
          tol += workingset.ATwset[br - 1] * xCurrent[br - minmn];
        }
        i2 = div_nde_s32_floor(minmn - 1, 97);
        workspace[i2] -= tol;
      }
      std::copy(&workspace[0], &workspace[23571], &B[0]);
      for (int k{0}; k <= 243; k += 243) {
        i1 = k + 1;
        i2 = k + nVar;
        if (i1 <= i2) {
          std::memset(&workspace[i1 + -1], 0,
                      static_cast<unsigned int>((i2 - i1) + 1) *
                          sizeof(double));
        }
      }
      br = -1;
      for (int k{0}; k <= 243; k += 243) {
        ar = -1;
        i1 = k + 1;
        i2 = k + nVar;
        for (int ic{i1}; ic <= i2; ic++) {
          tol = 0.0;
          for (minmn = 0; minmn < mWConstr; minmn++) {
            tol += qrmanager.Q[(minmn + ar) + 1] * B[(minmn + br) + 1];
          }
          workspace[ic - 1] += tol;
          ar += 120;
        }
        br += 243;
      }
      for (ar = 0; ar < 2; ar++) {
        ix = 243 * ar - 1;
        for (int k{rankQR}; k >= 1; k--) {
          minmn = 120 * (k - 1) - 1;
          i1 = k + ix;
          constrViolation_basicX = workspace[i1];
          if (constrViolation_basicX != 0.0) {
            workspace[i1] = constrViolation_basicX / qrmanager.QR[k + minmn];
            i2 = static_cast<unsigned char>(k - 1);
            for (mWConstr = 0; mWConstr < i2; mWConstr++) {
              br = (mWConstr + ix) + 1;
              workspace[br] -=
                  workspace[i1] * qrmanager.QR[(mWConstr + minmn) + 1];
            }
          }
        }
      }
      i1 = rankQR + 1;
      for (mWConstr = i1; mWConstr <= nVar; mWConstr++) {
        workspace[mWConstr - 1] = 0.0;
        workspace[mWConstr + 242] = 0.0;
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[qrmanager.jpvt[mWConstr] + 485] = workspace[mWConstr];
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[mWConstr] = workspace[mWConstr + 486];
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[qrmanager.jpvt[mWConstr] + 485] = workspace[mWConstr + 243];
      }
      for (mWConstr = 0; mWConstr < i; mWConstr++) {
        workspace[mWConstr + 243] = workspace[mWConstr + 486];
      }
    } else {
      int ar;
      int i1;
      int rankQR;
      boolean_T guard1;
      if (mWConstr - 1 >= 0) {
        std::memset(&qrmanager.jpvt[0], 0,
                    static_cast<unsigned int>(mWConstr) * sizeof(int));
      }
      i = nVar * mWConstr;
      guard1 = false;
      if (i > 0) {
        for (br = 0; br < mWConstr; br++) {
          minmn = 97 * br;
          ix = 120 * br;
          i = static_cast<unsigned char>(nVar);
          for (int k{0}; k < i; k++) {
            qrmanager.QR[ix + k] = workingset.ATwset[minmn + k];
          }
        }
        guard1 = true;
      } else if (i == 0) {
        qrmanager.mrows = nVar;
        qrmanager.ncols = mWConstr;
        qrmanager.minRowCol = 0;
      } else {
        guard1 = true;
      }
      if (guard1) {
        qrmanager.usedPivoting = true;
        qrmanager.mrows = nVar;
        qrmanager.ncols = mWConstr;
        if (nVar <= mWConstr) {
          minmn = nVar;
        } else {
          minmn = mWConstr;
        }
        qrmanager.minRowCol = minmn;
        internal::lapack::xgeqp3(qrmanager.QR, nVar, mWConstr, qrmanager.jpvt,
                                 qrmanager.tau);
      }
      QRManager::computeQ_(qrmanager, qrmanager.minRowCol);
      rankQR = 0;
      if (qrmanager.mrows < qrmanager.ncols) {
        minmn = 96;
      } else {
        minmn = qrmanager.ncols;
      }
      if (minmn > 0) {
        ix = qrmanager.mrows;
        br = qrmanager.ncols;
        if (ix >= br) {
          br = ix;
        }
        tol = std::fmin(1.4901161193847656E-8,
                        2.2204460492503131E-15 * static_cast<double>(br)) *
              std::abs(qrmanager.QR[0]);
        while ((rankQR < minmn) &&
               (!(std::abs(qrmanager.QR[rankQR + 120 * rankQR]) <= tol))) {
          rankQR++;
        }
      }
      for (br = 0; br < mWConstr; br++) {
        ix = (qrmanager.jpvt[br] - 1) * 97;
        tol = 0.0;
        i = static_cast<unsigned char>(nVar);
        for (int k{0}; k < i; k++) {
          tol += workingset.ATwset[ix + k] * xCurrent[k];
        }
        constrViolation_basicX = workingset.bwset[qrmanager.jpvt[br] - 1];
        workspace[br] = constrViolation_basicX - tol;
        workspace[br + 243] = constrViolation_basicX;
      }
      i = static_cast<unsigned char>(rankQR);
      for (ar = 0; ar < 2; ar++) {
        ix = 243 * ar;
        for (mWConstr = 0; mWConstr < i; mWConstr++) {
          minmn = 120 * mWConstr;
          br = mWConstr + ix;
          tol = workspace[br];
          for (int k{0}; k < mWConstr; k++) {
            tol -= qrmanager.QR[k + minmn] * workspace[k + ix];
          }
          workspace[br] = tol / qrmanager.QR[mWConstr + minmn];
        }
      }
      std::copy(&workspace[0], &workspace[23571], &B[0]);
      for (int k{0}; k <= 243; k += 243) {
        i = k + 1;
        i1 = k + nVar;
        if (i <= i1) {
          std::memset(&workspace[i + -1], 0,
                      static_cast<unsigned int>((i1 - i) + 1) * sizeof(double));
        }
      }
      br = 1;
      for (int k{0}; k <= 243; k += 243) {
        ar = -1;
        i = br + rankQR;
        for (mWConstr = br; mWConstr < i; mWConstr++) {
          int i2;
          i1 = k + 1;
          i2 = k + nVar;
          minmn = ((i2 - i1) + 1) / 2 * 2 + i1;
          ix = minmn - 2;
          for (int ic{i1}; ic <= ix; ic += 2) {
            r = _mm_loadu_pd(&qrmanager.Q[(ar + ic) - k]);
            r = _mm_mul_pd(_mm_set1_pd(B[mWConstr - 1]), r);
            r1 = _mm_loadu_pd(&workspace[ic - 1]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&workspace[ic - 1], r);
          }
          for (int ic{minmn}; ic <= i2; ic++) {
            workspace[ic - 1] += B[mWConstr - 1] * qrmanager.Q[(ar + ic) - k];
          }
          ar += 120;
        }
        br += 243;
      }
    }
    br = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (br <= static_cast<unsigned char>(nVar) - 1) {
        if (std::isinf(workspace[br]) || std::isnan(workspace[br])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          constrViolation_basicX = workspace[br + 243];
          if (std::isinf(constrViolation_basicX) ||
              std::isnan(constrViolation_basicX)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            br++;
          }
        }
      } else {
        minmn = nVar / 2 * 2;
        ix = minmn - 2;
        for (int k{0}; k <= ix; k += 2) {
          r = _mm_loadu_pd(&workspace[k]);
          r1 = _mm_loadu_pd(&xCurrent[k]);
          r = _mm_add_pd(r, r1);
          _mm_storeu_pd(&workspace[k], r);
        }
        for (int k{minmn}; k < nVar; k++) {
          workspace[k] += xCurrent[k];
        }
        tol = WorkingSet::maxConstraintViolation(workingset, workspace);
        constrViolation_basicX =
            WorkingSet::b_maxConstraintViolation(workingset, workspace);
        if ((tol <= 2.2204460492503131E-16) || (tol < constrViolation_basicX)) {
          i = static_cast<unsigned char>(nVar);
          std::copy(&workspace[0], &workspace[i], &xCurrent[0]);
        } else {
          i = static_cast<unsigned char>(nVar);
          std::copy(&workspace[243], &workspace[243 + i], &xCurrent[0]);
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return nonDegenerateWset;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for feasibleX0ForWorkingSet.cpp
//
// [EOF]
//
