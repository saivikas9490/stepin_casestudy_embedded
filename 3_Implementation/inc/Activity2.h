/**
 * @file Activity2.h
 * @author Saivikas (https://github.com/saivikas9490/stepin_casestudy_embedded.git)
 * @brief 
 * @version 0.1
 * @date 2021-09-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _Activity2_h_
#define _Activity2_h_

/**
 * @brief Initializes ADC Channels and its Registers
 * 
 */
void ADC_init();

/**
 * @brief Activity-2 To take data from temperature sensor through ADC channel
 * 
 * @return int 
 */
int Activity2(char);

#endif