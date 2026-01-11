//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFval_ReuseHx.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "computeFval_ReuseHx.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const b_struct_T &obj
//                double workspace[23571]
//                const double f[96]
//                const double x[97]
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
double computeFval_ReuseHx(const b_struct_T &obj, double workspace[23571],
                           const double f[96], const double x[97])
{
  double val;
  switch (obj.objtype) {
  case 5:
    val = obj.gammaScalar * x[obj.nvar - 1];
    break;
  case 3: {
    if (obj.hasLinear) {
      int i;
      int ixlast;
      int k;
      i = obj.nvar;
      ixlast = (i / 2) << 1;
      k = ixlast - 2;
      for (int b_i{0}; b_i <= k; b_i += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj.Hx[b_i]);
        _mm_storeu_pd(
            &workspace[b_i],
            _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5), r), _mm_loadu_pd(&f[b_i])));
      }
      for (int b_i{ixlast}; b_i < i; b_i++) {
        workspace[b_i] = 0.5 * obj.Hx[b_i] + f[b_i];
      }
      val = 0.0;
      if (obj.nvar >= 1) {
        for (k = 0; k < i; k++) {
          val += x[k] * workspace[k];
        }
      }
    } else {
      val = 0.0;
      if (obj.nvar >= 1) {
        int ixlast;
        ixlast = obj.nvar;
        for (int k{0}; k < ixlast; k++) {
          val += x[k] * obj.Hx[k];
        }
      }
      val *= 0.5;
    }
  } break;
  default: {
    if (obj.hasLinear) {
      int i;
      i = obj.nvar;
      if (i - 1 >= 0) {
        std::copy(&f[0], &f[i], &workspace[0]);
      }
      i = 96 - obj.nvar;
      for (int b_i{0}; b_i < i; b_i++) {
        workspace[obj.nvar + b_i] = 0.0;
      }
      val = 0.0;
      for (int b_i{0}; b_i < 96; b_i++) {
        double d;
        d = workspace[b_i] + 0.5 * obj.Hx[b_i];
        workspace[b_i] = d;
        val += x[b_i] * d;
      }
    } else {
      int i;
      val = 0.0;
      for (int k{0}; k < 96; k++) {
        val += x[k] * obj.Hx[k];
      }
      val *= 0.5;
      i = obj.nvar + 1;
      for (int ixlast{i}; ixlast < 97; ixlast++) {
        val += x[ixlast - 1] * 0.0;
      }
    }
  } break;
  }
  return val;
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeFval_ReuseHx.cpp
//
// [EOF]
//
