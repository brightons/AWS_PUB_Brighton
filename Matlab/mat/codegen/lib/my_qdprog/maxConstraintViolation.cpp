//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: maxConstraintViolation.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "maxConstraintViolation.h"
#include "my_qdprog_internal_types.h"
#include "my_qdprog_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : c_struct_T &obj
//                const double x[23571]
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
double b_maxConstraintViolation(c_struct_T &obj, const double x[23571])
{
  double v;
  int i;
  int idxLB;
  if (obj.probType == 2) {
    __m128d r;
    double c;
    v = 0.0;
    for (idxLB = 0; idxLB <= 24; idxLB += 2) {
      r = _mm_loadu_pd(&obj.bineq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2425; idxLB += 97) {
      c = 0.0;
      i = idxLB + 96;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) + 242];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 26; ia++) {
      c = obj.maxConstrWorkspace[ia] - x[ia + 339];
      obj.maxConstrWorkspace[ia] = c;
      v = std::fmax(v, c);
    }
    for (idxLB = 0; idxLB <= 22; idxLB += 2) {
      r = _mm_loadu_pd(&obj.beq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2231; idxLB += 97) {
      c = 0.0;
      i = idxLB + 96;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aeq[ia - 1] * x[(ia - idxLB) + 242];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 24; ia++) {
      c = (obj.maxConstrWorkspace[ia] - x[ia + 365]) + x[ia + 389];
      obj.maxConstrWorkspace[ia] = c;
      v = std::fmax(v, std::abs(c));
    }
  } else {
    __m128d r;
    double c;
    v = 0.0;
    for (idxLB = 0; idxLB <= 24; idxLB += 2) {
      r = _mm_loadu_pd(&obj.bineq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2425; idxLB += 97) {
      c = 0.0;
      i = idxLB + obj.nVar;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) + 242];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 26; ia++) {
      v = std::fmax(v, obj.maxConstrWorkspace[ia]);
    }
    for (idxLB = 0; idxLB <= 22; idxLB += 2) {
      r = _mm_loadu_pd(&obj.beq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2231; idxLB += 97) {
      c = 0.0;
      i = idxLB + obj.nVar;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aeq[ia - 1] * x[(ia - idxLB) + 242];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 24; ia++) {
      v = std::fmax(v, std::abs(obj.maxConstrWorkspace[ia]));
    }
  }
  if (obj.sizes[3] > 0) {
    i = static_cast<unsigned char>(obj.sizes[3]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexLB[ia];
      v = std::fmax(v, -x[idxLB + 242] - obj.lb[idxLB - 1]);
    }
  }
  if (obj.sizes[4] > 0) {
    i = static_cast<unsigned char>(obj.sizes[4]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexUB[ia];
      v = std::fmax(v, x[idxLB + 242] - obj.ub[idxLB - 1]);
    }
  }
  if (obj.sizes[0] > 0) {
    i = static_cast<unsigned char>(obj.sizes[0]);
    for (int ia{0}; ia < i; ia++) {
      v = std::fmax(v, std::abs(x[obj.indexFixed[ia] + 242] -
                                obj.ub[obj.indexFixed[ia] - 1]));
    }
  }
  return v;
}

