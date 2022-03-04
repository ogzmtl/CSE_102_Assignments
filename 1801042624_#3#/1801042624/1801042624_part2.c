#include <stdio.h>
#include <math.h>

int isprime(int a);

int main ()
{

	int number,i,check;

		printf("Please enter an integer : ");
		scanf("%d",&number);

		printf("2 is a prime number. \n");
		for ( i = 3; i < number; i++)
		{
			check = isprime(i);
			if(check == 0)
			{
				printf("\n%d is a prime number. \n",i);
			}
			else
			{
				printf("\n%d is not a prime number. It is dividible by %d \n",i,check);
			}
		}
}

int isprime(int a)
{
	int j,control_prime=0;
	double b;

	b = sqrt(a);
	b = floor(b);    /*This process change the double value to an integer value */
			for ( j = b ; j > 1 ; j = j-1)
			{     /*The reason of decreasing is, if the number dividible by lower value then change this check value = lower one*/
			
				if (a % j == 0)  /* If the loop value enters this condition the check value turns " j " and return main as j */
				{		
					control_prime = j ;
				}
			}

return control_prime;
}
