/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LEDtask */
osThreadId_t LEDtaskHandle;
const osThreadAttr_t LEDtask_attributes = {
  .name = "LEDtask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128
};
/* Definitions for USBtask */
osThreadId_t USBtaskHandle;
const osThreadAttr_t USBtask_attributes = {
  .name = "USBtask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128
};
/* Definitions for Buzzertask */
osThreadId_t BuzzertaskHandle;
const osThreadAttr_t Buzzertask_attributes = {
  .name = "Buzzertask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128
};
/* Definitions for Servotask */
osThreadId_t ServotaskHandle;
const osThreadAttr_t Servotask_attributes = {
  .name = "Servotask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128
};
/* Definitions for Buttontask */
osThreadId_t ButtontaskHandle;
const osThreadAttr_t Buttontask_attributes = {
  .name = "Buttontask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void LEDtask_entry(void *argument);
void USBtask_entry(void *argument);
void Buzzertask_entry(void *argument);
void Servotask_entry(void *argument);
void Buttontask_entry(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LEDtask */
  LEDtaskHandle = osThreadNew(LEDtask_entry, NULL, &LEDtask_attributes);

  /* creation of USBtask */
  USBtaskHandle = osThreadNew(USBtask_entry, NULL, &USBtask_attributes);

  /* creation of Buzzertask */
  BuzzertaskHandle = osThreadNew(Buzzertask_entry, NULL, &Buzzertask_attributes);

  /* creation of Servotask */
  ServotaskHandle = osThreadNew(Servotask_entry, NULL, &Servotask_attributes);

  /* creation of Buttontask */
  ButtontaskHandle = osThreadNew(Buttontask_entry, NULL, &Buttontask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_LEDtask_entry */
/**
  * @brief  Function implementing the LEDtask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_LEDtask_entry */
__weak void LEDtask_entry(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN LEDtask_entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END LEDtask_entry */
}

/* USER CODE BEGIN Header_USBtask_entry */
/**
* @brief Function implementing the USBtask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_USBtask_entry */
__weak void USBtask_entry(void *argument)
{
  /* USER CODE BEGIN USBtask_entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END USBtask_entry */
}

/* USER CODE BEGIN Header_Buzzertask_entry */
/**
* @brief Function implementing the Buzzertask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Buzzertask_entry */
__weak void Buzzertask_entry(void *argument)
{
  /* USER CODE BEGIN Buzzertask_entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Buzzertask_entry */
}

/* USER CODE BEGIN Header_Servotask_entry */
/**
* @brief Function implementing the Servotask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Servotask_entry */
__weak void Servotask_entry(void *argument)
{
  /* USER CODE BEGIN Servotask_entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Servotask_entry */
}

/* USER CODE BEGIN Header_Buttontask_entry */
/**
* @brief Function implementing the Buttontask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Buttontask_entry */
__weak void Buttontask_entry(void *argument)
{
  /* USER CODE BEGIN Buttontask_entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Buttontask_entry */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
