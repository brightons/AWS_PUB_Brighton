//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleratiotest.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "feasibleratiotest.h"
#include "my_qdprog_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <cmath>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const double solution_xstar[97]
//                const double solution_searchDir[97]
//                double workspace[23571]
//                int workingset_nVar
//                const double workingset_Aineq[2522]
//                const double workingset_bineq[26]
//                const double workingset_lb[97]
//                const double workingset_ub[97]
//                const int workingset_indexLB[97]
//                const int workingset_indexUB[97]
//                const int workingset_sizes[5]
//                const int workingset_isActiveIdx[6]
//                const boolean_T workingset_isActiveConstr[243]
//                const int workingset_nWConstr[5]
//                boolean_T isPhaseOne
//                boolean_T &newBlocking
//                int &constrType
//                int &constrIdx
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
double feasibleratiotest(
    const double solution_xstar[97], const double solution_searchDir[97],
    double workspace[23571], int workingset_nVar,
    const double workingset_Aineq[2522], const double workingset_bineq[26],
    const double workingset_lb[97], const double workingset_ub[97],
    const int workingset_indexLB[97], const int workingset_indexUB[97],
    const int workingset_sizes[5], const int workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr[243],
    const int workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T &newBlocking, int &constrType, int &constrIdx)
{
  double alpha;
  double c;
  double denomTol;
  double phaseOneCorrectionP;
  double phaseOneCorrectionX;
  double ratio;
  int i;
  int k;
  alpha = 1.0E+30;
  newBlocking = false;
  constrType = 0;
  constrIdx = 0;
  denomTol = 2.2204460492503131E-13 *
             internal::blas::xnrm2(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 26) {
    for (k = 0; k <= 24; k += 2) {
      __m128d r;
      r = _mm_loadu_pd(&workingset_bineq[k]);
      r = _mm_mul_pd(r, _mm_set1_pd(-1.0));
      _mm_storeu_pd(&workspace[k], r);
    }
    for (k = 0; k <= 2425; k += 97) {
      c = 0.0;
      i = k + workingset_nVar;
      for (int ia{k + 1}; ia <= i; ia++) {
        c += workingset_Aineq[ia - 1] * solution_xstar[(ia - k) - 1];
      }
      i = div_nde_s32_floor(k, 97);
      workspace[i] += c;
    }
    std::memset(&workspace[243], 0, 26U * sizeof(double));
    for (k = 0; k <= 2425; k += 97) {
      c = 0.0;
      i = k + workingset_nVar;
      for (int ia{k + 1}; ia <= i; ia++) {
        c += workingset_Aineq[ia - 1] * solution_searchDir[(ia - k) - 1];
      }
      i = div_nde_s32_floor(k, 97) + 243;
      workspace[i] += c;
    }
    for (int ia{0}; ia < 26; ia++) {
      phaseOneCorrectionX = workspace[ia + 243];
      if ((phaseOneCorrectionX > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] + ia) - 1])) {
        c = workspace[ia];
        c = std::fmin(std::abs(c), 1.0E-6 - c) / phaseOneCorrectionX;
        if (c < alpha) {
          alpha = c;
          constrType = 3;
          constrIdx = ia + 1;
          newBlocking = true;
        }
      }
    }
  }
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX =
        static_cast<double>(isPhaseOne) * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP = static_cast<double>(isPhaseOne) *
                          solution_searchDir[workingset_nVar - 1];
    i = workingset_sizes[3];
    for (int ia{0}; ia <= i - 2; ia++) {
      k = workingset_indexLB[ia];
      c = -solution_searchDir[k - 1] - phaseOneCorrectionP;
      if ((c > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + ia) - 1])) {
        ratio = (-solution_xstar[k - 1] - workingset_lb[k - 1]) -
                phaseOneCorrectionX;
        c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / c;
        if (c < alpha) {
          alpha = c;
          constrType = 4;
          constrIdx = ia + 1;
          newBlocking = true;
        }
      }
    }
    i = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    phaseOneCorrectionX = -solution_searchDir[i];
    if ((phaseOneCorrectionX > denomTol) &&
        (!workingset_isActiveConstr
             [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar[i] - workingset_lb[i];
      c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / phaseOneCorrectionX;
      if (c < alpha) {
        alpha = c;
        constrType = 4;
        constrIdx = workingset_sizes[3];
        newBlocking = true;
      }
    }
  }
  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    phaseOneCorrectionX =
        static_cast<double>(isPhaseOne) * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP = static_cast<double>(isPhaseOne) *
                          solution_searchDir[workingset_nVar - 1];
    i = static_cast<unsigned char>(workingset_sizes[4]);
    for (int ia{0}; ia < i; ia++) {
      k = workingset_indexUB[ia];
      c = solution_searchDir[k - 1] - phaseOneCorrectionP;
      if ((c > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + ia) - 1])) {
        ratio = (solution_xstar[k - 1] - workingset_ub[k - 1]) -
                phaseOneCorrectionX;
        c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / c;
        if (c < alpha) {
          alpha = c;
          constrType = 5;
          constrIdx = ia + 1;
          newBlocking = true;
        }
      }
    }
  }
  if (!isPhaseOne) {
    if (newBlocking && (alpha > 1.0)) {
      newBlocking = false;
    }
    alpha = std::fmin(alpha, 1.0);
  }
  return alpha;
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for feasibleratiotest.cpp
//
// [EOF]
//
