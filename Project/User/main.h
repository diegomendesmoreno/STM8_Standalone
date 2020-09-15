/**
  ******************************************************************************
  * @file    RCC/main.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    09/13/2010
  * @brief   Header for main.c module
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "gpio.h"
#include "tim.h"
#include "swim.h"
#include "auxiliar.h"
#include "stlink.h"
#include "syncsw.h"
#include "STM8_program.h"

/* ------------------------------- CONFIG ----------------------------------- */

/* Habilitar escrita na EEPROM / Enables EEPROM writting
   1 - Habilita a escrita do vetor EEPROMInit[EEP_SIZE] na EEPROM / Enables EEPROM writting
   0 - Não habilita escrita na EEPROM / Disables EEPROM writting
 */
#define W_EEPs        1

/* Habilitar Proteção de leitura (ROP) / Enables ROP (Read Out Protection)
   1 - Protege a memória FLASH contra leitura / Enables ROP (Read Out Protection)
   0 - Não protege a FLASH contra leitura / Disables ROP (Read Out Protection)
 */
#define ATIVAR_ROP    0

/* Família de microcontrolador utilizado / MCU Family
   Descomente a linha que contém a família do microcontrolador a ser gravado
   Uncomment the line that contains the STM8 family to be flashed
 */
#define STM8S001_STM8S003_STM8S103_STM8S903
//#define STM8S005_STM8S105_STM8S207_STM8S208
//#define STM8L001_STM8L101

/* -------------------------------------------------------------------------- */

/* ---------------------------- OPTION BYTES -------------------------------- */

/* Mude os Option Bytes aqui de acordo com a família usada
   Configure the Option bytes from the STM8 family to be flashed
 */

/* 
https://www.st.com/resource/en/datasheet/stm8s003f3.pdf
 */
#ifdef STM8S001_STM8S003_STM8S103_STM8S903

#define OPT1_BITS       0x00    // 0x4801 - UBC (UserBoot code size) - OPT1
#define NOPT1_BITS      0xFF    // 0x4802 - UBC (UserBoot code size) - NOPT1
#define OPT2_BITS       0x00    // 0x4803 - Alternate function remapping (AFR) - OPT2
#define NOPT2_BITS      0xFF    // 0x4804 - Alternate function remapping (AFR) - NOPT2
#define OPT3_BITS       0x00    // 0x4805 - Misc. option - OPT3
#define NOPT3_BITS      0xFF    // 0x4806 - Misc. option - NOPT3
#define OPT4_BITS       0x00    // 0x4807 - Clock option - OPT4
#define NOPT4_BITS      0xFF    // 0x4808 - Clock option - NOPT4
#define OPT5_BITS       0x00    // 0x4809 - HSE clock startup - OPT5
#define NOPT5_BITS      0xFF    // 0x480A - HSE clock startup - NOPT5

#endif

/* 
https://www.st.com/resource/en/datasheet/stm8s005c6.pdf
 */
#ifdef STM8S005_STM8S105_STM8S207_STM8S208

#define OPT1_BITS       0x00    // 0x4801 - UBC (UserBoot code size) - OPT1
#define NOPT1_BITS      0xFF    // 0x4802 - UBC (UserBoot code size) - NOPT1
#define OPT2_BITS       0x00    // 0x4803 - Alternate function remapping (AFR) - OPT2
#define NOPT2_BITS      0xFF    // 0x4804 - Alternate function remapping (AFR) - NOPT2
#define OPT3_BITS       0x00    // 0x4805 - Misc. option - OPT3
#define NOPT3_BITS      0xFF    // 0x4806 - Misc. option - NOPT3
#define OPT4_BITS       0x00    // 0x4807 - Clock option - OPT4
#define NOPT4_BITS      0xFF    // 0x4808 - Clock option - NOPT4
#define OPT5_BITS       0x00    // 0x4809 - HSE clock startup - OPT5
#define NOPT5_BITS      0xFF    // 0x480A - HSE clock startup - NOPT5
#define OPT7_BITS       0x00    // 0x480D - Flash wait states - OPT7
#define NOPT7_BITS      0xFF    // 0x480E - Flash wait states - NOPT7
#define OPTBL_BITS      0x00    // 0x480E - Bootloader - OPTBL
#define NOPTBL_BITS     0xFF    // 0x480F - Bootloader - NOPTBL

#endif

/* 
https://www.st.com/resource/en/datasheet/stm8l001j3.pdf
 */
#ifdef STM8L001_STM8L101

#define OPT2_BITS       0x00    // 0x4802 - UBC (UserBoot code size) - OPT2
#define OPT3_BITS       0x00    // 0x4803 - DATASIZE - OPT3
#define OPT4_BITS       0x00    // 0x4808 - Independent watchdog option (IWDG) - OPT4

#endif

/* -------------------------------------------------------------------------- */


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define ONE_KBYTE       1024
#define EEP_SIZE        (640)

#ifdef STM8S001_STM8S003_STM8S103_STM8S903
  #define FILE_SIZE (8*ONE_KBYTE)
#endif

#ifdef STM8S005_STM8S105_STM8S207_STM8S208
  #define FILE_SIZE (32*ONE_KBYTE)
#endif

#ifdef STM8L001_STM8L101
  #define FILE_SIZE (8*ONE_KBYTE)
#endif

/* Exported macro ------------------------------------------------------------*/
#define HSE_VALUE                       ((uint32_t)8000000)

#define _SYS_FREQUENCY                  72      // in MHz
#define _SYS_FLASH_VECTOR_TABLE_SHIFT	0x2000	// application will locate at 0x08002000
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