//
// Arguments    : c_struct_T &obj
//                const double x[97]
// Return Type  : double
//
double c_maxConstraintViolation(c_struct_T &obj, const double x[97])
{
  double v;
  int i;
  int idxLB;
  if (obj.probType == 2) {
    __m128d r;
    double c;
    v = 0.0;
    for (idxLB = 0; idxLB <= 24; idxLB += 2) {
      r = _mm_loadu_pd(&obj.bineq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2425; idxLB += 97) {
      c = 0.0;
      i = idxLB + 96;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 26; ia++) {
      c = obj.maxConstrWorkspace[ia] - x[96];
      obj.maxConstrWorkspace[ia] = c;
      v = std::fmax(v, c);
    }
    for (idxLB = 0; idxLB <= 22; idxLB += 2) {
      r = _mm_loadu_pd(&obj.beq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2231; idxLB += 97) {
      c = 0.0;
      i = idxLB + 96;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aeq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
  } else {
    __m128d r;
    double c;
    v = 0.0;
    for (idxLB = 0; idxLB <= 24; idxLB += 2) {
      r = _mm_loadu_pd(&obj.bineq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2425; idxLB += 97) {
      c = 0.0;
      i = idxLB + obj.nVar;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 26; ia++) {
      v = std::fmax(v, obj.maxConstrWorkspace[ia]);
    }
    for (idxLB = 0; idxLB <= 22; idxLB += 2) {
      r = _mm_loadu_pd(&obj.beq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2231; idxLB += 97) {
      c = 0.0;
      i = idxLB + obj.nVar;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aeq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 24; ia++) {
      v = std::fmax(v, std::abs(obj.maxConstrWorkspace[ia]));
    }
  }
  if (obj.sizes[3] > 0) {
    i = static_cast<unsigned char>(obj.sizes[3]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexLB[ia] - 1;
      v = std::fmax(v, -x[idxLB] - obj.lb[idxLB]);
    }
  }
  if (obj.sizes[4] > 0) {
    i = static_cast<unsigned char>(obj.sizes[4]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexUB[ia] - 1;
      v = std::fmax(v, x[idxLB] - obj.ub[idxLB]);
    }
  }
  if (obj.sizes[0] > 0) {
    i = static_cast<unsigned char>(obj.sizes[0]);
    for (int ia{0}; ia < i; ia++) {
      v = std::fmax(v, std::abs(x[obj.indexFixed[ia] - 1] -
                                obj.ub[obj.indexFixed[ia] - 1]));
    }
  }
  return v;
}

//
// Arguments    : c_struct_T &obj
//                const double x[23571]
// Return Type  : double
//
double maxConstraintViolation(c_struct_T &obj, const double x[23571])
{
  double v;
  int i;
  int idxLB;
  if (obj.probType == 2) {
    __m128d r;
    double c;
    v = 0.0;
    for (idxLB = 0; idxLB <= 24; idxLB += 2) {
      r = _mm_loadu_pd(&obj.bineq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2425; idxLB += 97) {
      c = 0.0;
      i = idxLB + 96;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 26; ia++) {
      c = obj.maxConstrWorkspace[ia] - x[ia + 96];
      obj.maxConstrWorkspace[ia] = c;
      v = std::fmax(v, c);
    }
    for (idxLB = 0; idxLB <= 22; idxLB += 2) {
      r = _mm_loadu_pd(&obj.beq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2231; idxLB += 97) {
      c = 0.0;
      i = idxLB + 96;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aeq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 24; ia++) {
      c = (obj.maxConstrWorkspace[ia] - x[ia + 122]) + x[ia + 146];
      obj.maxConstrWorkspace[ia] = c;
      v = std::fmax(v, std::abs(c));
    }
  } else {
    __m128d r;
    double c;
    v = 0.0;
    for (idxLB = 0; idxLB <= 24; idxLB += 2) {
      r = _mm_loadu_pd(&obj.bineq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2425; idxLB += 97) {
      c = 0.0;
      i = idxLB + obj.nVar;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aineq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 26; ia++) {
      v = std::fmax(v, obj.maxConstrWorkspace[ia]);
    }
    for (idxLB = 0; idxLB <= 22; idxLB += 2) {
      r = _mm_loadu_pd(&obj.beq[idxLB]);
      _mm_storeu_pd(&obj.maxConstrWorkspace[idxLB],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idxLB = 0; idxLB <= 2231; idxLB += 97) {
      c = 0.0;
      i = idxLB + obj.nVar;
      for (int ia{idxLB + 1}; ia <= i; ia++) {
        c += obj.Aeq[ia - 1] * x[(ia - idxLB) - 1];
      }
      i = div_nde_s32_floor(idxLB, 97);
      obj.maxConstrWorkspace[i] += c;
    }
    for (int ia{0}; ia < 24; ia++) {
      v = std::fmax(v, std::abs(obj.maxConstrWorkspace[ia]));
    }
  }
  if (obj.sizes[3] > 0) {
    i = static_cast<unsigned char>(obj.sizes[3]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexLB[ia] - 1;
      v = std::fmax(v, -x[idxLB] - obj.lb[idxLB]);
    }
  }
  if (obj.sizes[4] > 0) {
    i = static_cast<unsigned char>(obj.sizes[4]);
    for (int ia{0}; ia < i; ia++) {
      idxLB = obj.indexUB[ia] - 1;
      v = std::fmax(v, x[idxLB] - obj.ub[idxLB]);
    }
  }
  if (obj.sizes[0] > 0) {
    i = static_cast<unsigned char>(obj.sizes[0]);
    for (int ia{0}; ia < i; ia++) {
      v = std::fmax(v, std::abs(x[obj.indexFixed[ia] - 1] -
                                obj.ub[obj.indexFixed[ia] - 1]));
    }
  }
  return v;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for maxConstraintViolation.cpp
//
// [EOF]
//
