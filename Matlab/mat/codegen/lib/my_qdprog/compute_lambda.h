//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: compute_lambda.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef COMPUTE_LAMBDA_H
#define COMPUTE_LAMBDA_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct_T;

struct b_struct_T;

struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_lambda(double workspace[23571], struct_T &solution,
                    const b_struct_T &objective, const d_struct_T &qrmanager);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for compute_lambda.h
//
// [EOF]
//
