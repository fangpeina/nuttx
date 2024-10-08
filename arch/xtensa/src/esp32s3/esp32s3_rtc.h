/****************************************************************************
 * arch/xtensa/src/esp32s3/esp32s3_rtc.h
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#ifndef __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_RTC_H
#define __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_RTC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/timers/rtc.h>
#include <sys/types.h>
#include <time.h>
#include "hardware/esp32s3_soc.h"

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Number of cycles to wait from the 32k XTAL oscillator to
 * consider it running. Larger values increase startup delay.
 * Smaller values may cause false positive detection
 * (i.e. oscillator runs for a few cycles and then stops).
 */

#define SLOW_CLK_CAL_CYCLES         1024

/* Indicates that 32k oscillator gets input from external oscillator
 * instead of a crystal.
 */

#define EXT_OSC_FLAG    BIT(3)

/* Number of fractional bits in values returned by rtc_clk_cal */

#define RTC_CLK_CAL_FRACT  19

/* Cycles for RTC Timer clock source (internal oscillator) calibrate */

#define RTC_CLK_SRC_CAL_CYCLES      (10)

#define RTC_CNTL_XTL_BUF_WAIT_SLP_US        (250)
#define RTC_CNTL_PLL_BUF_WAIT_SLP_CYCLES    (1)
#define RTC_CNTL_CK8M_WAIT_SLP_CYCLES       (4)
#define RTC_CNTL_WAKEUP_DELAY_CYCLES        (4)

#define RTC_CNTL_CK8M_DFREQ_DEFAULT 100
#define RTC_CNTL_SCK_DCAP_DEFAULT   255

#define RTC_CNTL_ULPCP_TOUCH_START_WAIT_IN_SLEEP    (0xFF)
#define RTC_CNTL_ULPCP_TOUCH_START_WAIT_DEFAULT     (0x10)

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* CPU clock source */

enum esp32s3_rtc_cpu_freq_src_e
{
  RTC_CPU_FREQ_SRC_XTAL,  /* XTAL */
  RTC_CPU_FREQ_SRC_PLL,   /* PLL (480M or 320M) */
  RTC_CPU_FREQ_SRC_8M,    /* Internal 8M RTC oscillator */
};

/* Possible main XTAL frequency values.
 * Enum values should be equal to frequency in MHz.
 */

enum esp32s3_rtc_xtal_freq_e
{
  RTC_XTAL_FREQ_32M = 32,     /* 32 MHz XTAL */
  RTC_XTAL_FREQ_40M = 40,     /* 40 MHz XTAL */
};

/* RTC SLOW_CLK frequency values */

enum esp32s3_rtc_slow_freq_e
{
  RTC_SLOW_FREQ_RTC = 0,      /* Internal 150 kHz RC oscillator */
  RTC_SLOW_FREQ_32K_XTAL = 1, /* External 32 kHz XTAL */
  RTC_SLOW_FREQ_8MD256 = 2,   /* Internal 8 MHz RC oscillator, divided by 256 */
};

/* RTC FAST_CLK frequency values */

enum esp32s3_rtc_fast_freq_e
{
  RTC_FAST_FREQ_XTALD4 = 0,   /* Main XTAL, divided by 4 */
  RTC_FAST_FREQ_8M = 1,       /* Internal 8 MHz RC oscillator */
};

/* This is almost the same as esp32s3_rtc_slow_freq_e, except that we define
 * an extra enum member for the external 32k oscillator. For convenience,
 * lower 2 bits should correspond to esp32s3_rtc_slow_freq_e values.
 */

enum esp32s3_slow_clk_sel_e
{
  /* Internal 150 kHz RC oscillator */

  SLOW_CLK_150K = RTC_SLOW_FREQ_RTC,

  /* External 32 kHz XTAL */

  SLOW_CLK_32K_XTAL = RTC_SLOW_FREQ_32K_XTAL,

  /* Internal 8 MHz RC oscillator, divided by 256 */

  SLOW_CLK_8MD256 = RTC_SLOW_FREQ_8MD256,

  /* External 32k oscillator connected to 32K_XP pin */

  SLOW_CLK_32K_EXT_OSC = RTC_SLOW_FREQ_32K_XTAL | EXT_OSC_FLAG
};

/* Clock source to be calibrated using rtc_clk_cal function */

