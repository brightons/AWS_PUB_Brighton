//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeGrad_StoreHx.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "computeGrad_StoreHx.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : b_struct_T &obj
//                const double H[9216]
//                const double f[96]
//                const double x[97]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void computeGrad_StoreHx(b_struct_T &obj, const double H[9216],
                         const double f[96], const double x[97])
{
  switch (obj.objtype) {
  case 5: {
    int i;
    i = obj.nvar;
    if (i - 2 >= 0) {
      std::memset(&obj.grad[0], 0,
                  static_cast<unsigned int>(i - 1) * sizeof(double));
    }
    obj.grad[obj.nvar - 1] = obj.gammaScalar;
  } break;
  case 3: {
    int i;
    int ix;
    int ixlast;
    int lda;
    int vectorUB;
    ixlast = obj.nvar - 1;
    lda = obj.nvar;
    if (obj.nvar != 0) {
      if (ixlast >= 0) {
        std::memset(&obj.Hx[0], 0,
                    static_cast<unsigned int>(ixlast + 1) * sizeof(double));
      }
      ix = 0;
      i = obj.nvar * (obj.nvar - 1) + 1;
      for (int iac{1}; lda < 0 ? iac >= i : iac <= i; iac += lda) {
        vectorUB = iac + ixlast;
        for (int ia{iac}; ia <= vectorUB; ia++) {
          int i1;
          i1 = ia - iac;
          obj.Hx[i1] += H[ia - 1] * x[ix];
        }
        ix++;
      }
    }
    i = obj.nvar;
    if (i - 1 >= 0) {
      std::copy(&obj.Hx[0], &obj.Hx[i], &obj.grad[0]);
    }
    if (obj.hasLinear && (obj.nvar >= 1)) {
      ixlast = obj.nvar;
      ix = (ixlast / 2) << 1;
      vectorUB = ix - 2;
      for (lda = 0; lda <= vectorUB; lda += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj.grad[lda]);
        _mm_storeu_pd(&obj.grad[lda], _mm_add_pd(r, _mm_loadu_pd(&f[lda])));
      }
      for (lda = ix; lda < ixlast; lda++) {
        obj.grad[lda] += f[lda];
      }
    }
  } break;
  default: {
    int i;
    int ix;
    int ixlast;
    int lda;
    int vectorUB;
    ixlast = obj.nvar - 1;
    lda = obj.nvar;
    if (obj.nvar != 0) {
      if (ixlast >= 0) {
        std::memset(&obj.Hx[0], 0,
                    static_cast<unsigned int>(ixlast + 1) * sizeof(double));
      }
      ix = 0;
      i = obj.nvar * ixlast + 1;
      for (int iac{1}; lda < 0 ? iac >= i : iac <= i; iac += lda) {
        vectorUB = iac + ixlast;
        for (int ia{iac}; ia <= vectorUB; ia++) {
          int i1;
          i1 = ia - iac;
          obj.Hx[i1] += H[ia - 1] * x[ix];
        }
        ix++;
      }
    }
    i = obj.nvar + 1;
    ix = (((97 - i) / 2) << 1) + i;
    vectorUB = ix - 2;
    for (ixlast = i; ixlast <= vectorUB; ixlast += 2) {
      _mm_storeu_pd(&obj.Hx[ixlast - 1],
                    _mm_mul_pd(_mm_set1_pd(0.0), _mm_loadu_pd(&x[ixlast - 1])));
    }
    for (ixlast = ix; ixlast < 97; ixlast++) {
      obj.Hx[ixlast - 1] = 0.0 * x[ixlast - 1];
    }
    std::copy(&obj.Hx[0], &obj.Hx[96], &obj.grad[0]);
    if (obj.hasLinear && (obj.nvar >= 1)) {
      ixlast = obj.nvar;
      ix = (ixlast / 2) << 1;
      vectorUB = ix - 2;
      for (lda = 0; lda <= vectorUB; lda += 2) {
        __m128d r;
        r = _mm_loadu_pd(&obj.grad[lda]);
        _mm_storeu_pd(&obj.grad[lda], _mm_add_pd(r, _mm_loadu_pd(&f[lda])));
      }
      for (lda = ix; lda < ixlast; lda++) {
        obj.grad[lda] += f[lda];
      }
    }
  } break;
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeGrad_StoreHx.cpp
//
// [EOF]
//
