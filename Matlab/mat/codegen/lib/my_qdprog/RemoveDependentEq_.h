//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: RemoveDependentEq_.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef REMOVEDEPENDENTEQ__H
#define REMOVEDEPENDENTEQ__H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct e_struct_T;

struct c_struct_T;

struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int RemoveDependentEq_(e_struct_T &memspace, c_struct_T &workingset,
                       d_struct_T &qrmanager);

int b_RemoveDependentEq_(e_struct_T &memspace, c_struct_T &workingset,
                         d_struct_T &qrmanager);

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for RemoveDependentEq_.h
//
// [EOF]
//
