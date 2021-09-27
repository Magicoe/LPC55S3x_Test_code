/*
 *     Copyright 2020 NXP
 *     All rights reserved.
 *
 *     SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_IPED_H_
#define _FSL_IPED_H_

#include <stdint.h>
#include <stddef.h>

#include "fsl_common.h"

/*!
 * @addtogroup iped
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define IPED_RW_ENABLE_VAL  0x2
#define IPED_RW_DISABLE_VAL 0x1

#if !defined(IPED_Type)
typedef struct
{
    __IO uint32_t IPEDCTRL;
    uint8_t RESERVED_0[208];
    __IO uint32_t IPEDCTXCTRL0;
    __IO uint32_t IPEDCTXCTRL1;
    uint8_t RESERVED_1[24];
    __O uint32_t IPEDCTX0IV0;
    __O uint32_t IPEDCTX0IV1;
    __IO uint32_t IPEDCTX0START;
    __IO uint32_t IPEDCTX0END;
    uint8_t RESERVED_2[16];
    __O uint32_t IPEDCTX1IV0;
    __O uint32_t IPEDCTX1IV1;
    __IO uint32_t IPEDCTX1START;
    __IO uint32_t IPEDCTX1END;
    uint8_t RESERVED_3[16];
    __O uint32_t IPEDCTX2IV0;
    __O uint32_t IPEDCTX2IV1;
    __IO uint32_t IPEDCTX2START;
    __IO uint32_t IPEDCTX2END;
    uint8_t RESERVED_4[16];
    __O uint32_t IPEDCTX3IV0;
    __O uint32_t IPEDCTX3IV1;
    __IO uint32_t IPEDCTX3START;
    __IO uint32_t IPEDCTX3END;
} IPED_Type;

#define IPED_IPEDCTRL_CONFIG_MASK    (0x1)
#define IPED_IPEDCTRL_CONFIG_SHIFT   (0U)
#define IPED_IPEDCTRL_IPED_EN_MASK   (0x2)
#define IPED_IPEDCTRL_IPED_EN_SHIFT  (1U)
#define IPED_IPEDCTRL_IPWR_EN_MASK   (0x4)
#define IPED_IPEDCTRL_IPWR_EN_SHIFT  (2U)
#define IPED_IPEDCTRL_AHBWR_EN_MASK  (0x8)
#define IPED_IPEDCTRL_AHBWR_EN_SHIFT (3U)
#define IPED_IPEDCTRL_AHBRD_EN_MASK  (0x10)
#define IPED_IPEDCTRL_AHBRD_EN_SHIFT (4U)

#define IPED_IPEDCTXCTRL0_CTX0_FREEZE0_MASK  (0x3)
#define IPED_IPEDCTXCTRL0_CTX0_FREEZE0_SHIFT (0U)
#define IPED_IPEDCTXCTRL0_CTX1_FREEZE0_MASK  (0xC)
#define IPED_IPEDCTXCTRL0_CTX1_FREEZE0_SHIFT (2U)
#define IPED_IPEDCTXCTRL0_CTX2_FREEZE0_MASK  (0x30)
#define IPED_IPEDCTXCTRL0_CTX2_FREEZE0_SHIFT (4U)
#define IPED_IPEDCTXCTRL0_CTX3_FREEZE0_MASK  (0xC0)
#define IPED_IPEDCTXCTRL0_CTX3_FREEZE0_SHIFT (6U)

#define IPED_IPEDCTXCTRL1_CTX0_FREEZE1_MASK  (0x3)
#define IPED_IPEDCTXCTRL1_CTX0_FREEZE1_SHIFT (0U)
#define IPED_IPEDCTXCTRL1_CTX1_FREEZE1_MASK  (0xC)
#define IPED_IPEDCTXCTRL1_CTX1_FREEZE1_SHIFT (2U)
#define IPED_IPEDCTXCTRL1_CTX2_FREEZE1_MASK  (0x30)
#define IPED_IPEDCTXCTRL1_CTX2_FREEZE1_SHIFT (4U)
#define IPED_IPEDCTXCTRL1_CTX3_FREEZE1_MASK  (0xC0)
#define IPED_IPEDCTXCTRL1_CTX3_FREEZE1_SHIFT (6U)

#define IPED_IPEDCTX0IV0_CTX0_IV0_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX0IV0_CTX0_IV0_SHIFT        (0U)
#define IPED_IPEDCTX0IV1_CTX0_IV1_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX0IV1_CTX0_IV1_SHIFT        (0U)
#define IPED_IPEDCTX0START_START_ADDRESS_MASK  (0xFFFFFF00)
#define IPED_IPEDCTX0START_START_ADDRESS_SHIFT (8U)
#define IPED_IPEDCTX0END_END_ADDRESS_MASK      (0xFFFFFF00)
#define IPED_IPEDCTX0END_END_ADDRESS_SHIFT     (8U)

#define IPED_IPEDCTX1IV0_CTX1_IV0_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX1IV0_CTX1_IV0_SHIFT        (0U)
#define IPED_IPEDCTX1IV1_CTX1_IV1_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX1IV1_CTX1_IV1_SHIFT        (0U)
#define IPED_IPEDCTX1START_START_ADDRESS_MASK  (0xFFFFFF00)
#define IPED_IPEDCTX1START_START_ADDRESS_SHIFT (8U)
#define IPED_IPEDCTX1END_END_ADDRESS_MASK      (0xFFFFFF00)
#define IPED_IPEDCTX1END_END_ADDRESS_SHIFT     (8U)

#define IPED_IPEDCTX2IV0_CTX2_IV0_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX2IV0_CTX2_IV0_SHIFT        (0U)
#define IPED_IPEDCTX2IV1_CTX2_IV1_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX2IV1_CTX2_IV1_SHIFT        (0U)
#define IPED_IPEDCTX2START_START_ADDRESS_MASK  (0xFFFFFF00)
#define IPED_IPEDCTX2START_START_ADDRESS_SHIFT (8U)
#define IPED_IPEDCTX2END_END_ADDRESS_MASK      (0xFFFFFF00)
#define IPED_IPEDCTX2END_END_ADDRESS_SHIFT     (8U)

#define IPED_IPEDCTX3IV0_CTX3_IV0_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX3IV0_CTX3_IV0_SHIFT        (0U)
#define IPED_IPEDCTX3IV1_CTX3_IV1_MASK         (0xFFFFFFFF)
#define IPED_IPEDCTX3IV1_CTX3_IV1_SHIFT        (0U)
#define IPED_IPEDCTX3START_START_ADDRESS_MASK  (0xFFFFFF00)
#define IPED_IPEDCTX3START_START_ADDRESS_SHIFT (8U)
#define IPED_IPEDCTX3END_END_ADDRESS_MASK      (0xFFFFFF00)
#define IPED_IPEDCTX3END_END_ADDRESS_SHIFT     (8U)

#define IPED_BASE (0x500C042C)
#define IPED      ((IPED_Type *)IPED_BASE)
#define IPED_BASE_ADDRS \
    {                   \
        IPED_BASE       \
    }
#define IPED_BASE_PTRS \
    {                  \
        IPED           \
    }
#endif

#ifndef kStatusGroup_NBOOT_IPED
#define kStatusGroup_NBOOT_IPED 5
#endif

/*! @name Driver version */
/*@{*/
/*! @brief IPED driver version. Version 2.0.0.
 *
 * Current version: 2.0.0
 *
 * Change log:
 * - Version 2.0.0
 *   - Initial version
 */
