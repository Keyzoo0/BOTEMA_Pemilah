// =======================variabel=====================


//==============readCoordinat============

int x , y , z ; //  koordinat x,y untuk jalan koordinat z untuk rotasi


//====================================

//===============kinematic===============

// ===Motor==
#define MOTOR1A 10
#define MOTOR1B 9

#define MOTOR2A 12
#define MOTOR2B 11

#define MOTOR3A 8
#define MOTOR3B 7

#define MOTOR4A 6
#define MOTOR4B 5


#define ENA1 24 
#define ENA2 28
#define ENA3 44
#define ENA4 48
 
#define IS1 24
#define IS2 26
#define IS3 46
#define IS4 50

//===inverse kinematik===
#define lambda 5
#define d2r(x) x*(PI/180)

#define LengthAlpha 0.1 // Ubah Disini untuk panjang dari sumbu roda ke tengah roda

#define M1 1
#define M2 2
#define M3 3
#define M4 4

int pwm[4]; 


float atanVal;

//=============================================================================


//=======================Read Encoder===========================================

#define ENCODEROUTPUT 135
const int HALL_A[4] = { 19 , 18 , 3 , 2} ;
volatile long encoderValue[4] = {0 , 0 , 0 , 0};


int interval = 10;
long previousMillis = 0;
long currentMillis = 0;

boolean measureRpm = false;

//============================================================================


//========================Linearisasi Motor==================================

int set[4];
int coba_pwm[4];
int encoder[4][2];
int motor_mode = 0;
int rpm[4];
long long data[4];
double tes[4];
double a[4], b[4], c[4], d[4];
bool linear = false, can_bus = false;
bool usb = false;

// Motor 1 Positif
double linier_motor1[] = { 167.823705421052, 0.203825030994, 0.005407407002,
		-0.000009073620, 0.000000004768 };
// Motor 1 Negatif
double linier_motor2[] = { -187.099950980668, -0.302069430041, -0.008274048460,
		-0.000014922277, -0.000000008828 };

// Motor 2 Positif
double linier_motor3[] = { 168.161267432362, 0.237070933231, 0.006069205455,
		-0.000011715359, 0.000000007201 };
// Motor 2 Negatif
double linier_motor4[] = { -163.431964092543, -0.012607922385, -0.006348451939,
		-0.000010972864, -0.000000006313 };

// Motor 3 Positif
double linier_motor5[] = { 157.822591035905, 0.305632673512, 0.006537528118,
		-0.000012437181, 0.000000007071 };
// Motor 3 Negatif
double linier_motor6[] = { -193.51515668193, -0.150815642468273,
		-0.00773735736752408, -0.0000152276346793771, -0.000000009808 };

// Motor 4 Positif
double linier_motor7[] = { 175.013510950247, 0.081018606486, 0.006066495164,
		-0.000010207437, 0.000000005313 };
// Motor 4 Negatif
double linier_motor8[] = { -173.655463908713, -0.330329686641831,
		-0.00788300937747068, -0.0000136239800397376, -0.000000007817 };



//============================================================================

//=========================Control PID=========================================


double error[4], last_error[4], zigma_error[4], delta_error[4];
int outputPID[4], pwm_val[4];
double kp = 1, kd = 0.5;
double ki[] = { 0.001, 0.0007, 0.0007, 0.001 };



//=========================================================================

//=================================== lift =================================

int motorAL = 4,
    motorBL = 13 ,
    ENL = 23 ;


int l = 0;