enum esp32s3_rtc_cal_sel_e
{
  RTC_CAL_RTC_MUX = 0,       /* Currently selected RTC SLOW_CLK */
  RTC_CAL_8MD256 = 1,        /* Internal 8 MHz RC oscillator, divided by 256 */
  RTC_CAL_32K_XTAL = 2,      /* External 32 kHz XTAL */
  RTC_CAL_INTERNAL_OSC = 3   /* Internal 150 kHz oscillator */
};

/* CPU clock configuration structure */

struct esp32s3_cpu_freq_config_s
{
  /* The clock from which CPU clock is derived */

  enum esp32s3_rtc_cpu_freq_src_e source;
  uint32_t source_freq_mhz;    /* Source clock frequency */
  uint32_t div;                /* Divider, freq_mhz = source_freq_mhz / div */
  uint32_t freq_mhz;           /* CPU clock frequency */
};

#ifdef CONFIG_RTC_ALARM

/* The form of an alarm callback */

typedef void (*alm_callback_t)(void *arg, unsigned int alarmid);

enum alm_id_e
{
  RTC_ALARM0 = 0,           /* RTC ALARM 0 */
  RTC_ALARM1 = 1,           /* RTC ALARM 1 */
  RTC_ALARM_LAST,
};

/* Structure used to pass parameters to set an alarm */

struct alm_setalarm_s
{
  int               as_id;     /* enum alm_id_e */
  struct timespec   as_time;   /* Alarm expiration time */
  alm_callback_t    as_cb;     /* Callback (if non-NULL) */
  void              *as_arg;   /* Argument for callback */
};

#endif /* CONFIG_RTC_ALARM */

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: esp32s3_rtc_clk_slow_freq_get
 *
 * Description:
 *   This function gets the frequency of the slow clock from the RTC.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   The frequency of the slow clock from the RTC.
 *
 ****************************************************************************/

int esp32s3_rtc_clk_slow_freq_get(void);

/****************************************************************************
 * Name: esp32s3_rtc_clk_slow_freq_get_hz
 *
 * Description:
 *   Get the approximate frequency of RTC_SLOW_CLK, in Hz
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   slow_clk_freq - RTC_SLOW_CLK frequency, in Hz
 *
 ****************************************************************************/

uint32_t esp32s3_rtc_clk_slow_freq_get_hz(void);

/****************************************************************************
 * Name: esp32s3_rtc_clk_fast_freq_get_hz
 *
 * Description:
 *   Get fast_clk_rtc source in Hz.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   The clock source in Hz.
 *
 ****************************************************************************/

uint32_t esp32s3_rtc_clk_fast_freq_get_hz(void);

/****************************************************************************
 * Name: esp32s3_rtc_get_slow_clk_rtc
 *
 * Description:
 *   Get slow_clk_rtc source.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   The clock source:
 *   -  SLOW_CK
 *   -  CK_XTAL_32K
 *   -  CK8M_D256_OUT
 *
 ****************************************************************************/

enum esp32s3_rtc_slow_freq_e esp32s3_rtc_get_slow_clk(void);

/****************************************************************************
 * Name: esp32s3_rtc_clk_cal
 *
 * Description:
 *   Measure RTC slow clock's period, based on main XTAL frequency
 *
 * Input Parameters:
 *   cal_clk        - clock to be measured
 *   slowclk_cycles - number of slow clock cycles to average
 *
 * Returned Value:
 *   Average slow clock period in microseconds, Q13.19 fixed point format
 *   or 0 if calibration has timed out
 *
 ****************************************************************************/

uint32_t esp32s3_rtc_clk_cal(enum esp32s3_rtc_cal_sel_e cal_clk,
                             uint32_t slowclk_cycles);

/****************************************************************************
 * Name: esp32s3_rtc_clk_xtal_freq_get
 *
 * Description:
 *   Get main XTAL frequency
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   XTAL frequency (one of enum esp32s3_rtc_xtal_freq_e values)
 *
 ****************************************************************************/

enum esp32s3_rtc_xtal_freq_e esp32s3_rtc_clk_xtal_freq_get(void);

/****************************************************************************
 * Name: esp32s3_rtc_update_to_xtal
 *
 * Description:
 *   Switch to XTAL frequency, does not disable the PLL
 *
 * Input Parameters:
 *   freq -  XTAL frequency
 *   div  -  REF_TICK divider
 *
 * Returned Value:
 *   none
 *
 ****************************************************************************/

void esp32s3_rtc_update_to_xtal(int freq, int div);

