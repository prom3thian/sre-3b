<<<<<<< HEAD
/****************************************************************************
*  @file    shockPositionSensor.h
*  @brief   Shock Position Seonsor is same as a Linear Potentiometer
*           Position Sensor. It is used to monitor and track the linear
*           motion or position of a target
*
*           We choose the LPPS-050 model for the head file blue print
*           to fit the FSAE Suspension Rule (usable wheel travel of at least
*           50.8 mm (2 inches), see the engineering note book)
*           because the measuring range (stroke length) for this model is 2 inches.
*
*           The Max Input Voltage (VDC) is 24V?
*           Output: 0 to 100% of Input Voltage (potentiometer circuit)
*           The measuring range (stroke length)is 2 inches [50mm].
*           The Mechanical Stroke Length is + 3mm.
*
*  @author  Xiao Pan, Wilson Chung, Suyash Ganu
*  @date    11/28/2017
*  @reference http://thesensorconnection.com/linear-travel-sensors/
*  all-linear-travel-sensors/shock-absorber-travel-sensor-rod-end-joints
*
*****************************************************************************/
#ifndef SHOCK_POSITION_SENSOR_H_
#define SHOCK_POSITION_SENSOR_H_

#include "IO_Driver.h"
#include "sensors.h"

typedef struct _ShockPositionSensor     /**<reference: sensors.h*/
{
    Sensor* sps0;   /**<can read sensor value from sps0?*/
	/**<Sensor* bps1; //don't know what's this*/

	/**<sensor values min and max are declared in sps0, no need to redeclare?*/
	/**<sensor values min and max == voltage min and max ?*/

    /**<calibration values min and max == mechanical min and max ?*/
    ubyte2 SPS_calibMin;
    ubyte2 SPS_calibMax;

    ubyte4 sps0_value;

    /**<calibrated value, length compressed*/
    float4 calibratedValue1;
    float4 calibratedValue2;
}ShockPositionSensor;

#define MAX_V 24        /**< maximum output voltage 12VDC  */
#define MIN_V 0         /**< minimum output voltage 0VDC  */
#define MAX_mm 53       /**< maximum mechanical range 53 mm*/
#define MIN_mm 3        /**< minimum mechanical range 3 mm*/

/**< convert output voltage to length compressed*/
/**< specMin, specMax and sensorValue are from sps0, others from ShockPositionSensor*/
float4 SPS_calibration(ubyte4 sensorValue, ubyte4 specMin, ubyte4 specMax,
                     ubyte2 SPS_calibMin, ubyte2 SPS_calibMax);

/**< this function should be added to main.c to initialize the sensor?*/
ShockPositionSensor* ShockPositionSensor_new(void);

/*   void SPS_update(ShockPositionSensor* me);
*   void SPS_saveCalibToEEPROM(ShockPositionSensor* me);
*   void SPS_loadCalibToEEPROM(ShockPositionSensor* me);
*/

/*
void ShockPositionSensor_startCalibration(ShockPositionSensor* me, ubyte1 secondsToRun);
void ShockPositionSensor_update(ShockPositionSensor* me);*/
void ShockPositionSensor_testOutput(ShockPositionSensor* me);

#endif // MYHEADER_H_
=======
/****************************************************************************
*  @file    shockPositionSensor.h
*  @brief   Shock Position Seonsor is same as a Linear Potentiometer
*           Position Sensor. It is used to monitor and track the linear
*           motion or position of a target
*
*           We choose the LPPS-050 model for the head file blue print
*           to fit the FSAE Suspension Rule (usable wheel travel of at least
*           50.8 mm (2 inches), see the engineering note book)
*           because the measuring range (stroke length) for this model is 2 inches.
*
*           The Max Input Voltage (VDC) is 24V?
*           Output: 0 to 100% of Input Voltage (potentiometer circuit)
*           The measuring range (stroke length)is 2 inches [50mm].
*           The Mechanical Stroke Length is + 3mm.
*
*  @author  Xiao Pan, Wilson Chung, Suyash Ganu
*  @date    11/28/2017
*  @reference http://thesensorconnection.com/linear-travel-sensors/
*  all-linear-travel-sensors/shock-absorber-travel-sensor-rod-end-joints
*
*****************************************************************************/
#ifndef SHOCK_POSITION_SENSOR_H_
#define SHOCK_POSITION_SENSOR_H_

#include "IO_Driver.h"
#include "sensors.h"

typedef struct _ShockPositionSensor     //reference: sensors.h
{
    Sensor* sps0;   //can read sensor value from sps0?
	//Sensor* bps1; //don't know what's this

	//sensor values min and max are declared in sps0, no need to redeclare?
	//sensor values min and max == voltage min and max ?

    //calibration values min and max == mechanical min and max ?
    ubyte2 SPS_calibMin;
    ubyte2 SPS_calibMax;

    //calibrated value, length compressed
    float4 calibratedValue;
}ShockPositionSensor;

#define MAX_V 24        /**< maximum output voltage 12VDC  */
#define MIN_V 0         /**< minimum output voltage 0VDC  */
#define MAX_mm 53       /**< maximum mechanical range 53 mm*/
#define MIN_mm 3        /**< minimum mechanical range 3 mm*/

/**< convert output voltage to length compressed*/
/**< specMin, specMax and sensorValue are from sps0, others from ShockPositionSensor*/
float4 SPS_calibration(ubyte4 sensorValue, ubyte4 specMin, ubyte4 specMax,
                     ubyte2 SPS_calibMin, ubyte2 SPS_calibMax);

/**< this function should be added to main.c to initialize the sensor?*/
ShockPositionSensor* ShockPositionSensor_new(void);

/*   void SPS_update(ShockPositionSensor* me);
*   void SPS_saveCalibToEEPROM(ShockPositionSensor* me);
*   void SPS_loadCalibToEEPROM(ShockPositionSensor* me);
*/

#endif // MYHEADER_H_
>>>>>>> parent of 86aedd4... so-called message......
