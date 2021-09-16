/**
 * @file Activity2.c
 * @author Saivikas (https://github.com/saivikas9490/stepin_casestudy_embedded.git)
 * @brief 
 * @version 0.1
 * @date 2021-09-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<avr/io.h>
#include"../inc/Activity2.h"

/**
 * @brief Initializes ADC Channels and its Registers
 * 
 */

void ADC_init()
{
	ADCSRA = 0x87;			// Enable ADC, fr/128 
	ADMUX = 0x40;			// Vref: Avcc, ADC channel: 0
}

/**
 * @brief Activity-2 To take data from temperature sensor through ADC channel
 * 
 * @param channel 
 * @return int 
 */

int Activity2(char channel)
{
	uint8_t Ain_High=0, Ain_Low=0;
	uint16_t Ain=0;

	ADC_init();

	ADMUX = ADMUX|(channel & 0x0F);	// Set input channel to read 

	ADCSRA |= (1<<ADSC);		// Start conversion 
	while((ADCSRA&(1<<ADIF))==0);	// Monitor end of conversion interrupt 

	Ain_Low = (int)ADCL;		// Read ADC Lower Register bytes
	Ain_High = (int)ADCH;		// Read ADC Higher Register 2 bits and Multiply with weight
					 
	Ain = (Ain_High*256) + Ain_Low;

	return(Ain);			// Return digital value
}


