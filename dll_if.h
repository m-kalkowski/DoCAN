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
#ifndef _DLL_IF_H_
#define _DLL_IF_H_

#include <stdint.h> 
#include <stdbool.h> 


typedef enum 
{
    STANDARD,
    EXTENDED

} Identifier_Type_t

typedef struct
{
    Identifier_Type_t Type;
    
    uint32_t Id; 

} Identifier_t;

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
    void (*indication)(Identifier_t, DLC_t, Data_t);

} L_Data_t;

extern L_Data_t L_Data;


#endif
