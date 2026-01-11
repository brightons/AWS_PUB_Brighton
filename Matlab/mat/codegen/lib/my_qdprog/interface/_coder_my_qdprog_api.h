//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_my_qdprog_api.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef _CODER_MY_QDPROG_API_H
#define _CODER_MY_QDPROG_API_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void my_qdprog(real_T H[9216], real_T f[96], real_T A[2496], real_T B[26],
               real_T Aeq[2304], real_T beq[24], real_T lb[96], real_T ub[96],
               real_T x0[96], real_T x[96], real_T *fval);

void my_qdprog_api(const mxArray *const prhs[9], int32_T nlhs,
                   const mxArray *plhs[2]);

void my_qdprog_atexit();

void my_qdprog_initialize();

void my_qdprog_terminate();

void my_qdprog_xil_shutdown();

void my_qdprog_xil_terminate();

#endif
//
// File trailer for _coder_my_qdprog_api.h
//
// [EOF]
//
