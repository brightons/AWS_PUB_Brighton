//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fullColLDL2_.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "fullColLDL2_.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : f_struct_T &obj
//                int NColsRemain
//                double REG_PRIMAL
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void fullColLDL2_(f_struct_T &obj, int NColsRemain, double REG_PRIMAL)
{
  int jA;
  for (int k{0}; k < NColsRemain; k++) {
    __m128d r;
    double alpha1;
    double temp;
    int LD_diagOffset;
    int i;
    int offset1;
    int scalarLB;
    int subMatrixDim;
    int vectorUB;
    LD_diagOffset = 121 * k;
    temp = obj.FMat[LD_diagOffset];
    if (std::abs(temp) <= obj.regTol_) {
      temp += REG_PRIMAL;
      obj.FMat[LD_diagOffset] = temp;
    }
    alpha1 = -1.0 / temp;
    subMatrixDim = (NColsRemain - k) - 2;
    offset1 = LD_diagOffset + 2;
    for (jA = 0; jA <= subMatrixDim; jA++) {
      obj.workspace_[jA] = obj.FMat[(LD_diagOffset + jA) + 1];
    }
    if (!(alpha1 == 0.0)) {
      jA = LD_diagOffset;
      for (int j{0}; j <= subMatrixDim; j++) {
        temp = obj.workspace_[j];
        if (temp != 0.0) {
          int i1;
          temp *= alpha1;
          i = jA + 122;
          i1 = subMatrixDim + jA;
          scalarLB = (((((i1 - jA) + 1) / 2) << 1) + jA) + 122;
          vectorUB = scalarLB - 2;
          for (int ijA{i}; ijA <= vectorUB; ijA += 2) {
            __m128d r1;
            r = _mm_loadu_pd(&obj.workspace_[(ijA - jA) - 122]);
            r1 = _mm_loadu_pd(&obj.FMat[ijA - 1]);
            _mm_storeu_pd(&obj.FMat[ijA - 1],
                          _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(temp))));
          }
          for (int ijA{scalarLB}; ijA <= i1 + 122; ijA++) {
            obj.FMat[ijA - 1] += obj.workspace_[(ijA - jA) - 122] * temp;
          }
        }
        jA += 120;
      }
    }
    temp = 1.0 / obj.FMat[LD_diagOffset];
    i = LD_diagOffset + subMatrixDim;
    scalarLB = (((((i - LD_diagOffset) + 1) / 2) << 1) + LD_diagOffset) + 2;
    vectorUB = scalarLB - 2;
    for (jA = offset1; jA <= vectorUB; jA += 2) {
      r = _mm_loadu_pd(&obj.FMat[jA - 1]);
      _mm_storeu_pd(&obj.FMat[jA - 1], _mm_mul_pd(_mm_set1_pd(temp), r));
    }
    for (jA = scalarLB; jA <= i + 2; jA++) {
      obj.FMat[jA - 1] *= temp;
    }
  }
  jA = 121 * (NColsRemain - 1);
  if (std::abs(obj.FMat[jA]) <= obj.regTol_) {
    obj.FMat[jA] += REG_PRIMAL;
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for fullColLDL2_.cpp
//
// [EOF]
//
