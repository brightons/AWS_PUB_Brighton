//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: addAineqConstr.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "addAineqConstr.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : c_struct_T &obj
//                int idx_local
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void addAineqConstr(c_struct_T &obj, int idx_local)
{
  int i;
  int i1;
  int iAineq0;
  int iAw0;
  obj.nWConstr[2]++;
  obj.isActiveConstr[(obj.isActiveIdx[2] + idx_local) - 2] = true;
  obj.nActiveConstr++;
  i = obj.nActiveConstr - 1;
  obj.Wid[i] = 3;
  obj.Wlocalidx[i] = idx_local;
  iAineq0 = 97 * (idx_local - 1);
  iAw0 = 97 * i;
  i1 = obj.nVar;
  for (int idx{0}; idx < i1; idx++) {
    obj.ATwset[iAw0 + idx] = obj.Aineq[iAineq0 + idx];
  }
  obj.bwset[i] = obj.bineq[idx_local - 1];
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for addAineqConstr.cpp
//
// [EOF]
//
