//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: loadProblem.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "loadProblem.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : c_struct_T &obj
//                const double Aineq[2496]
//                const double bineq[26]
//                const double Aeq[2304]
//                const double beq[24]
//                int mLB
//                const double lb[96]
//                int mUB
//                const double ub[96]
//                int mFixed
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void loadProblem(c_struct_T &obj, const double Aineq[2496],
                 const double bineq[26], const double Aeq[2304],
                 const double beq[24], int mLB, const double lb[96], int mUB,
                 const double ub[96], int mFixed)
{
  int k;
  k = ((mLB + mUB) + mFixed) + 50;
  obj.mConstr = k;
  obj.mConstrOrig = k;
  obj.mConstrMax = 243;
  obj.sizes[0] = mFixed;
  obj.sizes[1] = 24;
  obj.sizes[2] = 26;
  obj.sizes[3] = mLB;
  obj.sizes[4] = mUB;
  obj.sizesPhaseOne[0] = mFixed;
  obj.sizesPhaseOne[1] = 24;
  obj.sizesPhaseOne[2] = 26;
  obj.sizesPhaseOne[3] = mLB + 1;
  obj.sizesPhaseOne[4] = mUB;
  obj.sizesRegularized[0] = mFixed;
  obj.sizesRegularized[1] = 24;
  obj.sizesRegularized[2] = 26;
  obj.sizesRegularized[3] = mLB + 74;
  obj.sizesRegularized[4] = mUB;
  obj.sizesRegPhaseOne[0] = mFixed;
  obj.sizesRegPhaseOne[1] = 24;
  obj.sizesRegPhaseOne[2] = 26;
  obj.sizesRegPhaseOne[3] = mLB + 75;
  obj.sizesRegPhaseOne[4] = mUB;
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = 24;
  obj.isActiveIdxRegPhaseOne[3] = 26;
  obj.isActiveIdxRegPhaseOne[4] = mLB;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.sizesNormal[k] = obj.sizes[k];
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  for (k = 0; k < 6; k++) {
    obj.isActiveIdx[k] = obj.isActiveIdxRegPhaseOne[k];
    obj.isActiveIdxNormal[k] = obj.isActiveIdxRegPhaseOne[k];
  }
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = 24;
  obj.isActiveIdxRegPhaseOne[3] = 26;
  obj.isActiveIdxRegPhaseOne[4] = mLB + 1;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  for (k = 0; k < 6; k++) {
    obj.isActiveIdxPhaseOne[k] = obj.isActiveIdxRegPhaseOne[k];
  }
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = 24;
  obj.isActiveIdxRegPhaseOne[3] = 26;
  obj.isActiveIdxRegPhaseOne[4] = mLB + 74;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  for (k = 0; k < 6; k++) {
    obj.isActiveIdxRegularized[k] = obj.isActiveIdxRegPhaseOne[k];
  }
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = 24;
  obj.isActiveIdxRegPhaseOne[3] = 26;
  obj.isActiveIdxRegPhaseOne[4] = mLB + 75;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  for (k = 0; k < 26; k++) {
    for (int idx_row{0}; idx_row < 96; idx_row++) {
      obj.Aineq[idx_row + 97 * k] = Aineq[k + 26 * idx_row];
    }
    obj.bineq[k] = bineq[k];
  }
  for (k = 0; k < 24; k++) {
    for (int idx_row{0}; idx_row < 96; idx_row++) {
      obj.Aeq[idx_row + 97 * k] = Aeq[k + 24 * idx_row];
    }
    obj.beq[k] = beq[k];
  }
  for (k = 0; k <= 94; k += 2) {
    _mm_storeu_pd(&obj.lb[k],
                  _mm_mul_pd(_mm_loadu_pd(&lb[k]), _mm_set1_pd(-1.0)));
    _mm_storeu_pd(&obj.ub[k], _mm_loadu_pd(&ub[k]));
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for loadProblem.cpp
//
// [EOF]
//
