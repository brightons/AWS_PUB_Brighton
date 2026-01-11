//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quadprog.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "quadprog.h"
#include "computeFval.h"
#include "driver.h"
#include "loadProblem.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const double H[9216]
//                const double f[96]
//                const double Aineq[2496]
//                const double bineq[26]
//                const double Aeq[2304]
//                const double beq[24]
//                const double lb[96]
//                const double ub[96]
//                double x0[96]
// Return Type  : double
//
namespace coder {
double quadprog(const double H[9216], const double f[96],
                const double Aineq[2496], const double bineq[26],
                const double Aeq[2304], const double beq[24],
                const double lb[96], const double ub[96], double x0[96])
{
  static c_struct_T WorkingSet;
  static d_struct_T QRManager;
  static e_struct_T memspace;
  static f_struct_T CholRegManager;
  b_struct_T QPObjective;
  g_struct_T expl_temp;
  struct_T solution;
  double fval;
  int idxFillStart;
  boolean_T exitg1;
  fval = rtInf;
  idxFillStart = 0;
  exitg1 = false;
  while ((!exitg1) && (idxFillStart < 96)) {
    if (lb[idxFillStart] > ub[idxFillStart]) {
      fval = -2.0;
      exitg1 = true;
    } else {
      idxFillStart++;
    }
  }
  if (fval == -2.0) {
    fval = rtInf;
  } else {
    double H_infnrm;
    double f_infnrm;
    double tol;
    int b_i;
    int i;
    int iATw0;
    int mFixed;
    int mLB;
    int mUB;
    solution.fstar = 0.0;
    solution.firstorderopt = 0.0;
    std::memset(&solution.lambda[0], 0, 243U * sizeof(double));
    solution.state = 0;
    solution.maxConstr = 0.0;
    solution.iterations = 0;
    std::memset(&solution.searchDir[0], 0, 97U * sizeof(double));
    std::copy(&x0[0], &x0[96], &solution.xstar[0]);
    CholRegManager.ndims = 0;
    CholRegManager.info = 0;
    CholRegManager.ConvexCheck = true;
    CholRegManager.regTol_ = 0.0;
    WorkingSet.mConstr = 0;
    WorkingSet.mConstrOrig = 0;
    WorkingSet.mConstrMax = 243;
    WorkingSet.nVar = 96;
    WorkingSet.nVarOrig = 96;
    WorkingSet.nVarMax = 97;
    WorkingSet.ldA = 97;
    std::memset(&WorkingSet.Aineq[0], 0, 2522U * sizeof(double));
    std::memset(&WorkingSet.bineq[0], 0, 26U * sizeof(double));
    std::memset(&WorkingSet.Aeq[0], 0, 2328U * sizeof(double));
    std::memset(&WorkingSet.beq[0], 0, 24U * sizeof(double));
    std::memset(&WorkingSet.lb[0], 0, 97U * sizeof(double));
    std::memset(&WorkingSet.ub[0], 0, 97U * sizeof(double));
    WorkingSet.mEqRemoved = 0;
    std::memset(&WorkingSet.indexEqRemoved[0], 0, 24U * sizeof(int));
    std::memset(&WorkingSet.ATwset[0], 0, 23571U * sizeof(double));
    WorkingSet.nActiveConstr = 0;
    std::memset(&WorkingSet.bwset[0], 0, 243U * sizeof(double));
    std::memset(&WorkingSet.maxConstrWorkspace[0], 0, 243U * sizeof(double));
    for (i = 0; i < 5; i++) {
      WorkingSet.sizes[i] = 0;
      WorkingSet.sizesNormal[i] = 0;
      WorkingSet.sizesPhaseOne[i] = 0;
      WorkingSet.sizesRegularized[i] = 0;
      WorkingSet.sizesRegPhaseOne[i] = 0;
    }
    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdx[i] = 0;
      WorkingSet.isActiveIdxNormal[i] = 0;
      WorkingSet.isActiveIdxPhaseOne[i] = 0;
      WorkingSet.isActiveIdxRegularized[i] = 0;
      WorkingSet.isActiveIdxRegPhaseOne[i] = 0;
    }
    std::memset(&WorkingSet.isActiveConstr[0], 0, 243U * sizeof(boolean_T));
    std::memset(&WorkingSet.Wid[0], 0, 243U * sizeof(int));
    std::memset(&WorkingSet.Wlocalidx[0], 0, 243U * sizeof(int));
    for (i = 0; i < 5; i++) {
      WorkingSet.nWConstr[i] = 0;
    }
    WorkingSet.probType = 3;
    WorkingSet.SLACK0 = 1.0E-5;
    std::memset(&WorkingSet.indexLB[0], 0, 97U * sizeof(int));
    std::memset(&WorkingSet.indexUB[0], 0, 97U * sizeof(int));
    std::memset(&WorkingSet.indexFixed[0], 0, 97U * sizeof(int));
    mLB = 0;
    mUB = 0;
    mFixed = 0;
    for (iATw0 = 0; iATw0 < 96; iATw0++) {
      boolean_T guard1;
      fval = lb[iATw0];
      guard1 = false;
      if ((!std::isinf(fval)) && (!std::isnan(fval))) {
        if (std::abs(fval - ub[iATw0]) < 1.0E-6) {
          mFixed++;
          WorkingSet.indexFixed[mFixed - 1] = iATw0 + 1;
        } else {
          mLB++;
          WorkingSet.indexLB[mLB - 1] = iATw0 + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        fval = ub[iATw0];
        if ((!std::isinf(fval)) && (!std::isnan(fval))) {
          mUB++;
          WorkingSet.indexUB[mUB - 1] = iATw0 + 1;
        }
      }
    }
    optim::coder::qpactiveset::WorkingSet::loadProblem(
        WorkingSet, Aineq, bineq, Aeq, beq, mLB, lb, mUB, ub, mFixed);
    optim::coder::qpactiveset::WorkingSet::setProblemType(WorkingSet, 3);
    idxFillStart = WorkingSet.isActiveIdx[2];
    for (iATw0 = idxFillStart; iATw0 < 244; iATw0++) {
      WorkingSet.isActiveConstr[iATw0 - 1] = false;
    }
    WorkingSet.nWConstr[0] = WorkingSet.sizes[0];
    WorkingSet.nWConstr[1] = 24;
    WorkingSet.nWConstr[2] = 0;
    WorkingSet.nWConstr[3] = 0;
    WorkingSet.nWConstr[4] = 0;
    WorkingSet.nActiveConstr = WorkingSet.nWConstr[0] + 24;
    b_i = static_cast<unsigned char>(WorkingSet.sizes[0]);
    for (int idx_local{0}; idx_local < b_i; idx_local++) {
      WorkingSet.Wid[idx_local] = 1;
      WorkingSet.Wlocalidx[idx_local] = idx_local + 1;
      WorkingSet.isActiveConstr[idx_local] = true;
      idxFillStart = 97 * idx_local;
      iATw0 = WorkingSet.indexFixed[idx_local];
      if (iATw0 - 2 >= 0) {
        std::memset(&WorkingSet.ATwset[idxFillStart], 0,
                    static_cast<unsigned int>(iATw0 - 1) * sizeof(double));
      }
      WorkingSet.ATwset[(WorkingSet.indexFixed[idx_local] + idxFillStart) - 1] =
          1.0;
      iATw0 = WorkingSet.indexFixed[idx_local] + 1;
      i = WorkingSet.nVar;
      if (iATw0 <= i) {
        std::memset(&WorkingSet.ATwset[(iATw0 + idxFillStart) + -1], 0,
                    static_cast<unsigned int>(
                        (((i + idxFillStart) - iATw0) - idxFillStart) + 1) *
                        sizeof(double));
      }
      WorkingSet.bwset[idx_local] =
          WorkingSet.ub[WorkingSet.indexFixed[idx_local] - 1];
    }
    WorkingSet.SLACK0 = 0.0;
    tol = 1.0;
    b_i = WorkingSet.nVar;
    for (int idx_local{0}; idx_local < 24; idx_local++) {
      int iAeq0_tmp;
      idxFillStart = WorkingSet.sizes[0] + idx_local;
      WorkingSet.Wid[idxFillStart] = 2;
      WorkingSet.Wlocalidx[idxFillStart] = idx_local + 1;
      WorkingSet.isActiveConstr[idxFillStart] = true;
      iAeq0_tmp = 97 * idx_local;
      iATw0 = 97 * idxFillStart;
      for (i = 0; i < b_i; i++) {
        WorkingSet.ATwset[iATw0 + i] = WorkingSet.Aeq[iAeq0_tmp + i];
      }
      WorkingSet.bwset[idxFillStart] = WorkingSet.beq[idx_local];
      fval = 0.0;
      for (i = 0; i < 96; i++) {
        fval += std::abs(WorkingSet.Aeq[i + iAeq0_tmp]);
      }
      tol = std::fmax(tol, fval);
    }
    for (iATw0 = 0; iATw0 < 26; iATw0++) {
      fval = 0.0;
      idxFillStart = 97 * iATw0;
      for (i = 0; i < 96; i++) {
        fval += std::abs(WorkingSet.Aineq[i + idxFillStart]);
      }
      tol = std::fmax(tol, fval);
    }
    H_infnrm = 0.0;
    f_infnrm = 0.0;
    for (iATw0 = 0; iATw0 < 96; iATw0++) {
      fval = 0.0;
      for (i = 0; i < 96; i++) {
        fval += std::abs(H[i + 96 * iATw0]);
      }
      H_infnrm = std::fmax(H_infnrm, fval);
      f_infnrm = std::fmax(f_infnrm, std::abs(f[iATw0]));
    }
    fval = std::fmax(std::fmax(tol, f_infnrm), H_infnrm);
    CholRegManager.scaleFactor = fval;
    expl_temp.ProbRelTolFactor = fval;
    expl_temp.ConstrRelTolFactor = tol;
    expl_temp.MaxIterations = 10 * (((mFixed + mLB) + mUB) + 146);
    optim::coder::qpactiveset::driver(H, f, solution, memspace, WorkingSet,
                                      CholRegManager, expl_temp, QRManager,
                                      QPObjective);
    std::copy(&solution.xstar[0], &solution.xstar[96], &x0[0]);
    if (solution.state > 0) {
      fval = solution.fstar;
    } else {
      fval = optim::coder::qpactiveset::Objective::computeFval(
          QPObjective, memspace.workspace_float, H, f, solution.xstar);
    }
  }
  return fval;
}

} // namespace coder

//
// File trailer for quadprog.cpp
//
// [EOF]
//
