/* Copyright (C) 
* 2019 - Mateusz Kalkowski
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
* 
*/
#ifndef _N_PDU_H_
#define _N_PDU_H_

#include <stdint.h> 
#include <stdbool.h> 
#include "n_sdu.h" 


#define N_WFTmax (0x5)

#define N_PCI_GET_TYPE(x)  ((uint8_t)x >> 4u)

/**
* @brief network protocol control information type
*/
typedef enum
{
    SINGLE_FRAME      = 0x0,
    FIRST_FRAME       = 0x1,
    CONSECUTIVE_FRAME = 0x2,
    FLOW_FRAME        = 0x3

} N_PCItype_t;

/**
* @brief SingleFrame DataLength
*/
typedef uint8_t SF_DL_t;

/**
* @brief FirstFrame DataLength
*/
typedef uint16_t FF_DL_t;

/**
* @brief SequenceNumber
*/
typedef uint8_t SN_t;

/**
* @brief FlowStatus
*/
typedef enum
{
    CTS   = 0x0,
    WAIT  = 0x1,
    OVFLW = 0x02    

} FS_t;

/**
* @brief BlockSize
*/
typedef uint8_t BS_t;

/**
* @brief SeparationTime minimum
*/
typedef uint8_t STmin_t;

/**
* @brief 
*/
typedef struct
{
    N_PCItype_t N_PCItype : 4;
    SF_DL_t     SF_DL     : 4;

} N_PCI_SF_t;

/**
* @brief 
*/
typedef struct
{
    N_PCItype_t N_PCItype : 4;
    FF_DL_t     FF_DL     : 12;

} N_PCI_FF_t;

/**
* @brief 
*/
typedef struct
{
    N_PCItype_t N_PCItype : 4;
    SN_t        SN        : 4;

} N_PCI_CF_t;

/**
* @brief 
*/
typedef struct
{
    N_PCItype_t N_PCItype : 4;
    FS_t        FS        : 4;
    BS_t        BS        : 8;
    STmin_t     STmin     : 8;

} N_PCI_FC_t;

/**
* @brief 
*/
typedef union
{
    N_PCI_SF_t SF;
    N_PCI_FF_t FF;
    N_PCI_CF_t CF;
    N_PCI_FC_t FC;

} N_PCI_t;

/**
* @brief 
*/
typedef uint8_t N_Data_t;

/**
* @brief N_PDU SingleFrame 
*/
typedef struct 
{
    N_AI_SF_t   N_AI;
    N_PCI_SF_t  N_PCI;
#if defined(USE_EXTENDED_ADDRESSING)
    N_Data_t    N_Data[6];
#else
    N_Data_t    N_Data[7];
#endif
    
} N_PDU_SF_t;

/**
* @brief N_PDU FirstFrame 
*/
typedef struct 
{
    N_AI_FF_t   N_AI;
    N_PCI_FF_t  N_PCI;
#if defined(USE_EXTENDED_ADDRESSING)
    N_Data_t    N_Data[5];
#else
    N_Data_t    N_Data[6];
#endif
    
} N_PDU_FF_t;

/**
* @brief N_PDU ConsecutiveFrame 
*/
typedef struct 
{
    N_AI_CF_t   N_AI;
    N_PCI_CF_t  N_PCI;
#if defined(USE_EXTENDED_ADDRESSING)
    N_Data_t    N_Data[6];
#else
    N_Data_t    N_Data[7];
#endif
    
} N_PDU_CF_t;

/**
* @brief N_PDU FlowControl
*/
typedef struct 
{
    N_AI_FC_t   N_AI;
    N_PCI_FC_t  N_PCI;
    
} N_PDU_FC_t;

/**
* @brief N_PDU 
*/
typedef union 
{
    N_PDU_SF_t SF;    
    N_PDU_FF_t FF;    
    N_PDU_CF_t CF;
    N_PDU_FC_t FC;

} N_PDU_t;


#endif
