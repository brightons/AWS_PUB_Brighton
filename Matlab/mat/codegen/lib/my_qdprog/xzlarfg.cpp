//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "xzlarfg.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <cmath>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : int n
//                double &alpha1
//                double x[29160]
//                int ix0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace reflapack {
double xzlarfg(int n, double &alpha1, double x[29160], int ix0)
{
  double tau;
  tau = 0.0;
  if (n > 0) {
    double xnorm;
    xnorm = blas::xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      double a_tmp;
      a_tmp = std::abs(alpha1);
      xnorm = std::abs(xnorm);
      if (a_tmp < xnorm) {
        a_tmp /= xnorm;
        xnorm *= std::sqrt(a_tmp * a_tmp + 1.0);
      } else if (a_tmp > xnorm) {
        xnorm /= a_tmp;
        xnorm = a_tmp * std::sqrt(xnorm * xnorm + 1.0);
      } else if (std::isnan(xnorm)) {
        xnorm = rtNaN;
      } else {
        xnorm = a_tmp * 1.4142135623730951;
      }
      if (alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (std::abs(xnorm) < 1.0020841800044864E-292) {
        __m128d r;
        int i;
        int knt;
        int scalarLB;
        int vectorUB;
        knt = 0;
        i = (ix0 + n) - 2;
        do {
          knt++;
          scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
          vectorUB = scalarLB - 2;
          for (int k{ix0}; k <= vectorUB; k += 2) {
            r = _mm_loadu_pd(&x[k - 1]);
            r = _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r);
            _mm_storeu_pd(&x[k - 1], r);
          }
          for (int k{scalarLB}; k <= i; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }
          xnorm *= 9.9792015476736E+291;
          alpha1 *= 9.9792015476736E+291;
        } while ((std::abs(xnorm) < 1.0020841800044864E-292) && (knt < 20));
        a_tmp = std::abs(alpha1);
        xnorm = std::abs(blas::xnrm2(n - 1, x, ix0));
        if (a_tmp < xnorm) {
          a_tmp /= xnorm;
          xnorm *= std::sqrt(a_tmp * a_tmp + 1.0);
        } else if (a_tmp > xnorm) {
          xnorm /= a_tmp;
          xnorm = a_tmp * std::sqrt(xnorm * xnorm + 1.0);
        } else if (std::isnan(xnorm)) {
          xnorm = rtNaN;
        } else {
          xnorm = a_tmp * 1.4142135623730951;
        }
        if (alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - alpha1) / xnorm;
        a_tmp = 1.0 / (alpha1 - xnorm);
        scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
        vectorUB = scalarLB - 2;
        for (int k{ix0}; k <= vectorUB; k += 2) {
          r = _mm_loadu_pd(&x[k - 1]);
          r = _mm_mul_pd(_mm_set1_pd(a_tmp), r);
          _mm_storeu_pd(&x[k - 1], r);
        }
        for (int k{scalarLB}; k <= i; k++) {
          x[k - 1] *= a_tmp;
        }
        for (int k{0}; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        alpha1 = xnorm;
      } else {
        int i;
        int scalarLB;
        int vectorUB;
        tau = (xnorm - alpha1) / xnorm;
        a_tmp = 1.0 / (alpha1 - xnorm);
        i = (ix0 + n) - 2;
        scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
        vectorUB = scalarLB - 2;
        for (int k{ix0}; k <= vectorUB; k += 2) {
          __m128d r;
          r = _mm_loadu_pd(&x[k - 1]);
          r = _mm_mul_pd(_mm_set1_pd(a_tmp), r);
          _mm_storeu_pd(&x[k - 1], r);
        }
        for (int k{scalarLB}; k <= i; k++) {
          x[k - 1] *= a_tmp;
        }
        alpha1 = xnorm;
      }
    }
  }
  return tau;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzlarfg.cpp
//
// [EOF]
//
