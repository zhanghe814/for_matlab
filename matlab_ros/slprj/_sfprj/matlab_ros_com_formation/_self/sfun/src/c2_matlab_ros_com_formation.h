#ifndef __c2_matlab_ros_com_formation_h__
#define __c2_matlab_ros_com_formation_h__

/* Type Definitions */
#ifndef struct_tag_sEkDe3AHTyRLyNwoguQj5dE
#define struct_tag_sEkDe3AHTyRLyNwoguQj5dE

struct tag_sEkDe3AHTyRLyNwoguQj5dE
{
  real_T posx;
  real_T posy;
  real_T posz;
};

#endif                                 /*struct_tag_sEkDe3AHTyRLyNwoguQj5dE*/

#ifndef typedef_c2_sEkDe3AHTyRLyNwoguQj5dE
#define typedef_c2_sEkDe3AHTyRLyNwoguQj5dE

typedef struct tag_sEkDe3AHTyRLyNwoguQj5dE c2_sEkDe3AHTyRLyNwoguQj5dE;

#endif                                 /*typedef_c2_sEkDe3AHTyRLyNwoguQj5dE*/

#ifndef struct_tag_sZqLEfG43dvHUaZMXoNcDdH
#define struct_tag_sZqLEfG43dvHUaZMXoNcDdH

struct tag_sZqLEfG43dvHUaZMXoNcDdH
{
  real_T x;
  real_T y;
  real_T z;
};

#endif                                 /*struct_tag_sZqLEfG43dvHUaZMXoNcDdH*/

#ifndef typedef_c2_sZqLEfG43dvHUaZMXoNcDdH
#define typedef_c2_sZqLEfG43dvHUaZMXoNcDdH

typedef struct tag_sZqLEfG43dvHUaZMXoNcDdH c2_sZqLEfG43dvHUaZMXoNcDdH;

#endif                                 /*typedef_c2_sZqLEfG43dvHUaZMXoNcDdH*/

#ifndef typedef_SFc2_matlab_ros_com_formationInstanceStruct
#define typedef_SFc2_matlab_ros_com_formationInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_matlab_ros_com_formation;
  void *c2_fEmlrtCtx;
  uav *c2_uav0_now;
  uav *c2_uav0_des;
  uav *c2_uav1_now;
  uav *c2_uav2_now;
  uav *c2_uav3_now;
  uav *c2_uav1_des;
  uav *c2_uav2_des;
  uav *c2_uav3_des;
} SFc2_matlab_ros_com_formationInstanceStruct;

#endif                                 /*typedef_SFc2_matlab_ros_com_formationInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_matlab_ros_com_formation_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_matlab_ros_com_formation_get_check_sum(mxArray *plhs[]);
extern void c2_matlab_ros_com_formation_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
