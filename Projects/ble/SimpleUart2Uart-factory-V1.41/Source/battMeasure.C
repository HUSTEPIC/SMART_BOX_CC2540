#include <ioCC2540.h>
#include "battMeasure.H"
#include "hal_adc.h"


uint16 battMinLevel = BATT_ADC_LEVEL_2V; // For VDD/3 measurements
uint16 battMaxLevel = BATT_ADC_LEVEL_3V; // For VDD/3 measurements

/*********************************************************************
 * @fn      battMeasure
 *
 * @brief   Measure the battery level with the ADC and return
 *          it as a percentage 0-100%.
 *
 * @return  Battery level.
 */ 
uint8 battMeasure( void )// 返回电池电量的百分比
{
  uint16 adc;
  uint8 percent;

  /**
   * Battery level conversion from ADC to a percentage:
   *
   * The maximum ADC value for the battery voltage level is 511 for a
   * 10-bit conversion.  The ADC value is references vs. 1.25v and
   * this maximum value corresponds to a voltage of 3.75v.
   *
   * For a coin cell battery 3.0v = 100%.  The minimum operating
   * voltage of the CC2540 is 2.0v so 2.0v = 0%.
   *
   * To convert a voltage to an ADC value use:
   *
   *   (v/3)/1.25 * 511 = adc
   *
   * 3.0v = 409 ADC
   * 2.0v = 273 ADC
   *
   * We need to map ADC values from 409-273 to 100%-0%.
   *
   * Normalize the ADC values to zero:
   *
   * 409 - 273 = 136
   *
   * And convert ADC range to percentage range:
   *
   * percent/adc = 100/136 = 25/34
   *
   * Resulting in the final equation, with round:
   *
   * percent = ((adc - 273) * 25) + 33 / 34
   */


  // Configure ADC and perform a read
  HalAdcSetReference( HAL_ADC_REF_125V );
  adc = HalAdcRead( HAL_ADC_CHANNEL_VDD, HAL_ADC_RESOLUTION_10 );

  // 下面的运算，是把 battMinLevel 与  battMaxLevel 之间的adc读数转换成 2~3v的百分比显示
  if (adc >= battMaxLevel)
  {
    percent = 100;
  }
  else if (adc <= battMinLevel)
  {
    percent = 0;
  }
  else
  {
      uint16 range =  battMaxLevel - battMinLevel + 1;

      // optional if you want to keep it even, otherwise just take floor of divide
      // range += (range & 1);
      range >>= 2; // divide by 4

      percent = (uint8) ((((adc - battMinLevel) * 25) + (range - 1)) / range);
  }

  return percent;
}

