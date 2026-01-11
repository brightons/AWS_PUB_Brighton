//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: removeEqConstr.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "removeEqConstr.h"
#include "my_qdprog_internal_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : c_struct_T &obj
//                int idx_global
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void removeEqConstr(c_struct_T &obj, int idx_global)
{
  int totalEq;
  totalEq = (obj.nWConstr[0] + obj.nWConstr[1]) - 1;
  if ((totalEq + 1 != 0) && (idx_global <= totalEq + 1)) {
    if ((obj.nActiveConstr == totalEq + 1) || (idx_global == totalEq + 1)) {
      obj.mEqRemoved++;
      obj.indexEqRemoved[obj.mEqRemoved - 1] = obj.Wlocalidx[idx_global - 1];
      removeConstr(obj, idx_global);
    } else {
      int TYPE_tmp;
      int i;
      int i1;
      obj.mEqRemoved++;
      TYPE_tmp = obj.Wid[idx_global - 1] - 1;
      i = obj.Wlocalidx[idx_global - 1];
      obj.indexEqRemoved[obj.mEqRemoved - 1] = i;
      obj.isActiveConstr[(obj.isActiveIdx[TYPE_tmp] + i) - 2] = false;
      obj.Wid[idx_global - 1] = obj.Wid[totalEq];
      obj.Wlocalidx[idx_global - 1] = obj.Wlocalidx[totalEq];
      i = static_cast<unsigned char>(obj.nVar);
      for (int idx{0}; idx < i; idx++) {
        obj.ATwset[idx + 97 * (idx_global - 1)] =
            obj.ATwset[idx + 97 * totalEq];
      }
      obj.bwset[idx_global - 1] = obj.bwset[totalEq];
      i1 = obj.nActiveConstr - 1;
      obj.Wid[totalEq] = obj.Wid[i1];
      obj.Wlocalidx[totalEq] = obj.Wlocalidx[i1];
      for (int idx{0}; idx < i; idx++) {
        obj.ATwset[idx + 97 * totalEq] = obj.ATwset[idx + 97 * i1];
      }
      obj.bwset[totalEq] = obj.bwset[i1];
      obj.nActiveConstr = i1;
      obj.nWConstr[TYPE_tmp]--;
    }
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for removeEqConstr.cpp
//
// [EOF]
//
