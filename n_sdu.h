#ifndef _N_SDU_H_
#define _N_SDU_H_

#include <stdint.h> 
#include <stdbool.h> 


typedef enum
{
    DIAGNOSTICS,
    REMOTE_DIAGNOSTICS

} Mtype_t;

typedef uint8_t N_SA_t;

typedef uint8_t N_TA_t;

typedef enum
{
    PHYSICAL,
    FUNCTIONAL

} N_TAtype_t;

typedef uint8_t N_AE_t;

typedef uint16_t Length_t;

typedef uint8_t * MessageData_t;

typedef enum
{
    STmin,
    BS

} Parameter_t;

typedef uint8_t Parameter_Value_t;

typedef enum
{
    N_OK,
    N_TIMEOUT_A,
    N_TIMEOUT_Bs,
    N_TIMEOUT_Cr,
    N_WRONG_SN,
    N_INVALID_FS,
    N_UNEXP_PDU,
    N_WFT_OVRN,
    N_BUFFER_OVFLW,
    N_ERROR

} N_Result_t;

typedef enum
{
    N_OK,
    N_RX_ON,
    N_WRONG_PARAMETER,
    N_WRONG_VALUE

} Result_ChangeParameter_t;

typedef struct
{
    N_SA_t     N_SA;
    N_TA_t     N_TA;
    N_TAtype_t N_TAtype;
    N_AE_t     N_AE;

} N_AI_t

typedef struct 
{
    void (* request)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, MessageData_t, Length_t);    
    void (* FF_indication)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, Length_t);    
    void (* indication)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, MessageData_t, Length_t, N_Result_t);    
    void (* confirm)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, N_Result_t);
 
} N_USData_t; 

typedef struct
{
    void (* request)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, Parameter_t, Parameter_Value_t);    
    void (* confirm)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, Parameter_t, Result_ChangeParameter_t);
 
} N_ChangeParameter_t;  


#endif
