/****************************************************************************
 * include/nuttx/lcd/ili9341.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __INCLUDE_NUTTX_LCD_ILI9341_H
#define __INCLUDE_NUTTX_LCD_ILI9341_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* ILI9341 ID code */

#define ILI9341_DEVICE_CODE                    0x9341

/* ILI9341 LCD Register Addresses *******************************************/

/* Level 1 commands */

#define ILI9341_NOP                            0x00 /* Nop operation */
#define ILI9341_SOFTWARE_RESET                 0x01 /* Software reset */
#define ILI9341_READ_DISP_ID                   0x04 /* Read Display Identification information */
#define ILI9341_READ_DISP_STATUS               0x09 /* Read display status*/
#define ILI9341_READ_DISP_POWER_MODE           0x0a /* Read display power mode */
#define ILI9341_READ_DISP_MADCTRL              0x0b /* Read display MADCTL */
#define ILI9341_READ_DISP_PIXEL_FORMAT         0x0c /* Read display pixel forma */
#define ILI9341_READ_DISP_IMAGE_FORMAT         0x0d /* Read display image format */
#define ILI9341_READ_DISP_SIGNAL_MODE          0x0e /* Read display signal mode */
#define ILI9341_READ_DISP_SELF_DIAGNOSTIC      0x0f /* Read display self-diagnostic result */
#define ILI9341_ENTER_SLEEP_MODE               0x10 /* Enter sleep mode */
#define ILI9341_SLEEP_OUT                      0x11 /* Sleep out */
#define ILI9341_PARTIAL_MODE_ON                0x12 /* Partial mode on */
#define ILI9341_NORMAL_DISP_MODE_ON            0x13 /* Normal display mode on */
#define ILI9341_DISP_INVERSION_OFF             0x20 /* Display inversion off */
#define ILI9341_DISP_INVERSION_ON              0x21 /* Display inversion on */
#define ILI9341_GAMMA_SET                      0x26 /* Gamma set */
#define ILI9341_DISPLAY_OFF                    0x28 /* Display off */
#define ILI9341_DISPLAY_ON                     0x29 /* Display on */
#define ILI9341_COLUMN_ADDRESS_SET             0x2a /* Column address set */
#define ILI9341_PAGE_ADDRESS_SET               0x2b /* Page address set */
#define ILI9341_MEMORY_WRITE                   0x2c /* Memory write */
#define ILI9341_COLOR_SET                      0x2d /* Color set */
#define ILI9341_MEMORY_READ                    0x2e /* Memory read */
#define ILI9341_PARTIAL_AREA                   0x30 /* Partial area */
#define ILI9341_VERT_SCROLL_DEFINITION         0x33 /* Vertical scrolling definition */
#define ILI9341_TEARING_EFFECT_LINE_OFF        0x34 /* Tearing effect line off */
#define ILI9341_TEARING_EFFECT_LINE_ON         0x35 /* Tearing effect line on */
#define ILI9341_MEMORY_ACCESS_CONTROL          0x36 /* Memory Access control */
#define ILI9341_VERT_SCROLL_START_ADDRESS      0x37 /* Vertical scrolling start address */
#define ILI9341_IDLE_MODE_OFF                  0x38 /* Idle mode off */
#define ILI9341_IDLE_MODE_ON                   0x39 /* Idle mode on */
#define ILI9341_PIXEL_FORMAT_SET               0x3a /* Pixel Format set */
#define ILI9341_WRITE_MEMORY_CONTINUE          0x3c /* Write memory continue */
#define ILI9341_READ_MEMORY_CONTINUE           0x3e /* Read memory continue */
#define ILI9341_SET_TEAR_SCANLINE              0x44 /* Set tear scanline */
#define ILI9341_GET_SCANLINE                   0x45 /* Get scanline */
#define ILI9341_WRITE_DISPLAY_BRIGHTNESS       0x51 /* Write display brightness */
#define ILI9341_READ_DISPLAY_BRIGHTNESS        0x52 /* Read display brightness */
#define ILI9341_WRITE_CTRL_DISPLAY             0x53 /* Write control display */
#define ILI9341_READ_CTRL_DISPLAY              0x54 /* Read control display */
#define ILI9341_WRITE_CONTENT_ADAPT_BRIGHTNESS 0x55 /* write content adaptive brightness control */
#define ILI9341_READ_CONTENT_ADAPT_BRIGHTNESS  0x56 /* Read content adaptive brightness control */
#define ILI9341_WRITE_MIN_CAB_LEVEL            0x5e /* Write CABC minimum brightness */
#define ILI9341_READ_MIN_CAB_LEVEL             0x5f /* Read CABC minimum brightness */
#define ILI9341_READ_ID1                       0xda /* Read ID1 */
#define ILI9341_READ_ID2                       0xdb /* Read ID2 */
#define ILI9341_READ_ID3                       0xdc /* Read ID3 */