#define FSL_IPED_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define kIPED_Region0 (0U) /*!< IPED region 0 */
#define kIPED_Region1 (1U) /*!< IPED region 1 */
#define kIPED_Region2 (2U) /*!< IPED region 2 */
#define kIPED_Region3 (3U) /*!< IPED region 3 */
typedef uint32_t iped_region_t;

#define kIPED_PrinceRounds12 (0U)
#define kIPED_PrinceRounds22 (1U)
typedef uint32_t iped_prince_rounds_t;

#define IPED_TAG 0x49

enum _iped_status
{
    kStatus_IPED_RegionIsLocked = MAKE_STATUS(kStatusGroup_NBOOT_IPED, 0x1),
};

typedef struct _flexspi_iped_region_option
{
    uint32_t iped_region : 2; // 0/1/2/3
    uint32_t reserved : 22;
    uint32_t tag : 8; // Fixed to 0x49 ('I')
} flexspi_iped_prot_region_option_t;
typedef struct _flexspi_iped_region_arg
{
    flexspi_iped_prot_region_option_t option;
    uint32_t start;
    uint32_t end;
} flexspi_iped_region_arg_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Enable data encryption.
 *
 * This function enables IPED on-the-fly data encryption.
 *
 * @param base IPED peripheral address.
 */
