/* 
 * File:   TMU.h
 * Author: ebrah
 *
 * Created on February 27, 2020, 10:54 AM
 */

#ifndef TMU_H
#define	TMU_H

#include "Timer.h"
void TMU_init(void (*P2F)(void));
void TMU_TriggerEvent (void);
void TMU_EndEvent(void);
void TMU_MainFunction(void);
void TMU_Cbk(void);
#endif	/* TMU_H */

