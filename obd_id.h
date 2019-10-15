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
#ifndef _OBD_ID_H_
#define _OBD_ID_H_

/**
* @name 11 bit CAN identifiers
* @{ */

/**
* @brief 11 bit legislated OBD/WWH-OBD CAN identifiers - request 
* @note It is strongly recommended (and may be required by applicable legislation) that for future implementations, 
*       the following 11 bit CAN identifier assignment be used:
*       ⎯ 0x7E0 for ECM (engine control module);
*       ⎯ 0x7E1 for TCM (transmission control module).
*/
typedef enum
{
    OBD_ID_REQUEST_11bit_FUNC       = 0x7DF, /*! CAN identifier for functionally addressed request messages sent by external test equipment */
    OBD_ID_REQUEST_11bit_PHYS_ECU_1 = 0x7E0, /*! Physical request CAN identifier from external test equipment to ECU #1 */
    OBD_ID_REQUEST_11bit_PHYS_ECU_2 = 0x7E1, /*! Physical request CAN identifier from external test equipment to ECU #2 */
    OBD_ID_REQUEST_11bit_PHYS_ECU_3 = 0x7E2, /*! Physical request CAN identifier from external test equipment to ECU #3 */
    OBD_ID_REQUEST_11bit_PHYS_ECU_4 = 0x7E3, /*! Physical request CAN identifier from external test equipment to ECU #4 */
    OBD_ID_REQUEST_11bit_PHYS_ECU_5 = 0x7E4, /*! Physical request CAN identifier from external test equipment to ECU #5 */
    OBD_ID_REQUEST_11bit_PHYS_ECU_6 = 0x7E5, /*! Physical request CAN identifier from external test equipment to ECU #6 */
    OBD_ID_REQUEST_11bit_PHYS_ECU_7 = 0x7E6, /*! Physical request CAN identifier from external test equipment to ECU #7 */
    OBD_ID_REQUEST_11bit_PHYS_ECU_8 = 0x7E7, /*! Physical request CAN identifier from external test equipment to ECU #8 */

} OBD_ID_Request_11bit_t;

/**
* @brief 11 bit legislated OBD/WWH-OBD CAN identifiers - response 
* @note It is strongly recommended (and may be required by applicable legislation) that for future implementations, 
*       the following 11 bit CAN identifier assignment be used:
*       ⎯ 0x7E8 for ECM (engine control module);
*       ⎯ 0x7E9 for TCM (transmission control module).
*/
typedef enum
{
    OBD_ID_RESPONSE_11bit_PHYS_ECU_1 = 0x7E8, /*! Physical response CAN identifier from ECU #1 to external test equipment */
    OBD_ID_RESPONSE_11bit_PHYS_ECU_2 = 0x7E9, /*! Physical response CAN identifier from ECU #2 to external test equipment */
    OBD_ID_RESPONSE_11bit_PHYS_ECU_3 = 0x7EA, /*! Physical response CAN identifier from ECU #3 to external test equipment */
    OBD_ID_RESPONSE_11bit_PHYS_ECU_4 = 0x7EB, /*! Physical response CAN identifier from ECU #4 to external test equipment */
    OBD_ID_RESPONSE_11bit_PHYS_ECU_5 = 0x7EC, /*! Physical response CAN identifier from ECU #5 to external test equipment */
    OBD_ID_RESPONSE_11bit_PHYS_ECU_6 = 0x7ED, /*! Physical response CAN identifier from ECU #6 to external test equipment */
    OBD_ID_RESPONSE_11bit_PHYS_ECU_7 = 0x7EE, /*! Physical response CAN identifier from ECU #7 to external test equipment */
    OBD_ID_RESPONSE_11bit_PHYS_ECU_8 = 0x7EF, /*! Physical response CAN identifier from ECU #8 to external test equipment */

} OBD_ID_Response_11bit_t;

/**  @} */

/**
* @name 29 bit CAN identifiers 
* @{ */

/**
* @brief 
*/
typedef enum 
{
    OBD_ID_FORMAT_NORMAL_FIXED_FUNC = 0x18DB, /*!  */
    OBD_ID_FORMAT_NORMAL_FIXED_PHYS = 0x18DA, /*!  */
    OBD_ID_FORMAT_MIXED_FUNC        = 0x18CD, /*!  */
    OBD_ID_FORMAT_MIXED_PHYS        = 0x18CE, /*!  */

} OBD_ID_Format_29bit_t

#define N_TATYPE_29bit(x) (x >> 16)

/**  @} */
#endif

