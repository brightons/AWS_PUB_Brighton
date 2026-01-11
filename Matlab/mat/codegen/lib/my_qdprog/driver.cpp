//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "driver.h"
#include "PresolveWorkingSet.h"
#include "computeFirstOrderOpt.h"
#include "computeFval.h"
#include "feasibleX0ForWorkingSet.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "my_qdprog_internal_types.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct h_struct_T {
  char SolverName[8];
};

// Function Definitions
//
// Arguments    : const double H[9216]
//                const double f[96]
//                struct_T &solution
//                e_struct_T &memspace
//                c_struct_T &workingset
//                f_struct_T &cholmanager
//                g_struct_T runTimeOptions
//                d_struct_T &qrmanager
//                b_struct_T &objective
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const double H[9216], const double f[96], struct_T &solution,
            e_struct_T &memspace, c_struct_T &workingset,
            f_struct_T &cholmanager, g_struct_T runTimeOptions,
            d_struct_T &qrmanager, b_struct_T &objective)
{
  static const char cv[128]{
      '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\a',   '\b',
      '\t',   '\n',   '\v',   '\f',   '\r',   '\x0e', '\x0f', '\x10', '\x11',
      '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',    '\x7f'};
  static const char cv1[8]{'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'};
  static const char t3_SolverName[8]{'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'};
  h_struct_T options;
  int i;
  int nVar;
  std::memset(&objective.grad[0], 0, 97U * sizeof(double));
  std::memset(&objective.Hx[0], 0, 96U * sizeof(double));
  objective.hasLinear = true;
  objective.nvar = 96;
  objective.maxVar = 97;
  objective.beta = 0.0;
  objective.rho = 0.0;
  objective.objtype = 3;
  objective.prev_objtype = 3;
  objective.prev_nvar = 0;
  objective.prev_hasLinear = false;
  objective.gammaScalar = 0.0;
  solution.iterations = 0;
  nVar = workingset.nVar;
  i = static_cast<unsigned char>(workingset.sizes[0]);
  for (int idx{0}; idx < i; idx++) {
    solution.xstar[workingset.indexFixed[idx] - 1] =
        workingset.ub[workingset.indexFixed[idx] - 1];
  }
  i = static_cast<unsigned char>(workingset.sizes[3]);
  for (int idx{0}; idx < i; idx++) {
    if (workingset.isActiveConstr[(workingset.isActiveIdx[3] + idx) - 1]) {
      solution.xstar[workingset.indexLB[idx] - 1] =
          -workingset.lb[workingset.indexLB[idx] - 1];
    }
  }
  i = static_cast<unsigned char>(workingset.sizes[4]);
  for (int idx{0}; idx < i; idx++) {
    if (workingset.isActiveConstr[(workingset.isActiveIdx[4] + idx) - 1]) {
      solution.xstar[workingset.indexUB[idx] - 1] =
          workingset.ub[workingset.indexUB[idx] - 1];
    }
  }
  initialize::PresolveWorkingSet(solution, memspace, workingset, qrmanager);
  for (i = 0; i < 8; i++) {
    options.SolverName[i] = t3_SolverName[i];
  }
  if (solution.state >= 0) {
    double d;
    boolean_T guard1;
    solution.iterations = 0;
    solution.maxConstr =
        WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
    d = 1.0E-6 * runTimeOptions.ConstrRelTolFactor;
    guard1 = false;
    if (solution.maxConstr > d) {
      phaseone(H, f, solution, memspace, workingset, qrmanager, cholmanager,
               runTimeOptions, objective);
      if (solution.state != 0) {
        solution.maxConstr =
            WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
        if (solution.maxConstr > d) {
          std::memset(&solution.lambda[0], 0, 243U * sizeof(double));
          solution.fstar = Objective::computeFval(
              objective, memspace.workspace_float, H, f, solution.xstar);
          solution.state = -2;
        } else {
          if (solution.maxConstr > 0.0) {
            double maxConstr_new;
            if (nVar - 1 >= 0) {
              std::copy(&solution.xstar[0], &solution.xstar[nVar],
                        &solution.searchDir[0]);
            }
            initialize::b_PresolveWorkingSet(solution, memspace, workingset,
                                             qrmanager);
            maxConstr_new = WorkingSet::c_maxConstraintViolation(
                workingset, solution.xstar);
            if (maxConstr_new >= solution.maxConstr) {
              solution.maxConstr = maxConstr_new;
              if (nVar - 1 >= 0) {
                std::copy(&solution.searchDir[0], &solution.searchDir[nVar],
                          &solution.xstar[0]);
              }
            }
          }
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      boolean_T b_bool;
      b_iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                objective, true, runTimeOptions.MaxIterations,
                runTimeOptions.ConstrRelTolFactor,
                runTimeOptions.ProbRelTolFactor);
      b_bool = false;
      nVar = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (nVar < 8) {
          if (cv[static_cast<int>(options.SolverName[nVar])] !=
              cv[static_cast<int>(cv1[nVar])]) {
            exitg1 = 1;
          } else {
            nVar++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      if (b_bool && (solution.state != -6)) {
        solution.maxConstr =
            WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
        parseoutput::computeFirstOrderOpt(
            solution, objective, workingset.nVar, workingset.ATwset,
            workingset.nActiveConstr, memspace.workspace_float);
        while ((solution.iterations < runTimeOptions.MaxIterations) &&
               ((solution.state == -7) ||
                ((solution.state == 1) &&
                 ((solution.maxConstr > d) ||
                  (solution.firstorderopt >
                   1.0E-8 * runTimeOptions.ProbRelTolFactor))))) {
          initialize::feasibleX0ForWorkingSet(
              memspace.workspace_float, solution.xstar, workingset, qrmanager);
          initialize::b_PresolveWorkingSet(solution, memspace, workingset,
                                           qrmanager);
          phaseone(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                   objective, runTimeOptions);
          b_iterate(H, f, solution, memspace, workingset, qrmanager,
                    cholmanager, objective, false, runTimeOptions.MaxIterations,
                    runTimeOptions.ConstrRelTolFactor,
                    runTimeOptions.ProbRelTolFactor);
          solution.maxConstr =
              WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
          parseoutput::computeFirstOrderOpt(
              solution, objective, workingset.nVar, workingset.ATwset,
              workingset.nActiveConstr, memspace.workspace_float);
        }
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for driver.cpp
//
// [EOF]
//
