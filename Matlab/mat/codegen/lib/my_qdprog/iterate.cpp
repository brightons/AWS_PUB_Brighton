//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: iterate.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "iterate.h"
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "feasibleratiotest.h"
#include "maxConstraintViolation.h"
#include "my_qdprog_internal_types.h"
#include "my_qdprog_rtwutil.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xgemv.h"
#include "xnrm2.h"
#include <algorithm>
#include <cmath>
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
//                b_struct_T &objective
//                boolean_T runTimeOptions_RemainFeasible
//                int runTimeOptions_MaxIterations
//                double runTimeOptions_ConstrRelTolFactor
//                double runTimeOptions_ProbRelTolFactor
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void b_iterate(const double H[9216], const double f[96], struct_T &solution,
               e_struct_T &memspace, c_struct_T &workingset,
               d_struct_T &qrmanager, f_struct_T &cholmanager,
               b_struct_T &objective, boolean_T runTimeOptions_RemainFeasible,
               int runTimeOptions_MaxIterations,
               double runTimeOptions_ConstrRelTolFactor,
               double runTimeOptions_ProbRelTolFactor)
{
  double tolDelta;
  int TYPE;
  int activeConstrChangedType;
  int activeSetChangeID;
  int globalActiveConstrIdx;
  int localActiveConstrIdx;
  int nVar;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective.objtype;
  tolDelta = 6.7434957617430445E-7;
  nVar = workingset.nVar;
  globalActiveConstrIdx = 0;
  Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
  solution.fstar = Objective::computeFval_ReuseHx(
      objective, memspace.workspace_float, f, solution.xstar);
  if (solution.iterations < runTimeOptions_MaxIterations) {
    solution.state = -5;
  } else {
    solution.state = 0;
  }
  std::memset(&solution.lambda[0], 0, 243U * sizeof(double));
  int exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      double c;
      double phaseOneCorrectionP;
      int i;
      int idxMinLambda;
      boolean_T guard1;
      guard1 = false;
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
          QRManager::factorQR(qrmanager, workingset.ATwset, nVar,
                              workingset.nActiveConstr);
          QRManager::computeQ_(qrmanager, qrmanager.mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                       objective);
        if (solution.state != -5) {
          exitg1 = 1;
        } else if ((internal::blas::xnrm2(nVar, solution.searchDir) < 1.0E-8) ||
                   (workingset.nActiveConstr >= nVar)) {
          guard1 = true;
        } else {
          updateFval = (TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            c = feasibleratiotest(
                solution.xstar, solution.searchDir, memspace.workspace_float,
                workingset.nVar, workingset.Aineq, workingset.bineq,
                workingset.lb, workingset.ub, workingset.indexLB,
                workingset.indexUB, workingset.sizes, workingset.isActiveIdx,
                workingset.isActiveConstr, workingset.nWConstr, updateFval,
                updateFval, activeConstrChangedType, localActiveConstrIdx);
          } else {
            double alpha;
            double alphaTemp;
            double denomTol;
            double p_max;
            double pk_corrected;
            double ratio_tmp;
            alpha = 1.0E+30;
            updateFval = false;
            activeConstrChangedType = 0;
            localActiveConstrIdx = 0;
            p_max = 0.0;
            denomTol =
                2.2204460492503131E-13 *
                internal::blas::xnrm2(workingset.nVar, solution.searchDir);
            if (workingset.nWConstr[2] < 26) {
              std::copy(&workingset.bineq[0], &workingset.bineq[26],
                        &memspace.workspace_float[0]);
              internal::blas::xgemv(workingset.nVar, workingset.Aineq,
                                    solution.xstar, memspace.workspace_float);
              std::memset(&memspace.workspace_float[243], 0,
                          26U * sizeof(double));
              for (idxMinLambda = 0; idxMinLambda <= 2425; idxMinLambda += 97) {
                c = 0.0;
                i = idxMinLambda + workingset.nVar;
                for (int ia{idxMinLambda + 1}; ia <= i; ia++) {
                  c += workingset.Aineq[ia - 1] *
                       solution.searchDir[(ia - idxMinLambda) - 1];
                }
                i = div_nde_s32_floor(idxMinLambda, 97) + 243;
                memspace.workspace_float[i] += c;
              }
              for (int ia{0}; ia < 26; ia++) {
                phaseOneCorrectionP = memspace.workspace_float[ia + 243];
                if ((phaseOneCorrectionP > denomTol) &&
                    (!workingset
                          .isActiveConstr[(workingset.isActiveIdx[2] + ia) -
                                          1])) {
                  c = memspace.workspace_float[ia];
                  alphaTemp = std::fmin(std::abs(c - tolDelta),
                                        (1.0E-6 - c) + tolDelta) /
                              phaseOneCorrectionP;
                  if ((alphaTemp <= alpha) &&
                      (std::abs(phaseOneCorrectionP) > p_max)) {
                    alpha = alphaTemp;
                    activeConstrChangedType = 3;
                    localActiveConstrIdx = ia + 1;
                    updateFval = true;
                  }
                  alphaTemp =
                      std::fmin(std::abs(c), 1.0E-6 - c) / phaseOneCorrectionP;
                  if (alphaTemp < alpha) {
                    alpha = alphaTemp;
                    activeConstrChangedType = 3;
                    localActiveConstrIdx = ia + 1;
                    updateFval = true;
                    p_max = std::abs(phaseOneCorrectionP);
                  }
                }
              }
            }
            if (workingset.nWConstr[3] < workingset.sizes[3]) {
              idxMinLambda = workingset.nVar - 1;
              c = 0.0 * solution.xstar[idxMinLambda];
              phaseOneCorrectionP = 0.0 * solution.searchDir[idxMinLambda];
              i = workingset.sizes[3];
              for (int ia{0}; ia <= i - 2; ia++) {
                pk_corrected = -solution.searchDir[workingset.indexLB[ia] - 1] -
                               phaseOneCorrectionP;
                if ((pk_corrected > denomTol) &&
                    (!workingset
                          .isActiveConstr[(workingset.isActiveIdx[3] + ia) -
                                          1])) {
                  ratio_tmp = -solution.xstar[workingset.indexLB[ia] - 1] -
                              workingset.lb[workingset.indexLB[ia] - 1];
                  alphaTemp = (ratio_tmp - tolDelta) - c;
                  alphaTemp =
                      std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) /
                      pk_corrected;
                  if ((alphaTemp <= alpha) &&
                      (std::abs(pk_corrected) > p_max)) {
                    alpha = alphaTemp;
                    activeConstrChangedType = 4;
                    localActiveConstrIdx = ia + 1;
                    updateFval = true;
                  }
                  alphaTemp = ratio_tmp - c;
                  alphaTemp =
                      std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) /
                      pk_corrected;
                  if (alphaTemp < alpha) {
                    alpha = alphaTemp;
                    activeConstrChangedType = 4;
                    localActiveConstrIdx = ia + 1;
                    updateFval = true;
                    p_max = std::abs(pk_corrected);
                  }
                }
              }
              i = workingset.indexLB[workingset.sizes[3] - 1] - 1;
              phaseOneCorrectionP = solution.searchDir[i];
              if ((-phaseOneCorrectionP > denomTol) &&
                  (!workingset.isActiveConstr[(workingset.isActiveIdx[3] +
                                               workingset.sizes[3]) -
                                              2])) {
                ratio_tmp = -solution.xstar[i] - workingset.lb[i];
                alphaTemp = ratio_tmp - tolDelta;
                alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) /
                            -phaseOneCorrectionP;
                if ((alphaTemp <= alpha) &&
                    (std::abs(phaseOneCorrectionP) > p_max)) {
                  alpha = alphaTemp;
                  activeConstrChangedType = 4;
                  localActiveConstrIdx = workingset.sizes[3];
                  updateFval = true;
                }
                alphaTemp = std::fmin(std::abs(ratio_tmp), 1.0E-6 - ratio_tmp) /
                            -phaseOneCorrectionP;
                if (alphaTemp < alpha) {
                  alpha = alphaTemp;
                  activeConstrChangedType = 4;
                  localActiveConstrIdx = workingset.sizes[3];
                  updateFval = true;
                  p_max = std::abs(solution.searchDir[i]);
                }
              }
            }
            if (workingset.nWConstr[4] < workingset.sizes[4]) {
              idxMinLambda = workingset.nVar - 1;
              c = 0.0 * solution.xstar[idxMinLambda];
              phaseOneCorrectionP = 0.0 * solution.searchDir[idxMinLambda];
              i = static_cast<unsigned char>(workingset.sizes[4]);
              for (int ia{0}; ia < i; ia++) {
                pk_corrected = solution.searchDir[workingset.indexUB[ia] - 1] -
                               phaseOneCorrectionP;
                if ((pk_corrected > denomTol) &&
                    (!workingset
                          .isActiveConstr[(workingset.isActiveIdx[4] + ia) -
                                          1])) {
                  ratio_tmp = solution.xstar[workingset.indexUB[ia] - 1] -
                              workingset.ub[workingset.indexUB[ia] - 1];
                  alphaTemp = (ratio_tmp - tolDelta) - c;
                  alphaTemp =
                      std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) /
                      pk_corrected;
                  if ((alphaTemp <= alpha) &&
                      (std::abs(pk_corrected) > p_max)) {
                    alpha = alphaTemp;
                    activeConstrChangedType = 5;
                    localActiveConstrIdx = ia + 1;
                    updateFval = true;
                  }
                  alphaTemp = ratio_tmp - c;
                  alphaTemp =
                      std::fmin(std::abs(alphaTemp), 1.0E-6 - alphaTemp) /
                      pk_corrected;
                  if (alphaTemp < alpha) {
                    alpha = alphaTemp;
                    activeConstrChangedType = 5;
                    localActiveConstrIdx = ia + 1;
                    updateFval = true;
                    p_max = std::abs(pk_corrected);
                  }
                }
              }
            }
            tolDelta += 6.608625846508183E-7;
            if (p_max > 0.0) {
              alpha = std::fmax(alpha, 6.608625846508183E-7 / p_max);
            }
            if (updateFval && (alpha > 1.0)) {
              updateFval = false;
            }
            c = std::fmin(alpha, 1.0);
          }
          if (updateFval) {
            switch (activeConstrChangedType) {
            case 3:
              WorkingSet::addAineqConstr(workingset, localActiveConstrIdx);
              break;
            case 4:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 4,
                                                     localActiveConstrIdx);
              break;
            default:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 5,
                                                     localActiveConstrIdx);
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
          if (!(c == 0.0)) {
            idxMinLambda = (nVar / 2) << 1;
            activeConstrChangedType = idxMinLambda - 2;
            for (localActiveConstrIdx = 0;
                 localActiveConstrIdx <= activeConstrChangedType;
                 localActiveConstrIdx += 2) {
              __m128d r;
              __m128d r1;
              r = _mm_loadu_pd(&solution.searchDir[localActiveConstrIdx]);
              r1 = _mm_loadu_pd(&solution.xstar[localActiveConstrIdx]);
              _mm_storeu_pd(&solution.xstar[localActiveConstrIdx],
                            _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(c), r)));
            }
            for (localActiveConstrIdx = idxMinLambda;
                 localActiveConstrIdx < nVar; localActiveConstrIdx++) {
              solution.xstar[localActiveConstrIdx] +=
                  c * solution.searchDir[localActiveConstrIdx];
            }
          }
          Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
          updateFval = true;
          stopping::checkStoppingAndUpdateFval(
              activeSetChangeID, f, solution, memspace, objective, workingset,
              qrmanager, runTimeOptions_MaxIterations,
              runTimeOptions_ConstrRelTolFactor, updateFval);
        }
      } else {
        i = static_cast<unsigned char>(nVar);
        std::memset(&solution.searchDir[0], 0,
                    static_cast<unsigned int>(i) * sizeof(double));
        guard1 = true;
      }
      if (guard1) {
        compute_lambda(memspace.workspace_float, solution, objective,
                       qrmanager);
        if ((solution.state != -7) || (workingset.nActiveConstr > nVar)) {
          idxMinLambda = 0;
          c = 0.0 * runTimeOptions_ProbRelTolFactor *
              static_cast<double>(TYPE != 5);
          i = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          activeConstrChangedType = workingset.nActiveConstr;
          for (int ia{i}; ia <= activeConstrChangedType; ia++) {
            phaseOneCorrectionP = solution.lambda[ia - 1];
            if (phaseOneCorrectionP < c) {
              c = phaseOneCorrectionP;
              idxMinLambda = ia;
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
          idxMinLambda = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          WorkingSet::removeConstr(workingset, workingset.nActiveConstr);
          solution.lambda[idxMinLambda - 1] = 0.0;
        }
        updateFval = false;
        stopping::checkStoppingAndUpdateFval(
            activeSetChangeID, f, solution, memspace, objective, workingset,
            qrmanager, runTimeOptions_MaxIterations,
            runTimeOptions_ConstrRelTolFactor, updateFval);
      }
    } else {
      if (!updateFval) {
        solution.fstar = Objective::computeFval_ReuseHx(
            objective, memspace.workspace_float, f, solution.xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
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
//                double options_ObjectiveLimit
//                int runTimeOptions_MaxIterations
//                double runTimeOptions_ConstrRelTolFactor
//                double runTimeOptions_ProbRelTolFactor
// Return Type  : void
//
void iterate(const double H[9216], const double f[96], struct_T &solution,
             e_struct_T &memspace, c_struct_T &workingset,
             d_struct_T &qrmanager, f_struct_T &cholmanager,
             b_struct_T &objective, double options_ObjectiveLimit,
             int runTimeOptions_MaxIterations,
             double runTimeOptions_ConstrRelTolFactor,
             double runTimeOptions_ProbRelTolFactor)
{
  int activeSetChangeID;
  int globalActiveConstrIdx;
  int nVar_tmp;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  nVar_tmp = workingset.nVar;
  globalActiveConstrIdx = 0;
  Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
  solution.fstar = Objective::computeFval_ReuseHx(
      objective, memspace.workspace_float, f, solution.xstar);
  solution.state = -5;
  std::memset(&solution.lambda[0], 0, 243U * sizeof(double));
  int exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      double c;
      double d;
      int i;
      int iAw0;
      int nVar;
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
          QRManager::factorQR(qrmanager, workingset.ATwset, nVar_tmp,
                              workingset.nActiveConstr);
          QRManager::computeQ_(qrmanager, qrmanager.mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                       objective);
        if (solution.state != -5) {
          exitg1 = 1;
        } else if ((internal::blas::xnrm2(nVar_tmp, solution.searchDir) <
                    1.4901161193847657E-10) ||
                   (workingset.nActiveConstr >= nVar_tmp)) {
          guard2 = true;
        } else {
          __m128d r;
          double alpha;
          double denomTol;
          double ratio;
          int idx_local;
          nVar = workingset.nVar - 1;
          alpha = 1.0E+30;
          updateFval = false;
          i = 0;
          idx_local = -1;
          denomTol = 2.2204460492503131E-13 *
                     internal::blas::xnrm2(workingset.nVar, solution.searchDir);
          if (workingset.nWConstr[2] < 26) {
            for (int k{0}; k <= 24; k += 2) {
              r = _mm_loadu_pd(&workingset.bineq[k]);
              r = _mm_mul_pd(r, _mm_set1_pd(-1.0));
              _mm_storeu_pd(&memspace.workspace_float[k], r);
            }
            for (int k{0}; k <= 2425; k += 97) {
              c = 0.0;
              iAw0 = k + workingset.nVar;
              for (int ia{k + 1}; ia <= iAw0; ia++) {
                c += workingset.Aineq[ia - 1] * solution.xstar[(ia - k) - 1];
              }
              iAw0 = div_nde_s32_floor(k, 97);
              memspace.workspace_float[iAw0] += c;
            }
            std::memset(&memspace.workspace_float[243], 0,
                        26U * sizeof(double));
            for (int k{0}; k <= 2425; k += 97) {
              c = 0.0;
              iAw0 = k + workingset.nVar;
              for (int ia{k + 1}; ia <= iAw0; ia++) {
                c +=
                    workingset.Aineq[ia - 1] * solution.searchDir[(ia - k) - 1];
              }
              iAw0 = div_nde_s32_floor(k, 97) + 243;
              memspace.workspace_float[iAw0] += c;
            }
            for (int k{0}; k < 26; k++) {
              d = memspace.workspace_float[k + 243];
              if ((d > denomTol) &&
                  (!workingset
                        .isActiveConstr[(workingset.isActiveIdx[2] + k) - 1])) {
                c = memspace.workspace_float[k];
                c = std::fmin(std::abs(c), 1.0E-6 - c) / d;
                if (c < alpha) {
                  alpha = c;
                  i = 3;
                  idx_local = k;
                  updateFval = true;
                }
              }
            }
          }
          if (workingset.nWConstr[3] < workingset.sizes[3]) {
            iAw0 = workingset.sizes[3];
            for (int k{0}; k <= iAw0 - 2; k++) {
              c = -solution.searchDir[workingset.indexLB[k] - 1] -
                  solution.searchDir[nVar];
              if ((c > denomTol) &&
                  (!workingset
                        .isActiveConstr[(workingset.isActiveIdx[3] + k) - 1])) {
                ratio = (-solution.xstar[workingset.indexLB[k] - 1] -
                         workingset.lb[workingset.indexLB[k] - 1]) -
                        solution.xstar[nVar];
                c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / c;
                if (c < alpha) {
                  alpha = c;
                  i = 4;
                  idx_local = k;
                  updateFval = true;
                }
              }
            }
            iAw0 = workingset.indexLB[workingset.sizes[3] - 1] - 1;
            d = -solution.searchDir[iAw0];
            if ((d > denomTol) &&
                (!workingset.isActiveConstr[(workingset.isActiveIdx[3] +
                                             workingset.sizes[3]) -
                                            2])) {
              ratio = -solution.xstar[iAw0] - workingset.lb[iAw0];
              c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / d;
              if (c < alpha) {
                alpha = c;
                i = 4;
                idx_local = workingset.sizes[3] - 1;
                updateFval = true;
              }
            }
          }
          if (workingset.nWConstr[4] < workingset.sizes[4]) {
            iAw0 = static_cast<unsigned char>(workingset.sizes[4]);
            for (int k{0}; k < iAw0; k++) {
              c = solution.searchDir[workingset.indexUB[k] - 1] -
                  solution.searchDir[nVar];
              if ((c > denomTol) &&
                  (!workingset
                        .isActiveConstr[(workingset.isActiveIdx[4] + k) - 1])) {
                ratio = (solution.xstar[workingset.indexUB[k] - 1] -
                         workingset.ub[workingset.indexUB[k] - 1]) -
                        solution.xstar[nVar];
                c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / c;
                if (c < alpha) {
                  alpha = c;
                  i = 5;
                  idx_local = k;
                  updateFval = true;
                }
              }
            }
          }
          if (updateFval) {
            switch (i) {
            case 3:
              workingset.nWConstr[2]++;
              workingset
                  .isActiveConstr[(workingset.isActiveIdx[2] + idx_local) - 1] =
                  true;
              workingset.nActiveConstr++;
              i = workingset.nActiveConstr - 1;
              workingset.Wid[i] = 3;
              workingset.Wlocalidx[i] = idx_local + 1;
              nVar = 97 * idx_local;
              iAw0 = 97 * i;
              for (int k{0}; k < nVar_tmp; k++) {
                workingset.ATwset[iAw0 + k] = workingset.Aineq[nVar + k];
              }
              workingset.bwset[i] = workingset.bineq[idx_local];
              break;
            case 4:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 4,
                                                     idx_local + 1);
              break;
            default:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 5,
                                                     idx_local + 1);
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
          if (!(alpha == 0.0)) {
            nVar = (nVar_tmp / 2) << 1;
            iAw0 = nVar - 2;
            for (int k{0}; k <= iAw0; k += 2) {
              __m128d r1;
              r = _mm_loadu_pd(&solution.searchDir[k]);
              r1 = _mm_loadu_pd(&solution.xstar[k]);
              _mm_storeu_pd(&solution.xstar[k],
                            _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(alpha), r)));
            }
            for (int k{nVar}; k < nVar_tmp; k++) {
              solution.xstar[k] += alpha * solution.searchDir[k];
            }
          }
          Objective::computeGrad_StoreHx(objective, H, f, solution.xstar);
          updateFval = true;
          guard1 = true;
        }
      } else {
        i = static_cast<unsigned char>(nVar_tmp);
        std::memset(&solution.searchDir[0], 0,
                    static_cast<unsigned int>(i) * sizeof(double));
        guard2 = true;
      }
      if (guard2) {
        compute_lambda(memspace.workspace_float, solution, objective,
                       qrmanager);
        if ((solution.state != -7) || (workingset.nActiveConstr > nVar_tmp)) {
          nVar = 0;
          c = 0.0 * runTimeOptions_ProbRelTolFactor * 0.0;
          i = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          iAw0 = workingset.nActiveConstr;
          for (int k{i}; k <= iAw0; k++) {
            d = solution.lambda[k - 1];
            if (d < c) {
              c = d;
              nVar = k;
            }
          }
          if (nVar == 0) {
            solution.state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = nVar;
            subProblemChanged = true;
            WorkingSet::removeConstr(workingset, nVar);
            if (nVar < workingset.nActiveConstr + 1) {
              solution.lambda[nVar - 1] =
                  solution.lambda[workingset.nActiveConstr];
            }
            solution.lambda[workingset.nActiveConstr] = 0.0;
          }
        } else {
          nVar = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          WorkingSet::removeConstr(workingset, workingset.nActiveConstr);
          solution.lambda[nVar - 1] = 0.0;
        }
        updateFval = false;
        guard1 = true;
      }
      if (guard1) {
        solution.iterations++;
        if (solution.iterations >= runTimeOptions_MaxIterations) {
          solution.state = 0;
        }
        if (solution.iterations - solution.iterations / 50 * 50 == 0) {
          solution.maxConstr =
              WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
          if (solution.maxConstr - solution.xstar[96] >
              1.0E-6 * runTimeOptions_ConstrRelTolFactor) {
            boolean_T nonDegenerateWset;
            std::copy(&solution.xstar[0], &solution.xstar[97],
                      &solution.searchDir[0]);
            nonDegenerateWset = initialize::feasibleX0ForWorkingSet(
                memspace.workspace_float, solution.searchDir, workingset,
                qrmanager);
            if ((!nonDegenerateWset) && (solution.state != 0)) {
              solution.state = -2;
            }
            activeSetChangeID = 0;
            c = WorkingSet::c_maxConstraintViolation(workingset,
                                                     solution.searchDir);
            if (c < solution.maxConstr) {
              std::copy(&solution.searchDir[0], &solution.searchDir[97],
                        &solution.xstar[0]);
              solution.maxConstr = c;
            }
          }
        }
        if (updateFval) {
          solution.fstar = Objective::computeFval_ReuseHx(
              objective, memspace.workspace_float, f, solution.xstar);
          if ((solution.fstar < options_ObjectiveLimit) &&
              (solution.state != 0)) {
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
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for iterate.cpp
//
// [EOF]
//
