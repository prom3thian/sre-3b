#include "steeringAngleSensor.h"
#include "IO_RTC.h"

SteeringAngleSensor* SteeringAngleSensor_new(void){

	SteeringAngleSensor* me = (SteeringAngleSensor*)malloc(sizeof(struct _SteeringAngleSensor));

    //TODO: Make sure the main loop is running before doing this
    me->sas = &Sensor_SAS;
    //me->tps1 = (benchMode == TRUE) ? &Sensor_BenchTPS1 : &Sensor_TPS1;

	//Note: BPS sits slightly below 0.5V but it's still within range
	Sensor_SAS.specMin = 500 - 4000 * .005; //5V +/- 10%
	Sensor_SAS.specMax = 4500 + 4000 * .0025; //+/- 0.25%

	//Where/should these be hardcoded?
	me->sas_reverse = FALSE;
	//me->bps1_reverse = TRUE;

    me->sas_percent = 0;
    me->runCalib = FALSE;  //Do not run the calibration at the next main loop cycle

    //me->calibrated = FALSE;
    // SteeringAngleSensor_resetCalibration(me);

    return me;
}

void SteeringAngleSensor_update(SteeringAngleSensor* me, bool done){
	me->sas_value = me->sas->sensorValue;
	//me->bps1_value = me->bps1->sensorValue;

	me->sas_percent = 0;

	// if (me->runCalibration == TRUE || me->calibrated == FALSE)
	// {
	// 	me->sas_percent = 0;
	// 	//errorCount++;  //DO SOMETHING WITH THIS
	// }
	// else
	// {
	// 	me->sas_percent = getPercent(me->sas_value, me->sas_calibMin, me->sas_calibMax, TRUE);
	// 	me->percent = me->sas_percent;
	// }

}

// void SteeringAngleSensor_getIndividualSensorPercent(SteeringAngleSensor* me, ubyte1 sensorNumber, float4* percent){

// }

// void SteeringAngleSensor_resetCalibration(SteeringAngleSensor* me){

// }

// void SteeringAngleSensor_saveCalibrationToEEPROM(SteeringAngleSensor* me){

// }

// void SteeringAngleSensor_loadCalibrationFromEEPROM(SteeringAngleSensor* me){

// }

// void SteeringAngleSensor_startCalibration(SteeringAngleSensor* me, ubyte1 secondsToRun){

// }

// void SteeringAngleSensor_calibrationCycle(SteeringAngleSensor* me, ubyte1* errorCount){

// }

// void SteeringAngleSensor_getLinearity(SteeringAngleSensor* me, ubyte1* errorCount, float4* linearity){

// }

// void SteeringAngleSensor_getOutputSignal(SteeringAngleSensor* me, ubyte1* dutyCycle){

// }