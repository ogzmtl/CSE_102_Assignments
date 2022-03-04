#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
struct Hospital			     /*NOTE TO TEACHER*/
{    /*There is some mistake in saving combination in the location which I didn't fix when hospital number is 4 the program running incorretcly*/	
char* name;
char citiesServed[3];
};
	struct card {
		const char *face;
		const char *suit;
	};

int numPathsHome(int street, int avenue);
int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]);
void shuffle_card(struct card deck[52]);

int city_comparison(char cit[6],char locc[4][3],int num_hospital);/*Helper function of 2.part compare the cities with locations*/
void all_combinations_loc(char location[4][3],int num_hospital);/*Helper function of 2.part calculates all possibilities of combination*/
void print_hospitals(struct Hospital hospital[4],int index, char location[4][3]);

int same_or_not(int rand_num[52],int index );/*Helper function of 3.part*/
void menu();

int main (){

	menu();
	
return 0;		
}
void menu (){
	struct Hospital hosp_res[4];
	struct card all_card[52];
	
  char arr[4][3]={{"ABC"},{"ACD"},{"BF"},{"CEF"}};
  char cities[6] = {"ABCDEF"};
  	int return_value; /*returning value of canOfferCovidCourage function*/
  	int num;/*ınput number of number of hospitals*/
	
	int aven,street;/*part1's avenue and street number*/
	int b ;/*returning value of numPathsHome function*/
	int s;/*Menu control number*/
	
		while(s != 4)
		{
			printf(" 1)PART 1\n 2)PART 2\n 3)PART 3\n 4)EXIT\n");
			scanf("%d",&s);
			
			switch(s)
			{
				case 1: 
					printf("Enter the street number : ");
					scanf("%d",&street);
					printf("street : %d\n",street);
							
					printf("Enter a avenue number :  ");
					scanf("%d",&aven);
					printf("avenue : %d\n",aven);
			
					b = numPathsHome(street+aven-2,aven-1);//I accet the origin point as (1,1)
					printf("Number of optimal paths to take back home : %d\n\n",b);
				break;
				case 2: 
  			  		 
  			  		 printf("Enter the maximum numbers of the hospital that can be constructed :");
 					 scanf("%d",&num);
  					 return_value = canOfferCovidCoverage(cities,arr,num,hosp_res);
  					   
  					   if(return_value == 1)print_hospitals(hosp_res,num,arr);
  					   else printf("No, some cities aren't covered. \n");
						s = 4;
							
				break;
				
				case 3 :
					printf("\nDeck is shuffling...Please wait...\n\n");
					printf("Completed ...\n\n");
					shuffle_card(all_card);
				
				break; 
				
				case 4: printf("\nHave a healthy day...\n");
				break;
				
				default:  printf("\nInvalid\n");
				break;	
			}	
		}
}

int numPathsHome(int street, int avenue){/*In this function street = (street + avenue)*/
 								/*this function works as recursive combination for instance 7! / (3!*4!)*/
 double a;						/*7! / 4! == 7! / 3! so we can hold one of this street or avenue value to operation*/
   		if(street == avenue) return 1;		
 		a =street-avenue;
return (double) (street/a)*numPathsHome(street-1,avenue);			
}

int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,struct Hospital results[4]){

int a,val=0;
int k=0 ;

 	 a = city_comparison(_cities,_locations,_numHospitals);
  
		if(a == 1) return 1;   
		
		else{ 
	      	  static int b;
		      if(b == 12) return 0;
	      b++;
	      all_combinations_loc(_locations,_numHospitals);
	      a = canOfferCovidCoverage(_cities,_locations,_numHospitals,results);
	    }
return a;
}

