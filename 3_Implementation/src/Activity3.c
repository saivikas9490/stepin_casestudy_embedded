/**
 * @file Activity3.c
 * @author Saivikas (https://github.com/saivikas9490/stepin_casestudy_embedded.git)
 * @brief 
 * @version 0.1
 * @date 2021-09-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<avr/io.h>
#include"../inc/Activity3.h"

/**
 * @brief Initializes Timer0(8-bit)
 * 
 */

void Timer_init()
{
    DDRD |= (1 << DDD6);         // PD6 is now an output

    TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);  // set none-inverting mode and set fast PWM Mode

    TCCR0B |= (1 << CS01);    // set prescaler to 8 and starts PWM
}

/**
 * @brief Activity-3 To generate PWM according to the data sensed by the ADC channel
 * 
 * @param adc_val 
 */

void Activity3(int adc_val)
{   
    Timer_init();

    if((adc_val>=0)&(adc_val<=200))
    {
        OCR0A = 51;
    }

    else if((adc_val>=210)&(adc_val<=500))
    {
        OCR0A = 128;
    }

    else if((adc_val>=510)&(adc_val<=700))
    {
        OCR0A = 179;
    }

    else if((adc_val>=710)&(adc_val<=1024))
    {
        OCR0A = 243;
    }
}