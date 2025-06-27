#include "stdio.h"

int a;
int b;
int c;

int main ()
{
	printf("MASUKAN NILAI A : ");
	scanf("%d",&a);
	printf("MASUKAN NILAI B : ");
	scanf("%d",&b);
	c = a + b;
	printf("HASIL C : %d\n\n",c);
	
	if (a == 10)
	{
		printf("nilai a = 10");
	}
	
	else 
	{
		printf("nilai a tidak = 10");
	}
	
	printf("\n");
	
	for (int f = 0; f <=100; f++)
	{
		printf("f = %d\n",f);
	}
	
}