void shuffle_card(struct card deck[52]){

	char face_card[13][20] = {{"Ace"}, {"Deuce"}, {"Three"}, {"Four"}, {"Five"}, {"Six"}, {"Seven"}, {"Eight"}, {"Nine"}, {"Ten"}, {"Jack"}, {"Queen"}, {"King"}};
	char suit_card[4][20] = {{"Hearts"},{"Diamonds"},{"Clubs"},{"Spades"}};
	int i=0,j=0;
	int random_number[52],check;
	
	srand(time(NULL));
	
		while(i < 52)
		{
			random_number[i] = rand() % 52;
			check = same_or_not(random_number,i);/*if any of the random numbers are the same then check will be 0 otherwise check = 1 */
			
			if(check == 1) {
				
					deck[random_number[i]].face = face_card[i%13];
					deck[random_number[i]].suit = suit_card[j];
				i++;
				if(i % 13 == 0)j++;
			}			
		}
	printf("\n");
	
	for(i = 0 ; i < 52 ; i++)
	{
		printf("    %s of %s\t\t ",deck[i].face,deck[i].suit);
		i++;
		printf("\t   %s of %s\n",deck[i].face,deck[i].suit);
	}
}
int same_or_not(int rand_num[52],int index){

	for(int j = 0 ; j < index ; j++)/*ın this function all the rand numbers must be different*/
	{
		if(rand_num[j] == rand_num[index]) return 0;
	}

return 1;
}
int city_comparison(char cit[6],char locc[4][3], int num_hospital){

	int i,counter=0 ;
	char helper[12];/*save the cities to compare in a helper array which size of all cities 4*3 = 12 */

	  for( i = 0; i < num_hospital ; i++ ){
	
    	  for(int j = 0 ; j < 3 ; j++)
    	  {
    	      if(num_hospital == 2)
    	      {
    	        
    	        if(locc[i+1][j]=='\0') ;
    	        else helper[j+(3*i)]=locc[i+1][j];
          
    	      }
    	      else  helper[j+(3*i)] = locc[i][j]; 

   	  }
  }
	
	for(int k = 0 ; k < 6 ; k++)
	{
		for(i = 0 ; i< 9 ; i++)
		{
			if(cit[k] ==helper[i])
			{
				counter++;
				i=9;
			}	
		}
	}

  if(counter == 6)return 1;
  else return 0;

}
void all_combinations_loc(char location[4][3],int num_hospital){

  char temp[3];						/*This function works as like this */
  for(int i =0 ; i < 4 ; i++ )		/*If our cluster is {1,2,3,4} then we want to find all 3 combinations*/
  {								/*Function take the first index of array and remove it from star to end  our cluster is now be like {2,3,4,1}*/
							/*Then we take first 3 of this cluster this is pur first combination {1.2.3}*/
      for(int j = 0 ; j < 3 ; j++)	/*Do this function to other combination if the hospital still doesnt found --> new cluster {3,4,1,2}*/
      {								/*take first 3 of them {3,4,1} other step is be like {4,1,2,3} this cluster's 3 comb is {4,1,2}*/
									
		temp[j] = location[i][j];							
		location[i][j] = location[i+1][j];	/*If our hosp number is 2 then  this function work as like this*/
		location[i+1][j] = temp[j];			/*If our cluster is {1,2,3,4} then we want to find all 2 combinations*/
       }   								/*Function take the first index of array and remove it one step now our cluster is now be like {2,1,3,4}*/
          								/*then we will take first 2 index {1,2} other step is like {2,3,1,4} then our 2 comb is {2,3}*/
          								/*So this function calculate the spesific 2 and 3 combinations of 4 */
    if(num_hospital==2) i = 4;			/*1 and 4th combination of 4 is itself so it doesn't change anything*/
  }
}
void print_hospitals(struct Hospital hospital[4],int index,char location[4][3]){
    
    int control;
    control = index ;
    
    for(int i = 0 ; i< index ; i++) 
    {   
    	  for(int j = 0 ; j < 3 ; j++ ) /*This for loop prints locations into the struct by character  */
    	  { 	    
    	      if(control == 2 )hospital[i].citiesServed[j] = location[i+1][j];
    	      else hospital[i].citiesServed[j] = location[i][j];
    	  }
    }
    
    printf("\n");
   		for(int i = 0 ; i < index ; i++)
		{
			printf("Hospital - %d\n",i);
			printf("Hospital Locations : %c%c%c\n",hospital[i].citiesServed[0],hospital[i].citiesServed[1],hospital[i].citiesServed[2]);		
		}
}





