#include "shockPositionSensor.h"
#include "sensors.h"
#include<stdio.h>

ShockPositionSensor* ShockPositionSensor_new(void)
{
    //allocate memory
    ShockPositionSensor* me=(ShockPositionSensor *)malloc(sizeof(ShockPositionSensor));

    //initialization
    me->sps0=&Sensor_SPS0;  ///we should add Sensor_SPS0 declaration in sensor.c
    Sensor_SPS0.specMin=Min_V;  //min voltage
    Sensor_SPS0.specMax=Max_V;  //max voltage
    me->SPS_calibMin=MIN_mm;    //minimum mechanical range 3 mm*/
    me->SPS_calibMax=MAX_mm;    //maximum mechanical range 53 mm*/

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> parent of 86aedd4... so-called message......
=======
>>>>>>> parent of 86aedd4... so-called message......
    //calculate mechanical displacement (length compressed of the shock)
    me->calibratedValue=SPS_calibration(me->sps0->sensorValue,me->sps0->specMin,
                                        me->sps0->specMax,me->SPS_calibMin,
                                        me->SPS_calibMax);
>>>>>>> parent of 86aedd4... so-called message......
    return me;
}

float4 SPS_calibration(ubyte4 sensorValue, ubyte4 specMin, ubyte4 specMax,
                     ubyte2 SPS_calibMin, ubyte2 SPS_calibMax)
{
    return ((float4)sensorValue-(float4)specMin)/((float4)specMax-(float4)specMin)*
           ((float4)SPS_calibMax-(float4)SPS_calibMin)+(float4)SPS_calibMin;
}

void ShockPositionSensor_update(ShockPositionSensor* me)
{
    	me->sps0_value = me->sps0->sensorValue;
}

void ShockPositionSensor_testOutput(ShockPositionSensor* me)
{
    /**<calculate mechanical displacement (length compressed of the shock)*/
    me->calibratedValue1=SPS_calibration(me->sps0->sensorValue,me->sps0->specMin,
                                        me->sps0->specMax,me->SPS_calibMin,
                                        me->SPS_calibMax);
    //only difference: use me->sps0_value instead of me->sps0->sensorValue
    me->calibratedValue2=SPS_calibration(me->sps0_value,me->sps0->specMin,
                                        me->sps0->specMax,me->SPS_calibMin,
                                        me->SPS_calibMax);
    printf("%X\n",me->sensorValue);
    printf("%f\n%f\n\n",me->calibratedValue1,me->calibratedValue1);

}
