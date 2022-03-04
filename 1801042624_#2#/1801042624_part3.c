#include <stdio.h>
#define dollar 6.14
#define euro 6.69

int main ()
{
	int choose,convert;
	double money;
	
		printf("***** WELCOME TO MUTLU EXCHANGE OFFICE ******\n\n");
		printf("Enter your amount:\n");
		scanf("%lf",&money);

	printf("\n\nPlease select your currency:\n1.Turkish Lira\n2.Euro\n3.Dollar\n\n");
	scanf("%d",&choose);
	
	switch(choose)
{
 		case 1: printf("You have %lf Turkish liras\n",money);
				printf("Choose which currency you want to convert :\n");
				scanf("%d",&convert);
			switch(convert)
			{
				case 1 : printf("You have %lf Turkish liras\n",money);
				break;
				
				case 2: money= money/euro;
					printf("You have %lf Euro \n",money);
				break;
				case 3: money = money/dollar; 
					printf("You have %lf Dollars\n",money);
				break;
			
				default: printf("Your selection is invalid.\n");
				
			}
		break;
		case 2: printf("You have %lf Euros\n",money);
				printf("Choose which currency you want to convert :\n");
				scanf("%d",&convert);
				
			switch(convert)
			{
				case 1 : money=money*euro;	
					 printf("You have %lf Turkish liras\n",money);
				break;
				
				
				case 2: 
					printf("You have %lf Euro \n",money);
				break;
				
			
				case 3: money = money*(euro/dollar); 
					printf("You have %lf Dollars\n",money);
				break;
		
				default: printf("Your selection is invalid.\n");
			
			}
		break;
		case 3: printf("You have %lf Dollars\n",money);
				printf("Choose which currency you want to convert :\n");
				scanf("%d",&convert);
			switch(convert)
			{
				case 1: money = money*dollar;
					printf("You have %lf Turkish liras\n",money);
				break;
				case 2: money = money * (dollar/euro);
					printf("You have %lf Euro \n",money);
				
				break;
				case 3: printf("You have %lf Dollars\n",money);
				break;
			
				default: printf("Your selection is invalid.\n");
			}
		break;
		
		default: printf("Your selection is invalid.\n");

}
		
}
