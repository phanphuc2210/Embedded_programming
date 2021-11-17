
#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

// Ham gui data/cmd ra 8 chan cua LCD
void send8BitLCD(char D) {
	// Dem D and so hoc voi 2^i de biet bit thu i =0 hay khac ko
	// tim gia tri cac bit
	int b0,b1,b2, b3,b4, b5, b6, b7;
  if ((D & 1) == 0)  b0=0;              // 1== 2^0
  else b0 =1;
  if ((D & 2) == 0)  b1=0;              // 2== 2^1
  else b1 =1;
  if ((D & 4) == 0)  b2=0;              // 4== 2^2
  else b2 =1;
  if ((D & 8) == 0)  b3=0;              // 8== 2^3
  else b3 =1;
  if ((D & 16) == 0)  b4=0;              // 16== 2^4
  else b4 =1;
  if ((D & 32) == 0)  b5=0;              // 32== 2^5
  else b5 =1;
  if ((D & 64) == 0)  b6=0;              // 64== 2^6
  else b6 =1;
  if ((D & 128) == 0)  b7=0;              // 128== 2^7
  else b7 =1;
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0, b0);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1, b1);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2, b2);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_3, b3);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4, b4);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5, b5);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6, b6);
  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7, b7);
}

// Ham gui lenh
void sendCMD2LCD(char cmd) {
	//B1. Done
	//B2. Dat chan RS =0, de noi rang cmd  là lenh
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,  GPIO_PIN_RESET);
	//B3. Gui 8 bit CMD vao 8 pin
	send8BitLCD(cmd);
	//B4. Enable cho cmd-->lcd
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,  GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,  GPIO_PIN_SET);
	//
	HAL_Delay(1);
}

// Ham gui ky tu hien thi
void sendChar2LCD(char Char) {
	//B1. Done
	//B2. Dat chan RS =1,  
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,  GPIO_PIN_SET);
	//B3. Gui 8 bit CMD vao 8 pin
	send8BitLCD(Char);
	//B4. Enable cho cmd-->lcd
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,  GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,  GPIO_PIN_SET);
	//
	HAL_Delay(1);
}

// Chuyen so thanh ky tu
int itoa(int value,char *ptr)
     {
        int count=0,temp;
        if(ptr==NULL)
            return 0;   
        if(value==0)
        {   
            *ptr='0';
            return 1;
        }

        if(value<0)
        {
            value*=(-1);    
            *ptr++='-';
            count++;
        }
        for(temp=value;temp>0;temp/=10,ptr++);
        *ptr='\0';
        for(temp=value;temp>0;temp/=10)
        {
            *--ptr=temp%10+'0';
            count++;
        }
        return count;
     }

void sendString2LCD(char *str) {
   for (int i=0; str[i] != '\0';  i++) {
			sendChar2LCD(str[i]);
   } 	
}


int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
	
	// Xoa noi dung tren LCD
   sendCMD2LCD(0x01);	
	 // Bat hien thi man hinh, tat con tro
	 sendCMD2LCD(0x0C);	
	 // Test thu chuoi Hello
	 sendString2LCD("Hello K61 NTU");	
	 // Xuong dong 2
	 sendCMD2LCD(0x38);   // CHE DO 2 DONG
	 sendCMD2LCD(0xC0);	  // TRO XUONG DONG 2 
	 sendString2LCD("PHAN PHUC ");	
	 char str[10];
   itoa(333,str);
   sendString2LCD(str);
		
	
	 HAL_Delay(1000);
 
  while (1)
  {
    
  }
  
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD0 PD1 PD2 PD3
                           PD4 PD5 PD6 PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
