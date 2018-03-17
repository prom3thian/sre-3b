//Undervoltage Detection and Preventative Measures
//TODO: lots and lots of documentation to take care of

#ifndef _UNDERVOLTAGE_H
#define _UNDERVOLTAGE_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "IO_Driver.h"
#include "IO_RTC.h"
#include "IO_ADC.h"
#include "IO_CAN.h"
#include "IO_PWM.h"
#include "APDB.h"
#include "IO_Constants.h"
//#include "bms.h"
//#include "canManager.h"


typedef struct underVoltage {

		//bms pointer will be used to use some of the bms functions that deal with undervoltage
		//BatteryManagementSystem* bms;

		float4 currentBatteryLevel; //gets information from the LV battery about it's current battery life (look at how other sensors extract voltage data from the LV battery)
		float4 warningBatteryConstant; // = batteryPercentage - 0.5; get voltage value from the LV battery and subtract it by a placeholder constant value
		int minBatteryThreshold; //a constant for the minimum battery threshold
		int maxBatteryThreshold;

		float4 batteryTemperature; //maximum threshold for the battery temperature
		float4 warningTempConstant; //= batteryTemperature + 0.5
		int maxTempThreshold;
		int minTempThreshold;

		IO_ErrorType ADC_Pin_Status;  //Stores the current IO_ErrorType of the ADC pin
		IO_ErrorType PWM_Pin_Status;  //Stores the current IO_ErrorType of the PWM pin

		bool PWM_Channel_OK;
		bool ADC_Channel_OK; 

} underVoltage_ ;

 //Constructor for initializing "me" variable
 underVoltage_* UnderVoltage_new( void );


/******** FUNCTIONS ********/
 float4 getLV_Voltage( void );
 float4 getLV_Temperature( void ); 
 float4 motorcontroller_Voltage( void );
 float4 motorcontroller_Current( void );
 float4 motorcontroller_Temperature( void );
 float4 cooling_Voltage( void );
 float4 cooling_Temperature( void );
 float brakePressure_Voltage( void );
 float wheelSpeeds_Voltage( void );	
 void UV_parseCanMessage(underVoltage_ *uv, IO_CAN_DATA_FRAME* uvCanMessage);
 //ADC and PWM channel OK could possible be converged into one single function. Will look into that later
 underVoltage_* ADC_Channel_OK( IO_ErrorType status , underVoltage_* me);
 underVoltage_* PWM_Channel_OK( IO_ErrorType status , underVoltage_* me);
// /*Mutators*/
 //void setConstants( void );
 //void setToDash( void );

#endif