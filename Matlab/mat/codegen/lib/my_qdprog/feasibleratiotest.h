//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleratiotest.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef FEASIBLERATIOTEST_H
#define FEASIBLERATIOTEST_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
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
    boolean_T &newBlocking, int &constrType, int &constrIdx);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for feasibleratiotest.h
//
// [EOF]
//
