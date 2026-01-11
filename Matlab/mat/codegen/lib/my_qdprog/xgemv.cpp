//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "xgemv.h"
#include "my_qdprog_rtwutil.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : int m
//                const double A[2522]
//                const double x[97]
//                double y[23571]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xgemv(int m, const double A[2522], const double x[97], double y[23571])
{
  int iy;
  for (iy = 0; iy <= 24; iy += 2) {
    __m128d r;
    r = _mm_loadu_pd(&y[iy]);
    r = _mm_mul_pd(r, _mm_set1_pd(-1.0));
    _mm_storeu_pd(&y[iy], r);
  }
  for (int iac{0}; iac <= 2425; iac += 97) {
    double c;
    c = 0.0;
    iy = iac + m;
    for (int ia{iac + 1}; ia <= iy; ia++) {
      c += A[ia - 1] * x[(ia - iac) - 1];
    }
    iy = div_nde_s32_floor(iac, 97);
    y[iy] += c;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xgemv.cpp
//
// [EOF]
//
