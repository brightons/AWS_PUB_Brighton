//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: compute_lambda.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "compute_lambda.h"
#include "my_qdprog_internal_types.h"
#include "my_qdprog_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : double workspace[23571]
//                struct_T &solution
//                const b_struct_T &objective
//                const d_struct_T &qrmanager
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_lambda(double workspace[23571], struct_T &solution,
                    const b_struct_T &objective, const d_struct_T &qrmanager)
{
  int nActiveConstr_tmp;
  nActiveConstr_tmp = qrmanager.ncols;
  if (qrmanager.ncols > 0) {
    double c;
    int idx;
    int idxQR;
    int jjA;
    boolean_T guard1;
    guard1 = false;
    if (objective.objtype != 4) {
      boolean_T nonDegenerate;
      idxQR = qrmanager.mrows;
      jjA = qrmanager.ncols;
      if (idxQR >= jjA) {
        jjA = idxQR;
      }
      c = std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * static_cast<double>(jjA));
      if ((qrmanager.mrows > 0) && (qrmanager.ncols > 0)) {
        nonDegenerate = true;
      } else {
        nonDegenerate = false;
      }
      if (nonDegenerate) {
        boolean_T guard2;
        idx = nActiveConstr_tmp;
        guard2 = false;
        if (qrmanager.mrows < qrmanager.ncols) {
          idxQR = qrmanager.mrows + 120 * (qrmanager.ncols - 1);
          while ((idx > qrmanager.mrows) &&
                 (std::abs(qrmanager.QR[idxQR - 1]) >= c)) {
            idx--;
            idxQR -= 120;
          }
          nonDegenerate = (idx == qrmanager.mrows);
          if (nonDegenerate) {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
        if (guard2) {
          idxQR = idx + 120 * (idx - 1);
          while ((idx >= 1) && (std::abs(qrmanager.QR[idxQR - 1]) >= c)) {
            idx--;
            idxQR -= 121;
          }
          nonDegenerate = (idx == 0);
        }
      }
      if (!nonDegenerate) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      if (qrmanager.mrows != 0) {
        std::memset(&workspace[0], 0,
                    static_cast<unsigned int>(nActiveConstr_tmp) *
                        sizeof(double));
        jjA = 120 * (qrmanager.ncols - 1) + 1;
        for (idx = 1; idx <= jjA; idx += 120) {
          c = 0.0;
          idxQR = idx + qrmanager.mrows;
          for (int ia{idx}; ia < idxQR; ia++) {
            c += qrmanager.Q[ia - 1] * objective.grad[ia - idx];
          }
          idxQR = div_nde_s32_floor(idx - 1, 120);
          workspace[idxQR] += c;
        }
      }
      for (idx = nActiveConstr_tmp; idx >= 1; idx--) {
        jjA = (idx + (idx - 1) * 120) - 1;
        workspace[idx - 1] /= qrmanager.QR[jjA];
        for (int ia{0}; ia <= idx - 2; ia++) {
          idxQR = (idx - ia) - 2;
          workspace[idxQR] -= workspace[idx - 1] * qrmanager.QR[(jjA - ia) - 1];
        }
      }
      jjA = nActiveConstr_tmp / 2 * 2;
      idxQR = jjA - 2;
      for (idx = 0; idx <= idxQR; idx += 2) {
        __m128d r;
        r = _mm_loadu_pd(&workspace[idx]);
        r = _mm_mul_pd(r, _mm_set1_pd(-1.0));
        _mm_storeu_pd(&solution.lambda[idx], r);
      }
      for (idx = jjA; idx < nActiveConstr_tmp; idx++) {
        solution.lambda[idx] = -workspace[idx];
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for compute_lambda.cpp
//
// [EOF]
//
