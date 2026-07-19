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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef CRC_INTERNAL_H_
    #define CRC_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "CRC.h"
    #include "driver/STM32L496VGT6P/CRC_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef CRC_TIM
        #define CRC_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef CRC_LOG
        #define CRC_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define CRC_NAME       "CRC"
    #define CRC_LOG_PREFIX UTIL_StringConcatenateConstant( CRC_NAME, "> " )

    #ifdef DEBUG
        #define CRC_Raw( Level, Format, ... ) CRC_LOG_Raw( Level, Format, ##__VA_ARGS__ )
        #define CRC_Trace( Format, ... )      CRC_LOG_Trace( UTIL_StringConcatenateConstant( CRC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CRC_Debug( Format, ... )      CRC_LOG_Debug( UTIL_StringConcatenateConstant( CRC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CRC_Info( Format, ... )       CRC_LOG_Info( UTIL_StringConcatenateConstant( CRC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CRC_Warning( Format, ... )    CRC_LOG_Warning( UTIL_StringConcatenateConstant( CRC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CRC_Error( Format, ... )      CRC_LOG_Error( UTIL_StringConcatenateConstant( CRC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CRC_Fatal( Format, ... )      CRC_LOG_Fatal( UTIL_StringConcatenateConstant( CRC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define CRC_Raw( Level, Format, ... )
        #define CRC_Trace( Format, ... )
        #define CRC_Debug( Format, ... )
        #define CRC_Info( Format, ... )
        #define CRC_Warning( Format, ... )
        #define CRC_Error( Format, ... )
        #define CRC_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum CRC_Type
    {
        CRC_Type_Unknown = 0,
        CRC_Type_Null,
        CRC_Type_STM32L496VGT6P,
    } CRC_Type_t;

    typedef struct CRC_Instance
    {
        CRC_Type_t Type;

        union
        {
            CRC_STM32L496VGT6P_t STM32L496VGT6Px;
        };
    } CRC_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    CRC_Status_t CRC_Port_Initialize( CRC_t CRCx );
    CRC_Status_t CRC_Port_Cycle( CRC_t CRCx );
    CRC_Status_t CRC_Port_DeInitialize( CRC_t CRCx );
    CRC_Status_t CRC_Port_Compute( CRC_t CRCx, CRC_Data_t * Data, CRC_DataLength_t DataLength, CRC_Value_t * Value );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* CRC_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
