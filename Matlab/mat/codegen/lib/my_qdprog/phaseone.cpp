//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: phaseone.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "phaseone.h"
#include "addBoundToActiveSetMatrix_.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "feasibleratiotest.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "my_qdprog_internal_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "squareQ_appendCol.h"
#include "xnrm2.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
//
// Arguments    : const double H[9216]
//                const double f[96]
//                struct_T &solution
//                e_struct_T &memspace
//                c_struct_T &workingset
//                d_struct_T &qrmanager
//                f_struct_T &cholmanager
//                const g_struct_T &runTimeOptions
//                b_struct_T &objective
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void phaseone(const double H[9216], const double f[96], struct_T &solution,
              e_struct_T &memspace, c_struct_T &workingset,
              d_struct_T &qrmanager, f_struct_T &cholmanager,
              const g_struct_T &runTimeOptions, b_struct_T &objective)
{
  int idxEndIneq_tmp;
  int idxStartIneq;
  int mConstr;
  int nVar;
  nVar = workingset.nVar;
  solution.xstar[96] = solution.maxConstr + 1.0;
  WorkingSet::setProblemType(workingset, 1);
  mConstr = workingset.nWConstr[0] + workingset.nWConstr[1];
  idxStartIneq = mConstr + 1;
  idxEndIneq_tmp = workingset.nActiveConstr;
  for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq_tmp;
       idx_global++) {
    workingset.isActiveConstr
        [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
          workingset.Wlocalidx[idx_global - 1]) -
         2] = false;
  }
  workingset.nWConstr[2] = 0;
  workingset.nWConstr[3] = 0;
  workingset.nWConstr[4] = 0;
  workingset.nActiveConstr = mConstr;
  std::memset(&objective.grad[0], 0, 97U * sizeof(double));
  std::memset(&objective.Hx[0], 0, 96U * sizeof(double));
  objective.maxVar = 97;
  objective.beta = 0.0;
  objective.rho = 0.0;
  objective.prev_objtype = 3;
  objective.prev_nvar = 96;
  objective.prev_hasLinear = true;
  objective.objtype = 5;
  objective.nvar = 97;
  objective.gammaScalar = 1.0;
  objective.hasLinear = true;
  solution.fstar = solution.xstar[96];
  solution.state = 5;
  iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
          objective, 1.0E-6 * runTimeOptions.ConstrRelTolFactor,
          runTimeOptions.MaxIterations, runTimeOptions.ConstrRelTolFactor,
          runTimeOptions.ProbRelTolFactor);
  if (workingset
          .isActiveConstr[(workingset.isActiveIdx[3] + workingset.sizes[3]) -
                          2]) {
    boolean_T exitg1;
    mConstr = workingset.sizes[0] + 25;
    exitg1 = false;
    while ((!exitg1) && (mConstr <= workingset.nActiveConstr)) {
      if ((workingset.Wid[mConstr - 1] == 4) &&
          (workingset.Wlocalidx[mConstr - 1] == workingset.sizes[3])) {
        WorkingSet::removeConstr(workingset, mConstr);
        exitg1 = true;
      } else {
        mConstr++;
      }
    }
  }
  mConstr = workingset.nActiveConstr;
  idxStartIneq = workingset.sizes[0] + 24;
  while ((mConstr > idxStartIneq) && (mConstr > nVar)) {
    WorkingSet::removeConstr(workingset, mConstr);
    mConstr--;
  }
  solution.maxConstr = solution.xstar[96];
  WorkingSet::setProblemType(workingset, 3);
  objective.objtype = objective.prev_objtype;
  objective.nvar = objective.prev_nvar;
  objective.hasLinear = objective.prev_hasLinear;
}

