//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: removeConstr.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "removeConstr.h"
#include "my_qdprog_internal_types.h"
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
void removeConstr(c_struct_T &obj, int idx_global)
{
  int TYPE_tmp;
  TYPE_tmp = obj.Wid[idx_global - 1] - 1;
  obj.isActiveConstr[(obj.isActiveIdx[TYPE_tmp] +
                      obj.Wlocalidx[idx_global - 1]) -
                     2] = false;
  if (idx_global < obj.nActiveConstr) {
    int i;
    int i1;
    i = obj.nActiveConstr - 1;
    obj.Wid[idx_global - 1] = obj.Wid[i];
    obj.Wlocalidx[idx_global - 1] = obj.Wlocalidx[i];
    i1 = static_cast<unsigned char>(obj.nVar);
    for (int idx{0}; idx < i1; idx++) {
      obj.ATwset[idx + 97 * (idx_global - 1)] = obj.ATwset[idx + 97 * i];
    }
    obj.bwset[idx_global - 1] = obj.bwset[i];
  }
  obj.nActiveConstr--;
  obj.nWConstr[TYPE_tmp]--;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for removeConstr.cpp
//
// [EOF]
//
