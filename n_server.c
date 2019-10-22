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
#include "n_server.h"
#include "tpl_socket.h"


tpl_addr_t tpl_addr_list[] =
{
    {
        .addr_format = ADDR_FORMAT_NORMAL_11Bit,    
        .rxid = None,
        .txid = 0x199u,
        .N_AI = 
        {
            .N_SA     = None,
            .N_TA     = None,
            .N_TAtype = None,
            .N_AE     = None,
        },
    },

    {
        .addr_format = ADDR_FORMAT_NORMAL_11Bit,    
        .rxid = 0x321u,
        .txid = None,
        .N_AI = 
        {
            .N_SA     = None,
            .N_TA     = None,
            .N_TAtype = None,
            .N_AE     = None,
        },
    },

    {
        .addr_format = ADDR_FORMAT_NORMAL_11Bit,    
        .rxid = 0x294u,
        .txid = None,
        .N_AI = 
        {
            .N_SA     = None,
            .N_TA     = None,
            .N_TAtype = None,
            .N_AE     = None,
        },
    },

    {
        .addr_format = ADDR_FORMAT_NORMAL_11Bit,    
        .rxid = 0x1a6u,
        .txid = None,
        .N_AI = 
        {
            .N_SA     = None,
            .N_TA     = None,
            .N_TAtype = None,
            .N_AE     = None,
        },
    },

    {
        .addr_format = ADDR_FORMAT_NORMAL_11Bit,    
        .rxid = 0x1a3u,
        .txid = None,
        .N_AI = 
        {
            .N_SA     = None,
            .N_TA     = None,
            .N_TAtype = None,
            .N_AE     = None,
        },
    },

    {
        .addr_format = ADDR_FORMAT_NORMAL_11Bit,    
        .rxid = 0x158u,
        .txid = None,
        .N_AI = 
        {
            .N_SA     = None,
            .N_TA     = None,
            .N_TAtype = None,
            .N_AE     = None,
        },
    },
};

#define TPL_SOCKET_NUM (sizeof(tpl_addr_list) / sizeof(tpl_addr_t))

void n_server_main(void)
{
    for (size_t i=0; i<TPL_SOCKET_NUM; ++i)
        bind(&tpl_socket[i], &tpl_addr[0]);

    bind(&tpl_socket[1], &tpl_addr[1]);
    bind(&tpl_socket[2], &tpl_addr[2]);
    bind(&tpl_socket[3], &tpl_addr[3]);
    bind(&tpl_socket[4], &tpl_addr[4]);

    receive(&tpl_socket[0]);
    receive(&tpl_socket[1]);
    receive(&tpl_socket[2]);
    receive(&tpl_socket[3]);
    receive(&tpl_socket[4]);
}
