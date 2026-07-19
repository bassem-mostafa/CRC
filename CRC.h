// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform CRC Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_CRC CRC
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_CRC_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef CRC_H_
    #define CRC_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "CRC_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief CRC Operation Status
     *
     *  @enum CRC_Status_t
     */
    typedef enum CRC_Status
    {
        CRC_Status_Success = 0,     ///< Success
        CRC_Status_ArgumentInvalid, ///< Argument Invalid
        CRC_Status_NotSupported,    ///< Not Supported
        CRC_Status_Error,           ///< General Error
        CRC_Status_Busy,            ///< Busy
        CRC_Status_Timeout,         ///< Timeout
    } CRC_Status_t;

    /**
     *  @brief CRC Data
     */
    typedef uint8_t CRC_Data_t;

    /**
     *  @brief CRC Data Length
     */
    typedef uint32_t CRC_DataLength_t;

    /**
     *  @brief CRC Value
     */
    typedef uint32_t CRC_Value_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize CRC peripheral
     *
     *  @note MUST BE called before using any CRC API
     *
     *  @param[in] CRCx Instance
     *
     *  @return CRC_Status_t
     */
    CRC_Status_t CRC_Initialize( CRC_t CRCx );

    /**
     *  @brief Cycle CRC peripheral
     *
     *  @param[in] CRCx Instance
     *
     *  @return CRC_Status_t
     */
    CRC_Status_t CRC_Cycle( CRC_t CRCx );

    /**
     *  @brief DeInitialize CRC peripheral
     *
     *  @param[in] CRCx Instance
     *
     *  @return CRC_Status_t
     */
    CRC_Status_t CRC_DeInitialize( CRC_t CRCx );

    /**
     *  @brief Compute CRC Value
     *
     *  @param[in]  CRCx       Instance
     *  @param[in]  Data       Data
     *  @param[in]  DataLength Data Length
     *  @param[out] Value      CRC Value
     *
     *  @return CRC_Status_t
     */
    CRC_Status_t CRC_Compute( CRC_t CRCx, CRC_Data_t * Data, CRC_DataLength_t DataLength, CRC_Value_t * Value );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char CRC_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* CRC_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
