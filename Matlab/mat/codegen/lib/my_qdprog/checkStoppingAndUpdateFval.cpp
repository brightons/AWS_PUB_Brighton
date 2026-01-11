//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingAndUpdateFval.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include <algorithm>

// Function Definitions
//
// Arguments    : int &activeSetChangeID
//                const double f[96]
//                struct_T &solution
//                e_struct_T &memspace
//                const b_struct_T &objective
//                c_struct_T &workingset
//                d_struct_T &qrmanager
//                int runTimeOptions_MaxIterations
//                double runTimeOptions_ConstrRelTolFactor
//                const boolean_T &updateFval
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkStoppingAndUpdateFval(int &activeSetChangeID, const double f[96],
                                struct_T &solution, e_struct_T &memspace,
                                const b_struct_T &objective,
                                c_struct_T &workingset, d_struct_T &qrmanager,
                                int runTimeOptions_MaxIterations,
                                double runTimeOptions_ConstrRelTolFactor,
                                const boolean_T &updateFval)
{
  int nVar;
  solution.iterations++;
  nVar = objective.nvar;
  if ((solution.iterations >= runTimeOptions_MaxIterations) &&
      ((solution.state != 1) || (objective.objtype == 5))) {
    solution.state = 0;
  }
  if (solution.iterations - solution.iterations / 50 * 50 == 0) {
    double tempMaxConstr;
    solution.maxConstr =
        WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
    tempMaxConstr = solution.maxConstr;
    if (objective.objtype == 5) {
      tempMaxConstr = solution.maxConstr - solution.xstar[objective.nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6 * runTimeOptions_ConstrRelTolFactor) {
      boolean_T nonDegenerateWset;
      if (nVar - 1 >= 0) {
        std::copy(&solution.xstar[0], &solution.xstar[nVar],
                  &solution.searchDir[0]);
      }
      nonDegenerateWset = initialize::feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.searchDir, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution.state != 0)) {
        solution.state = -2;
      }
      activeSetChangeID = 0;
      tempMaxConstr =
          WorkingSet::c_maxConstraintViolation(workingset, solution.searchDir);
      if (tempMaxConstr < solution.maxConstr) {
        nVar = static_cast<unsigned char>(objective.nvar);
        if (nVar - 1 >= 0) {
          std::copy(&solution.searchDir[0], &solution.searchDir[nVar],
                    &solution.xstar[0]);
        }
        solution.maxConstr = tempMaxConstr;
      }
    }
  }
  if (updateFval) {
    solution.fstar = Objective::computeFval_ReuseHx(
        objective, memspace.workspace_float, f, solution.xstar);
    if ((solution.fstar < -1.0E+20) &&
        ((solution.state != 0) || (objective.objtype != 5))) {
      solution.state = 2;
    }
  }
}

} // namespace stopping
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for checkStoppingAndUpdateFval.cpp
//
// [EOF]
//
