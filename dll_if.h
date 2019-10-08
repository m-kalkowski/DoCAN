#ifndef _DLL_IF_H_
#define _DLL_IF_H_

#include <stdint.h> 
#include <stdbool.h> 


typedef uint32_t Identifier_t;

typedef uint8_t DLC_t;

typedef uint8_t * Data_t;

typedef enum
{
    COMPLETE,
    NOT_COMPLETE,
    ABORTED

} Transfer_Status_t;

typedef struct
{
    void (*request)(Identifier_t, DLC_t, Data_t);
    void (*confirm)(Identifier_t, Transfer_Status_t);
    void (*indication)(Identifier_t, Transfer_Status_t);

} L_Data;

#endif
