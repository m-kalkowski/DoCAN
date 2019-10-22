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
#ifndef _TPL_SOCKET_H_
#define _TPL_SOCKET_H_

#include "n_pdu.h"


/**
* @brief 
*/
typedef enum
{
    int addr;

} tpl_addr_t; 

/**
* @brief 
*/
typedef struct
{
    
    int rxid;
    int txid;

} tpl_socket_t;

/**
* @brief 
*
* @param tpl_socket
* @param tpl_addr
*/
void bind(tpl_socket_t *tpl_socket, tpl_addr_t *tpl_addr);

/**
* @brief 
*
* @param tpl_socket
* @param BS
* @param STmin
*/
void setsockopt(tpl_socket_t *tpl_socket, BS_t BS, STmin_t STmin);

#endif
