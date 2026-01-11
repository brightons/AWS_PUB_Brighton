//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: my_qdprog_internal_types.h
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

#ifndef MY_QDPROG_INTERNAL_TYPES_H
#define MY_QDPROG_INTERNAL_TYPES_H

// Include Files
#include "my_qdprog_types.h"
#include "rtwtypes.h"

// Type Definitions
struct struct_T {
  double xstar[97];
  double fstar;
  double firstorderopt;
  double lambda[243];
  int state;
  double maxConstr;
  int iterations;
  double searchDir[97];
};

struct b_struct_T {
  double grad[97];
  double Hx[96];
  boolean_T hasLinear;
  int nvar;
  int maxVar;
  double beta;
  double rho;
  int objtype;
  int prev_objtype;
  int prev_nvar;
  boolean_T prev_hasLinear;
  double gammaScalar;
};

struct c_struct_T {
  int mConstr;
  int mConstrOrig;
  int mConstrMax;
  int nVar;
  int nVarOrig;
  int nVarMax;
  int ldA;
  double Aineq[2522];
  double bineq[26];
  double Aeq[2328];
  double beq[24];
  double lb[97];
  double ub[97];
  int indexLB[97];
  int indexUB[97];
  int indexFixed[97];
  int mEqRemoved;
  int indexEqRemoved[24];
  double ATwset[23571];
  double bwset[243];
  int nActiveConstr;
  double maxConstrWorkspace[243];
  int sizes[5];
  int sizesNormal[5];
  int sizesPhaseOne[5];
  int sizesRegularized[5];
  int sizesRegPhaseOne[5];
  int isActiveIdx[6];
  int isActiveIdxNormal[6];
  int isActiveIdxPhaseOne[6];
  int isActiveIdxRegularized[6];
  int isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[243];
  int Wid[243];
  int Wlocalidx[243];
  int nWConstr[5];
  int probType;
  double SLACK0;
};

struct d_struct_T {
  int ldq;
  double QR[29160];
  double Q[14400];
  int jpvt[243];
  int mrows;
  int ncols;
  double tau[120];
  int minRowCol;
  boolean_T usedPivoting;
};

struct e_struct_T {
  double workspace_float[23571];
  int workspace_int[243];
  int workspace_sort[243];
};

struct f_struct_T {
  double FMat[14400];
  int ndims;
  int info;
  double scaleFactor;
  boolean_T ConvexCheck;
  double regTol_;
  double workspace_[5760];
};

struct g_struct_T {
  int MaxIterations;
  double ConstrRelTolFactor;
  double ProbRelTolFactor;
};

#endif
//
// File trailer for my_qdprog_internal_types.h
//
// [EOF]
//
