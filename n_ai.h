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
#ifndef _N_AI_H_
#define _N_AI_H_

#include <stdint.h>

/**
 * @brief Network Source Address         
 */
typedef uint8_t N_SA_t;

/**
 * @brief Network Target Address
 */
typedef uint8_t N_TA_t;

/**
 * @brief Network Target Address type
 */
typedef enum
{
    N_TAtype_PHYSICAL,
    N_TAtype_FUNCTIONAL

} N_TAtype_t;

/**
 * @brief Network Address Extension
 */
typedef uint8_t N_AE_t;

/**
* @brief Address Information for Mtype = diagnostics
*/
typedef struct  
{
    N_SA_t     N_SA;
    N_TA_t     N_TA;
    N_TAtype_t N_TAtype;

} N_AI_Diagnostics_t;

/**
* @brief Address Information for Mtype = remote diagnostics
*/
typedef struct  
{
    N_SA_t     N_SA;
    N_TA_t     N_TA;
    N_TAtype_t N_TAtype;
    N_AE_t     N_AE;

} N_AI_RemoteDiagnostics_t;

/**
* @brief Address Information
*/
typedef union
{
    N_AI_Diagnostics_t       Diagnostics;   
    N_AI_RemoteDiagnostics_t RemoteDiagnostics;     

} N_AI_t;


#endif
