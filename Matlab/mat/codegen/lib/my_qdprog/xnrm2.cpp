//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int n
//                const double x[97]
// Return Type  : double
//
namespace coder {
namespace internal {
namespace blas {
double xnrm2(int n, const double x[97])
{
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[0]);
    } else {
      double scale;
      scale = 3.3121686421112381E-170;
      for (int k{0}; k < n; k++) {
        double absxk;
        absxk = std::abs(x[k]);
        if (absxk > scale) {
          double t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          double t;
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

//
// Arguments    : int n
//                const double x[29160]
//                int ix0
// Return Type  : double
//
double xnrm2(int n, const double x[29160], int ix0)
{
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      double scale;
      int kend;
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int k{ix0}; k < kend; k++) {
        double absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          double t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          double t;
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xnrm2.cpp
//
// [EOF]
//
