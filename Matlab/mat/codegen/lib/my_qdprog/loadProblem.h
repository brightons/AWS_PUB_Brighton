//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: loadProblem.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef LOADPROBLEM_H
#define LOADPROBLEM_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct c_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void loadProblem(c_struct_T &obj, const double Aineq[2496],
                 const double bineq[26], const double Aeq[2304],
                 const double beq[24], int mLB, const double lb[96], int mUB,
                 const double ub[96], int mFixed);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for loadProblem.h
//
// [EOF]
//
