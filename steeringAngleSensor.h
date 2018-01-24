/**********************************************************************//**
 *
 * \author 		Thinh Le
 * \reference	http://files.danfoss.com/documents/520l0942.pdf
 * \date 		11-2-2017
 **************************************************************************/
/**********************************************************************//**
 * \file steering.h
 *
 * \brief Steering Wheel Position for detection of absolute position and 
 * 		speed of the steering wheel.
 *
 *      The sensor can be used in electro-hydraulic steering systems 
 *		using steering valves with programmable controllers. A use case
 * 		could be a variable steering ratio and closed-loop set-ups where
 * 		steering wheel position and steering angle have to match.
 * 		
 * 		SAS is noncontact with high resolution. The output is a CAN signal
 * 		which makes an easy interface to advanced vehicle controllers. 
 * 		
 * 		The sensor functions by turning the rotor of the SAS via steering
 * 		wheel shaft. The sensor is mounted between the steering unit and
 * 		steering column.
 * 		
 *		• Accurate linearity to ± 0.5%
 *		• Easy mounting principle
 *		• Non contacting technology: Hall effect
 * 		• Model dedicated to all applications in harsh environments
 * 		• Spring loaded types available
 *
 *  \section sas_examples SAS Examples
 *
 **************************************************************************/
#ifndef _STEERING_H
#define _STEERING_H

/**************************************************************************
 *
 * I N C L U D E S
 *
 **************************************************************************/

#include "IO_Driver.h"	/**< Initializing drivers for laptop to VCU communication */
#include "IO_CAN.h" 	/**< Output is CAN signal */
#include "IO_PWM.h"		/**< Pulse Width Modulation for duty cycles*/
#include "IO_ADC.h"		/**< Get analog signals from sensor output */
#include "Sensors.h"

/**************************************************************************
 *
 * D E F I N I T I O N S
 *
 **************************************************************************/

/**
 * \name SAS Electrical Specifications
 * \anchor sas_settings
 *
 * Selects a position or speed configuration for steering angle sensor
 */
/*@{*/
// #define            		SUP_V_9    /**< minimum voltage 9VDC  */
// #define             	SUP_V_32    /**< minimum voltage 9VDC  */
// #define          		MIR_0    /**< mechanical input range 0 degrees  */
// #define            		MIR_360    /**< mechanical input range 360 degrees  */
// #define             	BAUD_OUT    /**< baud rate 125, 250, or 500 kb/s  */

/*@}*/

/**************************************************************************
 *
 * D A T A 	S T R U C T U R E S
 *
 **************************************************************************/

typedef enum{
	electricalAngle, // 90, 120, 180, 270, 360
	standardLinearity, // +1, -1
	specialLinearity, // +0.5, -0.5
	supplyVoltage = 5, // +10, -10
	standardSupplyCurrent = 10, // 16 mA max
	specialSupplyCurrent = 16,
	outputSignal, //10 to 90%, PWM 1000Hz, 10 to 90% duty cycle
	overVoltageProtection = 20, 
	reverseVoltageProtection = -10,
	loadResistance = 1000,
	hysteresisStatic = 0.3
} electricalSteeringAngleSensor;

typedef enum{
	mechanicalTravel = 360, // 124 ± 3 degrees
	bearingType, // sleeve bearing
	standard, // IP 50
	weight //19g ± 2g hollow shaft, 22g ± 2g D-shaft
} mechanicalSteeringAngleSensor;

typedef enum{
	vibrations,
	shocks,
	operatingTemp,
	lifeCycle,
	maxRotationSpeed,
	immunityRED, // radiated electromagnetic disturbances
	immunityPFMF, // power frequency magnetic field
	radiatedEMEmissions,
	electrostaticDischarges
} environmentSteeringAngleSensor;

typedef struct _SteeringAngleSensor {
    //Sensor values / properties
    Sensor* sas;

    ubyte2 sas_calibMin;  //2 bytes for ADC, 4 bytes if switch to digital/timer/PWM
	ubyte2 sas_calibMax;
	ubyte2 sas_value;
    float4 sas_percent;

    // Timestamps
    ubyte4 timestamp_calibrationStart;
    ubyte1 calibrationRunTime;

    // Flags
    bool done;
    bool sas_reverse;
    bool calibrated;
    bool implausability;
    bool runCalib;
} SteeringAngleSensor;

/**************************************************************************
 *
 * F U N C T I O N S
 *
 **************************************************************************/

SteeringAngleSensor* SteeringAngleSensor_new(void);
void SteeringAngleSensor_update(SteeringAngleSensor* me, bool done);
// void SteeringAngleSensor_getIndividualSensorPercent(SteeringAngleSensor* me, ubyte1 sensorNumber, float4* percent);
// void SteeringAngleSensor_resetCalibration(SteeringAngleSensor* me);
// void SteeringAngleSensor_saveCalibrationToEEPROM(SteeringAngleSensor* me);
// void SteeringAngleSensor_loadCalibrationFromEEPROM(SteeringAngleSensor* me);
// void SteeringAngleSensor_startCalibration(SteeringAngleSensor* me, ubyte1 secondsToRun);
// void SteeringAngleSensor_calibrationCycle(SteeringAngleSensor* me, ubyte1* errorCount);
// void SteeringAngleSensor_getLinearity(SteeringAngleSensor* me, ubyte1* errorCount, float4* linearity);
// void SteeringAngleSensor_getOutputSignal(SteeringAngleSensor* me, ubyte1* dutyCycle);

#endif
