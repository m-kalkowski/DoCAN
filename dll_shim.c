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
#include "dll_if.h"

#include "canCom1.h"
#include "n_sdu.h"


void dll_shim__request(Identifier_t Identifier, DLC_t DLC, Data_t Data)
{
    flexcan_data_info_t flexcan_data_info;

    flexcan_data_info.msg_id_type = Identifier.Type == STANDARD ? FLEXCAN_MSG_ID_STD : FLEXCAN_MSG_ID_EXT;
    flexcan_data_info.data_length = DLC;
    flexcan_data_info.fd_enable   = false;
    flexcan_data_info.fd_padding  = 0;
    flexcan_data_info.enable_brs  = false;
    flexcan_data_info.is_remote   = false;

    FLEXCAN_DRV_Send(INST_CANCOM1, 0, &flexcan_data_info, Identifier.Id, Data);   
}

void dll_shim__confirm(Identifier_t Identifier, Transfer_Status_t Transfer_Status)
{
    N_USData.confirm();
}

void dll_shim__indication(Identifier_t Identifier, Transfer_Status_t Transfer_Status)
{
    N_USData.indication();
}

void dll_shim__callback(uint8_t instance, flexcan_event_type_t eventType, flexcan_state_t *flexcanState)
{
    Identifier_t *Identifier = (Identifier_t *)flexcanState.callbackParam;
    switch (eventType)
    {
        case FLEXCAN_EVENT_TX_COMPLETE:
        {
            L_Data.confirm(*Identifier, COMPLETE);
        }
        case FLEXCAN_EVENT_RX_COMPLETE:
        {
            L_Data.indication(*Identifier, COMPLETE);
        }
    }
}


