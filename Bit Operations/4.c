/*Swap even and odd bits...nibbles...byte*/
#include <stdio.h>

void swap_bit(int);
void swap_nibble(int);
void swap_byte(int);
void show(int);
int main()
{
	int num;

	printf("Enter any number : ");
	scanf("%d",&num);

	show(num);
	swap_bit(num);	
	swap_nibble(num);	
	swap_byte(num);	
	return 0;
}

void show(int n)
{
	int i;

	for (i=1<<15; i>0; i=i/2)
		(n & i) ? printf("1") : printf("0");

	printf("\n");
}

void swap_bit(int n)
{
	int even, odd;

	even = n & 0xAAAA;
	even = even >> 1;
	
	odd = n & 0x5555;
	odd = odd << 1;
	
	n = odd | even ;
	show(n);
}

void swap_nibble(int n)
{
	int even, odd;

	even = n & 0xF0F0;
	even = even >> 4;
	
	odd = n & 0x0F0F;
	odd = odd << 4;
	
	n = odd | even ;
	show(n);
}

void swap_byte(int n)
{
	int even, odd;

	even = n & 0xFF00;
	even = even >> 8;
	
	odd = n & 0x00FF;
	odd = odd << 8;
	
	n = odd | even ;
	show(n);
}
