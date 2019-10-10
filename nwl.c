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
#include "nwl.h"

#include "n_pdu.h"
#include "n_sdu.h"


void nwl_send(Identifier_t Identifier, DLC_t DLC, Data_t Data)
{

}

void nwl_receive(N_TAtype_t N_TAtype, Identifier_t Identifier, DLC_t DLC, Data_t Data)
{
    if (DLC == 0 || DLC > 8)
        return;

    N_PCItype_t N_PCItype = N_PCI_GET_TYPE(Data[0]);

    switch (N_PCItype)
    {
        case SINGLE_FRAME:
        {   
            N_PCI_t *pN_PCI = (N_PCI_t *)Data;
            
            /* Ignore Messages with incorrect SF_DL */
            if (pN_PCI->SF_DL > DLC)  
                return;
            if (pN_PCI->SF_DL == 0)  
                return;
            if (pN_PCI->SF_DL > 7 && Identifier.Type == STANDARD)
                return;
            if (pN_PCI->SF_DL > 6 && Identifier.Type == EXTENDED)
                return;
            
            N_USData.indication(Mtype_t, N_SA_t, N_TA_t, N_TAtype, N_AE_t, MessageData_t, Length_t, N_Result_t);    
           
            break;
        }
        case FIRST_FRAME:
        {
            break;
        }
        case CONSECUTIVE_FRAME:
        {
            break;
        }
        case FLOW_FRAME:
        {
            break;
        }
        default:
        {
            break;
        }
    }        
}


