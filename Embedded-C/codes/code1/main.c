#include<avr/io.h>
#include<stdbool.h>
int main(void)
{
	int x,y,z;
	bool Y1,Y2;
	bool F;

	DDRB	|=0b11111111;
	PORTD=0xFC;;
	DDRB=0b00100000;
	
	while(1)
	{
		x=(PIND &(1<<PIND2))==(1<< PIND2);
		y=(PIND &(1<<PIND3))==(1<< PIND3);
		z=(PIND &(1<<PIND4))==(1<< PIND4);
                Y1=(x^y)^z;
		Y2=x^(y^z);
		if(Y1 == Y2){
			F=1;
		        }

		PORTB=(F<<5);

	}
	return 0;
}
