//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "xzgeqp3.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include <cstring>

// Function Definitions
//
// Arguments    : double A[29160]
//                int m
//                int n
//                int nfxd
//                double tau[120]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void qrf(double A[29160], int m, int n, int nfxd, double tau[120])
{
  double work[243];
  int i;
  std::memset(&tau[0], 0, 120U * sizeof(double));
  std::memset(&work[0], 0, 243U * sizeof(double));
  i = static_cast<unsigned char>(nfxd);
  for (int b_i{0}; b_i < i; b_i++) {
    double atmp;
    double d;
    int ii;
    int mmi;
    ii = b_i * 120 + b_i;
    mmi = m - b_i;
    if (b_i + 1 < m) {
      atmp = A[ii];
      d = xzlarfg(mmi, atmp, A, ii + 2);
      tau[b_i] = d;
      A[ii] = atmp;
    } else {
      d = 0.0;
      tau[b_i] = 0.0;
    }
    if (b_i + 1 < n) {
      atmp = A[ii];
      A[ii] = 1.0;
      xzlarf(mmi, (n - b_i) - 1, ii + 1, d, A, ii + 121, work);
      A[ii] = atmp;
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzgeqp3.cpp
//
// [EOF]
//
