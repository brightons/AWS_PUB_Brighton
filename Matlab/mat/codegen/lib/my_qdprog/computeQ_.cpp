//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeQ_.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "computeQ_.h"
#include "my_qdprog_internal_types.h"
#include "my_qdprog_rtwutil.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : d_struct_T &obj
//                int nrows
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void computeQ_(d_struct_T &obj, int nrows)
{
  double work[120];
  int iQR0;
  int idx;
  int k;
  int m;
  int n;
  k = obj.minRowCol;
  for (idx = 0; idx < k; idx++) {
    iQR0 = 120 * idx + idx;
    n = obj.mrows - idx;
    if (n - 2 >= 0) {
      std::copy(&obj.QR[iQR0 + 1], &obj.QR[iQR0 + n], &obj.Q[iQR0 + 1]);
    }
  }
  m = obj.mrows;
  if (nrows >= 1) {
    int ia;
    int itau;
    for (idx = k; idx < nrows; idx++) {
      ia = idx * 120;
      std::memset(&obj.Q[ia], 0, static_cast<unsigned int>(m) * sizeof(double));
      obj.Q[ia + idx] = 1.0;
    }
    itau = obj.minRowCol - 1;
    std::memset(&work[0], 0, 120U * sizeof(double));
    for (int i{obj.minRowCol}; i >= 1; i--) {
      int b_i;
      int iaii;
      iaii = i + (i - 1) * 120;
      if (i < nrows) {
        int lastc;
        int lastv;
        obj.Q[iaii - 1] = 1.0;
        idx = iaii + 120;
        if (obj.tau[itau] != 0.0) {
          boolean_T exitg2;
          lastv = m - i;
          iQR0 = (iaii + m) - i;
          while ((lastv + 1 > 0) && (obj.Q[iQR0 - 1] == 0.0)) {
            lastv--;
            iQR0--;
          }
          lastc = (nrows - i) - 1;
          exitg2 = false;
          while ((!exitg2) && (lastc + 1 > 0)) {
            int exitg1;
            iQR0 = (iaii + lastc * 120) + 120;
            ia = iQR0;
            do {
              exitg1 = 0;
              if (ia <= iQR0 + lastv) {
                if (obj.Q[ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  ia++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          lastc = -1;
        }
        if (lastv + 1 > 0) {
          double c;
          if (lastc + 1 != 0) {
            if (lastc >= 0) {
              std::memset(&work[0], 0,
                          static_cast<unsigned int>(lastc + 1) *
                              sizeof(double));
            }
            b_i = (iaii + 120 * lastc) + 120;
            for (n = idx; n <= b_i; n += 120) {
              c = 0.0;
              k = n + lastv;
              for (ia = n; ia <= k; ia++) {
                c += obj.Q[ia - 1] * obj.Q[((iaii + ia) - n) - 1];
              }
              iQR0 = div_nde_s32_floor((n - iaii) - 120, 120);
              work[iQR0] += c;
            }
          }
          if (!(-obj.tau[itau] == 0.0)) {
            iQR0 = iaii;
            for (idx = 0; idx <= lastc; idx++) {
              c = work[idx];
              if (c != 0.0) {
                c *= -obj.tau[itau];
                b_i = iQR0 + 120;
                k = lastv + iQR0;
                for (n = b_i; n <= k + 120; n++) {
                  obj.Q[n - 1] += obj.Q[((iaii + n) - iQR0) - 121] * c;
                }
              }
              iQR0 += 120;
            }
          }
        }
      }
      if (i < m) {
        iQR0 = iaii + 1;
        b_i = (iaii + m) - i;
        n = ((b_i - iQR0) + 1) / 2 * 2 + iQR0;
        idx = n - 2;
        for (k = iQR0; k <= idx; k += 2) {
          __m128d r;
          r = _mm_loadu_pd(&obj.Q[k - 1]);
          r = _mm_mul_pd(_mm_set1_pd(-obj.tau[itau]), r);
          _mm_storeu_pd(&obj.Q[k - 1], r);
        }
        for (k = n; k <= b_i; k++) {
          obj.Q[k - 1] *= -obj.tau[itau];
        }
      }
      obj.Q[iaii - 1] = 1.0 - obj.tau[itau];
      b_i = static_cast<unsigned char>(i - 1);
      for (idx = 0; idx < b_i; idx++) {
        obj.Q[(iaii - idx) - 2] = 0.0;
      }
      itau--;
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeQ_.cpp
//
// [EOF]
//
