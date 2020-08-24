/* Include files */

#include "matlab_ros_com_formation_sfun.h"
#include "c2_matlab_ros_com_formation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "matlab_ros_com_formation_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[18] = { "leader", "T_SIZE", "k_aij",
  "k_p", "relative_pos_to_leader0", "relative_pos_to_leader1",
  "relative_pos_to_leader2", "relative_pos_to_leader3", "nargin", "nargout",
  "uav0_now", "uav1_now", "uav2_now", "uav3_now", "uav0_des", "uav1_des",
  "uav2_des", "uav3_des" };

/* Function Declarations */
static void initialize_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void initialize_params_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void enable_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void disable_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void set_sim_state_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void sf_gateway_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void mdl_start_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void c2_chartstep_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void initSimStructsc2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_emlrt_marshallOut
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const uav *c2_u);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_b_uav3_des, const char_T *c2_identifier, uav
  *c2_y);
static void c2_b_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uav *c2_y);
static real_T c2_c_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static c2_sZqLEfG43dvHUaZMXoNcDdH c2_d_emlrt_marshallIn
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static c2_sEkDe3AHTyRLyNwoguQj5dE c2_e_emlrt_marshallIn
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_uav0_now_bus_io(void *chartInstanceVoid, void *c2_pData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_matlab_ros_com_formation,
  const char_T *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_matlab_ros_com_formation(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_matlab_ros_com_formation = 0U;
}

static void initialize_params_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uav c2_r0;
  uav c2_r1;
  uav c2_r2;
  uav c2_r3;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_b_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  c2_r0.posx = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[0];
  c2_r0.posy = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[8];
  c2_r0.posz = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[16];
  c2_r0.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[24];
  c2_r0.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[32];
  c2_r0.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[40];
  c2_r0.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[48];
  c2_r0.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[56];
  c2_r0.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[64];
  sf_mex_setcell(c2_y, 0, c2_emlrt_marshallOut(chartInstance, &c2_r0));
  c2_r1.posx = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[0];
  c2_r1.posy = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[8];
  c2_r1.posz = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[16];
  c2_r1.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[24];
  c2_r1.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[32];
  c2_r1.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[40];
  c2_r1.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[48];
  c2_r1.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[56];
  c2_r1.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[64];
  sf_mex_setcell(c2_y, 1, c2_emlrt_marshallOut(chartInstance, &c2_r1));
  c2_r2.posx = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[0];
  c2_r2.posy = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[8];
  c2_r2.posz = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[16];
  c2_r2.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[24];
  c2_r2.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[32];
  c2_r2.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[40];
  c2_r2.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[48];
  c2_r2.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[56];
  c2_r2.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[64];
  sf_mex_setcell(c2_y, 2, c2_emlrt_marshallOut(chartInstance, &c2_r2));
  c2_r3.posx = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[0];
  c2_r3.posy = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[8];
  c2_r3.posz = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[16];
  c2_r3.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[24];
  c2_r3.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[32];
  c2_r3.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[40];
  c2_r3.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[48];
  c2_r3.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[56];
  c2_r3.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[64];
  sf_mex_setcell(c2_y, 3, c2_emlrt_marshallOut(chartInstance, &c2_r3));
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_matlab_ros_com_formation;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 4, c2_b_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  uav c2_r4;
  uav c2_r5;
  uav c2_r6;
  uav c2_r7;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "uav0_des", &c2_r4);
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[0] = c2_r4.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[8] = c2_r4.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[16] = c2_r4.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[24] = c2_r4.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[32] = c2_r4.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[40] = c2_r4.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[48] = c2_r4.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[56] = c2_r4.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[64] = c2_r4.angularz;
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                      "uav1_des", &c2_r5);
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[0] = c2_r5.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[8] = c2_r5.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[16] = c2_r5.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[24] = c2_r5.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[32] = c2_r5.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[40] = c2_r5.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[48] = c2_r5.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[56] = c2_r5.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[64] = c2_r5.angularz;
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
                      "uav2_des", &c2_r6);
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[0] = c2_r6.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[8] = c2_r6.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[16] = c2_r6.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[24] = c2_r6.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[32] = c2_r6.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[40] = c2_r6.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[48] = c2_r6.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[56] = c2_r6.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[64] = c2_r6.angularz;
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                      "uav3_des", &c2_r7);
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[0] = c2_r7.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[8] = c2_r7.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[16] = c2_r7.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[24] = c2_r7.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[32] = c2_r7.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[40] = c2_r7.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[48] = c2_r7.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[56] = c2_r7.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[64] = c2_r7.angularz;
  chartInstance->c2_is_active_c2_matlab_ros_com_formation =
    c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
    "is_active_c2_matlab_ros_com_formation");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_matlab_ros_com_formation(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_matlab_ros_com_formation(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_matlab_ros_com_formationMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c2_chartstep_c2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  uav c2_b_uav0_now;
  uav c2_b_uav1_now;
  uav c2_b_uav2_now;
  uav c2_b_uav3_now;
  uint32_T c2_debug_family_var_map[18];
  c2_sEkDe3AHTyRLyNwoguQj5dE c2_leader;
  real_T c2_T_SIZE;
  real_T c2_k_aij;
  real_T c2_k_p;
  c2_sZqLEfG43dvHUaZMXoNcDdH c2_relative_pos_to_leader0;
  c2_sZqLEfG43dvHUaZMXoNcDdH c2_relative_pos_to_leader1;
  c2_sZqLEfG43dvHUaZMXoNcDdH c2_relative_pos_to_leader2;
  c2_sZqLEfG43dvHUaZMXoNcDdH c2_relative_pos_to_leader3;
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 4.0;
  uav c2_b_uav0_des;
  uav c2_b_uav1_des;
  uav c2_b_uav2_des;
  uav c2_b_uav3_des;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_b_uav0_now.posx = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[0];
  c2_b_uav0_now.posy = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[8];
  c2_b_uav0_now.posz = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[16];
  c2_b_uav0_now.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[24];
  c2_b_uav0_now.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[32];
  c2_b_uav0_now.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[40];
  c2_b_uav0_now.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[48];
  c2_b_uav0_now.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[56];
  c2_b_uav0_now.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav0_now)[64];
  c2_b_uav1_now.posx = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[0];
  c2_b_uav1_now.posy = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[8];
  c2_b_uav1_now.posz = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[16];
  c2_b_uav1_now.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[24];
  c2_b_uav1_now.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[32];
  c2_b_uav1_now.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[40];
  c2_b_uav1_now.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[48];
  c2_b_uav1_now.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[56];
  c2_b_uav1_now.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav1_now)[64];
  c2_b_uav2_now.posx = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[0];
  c2_b_uav2_now.posy = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[8];
  c2_b_uav2_now.posz = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[16];
  c2_b_uav2_now.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[24];
  c2_b_uav2_now.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[32];
  c2_b_uav2_now.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[40];
  c2_b_uav2_now.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[48];
  c2_b_uav2_now.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[56];
  c2_b_uav2_now.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav2_now)[64];
  c2_b_uav3_now.posx = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[0];
  c2_b_uav3_now.posy = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[8];
  c2_b_uav3_now.posz = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[16];
  c2_b_uav3_now.linearx = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[24];
  c2_b_uav3_now.lineary = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[32];
  c2_b_uav3_now.linearz = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[40];
  c2_b_uav3_now.angularx = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[48];
  c2_b_uav3_now.angulary = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[56];
  c2_b_uav3_now.angularz = *(real_T *)&((char_T *)chartInstance->c2_uav3_now)[64];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_leader, 0U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_T_SIZE, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k_aij, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k_p, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_relative_pos_to_leader0, 4U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_relative_pos_to_leader1, 5U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_relative_pos_to_leader2, 6U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_relative_pos_to_leader3, 7U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_uav0_now, 10U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_uav1_now, 11U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_uav2_now, 12U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_uav3_now, 13U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_uav0_des, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_uav1_des, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_uav2_des, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_uav3_des, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_leader.posx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_leader.posy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_leader.posz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_T_SIZE = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_k_aij = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_k_p = 1.95;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_relative_pos_to_leader0.x = -c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_relative_pos_to_leader0.y = c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_relative_pos_to_leader0.z = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_relative_pos_to_leader1.x = c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_relative_pos_to_leader1.y = c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_relative_pos_to_leader1.z = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_relative_pos_to_leader2.x = c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_relative_pos_to_leader2.y = -c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_relative_pos_to_leader2.z = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_relative_pos_to_leader3.x = -c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_relative_pos_to_leader3.y = -c2_T_SIZE;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_relative_pos_to_leader3.z = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_b_uav0_des.posx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_b_uav0_des.posy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_b_uav0_des.posz = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_b_uav0_des.linearx = (c2_k_p * ((c2_leader.posx +
    c2_relative_pos_to_leader0.x) - c2_b_uav0_now.posx) + c2_k_aij *
    (c2_b_uav1_now.posx - c2_b_uav0_now.posx)) + c2_k_aij * (c2_b_uav3_now.posx
    - c2_b_uav0_now.posx);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_b_uav0_des.lineary = (c2_k_p * ((c2_leader.posy +
    c2_relative_pos_to_leader0.y) - c2_b_uav0_now.posy) + c2_k_aij *
    (c2_b_uav1_now.posy - c2_b_uav0_now.posy)) + c2_k_aij * (c2_b_uav3_now.posy
    - c2_b_uav0_now.posy);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_b_uav0_des.linearz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_b_uav0_des.angularx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_b_uav0_des.angulary = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_b_uav0_des.angularz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  c2_b_uav1_des.posx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_b_uav1_des.posy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_b_uav1_des.posz = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  c2_b_uav1_des.linearx = (c2_k_p * ((c2_leader.posx +
    c2_relative_pos_to_leader1.x) - c2_b_uav1_now.posx) + c2_k_aij *
    (c2_b_uav0_now.posx - c2_b_uav1_now.posx)) + c2_k_aij * (c2_b_uav2_now.posx
    - c2_b_uav1_now.posx);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_b_uav1_des.lineary = (c2_k_p * ((c2_leader.posy +
    c2_relative_pos_to_leader1.y) - c2_b_uav1_now.posy) + c2_k_aij *
    (c2_b_uav0_now.posy - c2_b_uav1_now.posy)) + c2_k_aij * (c2_b_uav2_now.posy
    - c2_b_uav1_now.posy);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
  c2_b_uav1_des.linearz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
  c2_b_uav1_des.angularx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
  c2_b_uav1_des.angulary = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_b_uav1_des.angularz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
  c2_b_uav2_des.posx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  c2_b_uav2_des.posy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
  c2_b_uav2_des.posz = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
  c2_b_uav2_des.linearx = (c2_k_p * ((c2_leader.posx +
    c2_relative_pos_to_leader2.x) - c2_b_uav2_now.posx) + c2_k_aij *
    (c2_b_uav1_now.posx - c2_b_uav2_now.posx)) + c2_k_aij * (c2_b_uav3_now.posx
    - c2_b_uav2_now.posx);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
  c2_b_uav2_des.lineary = (c2_k_p * ((c2_leader.posy +
    c2_relative_pos_to_leader2.y) - c2_b_uav2_now.posy) + c2_k_aij *
    (c2_b_uav1_now.posy - c2_b_uav2_now.posy)) + c2_k_aij * (c2_b_uav3_now.posy
    - c2_b_uav2_now.posy);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  c2_b_uav2_des.linearz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
  c2_b_uav2_des.angularx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
  c2_b_uav2_des.angulary = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
  c2_b_uav2_des.angularz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
  c2_b_uav3_des.posx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
  c2_b_uav3_des.posy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 64);
  c2_b_uav3_des.posz = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
  c2_b_uav3_des.linearx = (c2_k_p * ((c2_leader.posx +
    c2_relative_pos_to_leader3.x) - c2_b_uav3_now.posx) + c2_k_aij *
    (c2_b_uav0_now.posx - c2_b_uav3_now.posx)) + c2_k_aij * (c2_b_uav2_now.posx
    - c2_b_uav3_now.posx);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
  c2_b_uav3_des.lineary = (c2_k_p * ((c2_leader.posy +
    c2_relative_pos_to_leader3.y) - c2_b_uav3_now.posy) + c2_k_aij *
    (c2_b_uav0_now.posy - c2_b_uav3_now.posy)) + c2_k_aij * (c2_b_uav2_now.posy
    - c2_b_uav3_now.posy);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
  c2_b_uav3_des.linearz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
  c2_b_uav3_des.angularx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
  c2_b_uav3_des.angulary = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
  c2_b_uav3_des.angularz = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -70);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[0] = c2_b_uav0_des.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[8] = c2_b_uav0_des.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[16] = c2_b_uav0_des.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[24] = c2_b_uav0_des.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[32] = c2_b_uav0_des.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[40] = c2_b_uav0_des.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[48] =
    c2_b_uav0_des.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[56] =
    c2_b_uav0_des.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav0_des)[64] =
    c2_b_uav0_des.angularz;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[0] = c2_b_uav1_des.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[8] = c2_b_uav1_des.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[16] = c2_b_uav1_des.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[24] = c2_b_uav1_des.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[32] = c2_b_uav1_des.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[40] = c2_b_uav1_des.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[48] =
    c2_b_uav1_des.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[56] =
    c2_b_uav1_des.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav1_des)[64] =
    c2_b_uav1_des.angularz;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[0] = c2_b_uav2_des.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[8] = c2_b_uav2_des.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[16] = c2_b_uav2_des.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[24] = c2_b_uav2_des.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[32] = c2_b_uav2_des.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[40] = c2_b_uav2_des.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[48] =
    c2_b_uav2_des.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[56] =
    c2_b_uav2_des.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav2_des)[64] =
    c2_b_uav2_des.angularz;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[0] = c2_b_uav3_des.posx;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[8] = c2_b_uav3_des.posy;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[16] = c2_b_uav3_des.posz;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[24] = c2_b_uav3_des.linearx;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[32] = c2_b_uav3_des.lineary;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[40] = c2_b_uav3_des.linearz;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[48] =
    c2_b_uav3_des.angularx;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[56] =
    c2_b_uav3_des.angulary;
  *(real_T *)&((char_T *)chartInstance->c2_uav3_des)[64] =
    c2_b_uav3_des.angularz;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_matlab_ros_com_formation
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_emlrt_marshallOut
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const uav *c2_u)
{
  const mxArray *c2_y;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_b_u = c2_u->posx;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_b_y, "posx", "posx", 0);
  c2_c_u = c2_u->posy;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_c_y, "posy", "posy", 0);
  c2_d_u = c2_u->posz;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_d_y, "posz", "posz", 0);
  c2_e_u = c2_u->linearx;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_e_y, "linearx", "linearx", 0);
  c2_f_u = c2_u->lineary;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_f_y, "lineary", "lineary", 0);
  c2_g_u = c2_u->linearz;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_g_y, "linearz", "linearz", 0);
  c2_h_u = c2_u->angularx;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_h_y, "angularx", "angularx", 0);
  c2_i_u = c2_u->angulary;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_i_y, "angulary", "angulary", 0);
  c2_j_u = c2_u->angularz;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_j_y, "angularz", "angularz", 0);
  return c2_y;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  sf_mex_assign(&c2_mxArrayOutData, c2_emlrt_marshallOut(chartInstance, (uav *)
    c2_inData), false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_b_uav3_des, const char_T *c2_identifier, uav
  *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_uav3_des), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_uav3_des);
}

