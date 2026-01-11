//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingAndUpdateFval.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef CHECKSTOPPINGANDUPDATEFVAL_H
#define CHECKSTOPPINGANDUPDATEFVAL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct_T;

struct e_struct_T;

struct b_struct_T;

struct c_struct_T;

struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkStoppingAndUpdateFval(int &activeSetChangeID, const double f[96],
                                struct_T &solution, e_struct_T &memspace,
                                const b_struct_T &objective,
                                c_struct_T &workingset, d_struct_T &qrmanager,
                                int runTimeOptions_MaxIterations,
                                double runTimeOptions_ConstrRelTolFactor,
                                const boolean_T &updateFval);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for checkStoppingAndUpdateFval.h
//
// [EOF]
//
