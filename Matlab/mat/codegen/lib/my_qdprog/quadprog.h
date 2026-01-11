//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quadprog.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef QUADPROG_H
#define QUADPROG_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
double quadprog(const double H[9216], const double f[96],
                const double Aineq[2496], const double bineq[26],
                const double Aeq[2304], const double beq[24],
                const double lb[96], const double ub[96], double x0[96]);

}

#endif
//
// File trailer for quadprog.h
//
// [EOF]
//
