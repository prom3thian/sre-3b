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
#define SUP_V_9            		SUP_V_9    /**< minimum voltage 9VDC  */
#define SUP_V_32            	SUP_V_32    /**< minimum voltage 9VDC  */
#define MIR_0            		MIR_0    /**< mechanical input range 0 degrees  */
#define MIR_360            		MIR_360    /**< mechanical input range 360 degrees  */
#define BAUD_OUT            	BAUD_OUT    /**< baud rate 125, 250, or 500 kb/s  */

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
 * \retval	
 *
 ***************************************************************************/
ubyte4 mySteer(...);