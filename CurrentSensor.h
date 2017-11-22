/**********************************************************************//**
 * \authors         Francisco Ibarra and Gabriel Asuncion
 * \reference    http://www.lem.com/docs/products/hal_50_600-s.pdf
 				 https://www.digikey.com/en/articles/techzone/2012/sep/the-basics-of-current-sensors
 * \date         11-9-17
 **************************************************************************/
/**********************************************************************//**
 * \file CurrentSensors.h
 *
 * \brief Current Sensor is used to measure the current running through a circuit
 *
 *	This sensor is a Hall Effect, open loop sensor that can be used to detect overcurrent in the system. This helps avoid
 *	 heavy damages and keeps the driver the SAFE. This is done by sending messages
 *	 to the VCU forcing the vehicle to shutdown. 
 *
 * 	 The current sensor is connected to the CAN Manager/VCU. It sends analog signals
 *	 to the CAN Manager. The only output would be to check if something bad has happened 
 * 	 I.E overcurrent. 
 *
 *	 The sensor would be placed next to important circuitry or wiring i.e. HV and BMS.
 * 	 The sensor detects if the current goes below or above the SRE current limits by 
 * 	 generating a signal proportional to the current being monitored. This creates a voltage drop
 *	 which can then be measured
 *
 *  \section cs_examples CS Examples
 *
 **************************************************************************/

#ifndef _CURRENTSENSOR_H  	
#define _CURRENTSENSOR_H 	

/**************************************************************************
 *
 * I N C L U D E S
 *
 **************************************************************************/

#include "IO_Driver.h"    /**< Initializing drivers for laptop to VCU communication */
#include "IO_CAN.h"     /**< Output is CAN signal */
#include "tempsensor.h" /**< Needed for current sensor temperature range */
#include "safety.h" /**< Links to error messages that will be displayed if something goes wrong */
#include "sensor.h"  /**< Allows access for communication to other sensors */
/**************************************************************************
 *
 * D E F I N I T I O N S
 *
 **************************************************************************/

/**
 * \name Pull up / down settings
 * \anchor dio_pupd_settings
 *
 * Selects a pull-up or pull-down configuration for a digital input
 */

/*@{*/

#define MIN_V_neg15                   SUP_V_neg15    /**< Minimum voltage -15V DC/AC */
#define MAX_V_15                MAX_V_15    /**< Maximum voltage 15V DC/AC*/
#define MEAS_ACDC_150                    MEAS_ACDC_150    /**< Measurable current -150 to 150A AC/DC*/
#define OTR_neg_25                 OTR_neg_25    /**< Operating temperature range -25 degrees Celcius */
#define OTR_85					   OTR_85		/**< Operating temperature range 85 degrees Celcius */

/*@}*/

/**************************************************************************
 *
 * F U N C T I O N S
 *
 **************************************************************************/
/**********************************************************************//**
 *
 * \brief begin reading steering angle
 *
 * \param di_channel                Analog input:
 *                                      - 
 * \param mode                      Input configuration:
 *                                      - 
 *
 * \return ubyte4:
 * \return val    
 *
 ***************************************************************************/
ubyte4 myCurrentSensor(...);

typedef struct CURRENTSENSOR CRS;
{

	float voltage;
	float currentValue;
	float resistance;
	bool emergency = false; //Returns signals to other sensors to potentially turn off the car
	bool SRC_HIGH = false; //true when there is a short circuit between VCU and any supply voltage
	bool SRC_LOW = false; //true when there is a short circuit between VCU and ground
	float *currentValue;

		
};


void SRC_HIGH(*currentValue);
void SRC_LOW(*currentValue);
bool safe_State(bool SRC_LOW, bool SRC_HIGH);




#endif _CURRENTSENSOR_H

//hyttc which one?
//Api is online?