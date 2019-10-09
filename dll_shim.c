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