static inline void IPED_EncryptEnable(IPED_Type *base)
{
    base->IPEDCTRL |= IPED_IPEDCTRL_IPED_EN_MASK | IPED_IPEDCTRL_IPWR_EN_MASK | IPED_IPEDCTRL_AHBWR_EN_MASK |
                      IPED_IPEDCTRL_AHBRD_EN_MASK;
}

/*!
 * @brief Disable data encryption.
 *
 * This function disables IPED on-the-fly data encryption.
 *
 * @param base IPED peripheral address.
 */
static inline void IPED_EncryptDisable(IPED_Type *base)
{
    base->IPEDCTRL &= ~(IPED_IPEDCTRL_IPED_EN_MASK | IPED_IPEDCTRL_IPWR_EN_MASK | IPED_IPEDCTRL_AHBWR_EN_MASK |
                        IPED_IPEDCTRL_AHBRD_EN_MASK);
}

/*!
 * @brief Locks access for specified region registers or data mask register.
 *
 * This function sets lock on specified region.
 *
 * @param base IPED peripheral address.
 * @param region number to lock
 */
static inline void IPED_SetLock(IPED_Type *base, iped_region_t region)
{
    /* Unlock soft-lock first */
    base->IPEDCTXCTRL0 = (base->IPEDCTXCTRL0 & ~(IPED_IPEDCTXCTRL0_CTX0_FREEZE0_MASK << (region * 2u))) |
                         (IPED_RW_ENABLE_VAL << (region * 2u));
    /* Lock region settings */
    base->IPEDCTXCTRL1 = (base->IPEDCTXCTRL1 & ~(IPED_IPEDCTXCTRL1_CTX0_FREEZE1_MASK << (region * 2u))) |
                         (IPED_RW_DISABLE_VAL << (region * 2u));
    /* Re-enable soft-lock */
    base->IPEDCTXCTRL0 = (base->IPEDCTXCTRL0 & ~(IPED_IPEDCTXCTRL0_CTX0_FREEZE0_MASK << (region * 2u))) |
                         (IPED_RW_DISABLE_VAL << (region * 2u));
}

/*!
 * @brief Sets IPED region address range.
 *
 * This function configures IPED region address range.
 *
 * @param base IPED peripheral address.
 * @param region Selection of the IPED region to be configured.
 * @param start_address Start address for region.
 * @param end_address End address for region.
 */
status_t IPED_SetRegionAddressRange(IPED_Type *base,
                                    iped_region_t region,
                                    uint32_t start_address,
                                    uint32_t end_address);

/*!
 * @brief Gets IPED region base address.
 *
 * This function reads current start and end address settings for selected region.
 *
 * @param base IPED peripheral address.
 * @param region Selection of the IPED region to be configured.
 * @param start_address Start address for region.
 * @param end_address End address for region.
 */
status_t IPED_GetRegionAddressRange(IPED_Type *base,
                                    iped_region_t region,
                                    uint32_t *start_address,
                                    uint32_t *end_address);

/*!
 * @brief Sets the IPED region IV.
 *
 * This function sets specified AES IV for the given region.
 *
 * @param base IPED peripheral address.
 * @param region Selection of the IPED region to be configured.
 * @param iv 64-bit AES IV in little-endian byte order.
 */
status_t IPED_SetRegionIV(IPED_Type *base, iped_region_t region, const uint8_t iv[8]);

/*!
 * @brief Sets the IPED region IV.
 *
 * This function sets specified AES IV for the given region.
 *
 * @param base IPED peripheral address.
 * @param rounds Number of PRINCE rounds used during encryption/decryption
 */
static inline void IPED_SetPrinceRounds(IPED_Type *base, iped_prince_rounds_t rounds)
{
    if (rounds == kIPED_PrinceRounds12)
    {
        base->IPEDCTRL &= ~IPED_IPEDCTRL_CONFIG_MASK;
    }
    else
    {
        base->IPEDCTRL |= IPED_IPEDCTRL_CONFIG_MASK;
    }
}

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* _FSL_IPED_H_ */