/* Level 2 Commands */

#define ILI9341_RGB_SIGNAL_CONTROL             0xb0 /* RGB interface signal control */
#define ILI9341_FRAME_RATE_CONTROL_NORMAL      0xb1 /* Frame control */
#define ILI9341_FRAME_RATE_CONTROL_IDLE_8COLOR 0xb2 /* Frame control in idle mode */
#define ILI9341_FRAME_RATE_CONTROL_PARTIAL     0xb3 /* Frame control in partial mode */
#define ILI9341_DISPLAY_INVERSION_CONTROL      0xb4 /* Display inversion control */
#define ILI9341_BLANKING_PORCH_CONTROL         0xb5 /* Blanking porch control */
#define ILI9341_DISPLAY_FUNCTION_CTL           0xb6 /* Display function control */
#define ILI9341_ENTRY_MODE_SET                 0xb7 /* Entry mode set */
#define ILI9341_BACKLIGHT_CONTROL_1            0xb8 /* Backlight control1 */
#define ILI9341_BACKLIGHT_CONTROL_2            0xb9 /* Backlight control2 */
#define ILI9341_BACKLIGHT_CONTROL_3            0xba /* Backlight control3 */
#define ILI9341_BACKLIGHT_CONTROL_4            0xbb /* Backlight control 4 */
#define ILI9341_BACKLIGHT_CONTROL_5            0xbc /* Backlight control 5 */
#define ILI9341_BACKLIGHT_CONTROL_7            0xbe /* Backlight control 7 */
#define ILI9341_BACKLIGHT_CONTROL_8            0xbf /* Backlight control 8 */
#define ILI9341_POWER_CONTROL_1                0xc0 /* Power control 1 */
#define ILI9341_POWER_CONTROL_2                0xc1 /* Power control 2 */
#define ILI9341_VCOM_CONTROL_1                 0xc5 /* VCOM control 1 */
#define ILI9341_VCOM_CONTROL_2                 0xc7 /* VCOM control 2 */
#define ILI9341_POWER_CONTROL_A                0xcb /* Power control A */
#define ILI9341_POWER_CONTROL_B                0xcf /* Power control B */
#define ILI9341_NVMEM_WRITE                    0xd0 /* NV memory write */
#define ILI9341_NVMEM_PROTECTION_KEY           0xd1 /* NV memory protection key */
#define ILI9341_NVMEM_STATUS_READ              0xd2 /* NV memory status read */
#define ILI9341_READ_ID4                       0xd3 /* Read ID4 */
#define ILI9341_POSITIVE_GAMMA_CORRECTION      0xe0 /* Positive gamma correction */
#define ILI9341_NEGATIVE_GAMMA_CORRECTION      0xe1 /* Negative gamma correction */
#define ILI9341_DIGITAL_GAMMA_CONTROL_1        0xe2 /* Digital gamma control 1 */
#define ILI9341_DIGITAL_GAMMA_CONTROL_2        0xe3 /* Digital gamma control 2 */
#define ILI9341_DRIVER_TIMING_CTL_A            0xe8 /* Driver timing control A */
#define ILI9341_DRIVER_TIMING_CTL_B            0xea /* Driver timing control B */
#define ILI9341_POWER_ON_SEQUENCE_CONTROL      0xed /* Power-on sequence control */
#define ILI9341_ENABLE_3_GAMMA_CONTROL         0xf2 /* Enable 3g gamma control */
#define ILI9341_INTERFACE_CONTROL              0xf6 /* Interface control */
#define ILI9341_PUMP_RATIO_CONTROL             0xf7 /* Pump ration control */

