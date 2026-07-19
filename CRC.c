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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "CRC.h"
#include "CRC_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct CRC_Context
{
} CRC_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static CRC_Status_t CRC_Context_Initialize( void );
static CRC_Status_t CRC_Context_Cycle( void );
static CRC_Status_t CRC_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static CRC_Context_t CRC_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static CRC_Status_t CRC_Context_Initialize( void )
{
    CRC_Status_t CRC_Status = CRC_Status_Success;

    do
    {
        CRC_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( CRC_Context );
    }
    while ( 0 );

    return CRC_Status;
}

static CRC_Status_t CRC_Context_Cycle( void )
{
    CRC_Status_t CRC_Status = CRC_Status_Success;

    do
    {
        CRC_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( CRC_Context );
    }
    while ( 0 );

    return CRC_Status;
}

static CRC_Status_t CRC_Context_DeInitialize( void )
{
    CRC_Status_t CRC_Status = CRC_Status_Success;

    do
    {
        CRC_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( CRC_Context );
    }
    while ( 0 );

    return CRC_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################
CRC_Status_t CRC_Initialize( CRC_t CRCx )
{
    CRC_Status_t Status = CRC_Status_Success;
    CRC_Status_t CRC_Status = CRC_Status_Success;

    do
    {
        CRC_Trace( "%s( CRCx=%d )", __FUNCTION__, CRCx );

        if ( ( Status = CRC_Context_Initialize( ) ) != CRC_Status_Success )
        {
            break;
        }

        CRC_t CRC_start = ( CRCx == CRC_All ? CRC_Null : CRCx );
        CRC_t CRC_end = ( CRCx == CRC_All ? CRC_Count : CRCx + 1 );
        for ( CRC_t CRC_x = CRC_start; CRC_x < CRC_end; ++CRC_x )
        {
            if ( ( CRC_Status = CRC_Port_Initialize( CRC_x ) ) != CRC_Status_Success )
            {
                Status = CRC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

CRC_Status_t CRC_Cycle( CRC_t CRCx )
{
    CRC_Status_t Status = CRC_Status_Success;
    CRC_Status_t CRC_Status = CRC_Status_Success;

    do
    {
        CRC_Trace( "%s( CRCx=%d )", __FUNCTION__, CRCx );

        if ( ( Status = CRC_Context_Cycle( ) ) != CRC_Status_Success )
        {
            break;
        }

        CRC_t CRC_start = ( CRCx == CRC_All ? CRC_Null : CRCx );
        CRC_t CRC_end = ( CRCx == CRC_All ? CRC_Count : CRCx + 1 );
        for ( CRC_t CRC_x = CRC_start; CRC_x < CRC_end; ++CRC_x )
        {
            if ( ( CRC_Status = CRC_Port_Cycle( CRC_x ) ) != CRC_Status_Success )
            {
                Status = CRC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

CRC_Status_t CRC_DeInitialize( CRC_t CRCx )
{
    CRC_Status_t Status = CRC_Status_Success;
    CRC_Status_t CRC_Status = CRC_Status_Success;

    do
    {
        CRC_Trace( "%s( CRCx=%d )", __FUNCTION__, CRCx );

        CRC_t CRC_start = ( CRCx == CRC_All ? CRC_Null : CRCx );
        CRC_t CRC_end = ( CRCx == CRC_All ? CRC_Count : CRCx + 1 );
        for ( CRC_t CRC_x = CRC_start; CRC_x < CRC_end; ++CRC_x )
        {
            if ( ( CRC_Status = CRC_Port_DeInitialize( CRC_x ) ) != CRC_Status_Success )
            {
                Status = CRC_Status;
            }
        }

        if ( ( Status = CRC_Context_DeInitialize( ) ) != CRC_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

CRC_Status_t CRC_Compute( CRC_t CRCx, CRC_Data_t * Data, CRC_DataLength_t DataLength, CRC_Value_t * Value )
{
    CRC_Status_t Status = CRC_Status_Success;
    CRC_Status_t CRC_Status = CRC_Status_Success;

    do
    {
        CRC_Trace( "%s( CRCx=%d )", __FUNCTION__, CRCx );

        if ( Value == NULL )
        {
            Status = CRC_Status_ArgumentInvalid;
            break;
        }

        if ( CRCx == CRC_All )
        {
            // FIXME Is it required to define a criteria to compute CRC on all peripherals ?
            Status = CRC_Status_NotSupported;
            break;
        }

        CRC_t CRC_start = ( CRCx == CRC_All ? CRC_Null : CRCx );
        CRC_t CRC_end = ( CRCx == CRC_All ? CRC_Count : CRCx + 1 );
        for ( CRC_t CRC_x = CRC_start; CRC_x < CRC_end; ++CRC_x )
        {
            if ( ( CRC_Status = CRC_Port_Compute( CRC_x, Data, DataLength, Value ) ) != CRC_Status_Success )
            {
                Status = CRC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char CRC_VERSION[] = "0.0.0.v20260719-2341";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
