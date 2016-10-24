#ifndef _DEFINITION_H
#define _DEFINITION_H

#define LEFT_IDS_PORT 3
#define MIDDLE_IDS_PORT 4
#define RIGHT_IDS_PORT 5

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif


#define FREEUP(x) if(x){ delete (x); (x) = NULL; }


#endif
