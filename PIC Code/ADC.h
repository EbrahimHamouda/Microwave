/* 
 * File:   ADC.h
 * Author: ebrah
 *
 * Created on March 4, 2020, 5:19 PM
 */

#ifndef ADC_H
#define	ADC_H
#include "ebra_common.h"
void adc_init(void);

unsigned int ADC_Read(unsigned char canal);

#endif	/* ADC_H */