/* ILI9341 LCD Register Bit Definitions *************************************/

/* Pixel format set */

#define ILI9341_PIXEL_FORMAT_SET_DPI_SHIFT     (4)
#define ILI9341_PIXEL_FORMAT_SET_DPI_MASK      (7 << ILI9341_PIXEL_FORMAT_SET_DPI_SHIFT)
#define ILI9341_PIXEL_FORMAT_SET_DPI(n)        ((n) << ILI9341_PIXEL_FORMAT_SET_DPI_SHIFT)
#define ILI9341_PIXEL_FORMAT_SET_DBI_SHIFT     (0)
#define ILI9341_PIXEL_FORMAT_SET_DBI_MASK      (7 << ILI9341_PIXEL_FORMAT_SET_DBI_SHIFT)
#define ILI9341_PIXEL_FORMAT_SET_DBI(n)        ((n) << ILI9341_PIXEL_FORMAT_SET_DBI_SHIFT)

/* Memory Access control */

#define ILI9341_MEMORY_ACCESS_CONTROL_MH       (1 << 2) /* Horizontal refresh order */
#define ILI9341_MEMORY_ACCESS_CONTROL_BGR      (1 << 3) /* RGB/BGR order */
#define ILI9341_MEMORY_ACCESS_CONTROL_ML       (1 << 4) /* Vertical refresh order */
#define ILI9341_MEMORY_ACCESS_CONTROL_MV       (1 << 5) /* Row/column exchange */
#define ILI9341_MEMORY_ACCESS_CONTROL_MX       (1 << 6) /* Column address order */
#define ILI9341_MEMORY_ACCESS_CONTROL_MY       (1 << 7) /* Row address order */

/* Display function control */

#define ILI9341_DISP_FUNC_CTL_ISC_SHIFT        (0)
#define ILI9341_DISP_FUNC_CTL_ISC_MASK         (15 << ILI9341_DISP_FUNC_CTL_ISC_SHIFT)
#  define ILI9341_DISP_FUNC_CTL_ISC(n)         ((n) << ILI9341_DISP_FUNC_CTL_ISC_SHIFT)
#define ILI9341_DISP_FUNC_CTL_SM               (1 << 4)
#define ILI9341_DISP_FUNC_CTL_SS               (1 << 5)
#define ILI9341_DISP_FUNC_CTL_GS               (1 << 6)
#define ILI9341_DISP_FUNC_CTL_REV              (1 << 7)

/* Interface function control */

#define ILI9341_INTERFACE_CONTROL_WEMODE       (1)
#define ILI9341_INTERFACE_CONTROL_BGREOR       (1 << 3)
#define ILI9341_INTERFACE_CONTROL_MVEOR        (1 << 5)
#define ILI9341_INTERFACE_CONTROL_MXEOR        (1 << 6)
#define ILI9341_INTERFACE_CONTROL_MYEOR        (1 << 7)

#define ILI9341_INTERFACE_CONTROL_MDT_SHIFT    (0)
#define ILI9341_INTERFACE_CONTROL_MDT_MASK     (3 << ILI9341_INTERFACE_CONTROL_MDT_SHIFT)
#define ILI9341_INTERFACE_CONTROL_MDT(n)       ((n) << ILI9341_INTERFACE_CONTROL_MDT_SHIFT)
#define ILI9341_INTERFACE_CONTROL_EPF_SHIFT    (4)
#define ILI9341_INTERFACE_CONTROL_EPF_MASK     (3 << ILI9341_INTERFACE_CONTROL_EPF_SHIFT)
#define ILI9341_INTERFACE_CONTROL_EPF(n)       ((n) << ILI9341_INTERFACE_CONTROL_EPF_SHIFT)

#define ILI9341_INTERFACE_CONTROL_RIM          (1)
#define ILI9341_INTERFACE_CONTROL_RM           (1 << 1)
#define ILI9341_INTERFACE_CONTROL_DM_SHIFT     (4)
#define ILI9341_INTERFACE_CONTROL_DM_MASK      (2 << ILI9341_INTERFACE_CONTROL_DM_SHIFT)
#define ILI9341_INTERFACE_CONTROL_DM(n)        ((n) << ILI9341_INTERFACE_CONTROL_DM_SHIFT)
#define ILI9341_INTERFACE_CONTROL_ENDIAN       (1 << 5)