static void c2_b_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uav *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[9] = { "posx", "posy", "posz", "linearx",
    "lineary", "linearz", "angularx", "angulary", "angularz" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_u, 9, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "posx";
  c2_y->posx = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "posx", "posx", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "posy";
  c2_y->posy = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "posy", "posy", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "posz";
  c2_y->posz = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "posz", "posz", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "linearx";
  c2_y->linearx = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "linearx", "linearx", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "lineary";
  c2_y->lineary = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "lineary", "lineary", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "linearz";
  c2_y->linearz = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "linearz", "linearz", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "angularx";
  c2_y->angularx = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "angularx", "angularx", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "angulary";
  c2_y->angulary = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "angulary", "angulary", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "angularz";
  c2_y->angularz = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "angularz", "angularz", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
}

static real_T c2_c_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_uav3_des;
  emlrtMsgIdentifier c2_thisId;
  uav c2_y;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_b_uav3_des = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_uav3_des), &c2_thisId,
                        &c2_y);
  sf_mex_destroy(&c2_b_uav3_des);
  *(uav *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sZqLEfG43dvHUaZMXoNcDdH c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_sZqLEfG43dvHUaZMXoNcDdH *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_b_u = c2_u.x;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_b_y, "x", "x", 0);
  c2_c_u = c2_u.y;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_c_y, "y", "y", 0);
  c2_d_u = c2_u.z;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_d_y, "z", "z", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static c2_sZqLEfG43dvHUaZMXoNcDdH c2_d_emlrt_marshallIn
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_sZqLEfG43dvHUaZMXoNcDdH c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[3] = { "x", "y", "z" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_u, 3, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "x";
  c2_y.x = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "x", "x", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "y";
  c2_y.y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "y", "y", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "z";
  c2_y.z = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "z", "z", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_relative_pos_to_leader3;
  emlrtMsgIdentifier c2_thisId;
  c2_sZqLEfG43dvHUaZMXoNcDdH c2_y;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_relative_pos_to_leader3 = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_relative_pos_to_leader3), &c2_thisId);
  sf_mex_destroy(&c2_relative_pos_to_leader3);
  *(c2_sZqLEfG43dvHUaZMXoNcDdH *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_sEkDe3AHTyRLyNwoguQj5dE c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_sEkDe3AHTyRLyNwoguQj5dE *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_b_u = c2_u.posx;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_b_y, "posx", "posx", 0);
  c2_c_u = c2_u.posy;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_c_y, "posy", "posy", 0);
  c2_d_u = c2_u.posz;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_d_y, "posz", "posz", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static c2_sEkDe3AHTyRLyNwoguQj5dE c2_e_emlrt_marshallIn
  (SFc2_matlab_ros_com_formationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_sEkDe3AHTyRLyNwoguQj5dE c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[3] = { "posx", "posy", "posz" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_u, 3, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "posx";
  c2_y.posx = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "posx", "posx", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "posy";
  c2_y.posy = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "posy", "posy", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "posz";
  c2_y.posz = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "posz", "posz", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_leader;
  emlrtMsgIdentifier c2_thisId;
  c2_sEkDe3AHTyRLyNwoguQj5dE c2_y;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_leader = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_leader), &c2_thisId);
  sf_mex_destroy(&c2_leader);
  *(c2_sEkDe3AHTyRLyNwoguQj5dE *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_matlab_ros_com_formation_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_uav0_now_bus_io(void *chartInstanceVoid, void *c2_pData)
{
  const mxArray *c2_mxVal;
  uav c2_tmp;
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)
    chartInstanceVoid;
  c2_mxVal = NULL;
  c2_mxVal = NULL;
  c2_tmp.posx = *(real_T *)&((char_T *)(uav *)c2_pData)[0];
  c2_tmp.posy = *(real_T *)&((char_T *)(uav *)c2_pData)[8];
  c2_tmp.posz = *(real_T *)&((char_T *)(uav *)c2_pData)[16];
  c2_tmp.linearx = *(real_T *)&((char_T *)(uav *)c2_pData)[24];
  c2_tmp.lineary = *(real_T *)&((char_T *)(uav *)c2_pData)[32];
  c2_tmp.linearz = *(real_T *)&((char_T *)(uav *)c2_pData)[40];
  c2_tmp.angularx = *(real_T *)&((char_T *)(uav *)c2_pData)[48];
  c2_tmp.angulary = *(real_T *)&((char_T *)(uav *)c2_pData)[56];
  c2_tmp.angularz = *(real_T *)&((char_T *)(uav *)c2_pData)[64];
  sf_mex_assign(&c2_mxVal, c2_sf_marshallOut(chartInstance, &c2_tmp), false);
  return c2_mxVal;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_matlab_ros_com_formation,
  const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_matlab_ros_com_formation), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_matlab_ros_com_formation);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_matlab_ros_com_formationInstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_uav0_now = (uav *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_uav0_des = (uav *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_uav1_now = (uav *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_uav2_now = (uav *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_uav3_now = (uav *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_uav1_des = (uav *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_uav2_des = (uav *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_uav3_des = (uav *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_matlab_ros_com_formation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(535546540U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3327216412U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1107141942U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3618646099U);
}

mxArray* sf_c2_matlab_ros_com_formation_get_post_codegen_info(void);
mxArray *sf_c2_matlab_ros_com_formation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("CZNaBBTZDa8CvlOwwEagfD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c2_matlab_ros_com_formation_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_matlab_ros_com_formation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_matlab_ros_com_formation_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("imported_bus");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("uav");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_matlab_ros_com_formation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_matlab_ros_com_formation_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_matlab_ros_com_formation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"uav0_des\",},{M[1],M[9],T\"uav1_des\",},{M[1],M[10],T\"uav2_des\",},{M[1],M[11],T\"uav3_des\",},{M[8],M[0],T\"is_active_c2_matlab_ros_com_formation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_matlab_ros_com_formation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_matlab_ros_com_formationInstanceStruct *chartInstance =
      (SFc2_matlab_ros_com_formationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _matlab_ros_com_formationMachineNumber_,
           2,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_matlab_ros_com_formationMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_matlab_ros_com_formationMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _matlab_ros_com_formationMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"uav0_now");
          _SFD_SET_DATA_PROPS(1,1,1,0,"uav1_now");
          _SFD_SET_DATA_PROPS(2,1,1,0,"uav2_now");
          _SFD_SET_DATA_PROPS(3,1,1,0,"uav3_now");
          _SFD_SET_DATA_PROPS(4,2,0,1,"uav0_des");
          _SFD_SET_DATA_PROPS(5,2,0,1,"uav1_des");
          _SFD_SET_DATA_PROPS(6,2,0,1,"uav2_des");
          _SFD_SET_DATA_PROPS(7,2,0,1,"uav3_des");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2659);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_uav0_now_bus_io,(MexInFcnForType)NULL);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _matlab_ros_com_formationMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_matlab_ros_com_formationInstanceStruct *chartInstance =
      (SFc2_matlab_ros_com_formationInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_uav0_now);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_uav0_des);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_uav1_now);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_uav2_now);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_uav3_now);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_uav1_des);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c2_uav2_des);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c2_uav3_des);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sbuZNGOe7vqgRjXGqHWVjTF";
}