//
// Arguments    : const double H[9216]
//                const double f[96]
//                struct_T &solution
//                e_struct_T &memspace
//                c_struct_T &workingset
//                d_struct_T &qrmanager
//                f_struct_T &cholmanager
//                b_struct_T &objective
//                const g_struct_T &runTimeOptions
// Return Type  : void
//
void phaseone(const double H[9216], const double f[96], struct_T &solution,
              e_struct_T &memspace, c_struct_T &workingset,
              d_struct_T &qrmanager, f_struct_T &cholmanager,
              b_struct_T &objective, const g_struct_T &runTimeOptions)
{
  double options_ObjectiveLimit_tmp;
  int PROBTYPE_ORIG;
  int activeSetChangeID;
  int globalActiveConstrIdx;
  int i;
  int iAineq0;
  int iAw0;
  int idx;
  int idxMinLambda;
  int idx_global;
  int nVar_tmp;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  PROBTYPE_ORIG = workingset.probType;
  nVar_tmp = workingset.nVar;
  solution.xstar[96] = solution.maxConstr + 1.0;
  if (workingset.probType == 3) {
    iAw0 = 1;
  } else {
    iAw0 = 4;
  }
  WorkingSet::setProblemType(workingset, iAw0);
  iAw0 = workingset.nWConstr[0] + workingset.nWConstr[1];
  idxMinLambda = iAw0 + 1;
  iAineq0 = workingset.nActiveConstr;
  for (idx_global = idxMinLambda; idx_global <= iAineq0; idx_global++) {
    workingset.isActiveConstr
        [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
          workingset.Wlocalidx[idx_global - 1]) -
         2] = false;
  }
  workingset.nWConstr[2] = 0;
  workingset.nWConstr[3] = 0;
  workingset.nWConstr[4] = 0;
  workingset.nActiveConstr = iAw0;
  objective.prev_objtype = objective.objtype;
  objective.prev_nvar = objective.nvar;
  objective.prev_hasLinear = objective.hasLinear;
  objective.objtype = 5;
  objective.nvar = 97;
  objective.gammaScalar = 1.0;
  objective.hasLinear = true;
  options_ObjectiveLimit_tmp = 1.0E-6 * runTimeOptions.ConstrRelTolFactor;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  i = workingset.nVar;
  globalActiveConstrIdx = 0;
  Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
  solution.fstar = Objective::computeFval_ReuseHx(
      objective, memspace.workspace_float, f, solution.xstar);
  if (solution.iterations < runTimeOptions.MaxIterations) {
    solution.state = -5;
  } else {
    solution.state = 0;
  }
  std::memset(&solution.lambda[0], 0, 243U * sizeof(double));
  int exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      double minLambda;
      int i1;
      boolean_T guard1;
      boolean_T guard2;
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          QRManager::squareQ_appendCol(qrmanager, workingset.ATwset,
                                       97 * (workingset.nActiveConstr - 1) + 1);
          break;
        case -1:
          QRManager::deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;
        default:
          QRManager::factorQR(qrmanager, workingset.ATwset, i,
                              workingset.nActiveConstr);
          QRManager::computeQ_(qrmanager, qrmanager.mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                       objective);
        if (solution.state != -5) {
          exitg1 = 1;
        } else if ((internal::blas::xnrm2(i, solution.searchDir) <
                    1.4901161193847657E-10) ||
                   (workingset.nActiveConstr >= i)) {
          guard2 = true;
        } else {
          minLambda = feasibleratiotest(
              solution.xstar, solution.searchDir, memspace.workspace_float,
              workingset.nVar, workingset.Aineq, workingset.bineq,
              workingset.lb, workingset.ub, workingset.indexLB,
              workingset.indexUB, workingset.sizes, workingset.isActiveIdx,
              workingset.isActiveConstr, workingset.nWConstr, true, updateFval,
              idx_global, idxMinLambda);
          if (updateFval) {
            switch (idx_global) {
            case 3:
              workingset.nWConstr[2]++;
              workingset
                  .isActiveConstr[(workingset.isActiveIdx[2] + idxMinLambda) -
                                  2] = true;
              workingset.nActiveConstr++;
              idx_global = workingset.nActiveConstr - 1;
              workingset.Wid[idx_global] = 3;
              workingset.Wlocalidx[idx_global] = idxMinLambda;
              iAineq0 = 97 * (idxMinLambda - 1);
              iAw0 = 97 * idx_global;
              i1 = workingset.nVar;
              for (idx = 0; idx < i1; idx++) {
                workingset.ATwset[iAw0 + idx] = workingset.Aineq[iAineq0 + idx];
              }
              workingset.bwset[idx_global] = workingset.bineq[idxMinLambda - 1];
              break;
            case 4:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 4,
                                                     idxMinLambda);
              break;
            default:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 5,
                                                     idxMinLambda);
              break;
            }
            activeSetChangeID = 1;
          } else {
            if (objective.objtype == 5) {
              if (internal::blas::xnrm2(objective.nvar, solution.searchDir) >
                  100.0 * static_cast<double>(objective.nvar) *
                      1.4901161193847656E-8) {
                solution.state = 3;
              } else {
                solution.state = 4;
              }
            }
            subProblemChanged = false;
            if (workingset.nActiveConstr == 0) {
              solution.state = 1;
            }
          }
          if (!(minLambda == 0.0)) {
            idxMinLambda = (i / 2) << 1;
            iAineq0 = idxMinLambda - 2;
            for (iAw0 = 0; iAw0 <= iAineq0; iAw0 += 2) {
              __m128d r;
              __m128d r1;
              r = _mm_loadu_pd(&solution.searchDir[iAw0]);
              r1 = _mm_loadu_pd(&solution.xstar[iAw0]);
              _mm_storeu_pd(
                  &solution.xstar[iAw0],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(minLambda), r)));
            }
            for (iAw0 = idxMinLambda; iAw0 < i; iAw0++) {
              solution.xstar[iAw0] += minLambda * solution.searchDir[iAw0];
            }
          }
          Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
          updateFval = true;
          guard1 = true;
        }
      } else {
        idx_global = static_cast<unsigned char>(i);
        std::memset(&solution.searchDir[0], 0,
                    static_cast<unsigned int>(idx_global) * sizeof(double));
        guard2 = true;
      }
      if (guard2) {
        compute_lambda(memspace.workspace_float, solution, objective,
                       qrmanager);
        if ((solution.state != -7) || (workingset.nActiveConstr > i)) {
          idxMinLambda = 0;
          minLambda = 0.0 * runTimeOptions.ProbRelTolFactor * 0.0;
          idx_global = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          i1 = workingset.nActiveConstr;
          for (idx = idx_global; idx <= i1; idx++) {
            double d;
            d = solution.lambda[idx - 1];
            if (d < minLambda) {
              minLambda = d;
              idxMinLambda = idx;
            }
          }
          if (idxMinLambda == 0) {
            solution.state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda;
            subProblemChanged = true;
            WorkingSet::removeConstr(workingset, idxMinLambda);
            if (idxMinLambda < workingset.nActiveConstr + 1) {
              solution.lambda[idxMinLambda - 1] =
                  solution.lambda[workingset.nActiveConstr];
            }
            solution.lambda[workingset.nActiveConstr] = 0.0;
          }
        } else {
          idx_global = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          WorkingSet::removeConstr(workingset, workingset.nActiveConstr);
          solution.lambda[idx_global - 1] = 0.0;
        }
        updateFval = false;
        guard1 = true;
      }
      if (guard1) {
        solution.iterations++;
        iAw0 = objective.nvar;
        if ((solution.iterations >= runTimeOptions.MaxIterations) &&
            ((solution.state != 1) || (objective.objtype == 5))) {
          solution.state = 0;
        }
        if (solution.iterations - solution.iterations / 50 * 50 == 0) {
          solution.maxConstr =
              WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
          minLambda = solution.maxConstr;
          if (objective.objtype == 5) {
            minLambda = solution.maxConstr - solution.xstar[objective.nvar - 1];
          }
          if (minLambda > options_ObjectiveLimit_tmp) {
            boolean_T nonDegenerateWset;
            if (iAw0 - 1 >= 0) {
              std::copy(&solution.xstar[0], &solution.xstar[iAw0],
                        &solution.searchDir[0]);
            }
            nonDegenerateWset = initialize::feasibleX0ForWorkingSet(
                memspace.workspace_float, solution.searchDir, workingset,
                qrmanager);
            if ((!nonDegenerateWset) && (solution.state != 0)) {
              solution.state = -2;
            }
            activeSetChangeID = 0;
            minLambda = WorkingSet::c_maxConstraintViolation(
                workingset, solution.searchDir);
            if ((minLambda < solution.maxConstr) && (iAw0 - 1 >= 0)) {
              std::copy(&solution.searchDir[0], &solution.searchDir[iAw0],
                        &solution.xstar[0]);
            }
          }
        }
        if (updateFval) {
          solution.fstar = Objective::computeFval_ReuseHx(
              objective, memspace.workspace_float, f, solution.xstar);
          if ((solution.fstar < options_ObjectiveLimit_tmp) &&
              ((solution.state != 0) || (objective.objtype != 5))) {
            solution.state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution.fstar = Objective::computeFval_ReuseHx(
            objective, memspace.workspace_float, f, solution.xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (workingset
          .isActiveConstr[(workingset.isActiveIdx[3] + workingset.sizes[3]) -
                          2]) {
    boolean_T exitg2;
    idx = workingset.sizes[0] + 25;
    exitg2 = false;
    while ((!exitg2) && (idx <= workingset.nActiveConstr)) {
      if ((workingset.Wid[idx - 1] == 4) &&
          (workingset.Wlocalidx[idx - 1] == workingset.sizes[3])) {
        WorkingSet::removeConstr(workingset, idx);
        exitg2 = true;
      } else {
        idx++;
      }
    }
  }
  iAw0 = workingset.nActiveConstr;
  idxMinLambda = workingset.sizes[0] + 24;
  while ((iAw0 > idxMinLambda) && (iAw0 > nVar_tmp)) {
    WorkingSet::removeConstr(workingset, iAw0);
    iAw0--;
  }
  solution.maxConstr = solution.xstar[96];
  WorkingSet::setProblemType(workingset, PROBTYPE_ORIG);
  objective.objtype = objective.prev_objtype;
  objective.nvar = objective.prev_nvar;
  objective.hasLinear = objective.prev_hasLinear;
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for phaseone.cpp
//
// [EOF]
//
