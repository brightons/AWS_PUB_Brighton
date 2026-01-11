//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 10-Jan-2026 02:02:07
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "my_qdprog.h"
#include "my_qdprog_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_24x1_real_T(double result[24]);

static void argInit_24x96_real_T(double result[2304]);

static void argInit_26x1_real_T(double result[26]);

static void argInit_26x96_real_T(double result[2496]);

static void argInit_96x1_real_T(double result[96]);

static void argInit_96x96_real_T(double result[9216]);

static double argInit_real_T();

// Function Definitions
//
// Arguments    : double result[24]
// Return Type  : void
//
static void argInit_24x1_real_T(double result[24])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 24; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[2304]
// Return Type  : void
//
static void argInit_24x96_real_T(double result[2304])
{
  // Loop over the array to initialize each element.
  for (int i{0}; i < 2304; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[i] = argInit_real_T();
  }
}

//
// Arguments    : double result[26]
// Return Type  : void
//
static void argInit_26x1_real_T(double result[26])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 26; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[2496]
// Return Type  : void
//
static void argInit_26x96_real_T(double result[2496])
{
  // Loop over the array to initialize each element.
  for (int i{0}; i < 2496; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[i] = argInit_real_T();
  }
}

//
// Arguments    : double result[96]
// Return Type  : void
//
static void argInit_96x1_real_T(double result[96])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 96; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[9216]
// Return Type  : void
//
static void argInit_96x96_real_T(double result[9216])
{
  // Loop over the array to initialize each element.
  for (int i{0}; i < 9216; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[i] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_my_qdprog();
  // Terminate the application.
  // You do not need to do this more than one time.
  my_qdprog_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_my_qdprog()
{
  double dv[9216];
  double dv1[2496];
  double dv3[2304];
  double f_tmp[96];
  double x[96];
  double dv2[26];
  double dv4[24];
  double fval;
  // Initialize function 'my_qdprog' input arguments.
  // Initialize function input argument 'H'.
  // Initialize function input argument 'f'.
  argInit_96x1_real_T(f_tmp);
  // Initialize function input argument 'A'.
  // Initialize function input argument 'B'.
  // Initialize function input argument 'Aeq'.
  // Initialize function input argument 'beq'.
  // Initialize function input argument 'lb'.
  // Initialize function input argument 'ub'.
  // Initialize function input argument 'x0'.
  // Call the entry-point 'my_qdprog'.
  argInit_96x96_real_T(dv);
  argInit_26x96_real_T(dv1);
  argInit_26x1_real_T(dv2);
  argInit_24x96_real_T(dv3);
  argInit_24x1_real_T(dv4);
  my_qdprog(dv, f_tmp, dv1, dv2, dv3, dv4, f_tmp, f_tmp, f_tmp, x, &fval);
}

//
// File trailer for main.cpp
//
// [EOF]
//
