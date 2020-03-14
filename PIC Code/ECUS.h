/* 
 * File:   Bazzer.h
 * Author: ebrah
 *
 * Created on March 3, 2020, 7:15 PM
 */

#ifndef ECUS_H
#define	ECUS_H
#include "ebra_common.h"

#define BAZZER_init    TRISCbits.RC1 = 0;\
                       PORTCbits.RC1 = 1 

#define BAZZER_ON      PORTCbits.RC1 = 0
#define BAZZER_OFF     PORTCbits.RC1 = 1
#define MLH_init           TRISCbits.RC2 = 0;\
                           PORTCbits.RC2 = 0

// Motor Lamp Heater
#define MLH_ON         PORTCbits.RC2 = 1  
#define MLH_OFF        PORTCbits.RC2 = 0
#endif	/* ECUS_H */

