//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgeqp3.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "xgeqp3.h"
#include "my_qdprog_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzgeqp3.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : double A[29160]
//                int m
//                int n
//                int jpvt[243]
//                double tau[120]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace lapack {
void xgeqp3(double A[29160], int m, int n, int jpvt[243], double tau[120])
{
  double vn1[243];
  double vn2[243];
  double work[243];
  double temp;
  int minmn_tmp;
  if (m <= n) {
    minmn_tmp = m;
  } else {
    minmn_tmp = n;
  }
  std::memset(&tau[0], 0, 120U * sizeof(double));
  if (minmn_tmp < 1) {
    int iy;
    int nfxd;
    iy = (n / 4) << 2;
    nfxd = iy - 4;
    for (int pvt{0}; pvt <= nfxd; pvt += 4) {
      _mm_storeu_si128(
          (__m128i *)&jpvt[pvt],
          _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(pvt),
                                      _mm_loadu_si128((const __m128i *)&iv[0])),
                        _mm_set1_epi32(1)));
    }
    for (int pvt{iy}; pvt < n; pvt++) {
      jpvt[pvt] = pvt + 1;
    }
  } else {
    int i;
    int ix;
    int iy;
    int nfxd;
    int pvt;
    int temp_tmp;
    nfxd = 0;
    for (pvt = 0; pvt < n; pvt++) {
      if (jpvt[pvt] != 0) {
        nfxd++;
        if (pvt + 1 != nfxd) {
          ix = pvt * 120;
          iy = (nfxd - 1) * 120;
          for (int k{0}; k < m; k++) {
            temp_tmp = ix + k;
            temp = A[temp_tmp];
            i = iy + k;
            A[temp_tmp] = A[i];
            A[i] = temp;
          }
          jpvt[pvt] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = pvt + 1;
        } else {
          jpvt[pvt] = pvt + 1;
        }
      } else {
        jpvt[pvt] = pvt + 1;
      }
    }
    if (nfxd > minmn_tmp) {
      nfxd = minmn_tmp;
    }
    reflapack::qrf(A, m, n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      double d;
      std::memset(&work[0], 0, 243U * sizeof(double));
      std::memset(&vn1[0], 0, 243U * sizeof(double));
      std::memset(&vn2[0], 0, 243U * sizeof(double));
      i = nfxd + 1;
      for (pvt = i; pvt <= n; pvt++) {
        d = blas::xnrm2(m - nfxd, A, (nfxd + (pvt - 1) * 120) + 1);
        vn1[pvt - 1] = d;
        vn2[pvt - 1] = d;
      }
      for (int b_i{i}; b_i <= minmn_tmp; b_i++) {
        double s;
        int ii;
        int ip1;
        int mmi;
        int nmi;
        ip1 = b_i + 1;
        iy = (b_i - 1) * 120;
        ii = (iy + b_i) - 1;
        nmi = (n - b_i) + 1;
        mmi = m - b_i;
        if (nmi < 1) {
          nfxd = -2;
        } else {
          nfxd = -1;
          if (nmi > 1) {
            temp = std::abs(vn1[b_i - 1]);
            for (int k{2}; k <= nmi; k++) {
              s = std::abs(vn1[(b_i + k) - 2]);
              if (s > temp) {
                nfxd = k - 2;
                temp = s;
              }
            }
          }
        }
        pvt = b_i + nfxd;
        if (pvt + 1 != b_i) {
          ix = pvt * 120;
          for (int k{0}; k < m; k++) {
            temp_tmp = ix + k;
            temp = A[temp_tmp];
            nfxd = iy + k;
            A[temp_tmp] = A[nfxd];
            A[nfxd] = temp;
          }
          nfxd = jpvt[pvt];
          jpvt[pvt] = jpvt[b_i - 1];
          jpvt[b_i - 1] = nfxd;
          vn1[pvt] = vn1[b_i - 1];
          vn2[pvt] = vn2[b_i - 1];
        }
        if (b_i < m) {
          temp = A[ii];
          d = reflapack::xzlarfg(mmi + 1, temp, A, ii + 2);
          tau[b_i - 1] = d;
          A[ii] = temp;
        } else {
          d = 0.0;
          tau[b_i - 1] = 0.0;
        }
        if (b_i < n) {
          temp = A[ii];
          A[ii] = 1.0;
          reflapack::xzlarf(mmi + 1, nmi - 1, ii + 1, d, A, ii + 121, work);
          A[ii] = temp;
        }
        for (pvt = ip1; pvt <= n; pvt++) {
          iy = b_i + (pvt - 1) * 120;
          d = vn1[pvt - 1];
          if (d != 0.0) {
            temp = std::abs(A[iy - 1]) / d;
            temp = 1.0 - temp * temp;
            if (temp < 0.0) {
              temp = 0.0;
            }
            s = d / vn2[pvt - 1];
            s = temp * (s * s);
            if (s <= 1.4901161193847656E-8) {
              if (b_i < m) {
                d = blas::xnrm2(mmi, A, iy + 1);
                vn1[pvt - 1] = d;
                vn2[pvt - 1] = d;
              } else {
                vn1[pvt - 1] = 0.0;
                vn2[pvt - 1] = 0.0;
              }
            } else {
              vn1[pvt - 1] = d * std::sqrt(temp);
            }
          }
        }
      }
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

//
// File trailer for xgeqp3.cpp
//
// [EOF]
//
