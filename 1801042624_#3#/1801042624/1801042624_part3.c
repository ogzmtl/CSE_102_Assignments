#include <stdio.h>

int find_digit(int a, int b); /* integer lenght of digit function */
int check_bin(int a,int b);   /* controlling function the number whether binary or not*/
int pow_find_ten(int a, int b); /* find the pow of ten instead of using math.h library */

int andop(int a, int b); 

int main()
{
	int first,second,lenght,binary,and_operation;

		printf("Enter first integer:  ");
		scanf("%d",&first);
		printf("Enter second integer: ");
		scanf("%d",&second);

		lenght=find_digit(first,second);
		binary=check_bin(first,second);
		if (lenght != -1  )
		{
			if (binary != -1)
			{
				and_operation = andop(first,second);
				printf("%d AND %d = %d \n",first, second, and_operation);
			}
			else
			{
				printf("Your number should be binary, please enter 2 new integers\n");
				main();
			}
		}
		else
		{
			printf("Your integers have to be same lenght, please enter 2 new integers.\n");
			main();
		}


return 0;
}

int find_digit(int a, int b)
{
	int counter_a=1,counter_b=1,check;

		if(a==0)    /*These if conditions check the one digit numbers like / 1 AND 0 = 0 / /1 AND 1 = 0 / /0 AND 0 = 0/ */
		counter_a++;
		if(b==0)
		counter_b++;		
		
		while(a!=0) /*This conditions count the lenght of integers by dividing 10*/
		{
			counter_a++;
			a /= 10;

		}
		while(b!=0)
		{
			counter_b++;
			b /= 10;

		}
		if(counter_b == counter_a)    /*this condition controls the counters whether the counters same or not*/
		{
			check = counter_a;
		} 
		else              	      /*these counters are not equal than function returns -1 value to error print*/
			check = -1;
return check;
}

int check_bin(int a,int b)
{
	int mod,check=1;
       
		while (a != 0)	/*If the mod of first value's steps greater than 1 than function returns -1 value*/
		{
			mod = a % 10;  
			a /= 10;
			if (mod >= 2)
			{
				check = -1;
			}

		}
       
		while (b != 0)
		{
			mod = b % 10;  
			b /= 10;
			if (mod >= 2)
			{
				check = -1;
			}

		}
return check;
}

int pow_find_ten(int a, int b)
{
    int ten_pow=1;
     
	while( a !=b ) /*This function calculates the power of ten from a to b */
	    {
	    	ten_pow *= 10;
	    	a++;
	    }
return ten_pow;
}


int andop(int a, int b)
{
	int check,x,pow_counter=1,number=0;

		check = a + b;  
	
		while(check != 0)	/*the while works */
		{			/*I add two numbers because the input changes 1 or 0 so sum of these numbers not higher than 9 */
			x = check % 10; /*Then I divide these result "check" and take this value's mod */ 
			if (x == 2 )	/*If the mod = 2 then our ones step is 1 (1 AND 1 = 1 ) */
			{		/*Then if the step is 1 I hold the counter to calculate which step is this */
					/*If step ( ones step ) is 1 than  pow_counter = 1 , if the counter = 2 then the step is tens step... */
				x = 1;
				x = pow_find_ten(x,pow_counter);
				number = x + number;
			}
			else if(x == 1|| x == 0) /* If the mod of check value is 1 or 0 these condition not doing anything*/
			{			/*then it moves out of this condition and increase the counter (power counter)*/
			x = 0;			 /*Finally divide the value by 10 move to another step's mod */
			}
			pow_counter++;	
			check /= 10 ; 
		}
		
return (number);
}
