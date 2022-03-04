#include <stdio.h>
#include <math.h>

int number_lenght(int number);
int find_digit(int number, int index);

int main () {
	
	int number,leng_digit,wanted,b;
		
	printf("Enter a number ( max 6 digits ):");
	scanf("%d",&number);
	
	leng_digit=number_lenght(number);
	if(leng_digit != -1)
	printf("Your number has %d digits \n",leng_digit);
	else 
	{
	printf("Your number has more than 6 digits. Please enter max 6 digits.\n");
	main();
	}	
	
	printf("\nWhen your number is written 100 times next to eaach other, which digit of this number would you like to see ? \n:");
	scanf("%d",&wanted);
	
	b = find_digit(number,wanted);
	printf("%d.th digit of the big number sequence : %d\n",wanted,b);
	
return 0;
}
int number_lenght(int number)
{
	int a=0;
	if(number >= pow(10,6))		/*BASIC IDEA IS I DIVIDE NUMBER BY TEN THEN ASSIGN THE NUMBER WİTH THIS VALUE AND INCREASE A KIND OF COUNTER */
	{				/*THEN IF THE VALUE IS ZERO I RETURN THE VALUE WHICH WE INCREASED BEFORE */
	     return -1;			/*IF WE HAVE 6 DIGIT NUMBER WE DIVIDE THE NUMBER 6 TIMES AND INCREASE THE COUNTER 6 STEPS COUNTER = 6 */
	}				/*RETURN THE COUNTER VALUE BY THE 6*/
					/*THE NUMBER IS GREATER THAN 6 DIGITS THEN OUR FUNCTION RETURNES -1 VALUE AND -1 FINISHES THE PROGRAM*/
	number = number/10;
	a      = a+1;
	if(number == 0)
	{
	     return (a);
	}

	number = number/10;
	 a     = a+1;
	if(number == 0)
	{
	     return (a);
	}

	number = number/10;
	a      = a+1;
	if(number == 0)
	{
	     return (a);
	}

	number = number/10;
	 a     = a+1;
	if(number == 0)
	{
	     return (a);
	}

	number = number/10;
	 a     = a+1;
	if(number == 0)
	{
	     return (a);
	}

	number = number/10;
	a      = a+1;
	
return a;
}

int find_digit (int number, int index)
{	int check,mod_index,a,b,c,d,e,f,assign;

	check = number_lenght(number);
	    mod_index=index % check;		

	if(mod_index == 1)	                 /*FIRST OF ALL I SUBSTRACT MOD OF INDEX TO NUMBER OF LENGHT WHICH NAME IS CHECK.*/
	{					 /*THEN I TAKE POWER OF TEN WITH ("a")AND ASSIGN THIS VALUE TO "a"*/
		a = check-mod_index;		 /*FINALLY I DIVIDE THE NUMBER WITH "a" AND TAKE THE MOD WİTH 10 */
		a= pow(10,a);
		assign =( number / a ) % 10;
	}
	if(mod_index == 2)
	{					/*FOR INSTANCE OUR NUMBER IS 432.567 AND INDEX = 61 */
		a = check-mod_index;		/*1.OUR NUMBERS LENGHT HAS 6 DIGITS */
		a= pow(10,a);			/*2.THEN OUR INDEX 61  TAKE THE MOD WİTH 6 61 % 6 = 1*/					
		assign =( number / a ) % 10;	/*3.THEN WE SUBSTRACT WITH DIGIT OF OUR NUMBER WİTH MOD_INDEX (LENGHT OF NUMBER - MOD )) 6-1= 5 */
	}					/*4.THIS SUBSTRACTION'S ASSIGN POWER OF TEN = 10^5 */
	if(mod_index == 3)			/*5.THEN I DIVIDE THE NUMBER WITH THIS POWER OF TEN AND FINALLY WE TAKE THE MOD WITH TEN */
	{					/* 432.567 / 10^5 = ASSIGN*/
		a = check-mod_index;		/* ASSIGN=4 THEN WE TAKE THE MOD 10 --> 4 % 10 = 4*/
		a= pow(10,a);			/*6.FINALLY WE RETURN THE ASSIGN VALUE TO MAIN FUNCTION*/
		assign =( number / a ) % 10;
	}
	if(mod_index == 4)
	{
		a = check-mod_index;
		a= pow(10,a);
		assign =( number / a ) % 10;
	}
	if(mod_index == 5)
	{
		a = check-mod_index;
		a= pow(10,a);
		assign =( number / a ) % 10;
	}
	if(mod_index == 0)
	{
 	      assign = number % 10;
	}
return assign;
}














