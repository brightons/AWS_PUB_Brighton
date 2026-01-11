//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: compute_deltax.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef COMPUTE_DELTAX_H
#define COMPUTE_DELTAX_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct_T;

struct e_struct_T;

struct d_struct_T;

struct f_struct_T;

struct b_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_deltax(const double H[9216], struct_T &solution,
                    e_struct_T &memspace, const d_struct_T &qrmanager,
                    f_struct_T &cholmanager, const b_struct_T &objective);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for compute_deltax.h
//
// [EOF]
//
