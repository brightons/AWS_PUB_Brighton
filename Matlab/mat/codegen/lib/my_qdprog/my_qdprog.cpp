//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: my_qdprog.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "my_qdprog.h"
#include "quadprog.h"
#include "rt_nonfinite.h"
#include <algorithm>

// Function Definitions
//
// Only include options supported for code generation
//
// Arguments    : const double H[9216]
//                const double f[96]
//                const double A[2496]
//                const double B[26]
//                const double Aeq[2304]
//                const double beq[24]
//                const double lb[96]
//                const double ub[96]
//                const double x0[96]
//                double x[96]
//                double *fval
// Return Type  : void
//
void my_qdprog(const double H[9216], const double f[96], const double A[2496],
               const double B[26], const double Aeq[2304], const double beq[24],
               const double lb[96], const double ub[96], const double x0[96],
               double x[96], double *fval)
{
  std::copy(&x0[0], &x0[96], &x[0]);
  *fval = coder::quadprog(H, f, A, B, Aeq, beq, lb, ub, x);
}

//
// File trailer for my_qdprog.cpp
//
// [EOF]
//