/* Interface Mode control */

#define ILI9341_INTERFACE_CONTROL_EPL          (1)
#define ILI9341_INTERFACE_CONTROL_DPL          (1 << 1)
#define ILI9341_INTERFACE_CONTROL_HSPL         (1 << 2)
#define ILI9341_INTERFACE_CONTROL_VSPL         (1 << 3)
#define ILI9341_INTERFACE_CONTROL_RCM_SHIFT    (5)
#define ILI9341_INTERFACE_CONTROL_RCM_MASK     (2 << ILI9341_INTERFACE_CONTROL_RCM_SHIFT)
#define ILI9341_INTERFACE_CONTROL_RCM(n)       ((n) << ILI9341_INTERFACE_CONTROL_RCM_SHIFT)
#define ILI9341_INTERFACE_CONTROL_BPASS        (1 << 7)

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct ili9341_lcd_s
{
  /* Interface to control the ILI9341 lcd driver
   *
   *  - select      Select the device (as necessary) before performing any
   *                operations.
   *  - deselect    Deselect the device (as necessary).
   *  - sendcmd     Send specific command to the LCD driver.
   *  - sendparam   Send specific parameter to the LCD driver.
   *  - recvparam   Receive specific parameter from the LCD driver.
   *  - sendgram    Send pixel data to the LCD drivers gram.
   *  - recvgram    Receive pixel data from the LCD drivers gram.
   *  - backlight   Change the backlight level of the connected display.
   *                In the context of the ili9341 that means change the
   *                backlight level of the connected LED driver.
   *                The implementation in detail is part of the platform
   *                specific sub driver.
   *
   */

  void (*select)(FAR struct ili9341_lcd_s *lcd);
  void (*deselect)(FAR struct ili9341_lcd_s *lcd);
  int (*sendcmd)(FAR struct ili9341_lcd_s *lcd, const uint8_t cmd);
  int (*sendparam)(FAR struct ili9341_lcd_s *lcd, const uint8_t param);
  int (*recvparam)(FAR struct ili9341_lcd_s *lcd, uint8_t *param);
  int (*recvgram)(FAR struct ili9341_lcd_s *lcd,
                  uint16_t *wd, uint32_t nwords);
  int (*sendgram)(FAR struct ili9341_lcd_s *lcd,
                  const uint16_t *wd, uint32_t nwords);
  int (*backlight)(FAR struct ili9341_lcd_s *lcd, int level);

  /* mcu interface specific data following */
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name:  ili9341_initialize
 *
 * Description:
 *   Initialize the LCD video driver internal structure. Also initialize the
 *   lcd hardware if not done. The control of the LCD driver is depend on the
 *   selected MCU interface and part of the platform specific subdriver (see
 *   config/stm32f429i-disco/src/stm32_ili93414ws.c)
 *
 * Input Parameters:
 *
 *   lcd - A reference to the platform specific driver instance to control
 *     the ili9341 display driver.
 *   devno - A value in the range of 0 through CONFIG_ILI9341_NINTERFACES-1.
 *     This allows support for multiple LCD devices.
 *
 * Returned Value:
 *
 *   On success, this function returns a reference to the LCD driver object
 *   for the specified LCD driver. NULL is returned on any failure.
 *
 ****************************************************************************/

FAR struct lcd_dev_s *ili9341_initialize(FAR struct ili9341_lcd_s *lcd,
                                         int devno);

/****************************************************************************
 * Name:  ili9341_clear
 *
 * Description:
 *   This is a non-standard LCD interface.  Because of the various rotations,
 *   clearing the display in the normal way by writing a sequences of runs
 *   that covers the entire display can be very slow.  Here the display is
 *   cleared by simply setting all GRAM memory to the specified color.
 *
 * Input Parameters:
 *   dev   - A reference to the lcd driver structure
 *   color - The background color
 *
 * Returned Value:
 *
 *  On success - OK
 *  On error   - -EINVAL
 *
 ****************************************************************************/

int ili9341_clear(FAR struct lcd_dev_s *dev, uint16_t color);
#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __INCLUDE_NUTTX_LCD_ILI9341_H */
