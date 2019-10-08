#ifndef _N_PDU_H_
#define _N_PDU_H_

#include <stdint.h> 
#include <stdbool.h> 


#define N_WFTmax (0x5)

typedef enum
{
    SINGLE_FRAME      = 0x0,
    FIRST_FRAME       = 0x1,
    CONSECUTIVE_FRAME = 0x2,
    FLOW_FRAME        = 0x3

} N_PCItype_t;

typedef uint8_t SF_DL_t;

typedef uint16_t FF_DL_t;

typedef uint8_t SN_t;

typedef enum
{
    CTS   = 0x0,
    WAIT  = 0x1,
    OVFLW = 0x02    

} FS_t;

typedef uint8_t BS_t;
typedef uint8_t STmin_t;

typedef struct
{
    N_PCItype_t N_PCItype : 4;
    SF_DL_t     SF_DL     : 4;

} N_PCI_SF_t;

typedef struct
{
    N_PCItype_t N_PCItype : 4;
    FF_DL_t     FF_DL     : 12;

} N_PCI_FF_t;

typedef struct
{
    N_PCItype_t N_PCItype : 4;
    SN_t        SN        : 4;

} N_PCI_CF_t;

typedef struct
{
    N_PCItype_t N_PCItype : 4;
    FS_t        FS        : 4;
    BS_t        BS        : 8;
    STmin_t     STmin     : 8;

} N_PCI_FC_t;

typedef union
{
    N_PCI_SF_t SF;
    N_PCI_FF_t FF;
    N_PCI_CF_t CF;
    N_PCI_FC_t FC;

} N_PCI_t;

typedef uint8_t * N_Data_t;

typedef struct 
{
   N_AI_t   N_AI;
   N_PCI_t  N_PCI;
   N_Data_t N_Data;

} N_PDU_t;


#endif
