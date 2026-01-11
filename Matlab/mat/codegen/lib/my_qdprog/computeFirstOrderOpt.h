//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFirstOrderOpt.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef COMPUTEFIRSTORDEROPT_H
#define COMPUTEFIRSTORDEROPT_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct_T;

struct b_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace parseoutput {
void computeFirstOrderOpt(struct_T &solution, const b_struct_T &objective,
                          int workingset_nVar,
                          const double workingset_ATwset[23571],
                          int workingset_nActiveConstr,
                          double workspace[23571]);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for computeFirstOrderOpt.h
//
// [EOF]
//
