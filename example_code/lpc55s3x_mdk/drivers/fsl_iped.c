/*
 *     Copyright 2020 NXP
 *     All rights reserved.
 *
 *     SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_iped.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
status_t IPED_SetRegionAddressRange(IPED_Type *base, iped_region_t region, uint32_t start_address, uint32_t end_address)
{
    status_t status = kStatus_Fail;

    do
    {
        /* Check if region is not locked */
        if ((base->IPEDCTXCTRL1 & (IPED_IPEDCTXCTRL1_CTX0_FREEZE1_MASK << (region * 2u))) !=
            (IPED_RW_ENABLE_VAL << (region * 2u)))
        {
            status = kStatus_IPED_RegionIsLocked;
            break;
        }

        /* Disable soft lock for given region first */
        base->IPEDCTXCTRL0 = (base->IPEDCTXCTRL0 & ~(IPED_IPEDCTXCTRL0_CTX0_FREEZE0_MASK << (region * 2u))) |
                             (IPED_RW_ENABLE_VAL << (region * 2u));

        switch (region)
        {
            case kIPED_Region0:
                base->IPEDCTX0START = start_address;
                base->IPEDCTX0END   = end_address;
                status              = kStatus_Success;
                break;

            case kIPED_Region1:
                base->IPEDCTX1START = start_address;
                base->IPEDCTX1END   = end_address;
                status              = kStatus_Success;
                break;

            case kIPED_Region2:
                base->IPEDCTX2START = start_address;
                base->IPEDCTX2END   = end_address;
                status              = kStatus_Success;
                break;

            case kIPED_Region3:
                base->IPEDCTX3START = start_address;
                base->IPEDCTX3END   = end_address;
                status              = kStatus_Success;
                break;

            default:
                status = kStatus_InvalidArgument;
                break;
        }

        /* Re-enable soft lock for given region */
        base->IPEDCTXCTRL0 = (base->IPEDCTXCTRL0 & ~(IPED_IPEDCTXCTRL0_CTX0_FREEZE0_MASK << (region * 2u))) |
                             (IPED_RW_DISABLE_VAL << (region * 2u));
    } while (0);

    return status;
}

status_t IPED_GetRegionAddressRange(IPED_Type *base,
                                    iped_region_t region,
                                    uint32_t *start_address,
                                    uint32_t *end_address)
{
    status_t status = kStatus_Fail;

    switch (region)
    {
        case kIPED_Region0:
            *start_address = base->IPEDCTX0START;
            *end_address   = base->IPEDCTX0END;
            status         = kStatus_Success;
            break;

        case kIPED_Region1:
            *start_address = base->IPEDCTX1START;
            *end_address   = base->IPEDCTX1END;
            status         = kStatus_Success;
            break;

        case kIPED_Region2:
            *start_address = base->IPEDCTX2START;
            *end_address   = base->IPEDCTX2END;
            status         = kStatus_Success;
            break;

        case kIPED_Region3:
            *start_address = base->IPEDCTX3START;
            *end_address   = base->IPEDCTX3END;
            status         = kStatus_Success;
            break;

        default:
            status = kStatus_InvalidArgument;
            break;
    }

    return status;
}

status_t IPED_SetRegionIV(IPED_Type *base, iped_region_t region, const uint8_t iv[8])
{
    status_t status = kStatus_Fail;

    switch (region)
    {
        case kIPED_Region0:
            base->IPEDCTX0IV0 = ((uint32_t *)(uintptr_t)iv)[0];
            base->IPEDCTX0IV1 = ((uint32_t *)(uintptr_t)iv)[1];
            status            = kStatus_Success;
            break;

        case kIPED_Region1:
            base->IPEDCTX1IV0 = ((uint32_t *)(uintptr_t)iv)[0];
            base->IPEDCTX1IV1 = ((uint32_t *)(uintptr_t)iv)[1];
            status            = kStatus_Success;
            break;

        case kIPED_Region2:
            base->IPEDCTX2IV0 = ((uint32_t *)(uintptr_t)iv)[0];
            base->IPEDCTX2IV1 = ((uint32_t *)(uintptr_t)iv)[1];
            status            = kStatus_Success;
            break;

        case kIPED_Region3:
            base->IPEDCTX3IV0 = ((uint32_t *)(uintptr_t)iv)[0];
            base->IPEDCTX3IV1 = ((uint32_t *)(uintptr_t)iv)[1];
            status            = kStatus_Success;
            break;

        default:
            status = kStatus_InvalidArgument;
            break;
    }

    return status;
}
