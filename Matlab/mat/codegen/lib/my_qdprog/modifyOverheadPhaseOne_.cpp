//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: modifyOverheadPhaseOne_.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "modifyOverheadPhaseOne_.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : c_struct_T &obj
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void modifyOverheadPhaseOne_(c_struct_T &obj)
{
  int i;
  int idxEq;
  i = static_cast<unsigned char>(obj.sizes[0]);
  for (int idx{0}; idx < i; idx++) {
    obj.ATwset[97 * idx + 96] = 0.0;
  }
  for (int idx{0}; idx < 24; idx++) {
    idxEq = 97 * idx + 96;
    obj.Aeq[idxEq] = 0.0;
    obj.ATwset[idxEq + 97 * (obj.isActiveIdx[1] - 1)] = 0.0;
  }
  for (int idx{0}; idx < 26; idx++) {
    obj.Aineq[97 * idx + 96] = -1.0;
  }
  obj.indexLB[obj.sizes[3] - 1] = 97;
  obj.lb[96] = obj.SLACK0;
  idxEq = obj.isActiveIdx[2];
  i = obj.nActiveConstr;
  for (int idx{idxEq}; idx <= i; idx++) {
    obj.ATwset[97 * (idx - 1) + 96] = -1.0;
  }
  idxEq = obj.isActiveIdx[4] - 1;
  if (obj.nWConstr[4] > 0) {
    i = obj.sizesNormal[4];
    for (int idx{i}; idx >= 1; idx--) {
      int i1;
      i1 = idxEq + idx;
      obj.isActiveConstr[i1] = obj.isActiveConstr[i1 - 1];
    }
  } else {
    obj.isActiveConstr[(obj.isActiveIdx[4] + obj.sizesNormal[4]) - 1] = false;
  }
  obj.isActiveConstr[obj.isActiveIdx[4] - 1] = false;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for modifyOverheadPhaseOne_.cpp
//
// [EOF]
//
