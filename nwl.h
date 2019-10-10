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
#ifndef _NWL_H_
#define _NWL_H_

#include "dll_if.h"

/**
* @brief NWL status
*/
typedef enum
{
    SEGMENTED_TRANSMIT_IN_PROGRESS,
    SEGMENTED_RECEIVE_IN_PROGRESS,
    IDLE    

} nwl_status_t;

/**
* @brief 
*
* @param Identifier CAN identifier
* @param DLC data length code
* @param Data CAN frame data
*/
void nwl_send(Identifier_t Identifier, DLC_t DLC, Data_t Data);

/**
* @brief 
*
* @param Identifier CAN identifier
* @param DLC data length code
* @param Data CAN frame data
*/
void nwl_receive(Identifier_t Identifier, DLC_t DLC, Data_t Data);

#endif
