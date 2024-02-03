#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

unsigned char sec = 0;
unsigned char min = 0;
unsigned char hr = 0;


ISR(TIMER1_COMPA_vect)
{

	sec++;
	if(sec == 60)
	{
		sec =0;
		min++;
	}
	if(min == 60)
	{
		min = 0;
		hr++;
	}
	if(hr == 100)
	{
		hr = 0;
	}


}
ISR(INT0_vect)
{
	sec = 0;
	min = 0;
	hr = 0;
}
ISR(INT1_vect)
{
	TCCR1B &= ~(1<<CS12) & ~(1<<CS10);
}
ISR(INT2_vect)
{
	TCCR1B |= (1<<CS12) | (1<<CS10);
}
void TIMER1_int (void)
{
	TCNT1 = 0;
	OCR1A = 977;
	TCCR1A = (1<<FOC1A);
	TCCR1B = (1<<WGM12) | (1<<CS12) | (1<<CS10);
	TIMSK = (1<<OCIE1A);
}
void INT0_int (void)
{
	DDRD &= ~(1<<2);
	PORTD |= (1<<2);
	MCUCR |= (1<<ISC01);
	GICR |= (1<<INT0);
}
void INT1_int (void)
{
	DDRD &= ~(1<<3);
	MCUCR |= (1<<ISC01)|(1<<ISC11);
	GICR |= (1<<INT1);
}
void INT2_int (void)
{
	DDRB &= ~(1<<2);
	MCUCSR &= ~(1<<ISC2);
	GICR |= (1<<INT2);
}
int main(void)
{
	//ACTIVATING PINS TO DECODER
	DDRC |= 0x0f;
	PORTC = (PORTC & 0xf0) | (0x0f | 0x00);
	//ACTIVATING ENABLE PINS OF 7 SEGMENTS
	DDRA |= 0X3f;
	PORTA |= 0x00;
	//ACTIVATING INTERRUPTS
	SREG |= (1<<7);
	//INTERRUPTS INTIALIZATION
	INT0_int();
	INT1_int();
	INT2_int();
	//TIMER1 INTIALIZATION
	TIMER1_int();
	//ARRAY OF TIME
	unsigned char arr[6];
	//WHILE LOOP "PROGRAM CODE"
	while(1)
	{
		arr[0]=(sec%10);
		arr[1]=(sec/10);
		arr[2]=(min%10);
		arr[3]=(min/10);
		arr[4]=(hr%10);
		arr[5]=(hr/10);
		for (char i =0 ; i<6;i++)
		{
			PORTA = (PORTA & 0xc0) | (1<<i);
			PORTC = (PORTC & 0xf0) | arr[i];
			_delay_ms(1);
		}

	}
}



