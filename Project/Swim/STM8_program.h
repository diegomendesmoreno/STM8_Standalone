/**
******************************************************************************
* @file    \StandAlone\Project\Swim\STM8_program.h
* @author  Bruno Montanari
* @version V1.0.0
* @date    05/13/2011
* @brief   Main program body.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "swim.h"
#include "auxiliar.h"
#include "stlink.h"
#include "syncsw.h"

/* Private define ------------------------------------------------------------*/
#ifdef STM8S001_STM8S003_STM8S103_STM8S903
  #define FLASH_CR2       (uint32_t)0x505B
  #define FLASH_PUKR      (uint32_t)0x5062
  #define FLASH_DUKR      (uint32_t)0x5064
  #define FLASH_IAPSR     (uint32_t)0x505F
#endif

#ifdef STM8S005_STM8S105_STM8S207_STM8S208
  #define FLASH_CR2       (uint32_t)0x505B
  #define FLASH_PUKR      (uint32_t)0x5062
  #define FLASH_DUKR      (uint32_t)0x5064
  #define FLASH_IAPSR     (uint32_t)0x505F
#endif

#ifdef STM8L001_STM8L101
  #define FLASH_CR2       (uint32_t)0x5051
  #define FLASH_PUKR      (uint32_t)0x5052
  #define FLASH_DUKR      (uint32_t)0x5053
  #define FLASH_IAPSR     (uint32_t)0x5054
#endif


/* Private variables ---------------------------------------------------------*/
extern uint8 SWIM_Estado;

/* Private function prototypes -----------------------------------------------*/
void STM8_program(void);
void WriteEEPROMData(void);
extern void Error_handler(void);