



#include "cc112x_spi.h"
#include "cc1120_config.h"
#include "utils.h"
#include "log.h"
#include "status.h"
#include "scrambler.h"
#include "cc_tx_init.h"
#include "sysview.h"
#include <string.h>

#undef __FILE_ID__
#define __FILE_ID__ 26

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
extern UART_HandleTypeDef huart5;
volatile extern uint8_t tx_thr_flag;
volatile extern uint8_t tx_fin_flag;
volatile extern uint8_t rx_sync_flag;
volatile extern uint8_t rx_finished_flag;
volatile extern uint8_t rx_thr_flag;

static uint8_t tx_frag_buf[2 + CC1120_TX_FIFO_SIZE];
static uint8_t rx_spi_tx_buf[2 + CC1120_RX_FIFO_SIZE];
static uint8_t rx_tmp_buf[2 + CC1120_RX_FIFO_SIZE];


/**
 * Delay for \p us microseconds.
 * NOTE: This delay function is not so accurate!!!
 * @param us how many microseconds to delay the execution
 */
static inline void
delay_us (uint32_t us)
{
  volatile uint32_t cycles = (SystemCoreClock / 1000000L) * us;
  volatile uint32_t start = 0;
  do {
    start++;
  }
  while (start < cycles);
}