/****************************************************************************
 * Name: esp32s3_rtc_clk_set
 *
 * Description:
 *   Set RTC CLK frequency.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_clk_set(void);

/****************************************************************************
 * Name: esp32s3_rtc_init
 *
 * Description:
 *   Initialize RTC clock and power control related functions.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_init(void);

/****************************************************************************
 * Name: esp32s3_rtc_time_get
 *
 * Description:
 *   Get current value of RTC counter.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   current value of RTC counter
 *
 ****************************************************************************/

uint64_t esp32s3_rtc_time_get(void);

/****************************************************************************
 * Name: esp32s3_rtc_sleep_low_init
 *
 * Description:
 *   Low level initialize for rtc state machine waiting
 *   cycles after waking up.
 *
 * Input Parameters:
 *   slowclk_period - Re-calibrated slow clock period
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_sleep_low_init(uint32_t slowclk_period);

/****************************************************************************
 * Name: esp32s3_rtc_time_us_to_slowclk
 *
 * Description:
 *   Convert time interval from microseconds to RTC_SLOW_CLK cycles.
 *
 * Input Parameters:
 *   time_in_us      - Time interval in microseconds
 *   slow_clk_period -  Period of slow clock in microseconds
 *
 * Returned Value:
 *   number of slow clock cycles
 *
 ****************************************************************************/

uint64_t esp32s3_rtc_time_us_to_slowclk(uint64_t time_in_us,
                                        uint32_t period);

/****************************************************************************
 * Name: esp32s3_rtc_time_slowclk_to_us
 *
 * Description:
 *   Convert time interval from RTC_SLOW_CLK to microseconds
 *
 * Input Parameters:
 *   rtc_cycles - Time interval in RTC_SLOW_CLK cycles
 *   period     - Period of slow clock in microseconds
 *
 * Returned Value:
 *   Time interval in microseconds
 *
 ****************************************************************************/

uint64_t esp32s3_rtc_time_slowclk_to_us(uint64_t rtc_cycles,
                                        uint32_t period);

/****************************************************************************
 * Name: esp32s3_clk_slowclk_cal_get
 *
 * Description:
 *   Get the calibration value of RTC slow clock.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   the calibration value obtained using rtc_clk_cal
 *
 ****************************************************************************/

uint32_t esp32s3_clk_slowclk_cal_get(void);

/****************************************************************************
 * Name: esp32s3_rtc_sleep_set_wakeup_time
 *
 * Description:
 *   Set target value of RTC counter for RTC_TIMER_TRIG_EN wakeup source.
 *
 * Input Parameters:
 *   t - value of RTC counter at which wakeup from sleep will happen.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_sleep_set_wakeup_time(uint64_t t);

/****************************************************************************
 * Name: esp32s3_rtc_wait_for_slow_cycle
 *
 * Description:
 *   Busy loop until next RTC_SLOW_CLK cycle.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   none
 *
 ****************************************************************************/

void esp32s3_rtc_wait_for_slow_cycle(void);

/****************************************************************************
 * Name: esp32s3_rtc_cpu_freq_set_xtal
 *
 * Description:
 *   Switch CPU clock source to XTAL
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_cpu_freq_set_xtal(void);

/****************************************************************************
 * Name: esp_rtc_clk_get_cpu_freq
 *
 * Description:
 *   Get the currently used CPU frequency configuration.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   CPU frequency
 *
 ****************************************************************************/

int esp_rtc_clk_get_cpu_freq(void);

/****************************************************************************
 * Name: esp32s3_rtc_sleep_init
 *
 * Description:
 *   Prepare the chip to enter sleep mode
 *
 * Input Parameters:
 *   flags - sleep mode configuration
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_sleep_init(uint32_t flags);

/****************************************************************************
 * Name: esp32s3_rtc_sleep_start
 *
 * Description:
 *   Enter force sleep mode.
 *
 * Input Parameters:
 *   wakeup_opt - bit mask wake up reasons to enable
 *   reject_opt - bit mask of sleep reject reasons.
 *
 * Returned Value:
 *   non-zero if sleep was rejected by hardware
 *
 ****************************************************************************/

int esp32s3_rtc_sleep_start(uint32_t wakeup_opt, uint32_t reject_opt);

/****************************************************************************
 * Name: esp32s3_rtc_get_time_us
 *
 * Description:
 *   Get current value of RTC counter in microseconds
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Current value of RTC counter in microseconds
 *
 ****************************************************************************/

uint64_t esp32s3_rtc_get_time_us(void);

