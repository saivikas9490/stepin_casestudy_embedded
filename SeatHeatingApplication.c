/**
 * @file main.c
 * @author Saivikas (https://github.com/saivikas9490/stepin_casestudy_embedded.git)
 * @brief 
 * @version 0.1
 * @date 2021-09-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>

#include"./inc/Activity1.h"
#include"./inc/Activity2.h"
#include"./inc/Activity3.h"

#define LED_ON  PORTD |= (1<<PD3)
#define LED_OFF PORTD &= ~(1<<PD3)

int main(void)
{
    uint16_t value = 0;
    
	while(1)
    {   
        Activity1();

        if ((!(PIND & (1<<PD2))) & (!(PIND & (1<<PD4))))    //LED ON or OFF  
        {
            value = Activity2(0);   //Read ADC Channel-0

            Activity3(value);
        }

        else
        OCR0A = 0x00;   //Clear compare register A when any one switch is opened
    }
    return 0;
}