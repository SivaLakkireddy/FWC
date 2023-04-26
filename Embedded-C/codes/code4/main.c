#include<avr/io.h>
#include<stdbool.h>
int main(void)
{
	int x,y;
	bool F;

	DDRB	|=0b11111111;
	PORTD=0xFC;;
	DDRB=0b00100000;
	
	while(1)
	{
		x=(PIND &(1<<PIND2))==(1<< PIND2);
		y=(PIND &(1<<PIND3))==(1<< PIND3);
	

		F=x^y;

		PORTB=(F<<5);

	}
	return 0;
}
