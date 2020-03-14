/* 
 * File:   Bazzer.h
 * Author: ebrah
 *
 * Created on March 3, 2020, 7:15 PM
 */

#ifndef ECUS_H
#define	ECUS_H
#include "ebra_common.h"
#include <avr/\io.h>

#define BAZZER_init    DDRB|=(1<<1)
#define BAZZER_ON      PORTB|=(1<<1)
#define BAZZER_OFF     PORTB&=(~(1<<1))   

#define MLH_init       DDRB|=(1<<0)  
#define MLH_ON         PORTB|=(1<<0)  
#define MLH_OFF        PORTB&=(~(1<<0))

#endif	/* ECUS_H */

