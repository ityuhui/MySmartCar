#ifndef _DEFINITION_H
#define _DEFINITION_H

#define LEFT_IDS_PORT 2
#define MIDDLE_IDS_PORT 3
#define RIGHT_IDS_PORT 4

#define ENGINE_IN1 5
#define ENGINE_IN2 6
#define ENGINE_IN3 7
#define ENGINE_IN4 8
#define ENGINE_PWM_ENA 9 
#define ENGINE_PWM_ENB 10

#define ENGINE_A_SPEED 100
#define ENGINE_B_SPEED 100

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif


#define FREEUP(x) if(x){ delete (x); (x) = NULL; }


#endif
