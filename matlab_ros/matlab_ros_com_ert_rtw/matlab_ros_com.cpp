//
// File: matlab_ros_com.cpp
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
#include "matlab_ros_com.h"
#include "matlab_ros_com_private.h"
#define matlab_ros_com_MessageQueueLen (1)

// Block signals (auto storage)
B_matlab_ros_com_T matlab_ros_com_B;

// Block states (auto storage)
DW_matlab_ros_com_T matlab_ros_com_DW;

// Real-time model
RT_MODEL_matlab_ros_com_T matlab_ros_com_M_;
RT_MODEL_matlab_ros_com_T *const matlab_ros_com_M = &matlab_ros_com_M_;

// Model step function
void matlab_ros_com_step(void)
{
  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S1>/Constant'

  matlab_ros_com_B.BusAssignment = matlab_ros_com_P.Constant_Value_l;
  matlab_ros_com_B.BusAssignment.Pose.Position.X =
    matlab_ros_com_P.Constant3_Value;
  matlab_ros_com_B.BusAssignment.Pose.Position.Y =
    matlab_ros_com_P.Constant3_Value;
  matlab_ros_com_B.BusAssignment.Pose.Position.Z =
    matlab_ros_com_P.Constant3_Value;

  // Outputs for Atomic SubSystem: '<Root>/Publish UAV1 Pose'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   MATLABSystem: '<S3>/SinkBlock'

  Pub_matlab_ros_com_7.publish(&matlab_ros_com_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish UAV1 Pose'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S2>/Constant'

  matlab_ros_com_B.BusAssignment1 = matlab_ros_com_P.Constant_Value_ow;
  matlab_ros_com_B.BusAssignment1.Twist.Linear.X =
    matlab_ros_com_P.Constant_Value_n;
  matlab_ros_com_B.BusAssignment1.Twist.Linear.Y =
    matlab_ros_com_P.Constant_Value_n;
  matlab_ros_com_B.BusAssignment1.Twist.Linear.Z =
    matlab_ros_com_P.Constant_Value_n;
  matlab_ros_com_B.BusAssignment1.Twist.Angular.X =
    matlab_ros_com_P.Constant_Value_n;
  matlab_ros_com_B.BusAssignment1.Twist.Angular.Y =
    matlab_ros_com_P.Constant_Value_n;
  matlab_ros_com_B.BusAssignment1.Twist.Angular.Z =
    matlab_ros_com_P.Constant_Value_n;

  // Outputs for Atomic SubSystem: '<Root>/Publish UAV1 Velocity'
  // Start for MATLABSystem: '<S4>/SinkBlock' incorporates:
  //   MATLABSystem: '<S4>/SinkBlock'

  Pub_matlab_ros_com_37.publish(&matlab_ros_com_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish UAV1 Velocity'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  Sub_matlab_ros_com_1.getLatestMessage(&matlab_ros_com_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  Sub_matlab_ros_com_25.getLatestMessage(&matlab_ros_com_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Subscribe1'
}

// Model initialize function
void matlab_ros_com_initialize(void)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(matlab_ros_com_M, (NULL));

  // states (dwork)
  (void) memset((void *)&matlab_ros_com_DW, 0,
                sizeof(DW_matlab_ros_com_T));

  {
    static const char_T tmp[42] = { '/', 'u', 'a', 'v', '1', '/', 'm', 'a', 'v',
      'r', 'o', 's', '/', 'l', 'o', 'c', 'a', 'l', '_', 'p', 'o', 's', 'i', 't',
      'i', 'o', 'n', '/', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y', '_', 'l', 'o',
      'c', 'a', 'l' };

    static const char_T tmp_0[32] = { '/', 'u', 'a', 'v', '1', '/', 'm', 'a',
      'v', 'r', 'o', 's', '/', 'l', 'o', 'c', 'a', 'l', '_', 'p', 'o', 's', 'i',
      't', 'i', 'o', 'n', '/', 'p', 'o', 's', 'e' };

    static const char_T tmp_1[48] = { 'u', 'a', 'v', '1', '_', 'm', 'a', 't',
      'l', 'a', 'b', '/', 'm', 'a', 'v', 'r', 'o', 's', '/', 'l', 'o', 'c', 'a',
      'l', '_', 'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '/', 'v', 'e', 'l', 'o',
      'c', 'i', 't', 'y', '_', 'l', 'o', 'c', 'a', 'l' };

    static const char_T tmp_2[38] = { 'u', 'a', 'v', '1', '_', 'm', 'a', 't',
      'l', 'a', 'b', '/', 'm', 'a', 'v', 'r', 'o', 's', '/', 'l', 'o', 'c', 'a',
      'l', '_', 'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '/', 'p', 'o', 's', 'e'
    };

    char_T tmp_3[33];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Publish UAV1 Pose'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    matlab_ros_com_DW.obj_i.isInitialized = 0;
    matlab_ros_com_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 38; i++) {
      matlab_ros_com_B.cv2[i] = tmp_2[i];
    }

    matlab_ros_com_B.cv2[38] = '\x00';
    Pub_matlab_ros_com_7.createPublisher(matlab_ros_com_B.cv2,
      matlab_ros_com_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish UAV1 Pose'

    // Start for Atomic SubSystem: '<Root>/Publish UAV1 Velocity'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    matlab_ros_com_DW.obj.isInitialized = 0;
    matlab_ros_com_DW.obj.isInitialized = 1;
    for (i = 0; i < 48; i++) {
      matlab_ros_com_B.cv0[i] = tmp_1[i];
    }

    matlab_ros_com_B.cv0[48] = '\x00';
    Pub_matlab_ros_com_37.createPublisher(matlab_ros_com_B.cv0,
      matlab_ros_com_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish UAV1 Velocity'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    matlab_ros_com_DW.obj_n.isInitialized = 0;
    matlab_ros_com_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 32; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[32] = '\x00';
    Sub_matlab_ros_com_1.createSubscriber(tmp_3, matlab_ros_com_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    matlab_ros_com_DW.obj_p.isInitialized = 0;
    matlab_ros_com_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 42; i++) {
      matlab_ros_com_B.cv1[i] = tmp[i];
    }

    matlab_ros_com_B.cv1[42] = '\x00';
    Sub_matlab_ros_com_25.createSubscriber(matlab_ros_com_B.cv1,
      matlab_ros_com_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe1'
  }
}

// Model terminate function
void matlab_ros_com_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish UAV1 Pose'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SinkBlock'

  if (matlab_ros_com_DW.obj_i.isInitialized == 1) {
    matlab_ros_com_DW.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish UAV1 Pose'

  // Terminate for Atomic SubSystem: '<Root>/Publish UAV1 Velocity'
  // Start for MATLABSystem: '<S4>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SinkBlock'

  if (matlab_ros_com_DW.obj.isInitialized == 1) {
    matlab_ros_com_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish UAV1 Velocity'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (matlab_ros_com_DW.obj_n.isInitialized == 1) {
    matlab_ros_com_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (matlab_ros_com_DW.obj_p.isInitialized == 1) {
    matlab_ros_com_DW.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'
}

//
// File trailer for generated code.
//
// [EOF]
//
