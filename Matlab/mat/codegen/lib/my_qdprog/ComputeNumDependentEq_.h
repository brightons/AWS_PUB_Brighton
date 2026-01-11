//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeNumDependentEq_.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef COMPUTENUMDEPENDENTEQ__H
#define COMPUTENUMDEPENDENTEQ__H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int ComputeNumDependentEq_(d_struct_T &qrmanager, const double beqf[243],
                           int mConstr, int nVar);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for ComputeNumDependentEq_.h
//
// [EOF]
//
