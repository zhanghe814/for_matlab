//
// File: matlab_ros_com.h
//
// Code generated for Simulink model 'matlab_ros_com'.
//
// Model version                  : 1.10
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Wed May 27 09:53:43 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_matlab_ros_com_h_
#define RTW_HEADER_matlab_ros_com_h_
#include <stddef.h>
#include <string.h>
#ifndef matlab_ros_com_COMMON_INCLUDES_
# define matlab_ros_com_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // matlab_ros_com_COMMON_INCLUDES_

#include "matlab_ros_com_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped BusAssignment1;// '<Root>/Bus Assignment1' 
  char_T cv0[49];
  char_T cv1[43];
  char_T cv2[39];
} B_matlab_ros_com_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S6>/SourceBlock'
  void *SourceBlock_PWORK_f;           // '<S5>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S4>/SinkBlock'
  void *SinkBlock_PWORK_p;             // '<S3>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S4>/SinkBlock'
  robotics_slros_internal_block_T obj_i;// '<S3>/SinkBlock'
  robotics_slros_internal_blo_e_T obj_p;// '<S6>/SourceBlock'
  robotics_slros_internal_blo_e_T obj_n;// '<S5>/SourceBlock'
} DW_matlab_ros_com_T;

// Parameters (auto storage)
struct P_matlab_ros_com_T_ {
  SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S7>/Out1'

  SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S5>/Constant'

  SL_Bus_matlab_ros_com_geometry_msgs_PoseStamped Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                                   //  Referenced by: '<S1>/Constant'

  SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                             //  Referenced by: '<S8>/Out1'

  SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                    //  Referenced by: '<S6>/Constant'

  SL_Bus_matlab_ros_com_geometry_msgs_TwistStamped Constant_Value_ow;// Computed Parameter: Constant_Value_ow
                                                                     //  Referenced by: '<S2>/Constant'

  real_T Constant3_Value;              // Expression: 1
                                       //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value_n;             // Expression: 0
                                       //  Referenced by: '<Root>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_matlab_ros_com_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_matlab_ros_com_T matlab_ros_com_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_matlab_ros_com_T matlab_ros_com_B;

// Block states (auto storage)
extern DW_matlab_ros_com_T matlab_ros_com_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void matlab_ros_com_initialize(void);
  extern void matlab_ros_com_step(void);
  extern void matlab_ros_com_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_matlab_ros_com_T *const matlab_ros_com_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Scope10' : Unused code path elimination
//  Block '<Root>/Scope2' : Unused code path elimination
//  Block '<Root>/Scope3' : Unused code path elimination
//  Block '<Root>/Scope4' : Unused code path elimination
//  Block '<Root>/Scope5' : Unused code path elimination
//  Block '<Root>/Scope6' : Unused code path elimination
//  Block '<Root>/Scope7' : Unused code path elimination
//  Block '<Root>/Scope8' : Unused code path elimination
//  Block '<Root>/Scope9' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'matlab_ros_com'
//  '<S1>'   : 'matlab_ros_com/Blank Message'
//  '<S2>'   : 'matlab_ros_com/Blank Message1'
//  '<S3>'   : 'matlab_ros_com/Publish UAV1 Pose'
//  '<S4>'   : 'matlab_ros_com/Publish UAV1 Velocity'
//  '<S5>'   : 'matlab_ros_com/Subscribe'
//  '<S6>'   : 'matlab_ros_com/Subscribe1'
//  '<S7>'   : 'matlab_ros_com/Subscribe/Enabled Subsystem'
//  '<S8>'   : 'matlab_ros_com/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_matlab_ros_com_h_

//
// File trailer for generated code.
//
// [EOF]
//
