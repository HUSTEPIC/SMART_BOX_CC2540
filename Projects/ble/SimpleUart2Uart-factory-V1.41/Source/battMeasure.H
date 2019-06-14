#ifndef __BATT_MEASURE_H__
#define __BATT_MEASURE_H__
#include "DHT11.H"
#include "OSAL.h"


#define BATT_ADC_LEVEL_3V           409
#define BATT_ADC_LEVEL_2V           273


extern uint16 battMinLevel ;
extern uint16 battMaxLevel ;
 
uint8 battMeasure( );
#endif