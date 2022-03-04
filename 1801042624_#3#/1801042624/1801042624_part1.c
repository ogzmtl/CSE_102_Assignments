#include <stdio.h>

int sum(int n, int flag);
int mult(int n, int flag);

int main()
{
	int number,flag,first_choose,sec_choose;

	printf("Enter a integer: ");
	scanf("%d",&number);

	printf("Please enter '0' for sum '1' for multiplication :\n");
	scanf("%d",&first_choose);
	printf("Please enter '0' to work on even numbers, '1' to work an odd numbers :\n");
	scanf("%d",&sec_choose);

	switch(first_choose)
	{
		case 0 : 
			switch(sec_choose)
		{
			case 0 : sum(number,sec_choose);
			break; 
			
			case 1 : sum(number, sec_choose);
			break;
		
		default : printf("Invalid value for odd/even selection\n");
		}	
		break;

		
		case 1 :
			switch(sec_choose)
		{
			case 0 : mult(number,sec_choose);
			break; 
			
			case 1 : mult(number, sec_choose);
			break;
		
		default : printf("Invalid value for even/odd selection.\n");
		}	
		break; 
	
	default : printf("Unsported operation.\n");
	}
	

	


return 0;
}


int sum(int n, int flag)
{
	int i,add=0;

	if(flag == 0)
	{

		if(n <= 1) /*This if condition check the when the user enter 1 0 0 and 0 0 0 value to print 1 = 1 or 0 = 0 */
		{
		    printf("%d = %d\n",n,n);
		}

		if(n>1)
		{ 
		n = n - (n % 2);       /*when the number is odd and the user want to find the sum of even number (0 to number (which is odd ))*/
		printf("%d",flag);      /* this process find the end end for example if the input number is 13 n= (n -2 )% 2 operations works this way */
				       /* n = 13 - (13 % 2)--> n = 13 -1 then we will find n = 12 */
		

			for (i = flag+2 ; i <= n; i=i+2)    /* The for loop work by 12 whic we found the last step */
			{
				printf("+%d",i);
				add = add + i;
				
				if (i==n)
				{
					printf(" = %d\n", add);	/* This equality's purpose arrange the output format. */
				}
			}
		}
	}

	else
	{
		printf("%d",flag);

			for (i = flag+2 ; i <= n; i=i+2)
			{
				printf("+%d",i);
				add = add + i;
			}
				if (i==n)
				{
					printf(" = %d\n", add+flag);
				}
				else
					printf(" = %d\n",add+flag);

	}
return 0;
}


int mult(int n, int flag)
{
	int i,j=0,multi=1;   
	if (flag == 0)		
	{
		n =  n - (n % 2);
		
		if(n==2 || n == 0)      /* This if condition is special for value of 2 and zeero this condition provides the nicer output*/
		{		        /*If the user enters a 2 as an integer and their multiplication the output showns as 2 = 2 */
		printf("%d = %d",n,n);
		}

		for (i = flag+2 ; i <n; i=i+2) 	/*This for loop helps me to calculate the multiplication of numbers as and also the output view*/
			{
				printf("%d",i);	
				multi = multi * i;

				printf(" * ");
				if (i==n-2)		/*The if condition in this part is arranged the equality output view */
				{			/*If the " n - i = 2 " than this if condition works as the adding 2 to i and it arrange the output*/
					i=i+2;
					printf("%d = %d\n",i,multi*i );

				}
			}
			
	}	
	if (flag == 1)
	{
		printf("%d",flag);		/*In this part it doesn't work as like even numbers */
						/*This time I put the * beginning of the number because I printed the first odd number out of the loop*/
		for (i = flag+2 ; i <=n; i=i+2)  
		{
			printf(" * %d",i);
			multi = multi * i;

		}
			printf(" = %d \n",multi);
			
	}

return 0;
}
