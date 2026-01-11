//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: setProblemType.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "setProblemType.h"
#include "modifyOverheadPhaseOne_.h"
#include "my_qdprog_internal_types.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
//
// Arguments    : c_struct_T &obj
//                int PROBLEM_TYPE
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void setProblemType(c_struct_T &obj, int PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
  case 3: {
    int i;
    obj.nVar = 96;
    obj.mConstr = obj.mConstrOrig;
    if (obj.nWConstr[4] > 0) {
      int idxUpperExisting;
      idxUpperExisting = obj.isActiveIdx[4] - 2;
      i = static_cast<unsigned char>(obj.sizesNormal[4]);
      for (int colOffsetAeq{0}; colOffsetAeq < i; colOffsetAeq++) {
        int i1;
        i1 = (idxUpperExisting + colOffsetAeq) + 1;
        obj.isActiveConstr[(obj.isActiveIdxNormal[4] + colOffsetAeq) - 1] =
            obj.isActiveConstr[i1];
        obj.isActiveConstr[i1] = false;
      }
    }
    for (i = 0; i < 5; i++) {
      obj.sizes[i] = obj.sizesNormal[i];
    }
    for (i = 0; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxNormal[i];
    }
  } break;
  case 1:
    obj.nVar = 97;
    obj.mConstr = obj.mConstrOrig + 1;
    for (int i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (int i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxPhaseOne[i];
    }
    break;
  case 2: {
    int i;
    obj.nVar = 96;
    obj.mConstr = 242;
    for (i = 0; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegularized[i];
    }
    if (obj.probType != 4) {
      int colOffsetATw;
      int colOffsetAeq;
      int i1;
      int i2;
      int idxUpperExisting;
      for (int idx_col{0}; idx_col < 26; idx_col++) {
        idxUpperExisting = 97 * idx_col;
        i = idx_col + 96;
        if (i >= 97) {
          std::memset(&obj.Aineq[idxUpperExisting + 96], 0,
                      static_cast<unsigned int>(i - 96) * sizeof(double));
        }
        obj.Aineq[(idx_col + idxUpperExisting) + 96] = -1.0;
      }
      for (int idx_col{0}; idx_col < 24; idx_col++) {
        idxUpperExisting = idx_col + 122;
        colOffsetAeq = 97 * idx_col - 1;
        colOffsetATw = colOffsetAeq + 97 * (obj.isActiveIdx[1] - 1);
        std::memset(&obj.Aeq[colOffsetAeq + 97], 0, 26U * sizeof(double));
        std::memset(&obj.ATwset[colOffsetATw + 97], 0, 26U * sizeof(double));
        if (idxUpperExisting >= 123) {
          std::memset(&obj.Aeq[colOffsetAeq + 123], 0,
                      static_cast<unsigned int>(idxUpperExisting - 122) *
                          sizeof(double));
          std::memset(&obj.ATwset[colOffsetATw + 123], 0,
                      static_cast<unsigned int>(idxUpperExisting - 122) *
                          sizeof(double));
        }
        i = idx_col + colOffsetAeq;
        obj.Aeq[i + 123] = -1.0;
        i1 = idx_col + colOffsetATw;
        obj.ATwset[i1 + 123] = -1.0;
        i2 = idx_col + 124;
        if (i2 <= 146) {
          std::memset(&obj.Aeq[i2 + colOffsetAeq], 0,
                      static_cast<unsigned int>(
                          ((colOffsetAeq - i2) - colOffsetAeq) + 147) *
                          sizeof(double));
          std::memset(&obj.ATwset[i2 + colOffsetATw], 0,
                      static_cast<unsigned int>(
                          ((colOffsetATw - i2) - colOffsetATw) + 147) *
                          sizeof(double));
        }
        i2 = idx_col + 146;
        if (i2 >= 147) {
          std::memset(&obj.Aeq[colOffsetAeq + 147], 0,
                      static_cast<unsigned int>(i2 - 146) * sizeof(double));
          std::memset(&obj.ATwset[colOffsetATw + 147], 0,
                      static_cast<unsigned int>(i2 - 146) * sizeof(double));
        }
        obj.Aeq[i + 147] = 1.0;
        obj.ATwset[i1 + 147] = 1.0;
      }
      idxUpperExisting = 96;
      i = obj.sizesNormal[3] + 1;
      i1 = obj.sizesRegularized[3];
      for (colOffsetAeq = i; colOffsetAeq <= i1; colOffsetAeq++) {
        idxUpperExisting++;
        obj.indexLB[colOffsetAeq - 1] = idxUpperExisting;
      }
      if (obj.nWConstr[4] > 0) {
        i = static_cast<unsigned char>(obj.sizesRegularized[4]);
        for (colOffsetAeq = 0; colOffsetAeq < i; colOffsetAeq++) {
          obj.isActiveConstr[obj.isActiveIdxRegularized[4] + colOffsetAeq] =
              obj.isActiveConstr[(obj.isActiveIdx[4] + colOffsetAeq) - 1];
        }
      }
      i = obj.isActiveIdx[4];
      i1 = obj.isActiveIdxRegularized[4];
      if (i <= i1 - 1) {
        std::memset(&obj.isActiveConstr[i + -1], 0,
                    static_cast<unsigned int>(i1 - i) * sizeof(boolean_T));
      }
      obj.lb[96] = 0.0;
      idxUpperExisting = obj.isActiveIdx[2];
      i = obj.nActiveConstr;
      for (int idx_col{idxUpperExisting}; idx_col <= i; idx_col++) {
        colOffsetATw = 97 * (idx_col - 1) - 1;
        if (obj.Wid[idx_col - 1] == 3) {
          i1 = obj.Wlocalidx[idx_col - 1];
          i2 = i1 + 95;
          if (i2 >= 97) {
            std::memset(&obj.ATwset[colOffsetATw + 97], 0,
                        static_cast<unsigned int>(i2 - 96) * sizeof(double));
          }
          obj.ATwset[(i1 + colOffsetATw) + 96] = -1.0;
          i1 += 97;
          if (i1 <= 96) {
            std::memset(&obj.ATwset[i1 + colOffsetATw], 0,
                        static_cast<unsigned int>(
                            ((colOffsetATw - i1) - colOffsetATw) + 97) *
                            sizeof(double));
          }
        }
      }
    }
    for (i = 0; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegularized[i];
    }
  } break;
  default:
    obj.nVar = 97;
    obj.mConstr = 243;
    for (int i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (int i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegPhaseOne[i];
    }
    break;
  }
  obj.probType = PROBLEM_TYPE;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for setProblemType.cpp
//
// [EOF]
//
