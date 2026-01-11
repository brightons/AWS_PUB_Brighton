//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squareQ_appendCol.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

// Include Files
#include "squareQ_appendCol.h"
#include "my_qdprog_internal_types.h"
#include "my_qdprog_rtwutil.h"
#include "rt_nonfinite.h"
#include "xrotg.h"
#include <cstring>

// Function Definitions
//
// Arguments    : d_struct_T &obj
//                const double vec[23571]
//                int iv0
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void squareQ_appendCol(d_struct_T &obj, const double vec[23571], int iv0)
{
  double b_temp_tmp;
  double c;
  double s;
  int Qk0;
  int i;
  int iyend;
  int temp_tmp;
  iyend = obj.mrows;
  Qk0 = obj.ncols + 1;
  if (iyend <= Qk0) {
    Qk0 = iyend;
  }
  obj.minRowCol = Qk0;
  Qk0 = 120 * obj.ncols;
  if (obj.mrows != 0) {
    iyend = Qk0 + obj.mrows;
    if (Qk0 + 1 <= iyend) {
      std::memset(&obj.QR[Qk0], 0,
                  static_cast<unsigned int>(iyend - Qk0) * sizeof(double));
    }
    i = 120 * (obj.mrows - 1) + 1;
    for (iyend = 1; iyend <= i; iyend += 120) {
      c = 0.0;
      temp_tmp = iyend + obj.mrows;
      for (int idx{iyend}; idx < temp_tmp; idx++) {
        c += obj.Q[idx - 1] * vec[((iv0 + idx) - iyend) - 1];
      }
      temp_tmp = Qk0 + div_nde_s32_floor(iyend - 1, 120);
      obj.QR[temp_tmp] += c;
    }
  }
  obj.ncols++;
  i = obj.ncols - 1;
  obj.jpvt[i] = obj.ncols;
  for (int idx{obj.mrows - 2}; idx + 2 > obj.ncols; idx--) {
    temp_tmp = idx + 120 * i;
    b_temp_tmp = obj.QR[temp_tmp + 1];
    c = internal::blas::xrotg(obj.QR[temp_tmp], b_temp_tmp, s);
    obj.QR[temp_tmp + 1] = b_temp_tmp;
    Qk0 = 120 * idx;
    iyend = obj.mrows;
    if (obj.mrows >= 1) {
      for (int k{0}; k < iyend; k++) {
        double temp;
        temp_tmp = Qk0 + k;
        b_temp_tmp = obj.Q[temp_tmp + 120];
        temp = c * obj.Q[temp_tmp] + s * b_temp_tmp;
        obj.Q[temp_tmp + 120] = c * b_temp_tmp - s * obj.Q[temp_tmp];
        obj.Q[temp_tmp] = temp;
      }
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for squareQ_appendCol.cpp
//
// [EOF]
//