/****************************************************************************
 * Name: esp32s3_rtc_set_boot_time
 *
 * Description:
 *   Set time to RTC register to replace the original boot time.
 *
 * Input Parameters:
 *   time_us - set time in microseconds.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_set_boot_time(uint64_t time_us);

/****************************************************************************
 * Name: esp32s3_rtc_get_boot_time
 *
 * Description:
 *   Get time of RTC register to indicate the original boot time.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   time_us - get time in microseconds.
 *
 ****************************************************************************/

uint64_t esp32s3_rtc_get_boot_time(void);

/****************************************************************************
 * Name: esp32s3_rtc_clk_cpu_freq_set_config
 *
 * Description:
 *   Set CPU frequency configuration.
 *
 * Input Parameters:
 *   config - CPU frequency configuration
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32s3_rtc_clk_cpu_freq_set_config(
               const struct esp32s3_cpu_freq_config_s *config);

/****************************************************************************
 * Name: esp32s3_rtc_clk_cpu_freq_get_config
 *
 * Description:
 *   Get the currently used CPU frequency configuration.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   CPU clock configuration structure
 *
 ****************************************************************************/

void esp32s3_rtc_clk_cpu_freq_get_config(
             struct esp32s3_cpu_freq_config_s *out_config);

/****************************************************************************
 * Name: esp32s3_rtc_recalib_bbpll
 *
 * Description:
 *   Re-calibration BBPLL, workaround for bootloader not calibration well
 *   issue.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

#ifdef CONFIG_ESP32S3_SYSTEM_BBPLL_RECALIB
void esp32s3_rtc_recalib_bbpll(void);
#endif

#ifdef CONFIG_RTC_DRIVER

/****************************************************************************
 * Name: up_rtc_time
 *
 * Description:
 *   Get the current time in seconds.  This is similar to the standard time()
 *   function.  This interface is only required if the low-resolution
 *   RTC/counter hardware implementation selected.  It is only used by the
 *   RTOS during initialization to set up the system time when CONFIG_RTC is
 *   set but neither CONFIG_RTC_HIRES nor CONFIG_RTC_DATETIME are set.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   The current time in seconds
 *
 ****************************************************************************/

#ifndef CONFIG_RTC_HIRES
time_t up_rtc_time(void);
#endif

/****************************************************************************
 * Name: up_rtc_settime
 *
 * Description:
 *   Set the RTC to the provided time.  All RTC implementations must be
 *   able to set their time based on a standard timespec.
 *
 * Input Parameters:
 *   tp - the time to use
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

int up_rtc_settime(const struct timespec *ts);

/****************************************************************************
 * Name: up_rtc_initialize
 *
 * Description:
 *   Initialize the hardware RTC per the selected configuration.
 *   This function is called once during the OS initialization sequence
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

int up_rtc_initialize(void);

/****************************************************************************
 * Name: up_rtc_gettime
 *
 * Description:
 *   Get the current time from the high resolution RTC clock/counter.  This
 *   interface is only supported by the high-resolution RTC/counter hardware
 *   implementation.  It is used to replace the system timer.
 *
 * Input Parameters:
 *   tp - The location to return the high resolution time value.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

#ifdef CONFIG_RTC_HIRES
int up_rtc_gettime(struct timespec *tp);
#endif

#ifdef CONFIG_RTC_ALARM

/****************************************************************************
 * Name: up_rtc_setalarm
 *
 * Description:
 *   Set up an alarm.
 *
 * Input Parameters:
 *   alminfo - Information about the alarm configuration.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

int up_rtc_setalarm(struct alm_setalarm_s *alminfo);

/****************************************************************************
 * Name: up_rtc_cancelalarm
 *
 * Description:
 *   Cancel an alaram.
 *
 * Input Parameters:
 *  alarmid - Identifies the alarm to be cancelled
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

int up_rtc_cancelalarm(enum alm_id_e alarmid);

/****************************************************************************
 * Name: up_rtc_rdalarm
 *
 * Description:
 *   Query an alarm configured in hardware.
 *
 * Input Parameters:
 *  tp      - Location to return the timer match register.
 *  alarmid - Identifies the alarm to be cancelled
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

int up_rtc_rdalarm(struct timespec *tp, uint32_t alarmid);

#endif /* CONFIG_RTC_ALARM */

/****************************************************************************
 * Name: up_rtc_timer_init
 *
 * Description:
 *   Init RTC timer.
 *
 * Input Parameters:
 *  None
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

int up_rtc_timer_init(void);

#endif /* CONFIG_RTC_DRIVER */

#ifdef __cplusplus
}
#endif
#undef EXTERN

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_RTC_H */
