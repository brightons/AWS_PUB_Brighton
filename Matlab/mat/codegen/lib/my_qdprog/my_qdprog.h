//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: my_qdprog.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef MY_QDPROG_H
#define MY_QDPROG_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void my_qdprog(const double H[9216], const double f[96],
                      const double A[2496], const double B[26],
                      const double Aeq[2304], const double beq[24],
                      const double lb[96], const double ub[96],
                      const double x0[96], double x[96], double *fval);

#endif
//
// File trailer for my_qdprog.h
//
// [EOF]
//