static void sf_opaque_initialize_c2_matlab_ros_com_formation(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_matlab_ros_com_formationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct*) chartInstanceVar);
  initialize_c2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_matlab_ros_com_formation(void *chartInstanceVar)
{
  enable_c2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_matlab_ros_com_formation(void *chartInstanceVar)
{
  disable_c2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_matlab_ros_com_formation(void *chartInstanceVar)
{
  sf_gateway_c2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_matlab_ros_com_formation
  (SimStruct* S)
{
  return get_sim_state_c2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_matlab_ros_com_formation(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c2_matlab_ros_com_formation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_matlab_ros_com_formationInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_matlab_ros_com_formation_optimization_info();
    }

    finalize_c2_matlab_ros_com_formation
      ((SFc2_matlab_ros_com_formationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_matlab_ros_com_formation
    ((SFc2_matlab_ros_com_formationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_matlab_ros_com_formation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_matlab_ros_com_formation
      ((SFc2_matlab_ros_com_formationInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_matlab_ros_com_formation(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_matlab_ros_com_formation_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3472789046U));
  ssSetChecksum1(S,(4213461150U));
  ssSetChecksum2(S,(1846850005U));
  ssSetChecksum3(S,(2076440164U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_matlab_ros_com_formation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_matlab_ros_com_formation(SimStruct *S)
{
  SFc2_matlab_ros_com_formationInstanceStruct *chartInstance;
  chartInstance = (SFc2_matlab_ros_com_formationInstanceStruct *)utMalloc(sizeof
    (SFc2_matlab_ros_com_formationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_matlab_ros_com_formationInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_matlab_ros_com_formation;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_matlab_ros_com_formation(chartInstance);
}

void c2_matlab_ros_com_formation_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_matlab_ros_com_formation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_matlab_ros_com_formation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_matlab_ros_com_formation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_matlab_ros_com_formation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
