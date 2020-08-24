function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Blank Message */
	this.urlHashMap["matlab_ros_com:9"] = "matlab_ros_com.h:183";
	/* <Root>/Blank Message1 */
	this.urlHashMap["matlab_ros_com:33"] = "matlab_ros_com.h:184";
	/* <Root>/Bus
Assignment */
	this.urlHashMap["matlab_ros_com:11"] = "matlab_ros_com.cpp:32&matlab_ros_com.h:38";
	/* <Root>/Bus
Assignment1 */
	this.urlHashMap["matlab_ros_com:34"] = "matlab_ros_com.cpp:52&matlab_ros_com.h:39";
	/* <Root>/Constant */
	this.urlHashMap["matlab_ros_com:36"] = "matlab_ros_com.cpp:53&matlab_ros_com.h:81&matlab_ros_com_data.cpp:284";
	/* <Root>/Constant3 */
	this.urlHashMap["matlab_ros_com:43"] = "matlab_ros_com.cpp:33&matlab_ros_com.h:78&matlab_ros_com_data.cpp:281";
	/* <Root>/Display */
	this.urlHashMap["matlab_ros_com:22"] = "matlab_ros_com.h:154";
	/* <Root>/Publish UAV1 Pose */
	this.urlHashMap["matlab_ros_com:7"] = "matlab_ros_com.cpp:44,50,130,143,194,203&matlab_ros_com.h:177,185";
	/* <Root>/Publish UAV1 Velocity */
	this.urlHashMap["matlab_ros_com:37"] = "matlab_ros_com.cpp:70,76,145,158,205,214&matlab_ros_com.h:186";
	/* <Root>/Scope */
	this.urlHashMap["matlab_ros_com:4"] = "matlab_ros_com.h:155";
	/* <Root>/Scope1 */
	this.urlHashMap["matlab_ros_com:5"] = "matlab_ros_com.h:156";
	/* <Root>/Scope10 */
	this.urlHashMap["matlab_ros_com:42"] = "matlab_ros_com.h:157";
	/* <Root>/Scope2 */
	this.urlHashMap["matlab_ros_com:6"] = "matlab_ros_com.h:158";
	/* <Root>/Scope3 */
	this.urlHashMap["matlab_ros_com:23"] = "matlab_ros_com.h:159";
	/* <Root>/Scope4 */
	this.urlHashMap["matlab_ros_com:27"] = "matlab_ros_com.h:160";
	/* <Root>/Scope5 */
	this.urlHashMap["matlab_ros_com:28"] = "matlab_ros_com.h:161";
	/* <Root>/Scope6 */
	this.urlHashMap["matlab_ros_com:29"] = "matlab_ros_com.h:162";
	/* <Root>/Scope7 */
	this.urlHashMap["matlab_ros_com:30"] = "matlab_ros_com.h:163";
	/* <Root>/Scope8 */
	this.urlHashMap["matlab_ros_com:31"] = "matlab_ros_com.h:164";
	/* <Root>/Scope9 */
	this.urlHashMap["matlab_ros_com:32"] = "matlab_ros_com.h:165";
	/* <Root>/Subscribe */
	this.urlHashMap["matlab_ros_com:1"] = "matlab_ros_com.cpp:78,84,160,172,216,225&matlab_ros_com.h:187";
	/* <Root>/Subscribe1 */
	this.urlHashMap["matlab_ros_com:25"] = "matlab_ros_com.cpp:86,92,174,187,227,236&matlab_ros_com.h:188";
	/* <S1>/Constant */
	this.urlHashMap["matlab_ros_com:9:33"] = "matlab_ros_com.cpp:34&matlab_ros_com.h:66&matlab_ros_com_data.cpp:149";
	/* <S2>/Constant */
	this.urlHashMap["matlab_ros_com:33:33"] = "matlab_ros_com.cpp:54&matlab_ros_com.h:75&matlab_ros_com_data.cpp:278";
	/* <S3>/SinkBlock */
	this.urlHashMap["matlab_ros_com:7:31"] = "matlab_ros_com.cpp:45,46,131,142,195,196,202&matlab_ros_com.h:50,52";
	/* <S4>/SinkBlock */
	this.urlHashMap["matlab_ros_com:37:31"] = "matlab_ros_com.cpp:71,72,146,157,206,207,213&matlab_ros_com.h:49,51";
	/* <S5>/Constant */
	this.urlHashMap["matlab_ros_com:1:51"] = "matlab_ros_com.h:63&matlab_ros_com_data.cpp:105";
	/* <S5>/Enabled
Subsystem */
	this.urlHashMap["matlab_ros_com:1:52"] = "matlab_ros_com.h:189";
	/* <S5>/SourceBlock */
	this.urlHashMap["matlab_ros_com:1:58"] = "matlab_ros_com.cpp:79,80,161,171,217,218,224&matlab_ros_com.h:48,54";
	/* <S6>/Constant */
	this.urlHashMap["matlab_ros_com:25:51"] = "matlab_ros_com.h:72&matlab_ros_com_data.cpp:235";
	/* <S6>/Enabled
Subsystem */
	this.urlHashMap["matlab_ros_com:25:52"] = "matlab_ros_com.h:190";
	/* <S6>/SourceBlock */
	this.urlHashMap["matlab_ros_com:25:58"] = "matlab_ros_com.cpp:87,88,175,186,228,229,235&matlab_ros_com.h:47,53";
	/* <S7>/Out1 */
	this.urlHashMap["matlab_ros_com:1:55"] = "matlab_ros_com.h:60&matlab_ros_com_data.cpp:61";
	/* <S8>/Out1 */
	this.urlHashMap["matlab_ros_com:25:55"] = "matlab_ros_com.h:69&matlab_ros_com_data.cpp:192";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "matlab_ros_com"};
	this.sidHashMap["matlab_ros_com"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "matlab_ros_com:9"};
	this.sidHashMap["matlab_ros_com:9"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "matlab_ros_com:33"};
	this.sidHashMap["matlab_ros_com:33"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "matlab_ros_com:7"};
	this.sidHashMap["matlab_ros_com:7"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "matlab_ros_com:37"};
	this.sidHashMap["matlab_ros_com:37"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "matlab_ros_com:1"};
	this.sidHashMap["matlab_ros_com:1"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "matlab_ros_com:25"};
	this.sidHashMap["matlab_ros_com:25"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "matlab_ros_com:1:52"};
	this.sidHashMap["matlab_ros_com:1:52"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<S8>"] = {sid: "matlab_ros_com:25:52"};
	this.sidHashMap["matlab_ros_com:25:52"] = {rtwname: "<S8>"};
	this.rtwnameHashMap["<Root>/Blank Message"] = {sid: "matlab_ros_com:9"};
	this.sidHashMap["matlab_ros_com:9"] = {rtwname: "<Root>/Blank Message"};
	this.rtwnameHashMap["<Root>/Blank Message1"] = {sid: "matlab_ros_com:33"};
	this.sidHashMap["matlab_ros_com:33"] = {rtwname: "<Root>/Blank Message1"};
	this.rtwnameHashMap["<Root>/Bus Assignment"] = {sid: "matlab_ros_com:11"};
	this.sidHashMap["matlab_ros_com:11"] = {rtwname: "<Root>/Bus Assignment"};
	this.rtwnameHashMap["<Root>/Bus Assignment1"] = {sid: "matlab_ros_com:34"};
	this.sidHashMap["matlab_ros_com:34"] = {rtwname: "<Root>/Bus Assignment1"};
	this.rtwnameHashMap["<Root>/Bus Selector"] = {sid: "matlab_ros_com:24"};
	this.sidHashMap["matlab_ros_com:24"] = {rtwname: "<Root>/Bus Selector"};
	this.rtwnameHashMap["<Root>/Bus Selector1"] = {sid: "matlab_ros_com:26"};
	this.sidHashMap["matlab_ros_com:26"] = {rtwname: "<Root>/Bus Selector1"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "matlab_ros_com:36"};
	this.sidHashMap["matlab_ros_com:36"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant3"] = {sid: "matlab_ros_com:43"};
	this.sidHashMap["matlab_ros_com:43"] = {rtwname: "<Root>/Constant3"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "matlab_ros_com:22"};
	this.sidHashMap["matlab_ros_com:22"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/Publish UAV1 Pose"] = {sid: "matlab_ros_com:7"};
	this.sidHashMap["matlab_ros_com:7"] = {rtwname: "<Root>/Publish UAV1 Pose"};
	this.rtwnameHashMap["<Root>/Publish UAV1 Velocity"] = {sid: "matlab_ros_com:37"};
	this.sidHashMap["matlab_ros_com:37"] = {rtwname: "<Root>/Publish UAV1 Velocity"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "matlab_ros_com:4"};
	this.sidHashMap["matlab_ros_com:4"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "matlab_ros_com:5"};
	this.sidHashMap["matlab_ros_com:5"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/Scope10"] = {sid: "matlab_ros_com:42"};
	this.sidHashMap["matlab_ros_com:42"] = {rtwname: "<Root>/Scope10"};
	this.rtwnameHashMap["<Root>/Scope2"] = {sid: "matlab_ros_com:6"};
	this.sidHashMap["matlab_ros_com:6"] = {rtwname: "<Root>/Scope2"};
	this.rtwnameHashMap["<Root>/Scope3"] = {sid: "matlab_ros_com:23"};
	this.sidHashMap["matlab_ros_com:23"] = {rtwname: "<Root>/Scope3"};
	this.rtwnameHashMap["<Root>/Scope4"] = {sid: "matlab_ros_com:27"};
	this.sidHashMap["matlab_ros_com:27"] = {rtwname: "<Root>/Scope4"};
	this.rtwnameHashMap["<Root>/Scope5"] = {sid: "matlab_ros_com:28"};
	this.sidHashMap["matlab_ros_com:28"] = {rtwname: "<Root>/Scope5"};
	this.rtwnameHashMap["<Root>/Scope6"] = {sid: "matlab_ros_com:29"};
	this.sidHashMap["matlab_ros_com:29"] = {rtwname: "<Root>/Scope6"};
	this.rtwnameHashMap["<Root>/Scope7"] = {sid: "matlab_ros_com:30"};
	this.sidHashMap["matlab_ros_com:30"] = {rtwname: "<Root>/Scope7"};
	this.rtwnameHashMap["<Root>/Scope8"] = {sid: "matlab_ros_com:31"};
	this.sidHashMap["matlab_ros_com:31"] = {rtwname: "<Root>/Scope8"};
	this.rtwnameHashMap["<Root>/Scope9"] = {sid: "matlab_ros_com:32"};
	this.sidHashMap["matlab_ros_com:32"] = {rtwname: "<Root>/Scope9"};
	this.rtwnameHashMap["<Root>/Subscribe"] = {sid: "matlab_ros_com:1"};
	this.sidHashMap["matlab_ros_com:1"] = {rtwname: "<Root>/Subscribe"};
	this.rtwnameHashMap["<Root>/Subscribe1"] = {sid: "matlab_ros_com:25"};
	this.sidHashMap["matlab_ros_com:25"] = {rtwname: "<Root>/Subscribe1"};
	this.rtwnameHashMap["<S1>/Constant"] = {sid: "matlab_ros_com:9:33"};
	this.sidHashMap["matlab_ros_com:9:33"] = {rtwname: "<S1>/Constant"};
	this.rtwnameHashMap["<S1>/Out"] = {sid: "matlab_ros_com:9:34"};
	this.sidHashMap["matlab_ros_com:9:34"] = {rtwname: "<S1>/Out"};
	this.rtwnameHashMap["<S2>/Constant"] = {sid: "matlab_ros_com:33:33"};
	this.sidHashMap["matlab_ros_com:33:33"] = {rtwname: "<S2>/Constant"};
	this.rtwnameHashMap["<S2>/Out"] = {sid: "matlab_ros_com:33:34"};
	this.sidHashMap["matlab_ros_com:33:34"] = {rtwname: "<S2>/Out"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "matlab_ros_com:7:29"};
	this.sidHashMap["matlab_ros_com:7:29"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/SignalSpecification"] = {sid: "matlab_ros_com:7:30"};
	this.sidHashMap["matlab_ros_com:7:30"] = {rtwname: "<S3>/SignalSpecification"};
	this.rtwnameHashMap["<S3>/SinkBlock"] = {sid: "matlab_ros_com:7:31"};
	this.sidHashMap["matlab_ros_com:7:31"] = {rtwname: "<S3>/SinkBlock"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "matlab_ros_com:37:29"};
	this.sidHashMap["matlab_ros_com:37:29"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/SignalSpecification"] = {sid: "matlab_ros_com:37:30"};
	this.sidHashMap["matlab_ros_com:37:30"] = {rtwname: "<S4>/SignalSpecification"};
	this.rtwnameHashMap["<S4>/SinkBlock"] = {sid: "matlab_ros_com:37:31"};
	this.sidHashMap["matlab_ros_com:37:31"] = {rtwname: "<S4>/SinkBlock"};
	this.rtwnameHashMap["<S5>/Constant"] = {sid: "matlab_ros_com:1:51"};
	this.sidHashMap["matlab_ros_com:1:51"] = {rtwname: "<S5>/Constant"};
	this.rtwnameHashMap["<S5>/Enabled Subsystem"] = {sid: "matlab_ros_com:1:52"};
	this.sidHashMap["matlab_ros_com:1:52"] = {rtwname: "<S5>/Enabled Subsystem"};
	this.rtwnameHashMap["<S5>/SourceBlock"] = {sid: "matlab_ros_com:1:58"};
	this.sidHashMap["matlab_ros_com:1:58"] = {rtwname: "<S5>/SourceBlock"};
	this.rtwnameHashMap["<S5>/Out1"] = {sid: "matlab_ros_com:1:59"};
	this.sidHashMap["matlab_ros_com:1:59"] = {rtwname: "<S5>/Out1"};
	this.rtwnameHashMap["<S5>/Out2"] = {sid: "matlab_ros_com:1:60"};
	this.sidHashMap["matlab_ros_com:1:60"] = {rtwname: "<S5>/Out2"};
	this.rtwnameHashMap["<S6>/Constant"] = {sid: "matlab_ros_com:25:51"};
	this.sidHashMap["matlab_ros_com:25:51"] = {rtwname: "<S6>/Constant"};
	this.rtwnameHashMap["<S6>/Enabled Subsystem"] = {sid: "matlab_ros_com:25:52"};
	this.sidHashMap["matlab_ros_com:25:52"] = {rtwname: "<S6>/Enabled Subsystem"};
	this.rtwnameHashMap["<S6>/SourceBlock"] = {sid: "matlab_ros_com:25:58"};
	this.sidHashMap["matlab_ros_com:25:58"] = {rtwname: "<S6>/SourceBlock"};
	this.rtwnameHashMap["<S6>/Out1"] = {sid: "matlab_ros_com:25:59"};
	this.sidHashMap["matlab_ros_com:25:59"] = {rtwname: "<S6>/Out1"};
	this.rtwnameHashMap["<S6>/Out2"] = {sid: "matlab_ros_com:25:60"};
	this.sidHashMap["matlab_ros_com:25:60"] = {rtwname: "<S6>/Out2"};
	this.rtwnameHashMap["<S7>/In1"] = {sid: "matlab_ros_com:1:53"};
	this.sidHashMap["matlab_ros_com:1:53"] = {rtwname: "<S7>/In1"};
	this.rtwnameHashMap["<S7>/Enable"] = {sid: "matlab_ros_com:1:54"};
	this.sidHashMap["matlab_ros_com:1:54"] = {rtwname: "<S7>/Enable"};
	this.rtwnameHashMap["<S7>/Out1"] = {sid: "matlab_ros_com:1:55"};
	this.sidHashMap["matlab_ros_com:1:55"] = {rtwname: "<S7>/Out1"};
	this.rtwnameHashMap["<S8>/In1"] = {sid: "matlab_ros_com:25:53"};
	this.sidHashMap["matlab_ros_com:25:53"] = {rtwname: "<S8>/In1"};
	this.rtwnameHashMap["<S8>/Enable"] = {sid: "matlab_ros_com:25:54"};
	this.sidHashMap["matlab_ros_com:25:54"] = {rtwname: "<S8>/Enable"};
	this.rtwnameHashMap["<S8>/Out1"] = {sid: "matlab_ros_com:25:55"};
	this.sidHashMap["matlab_ros_com:25:55"] = {rtwname: "<S8>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
