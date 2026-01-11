//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factorQR.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "factorQR.h"
#include "my_qdprog_data.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : d_struct_T &obj
//                const double A[23571]
//                int mrows
//                int ncols
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void factorQR(d_struct_T &obj, const double A[23571], int mrows, int ncols)
{
  int ix0;
  int scalarLB;
  boolean_T guard1;
  scalarLB = mrows * ncols;
  guard1 = false;
  if (scalarLB > 0) {
    for (int idx{0}; idx < ncols; idx++) {
      int iy0;
      ix0 = 97 * idx;
      iy0 = 120 * idx;
      scalarLB = static_cast<unsigned char>(mrows);
      for (int k{0}; k < scalarLB; k++) {
        obj.QR[iy0 + k] = A[ix0 + k];
      }
    }
    guard1 = true;
  } else if (scalarLB == 0) {
    obj.mrows = mrows;
    obj.ncols = ncols;
    obj.minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj.usedPivoting = false;
    obj.mrows = mrows;
    obj.ncols = ncols;
    scalarLB = (ncols / 4) << 2;
    ix0 = scalarLB - 4;
    for (int idx{0}; idx <= ix0; idx += 4) {
      _mm_storeu_si128(
          (__m128i *)&obj.jpvt[idx],
          _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(idx),
                                      _mm_loadu_si128((const __m128i *)&iv[0])),
                        _mm_set1_epi32(1)));
    }
    for (int idx{scalarLB}; idx < ncols; idx++) {
      obj.jpvt[idx] = idx + 1;
    }
    if (mrows <= ncols) {
      scalarLB = mrows;
    } else {
      scalarLB = ncols;
    }
    obj.minRowCol = scalarLB;
    std::memset(&obj.tau[0], 0, 120U * sizeof(double));
    if (scalarLB >= 1) {
      internal::reflapack::qrf(obj.QR, mrows, ncols, scalarLB, obj.tau);
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for factorQR.cpp
//
// [EOF]
//
