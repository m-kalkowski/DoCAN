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
/**
 * @file n_sdu.h
 * @brief 
 * @author Mateusz Kalkowski
 * @version 0.1
 * @date 2019-10-09
 */
#ifndef _N_SDU_H_
#define _N_SDU_H_

#include <stdint.h> 
#include <stdbool.h> 


/**
 * @brief Message type 
 */
typedef enum
{
    DIAGNOSTICS,
    REMOTE_DIAGNOSTICS

} Mtype_t;


/**
 * @brief 
 */
typedef uint8_t N_SA_t;

/**
 * @brief 
 */
typedef uint8_t N_TA_t;

/**
 * @brief 
 */
typedef enum
{
    PHYSICAL,
    FUNCTIONAL

} N_TAtype_t;

/**
 * @brief 
 */
typedef uint8_t N_AE_t;

/**
 * @brief 
 */
typedef uint16_t Length_t;

/**
 * @brief 
 */
typedef uint8_t * MessageData_t;

/**
 * @brief 
 */
typedef enum
{
    STmin,
    BS

} Parameter_t;

/**
 * @brief 
 */
typedef uint8_t Parameter_Value_t;

/**
 * @brief 
 */
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

/**
 * @brief 
 */
typedef enum
{
    N_OK,
    N_RX_ON,
    N_WRONG_PARAMETER,
    N_WRONG_VALUE

} Result_ChangeParameter_t;

/**
 * @brief 
 */
typedef struct
{
    N_SA_t     N_SA;
    N_TA_t     N_TA;
    N_TAtype_t N_TAtype;
    N_AE_t     N_AE;

} N_AI_t

/**
 * @brief 
 */
typedef struct 
{
    void (* request)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, MessageData_t, Length_t);    
    void (* FF_indication)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, Length_t);    
    void (* indication)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, MessageData_t, Length_t, N_Result_t);    
    void (* confirm)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, N_Result_t);
 
} N_USData_t; 

/**
 * @brief 
 */
typedef struct
{
    void (* request)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, Parameter_t, Parameter_Value_t);    
    void (* confirm)(Mtype_t, N_SA_t, N_TA_t, N_TAtype_t, N_AE_t, Parameter_t, Result_ChangeParameter_t);
 
} N_ChangeParameter_t;  

/**
 * @brief 
 */
extern N_USData_t N_USData;


#endif
