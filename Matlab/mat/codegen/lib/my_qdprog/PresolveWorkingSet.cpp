//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PresolveWorkingSet.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "PresolveWorkingSet.h"
#include "RemoveDependentEq_.h"
#include "RemoveDependentIneq_.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : struct_T &solution
//                e_struct_T &memspace
//                c_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void PresolveWorkingSet(struct_T &solution, e_struct_T &memspace,
                        c_struct_T &workingset, d_struct_T &qrmanager)
{
  int idxStartIneq_tmp;
  solution.state = 82;
  idxStartIneq_tmp = RemoveDependentEq_(memspace, workingset, qrmanager);
  if ((idxStartIneq_tmp != -1) && (workingset.nActiveConstr <= 120)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    RemoveDependentIneq_(workingset, qrmanager, memspace, 1.0);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace.workspace_float, solution.xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 10.0);
      okWorkingSet = feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 &&
        (workingset.nWConstr[0] + workingset.nWConstr[1] == workingset.nVar)) {
      double constrViolation;
      constrViolation =
          WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
      if (constrViolation > 1.0E-6) {
        solution.state = -2;
      }
    }
  } else {
    int idxEndIneq;
    int idxStartIneq;
    solution.state = -3;
    idxStartIneq_tmp = workingset.nWConstr[0] + workingset.nWConstr[1];
    idxStartIneq = idxStartIneq_tmp + 1;
    idxEndIneq = workingset.nActiveConstr;
    for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq; idx_global++) {
      workingset.isActiveConstr
          [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
            workingset.Wlocalidx[idx_global - 1]) -
           2] = false;
    }
    workingset.nWConstr[2] = 0;
    workingset.nWConstr[3] = 0;
    workingset.nWConstr[4] = 0;
    workingset.nActiveConstr = idxStartIneq_tmp;
  }
}

//
// Arguments    : struct_T &solution
//                e_struct_T &memspace
//                c_struct_T &workingset
//                d_struct_T &qrmanager
// Return Type  : void
//
void b_PresolveWorkingSet(struct_T &solution, e_struct_T &memspace,
                          c_struct_T &workingset, d_struct_T &qrmanager)
{
  int idxStartIneq_tmp;
  solution.state = 82;
  idxStartIneq_tmp = b_RemoveDependentEq_(memspace, workingset, qrmanager);
  if ((idxStartIneq_tmp != -1) && (workingset.nActiveConstr <= 120)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    RemoveDependentIneq_(workingset, qrmanager, memspace, 1.0);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace.workspace_float, solution.xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 10.0);
      okWorkingSet = feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 &&
        (workingset.nWConstr[0] + workingset.nWConstr[1] == workingset.nVar)) {
      double constrViolation;
      constrViolation =
          WorkingSet::c_maxConstraintViolation(workingset, solution.xstar);
      if (constrViolation > 1.0E-6) {
        solution.state = -2;
      }
    }
  } else {
    int idxEndIneq;
    int idxStartIneq;
    solution.state = -3;
    idxStartIneq_tmp = workingset.nWConstr[0] + workingset.nWConstr[1];
    idxStartIneq = idxStartIneq_tmp + 1;
    idxEndIneq = workingset.nActiveConstr;
    for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq; idx_global++) {
      workingset.isActiveConstr
          [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
            workingset.Wlocalidx[idx_global - 1]) -
           2] = false;
    }
    workingset.nWConstr[2] = 0;
    workingset.nWConstr[3] = 0;
    workingset.nWConstr[4] = 0;
    workingset.nActiveConstr = idxStartIneq_tmp;
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for PresolveWorkingSet.cpp
//
// [EOF]
//
