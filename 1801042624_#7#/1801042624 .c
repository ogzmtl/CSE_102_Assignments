#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_from_file(char game_features[2002][200]);/*reads the file line by line*/
void read_only_name(char game_feat[2002][200],char select_name[2002][100]);/*read the names from char array which includes all games features*/
void read_genre(char game_feature[2002][200], char only_genre[2002][100]);/*read the genres from char array which includes all games feeatures*/
void read_platform(char game_feature[2002][200],char platform[2002][20]);/*read platforms*/
void other_data(char game_features[2002][200],float other_info[2002][8],char genre_n[2002][100],char platform[2002][20]);
void menu(char game_name[2002][100],char genres[2002][100],char platforms[2002][20],float games_info[2002][8]);

int main() {

  char game_ftr[2002][200];
  char name[2002][100];
  char genre[2002][100];
  char platf[2002][20];
  float game_info[2002][8];
     
      read_from_file(game_ftr);
      read_only_name(game_ftr,name);
      read_genre(game_ftr,genre);
      read_platform(game_ftr,platf);
      other_data(game_ftr,game_info,genre,platf);/*This function read other information about the game and write this info's into the another game*/
      
      menu(name,genre,platf,game_info);
	  
  return 0;
}
void menu(char game_name[2002][100],char genres[2002][100],char platforms[2002][20],float games_info[2002][8])
{
	int d,try_it = -1,i,unt_sin,a,b,game_kontrol =-1,counter = 0,k;
	float year,j=-1,sum;
	char input_g_name[100];
		

		while(d != 8)/*If the user doesn't enter "8" then the program works until user enters 8 value*/
		{	
		printf("\n***** WELCOME TO THE GAME LIBRARY *****\n");
		printf("      ---------------------------      \n\n");	
		
			printf("0 : List of the Genres\n");
			printf("1 : List of the Platforms\n");
			printf("2 : List of the Games Through the Years\n");
			printf("3 : All Informations of a Single Game\n");
			printf("4 : Average of the User Scores\n");
			printf("5 : Georographical Information of a Single Game\n");
			printf("6 : Frequence of the Genres\n");
			printf("7 : Frequence of the Platforms\n");
			printf("8 : Exit\n");
			printf("\n\nPlease select an operation : ");
			scanf(" %d",&d);
				
				switch(d)
				{
					case 0: for(i = 1 ; i < 14 ; i++)
					{
						printf("%s\n",genres[i]);
					}
					break;
					
					case 1: for(i = 1 ; i < 14 ; i++)
					{
						printf("%s\n",platforms[i]);
					}
					break;
					
					case 2: 
					
						while(try_it != 0 )/*If the user doesn't enter "8" then the program works until user enters true value*/
						{
							printf("Enter a year : ");
							scanf(" %f",&year);
							printf("\nUntil (0) or Since(1) %.0f :",year);
							scanf(" %d",&unt_sin);
								if(unt_sin == 0)
								{
									for(i = 1 ; i < 2001 ; i++) 
									{
										if(games_info[i][2] <= year) /*games_info[x][2] the 2.index of info arrays assigns year of game*/
										{
											printf("%s\n",game_name[i]);
											try_it = 0;
										}
									
									
									}
								}
								if(unt_sin == 1)
								{
									for(i = 1 ; i < 2001 ; i++)
								{
										if(games_info[i][2] > year)
										{
											printf("%s\n",game_name[i]);
											try_it = 0;
										}
									}
								}
								
								if(unt_sin != 0 && unt_sin != 1 )/*User doesn't enter 1-0 then print error message */
								{
									printf("TRY AGAIN\n\n");
									try_it = 0 ;
						    	}
							
					
						    	if(try_it != 0 )/*tamamen yanlis girilirse calısır !!! unutma !!!*/
						    	{
							    	printf("TRY AGAIN\n\n");
						    	}
						    	break;
						    	
			    		case 3 : 
			    		while(j != 0)
			    		{
				    		printf("Please Enter the Game Name : \n");
				    		scanf("%s",input_g_name);
				    			
				    			for(i = 0 ; i<2002 ; i++ )
				    			{	
				    				if(strcmp(input_g_name,game_name[i]) == 0 )
				    				{
				  		  				a = games_info[i][0];
				  		  				b = games_info[i][1];
				    						printf("\nName         :%s\n" ,game_name[i]);
				    						printf("Genre        :%s\n" ,genres[a]);
				    						printf("Platform     :%s\n" ,platforms[b]);
				    						printf("Year         :%.0f\n" ,games_info[i][2]);
				    						printf("Sales In NA  :%f\n" ,games_info[i][3]);
				    						printf("Sales In EU  :%f\n" ,games_info[i][4]);
				  
				   							if(games_info[i][5] == -1) printf("Total Sales  :Not available\n");/*If there is no as a sales value */
				   							else printf("Total Sales  :%f\n" ,games_info[i][5]);              /*printf not available value*/
				  
				    						printf("User Score   :%f\n\n" ,games_info[i][6]);
				    				 j=0; 
				    				}
 
				    			}
				    			if (j == -1 ) printf("\n\nThis game isn't included or You write wrong name .\n\n");
						}							/*If there is no match with game name and input prints this error mesage*/
				    break;
					
					case 4: 
						for(i = 1 ; i< 2001 ; i++)
							{
								sum += games_info[i][6];
							}
				    	sum = sum/(i-1);//i degiskeni donguden 2001 olarak ciktigi icin 1 cikardik 
				    	printf("\nAverage:%f \n\n",sum);
				    break;
				    
				    case 5: 
				    
				    	while(game_kontrol != 0)
				    	{
				    		printf("Please enter the name of the game : \n");
				  		  	scanf("%s",input_g_name);
				   		 	for(i = 0 ; i < 2001 ; i++)
				   		 	{
				    			if(strcmp(input_g_name,game_name[i]) == 0)
				    			{
				    			game_kontrol = 0;
				    				if(games_info[i][3] < games_info[i][4])
				    				{
				    					printf("\nThis game was popular in Europe\n\n");
				    				}
				    				else if(games_info[i][3] > games_info[i][4])
				    				{
				    					printf("\nThis game was popular in North America\n\n");
				    				}

				    				else
				    				printf("\n\nThis game wasn't popular either North America or Europe\n");
				    			i=2000;
				    			}
				    		}
				    	
				    		if(game_kontrol != 0) printf("This game couldn't found.  TRY AGAIN ...\n\n");
				    	}/*If the game name doesn't match with program will print this error message*/
				    	break;
				    	
				    	case 6: 
				    		
				    		for(k = 1 ; k<13 ; k++)
				    		{
				    			for(i=1 ; i<2001 ; i++)
				    			{
				    				if(games_info[i][0] == k) counter++;
				    				
				    			}
				    			printf("%s : %d\n",genres[k],counter);
				    			counter = 0 ;
				    		}
				    		printf("\n\n");
				    	break;
				    	
				    	case 7 :	
				    	
				    		for(k = 1 ; k<11 ; k++)
				    		{
				    			for(i=1 ; i<2001 ; i++)
				    			{
				    				if(games_info[i][1] == k) counter++;
				    				
				    			}
				    			printf("%s : %d\n",platforms[k],counter);
				    			counter = 0 ;
				    		}
				    		printf("\n\n");
				    	break;
				    	
				    	case 8:
				    		printf("\n\nHave a healthy day ... #STAYHOME\n\n");
				    	break;
				    	
				    	default: printf("\n!!! INVALID OPERAND.PLEASE TRY AGAIN. !!! \n\n");
				    	break;
				    
				    }
				}
		
		try_it =-1;/*this value assignment's reason is if the program change the value of that part */
		j=-1;			/*then I fix this change situation, when program  every refreshes the for loop*/
		game_kontrol =-1;
		}

}
void read_from_file(char game_features[2002][200])
{
    char *name_file = "Video_Games.txt";
    char d;
    int i = 0;
    FILE *fp;
    
    fp = fopen(name_file,"r");
      while(!feof(fp))
      { 
        fgets(game_features[i],200,fp);
        i++;              
      }

fclose(fp);
}
void read_only_name(char game_feat[2002][200],char select_name[2002][100])
{
  char d;
  int i,j;

      for(i = 0 ; i < 2002 ; i++)
      {
          for(j = 0 ; j < 100 ; j++)
          {
            if(game_feat[i][j] == ',' )
            {
              j = 100;  
              select_name[i][j] = '\0'; /*I assign NULL charachter because otherwise array is filling with random value*/  
            }
            
            else
            select_name[i][j] = game_feat[i][j];
          }
      } 
}
void read_genre(char game_feature[2002][200], char only_genre[2002][100])
{
int i,j;
int genre_count = 0,cmp_count = 0,write_index = 0,a=0;
char overlap_cntrl[100];

      for(i = 0 ; i < 2002 ; i++)
      {
          for(j = 0 ; j < 100 ; j++)
          {
         	if(game_feature[i][j] == ',' )
            {
           		j++;
           			while(game_feature[i][j] != ',')
           			{
           				//only_genre[i][genre_count] = game_feature[i][j];/*just control previous version*/
           				overlap_cntrl[genre_count] = game_feature[i][j];
           				genre_count++;
           				j++;
           			}
           			overlap_cntrl[genre_count] = '\0';
           				
           		j =  100;
           		genre_count = 0;
           		
            }         
            
          }
           	while(cmp_count != i)
           	{
           		if(strstr(only_genre[cmp_count],overlap_cntrl) != NULL)
           		{
           			write_index = -1;		
           			cmp_count = i-1;
           		}
           		cmp_count++;
           		
           	}
           				
           	if(write_index != -1)
           	{	
           		strcpy(only_genre[a],overlap_cntrl);
           		a++;
           	}          
		cmp_count = 0; 
		write_index=0;    
      }
}
void read_platform(char game_feature[2002][200],char platform[2002][20])
{
	int i,j,c=0,check=0,array_check = 0, index = 0, a=0;
	char platform_cont[100];
		for(i = 0 ; i < 2002 ; i++)
		{
			for(j = 0 ; j < 100 ; j++)
			{
				if(game_feature[i][j] == ',')
				{
					c++;
				}
				
				if (c == 2)
				{
					j++;
						while(game_feature[i][j] != ',')
						{
							platform_cont[check] = game_feature[i][j];
							j++;
							check++;
						}
					platform_cont[check] = '\0';
				 	j = 100;
				}
			}
				while(array_check != i)
				{
					if(strstr(platform[array_check],platform_cont) != NULL)
					{
						index = -1 ;
						array_check = i-1;
					}
				array_check++;
				}
			
				if(index != -1)
				{
					strcpy(platform[a],platform_cont);
					a++;
				}			
		 c = 0;
		 check = 0;		
		 array_check = 0 ;
		 index = 0;
		}	
}
void other_data(char game_features[2002][200],float other_info[2002][8],char genre_n[2002][100],char platform[2002][20])
{
	int i,j,c=0,count=0;
	char *control;
	char *not_ava="not_available";
	char *ptr;
	float a,sayac = 0;
	double temp;
		for(i = 0 ; i < 2002 ; i++)
		{
				control = strtok(game_features[i],",");
			
				while(control != NULL) /*strtok fonksiyonu sayesinde iki virgul arası string degerini control adlı degiskende tuttum*/
				{						/*while dongusu disinda ismi okuttuktan sonra diger ozellikleri okutup controla atıyorum */
					c++;				/*satırda null degeri gelene kadar okuduktan sonra c yi arttırıp float array indislerini dolduruyorum.*/
					control = strtok(NULL,",");
						
						
						switch(c)
						{
							case 1 : 
							
								while(count != 13)
								{
									if(strcmp(control,genre_n[count]) == 0)
									{
										sayac = count ;
										other_info[i][c-1] = sayac ;
									}
								count++;
								}
							break;
							
							case 2: 
								while(count != 20)
								{
									if(strcmp(control,platform[count])== 0)
									{
										sayac = count;
										other_info[i][c-1] = sayac;
									}
								count++;
								}
							break;
							
							case 3: 
								temp = strtod(control,&ptr);/*string olarak okunan yil,satislar,skor gibi degerlerin double olarak okunması*/
								sayac = temp;				/*double degerleriin floata esitlenmesi(? hata (belki) ?)*/
								other_info[i][c-1] = sayac; /*float info arrayin [i][2] 2. indis = yil*/
							break;	
						
							case 4: 
								temp = strtod(control,&ptr);
								sayac = temp;
								other_info[i][c-1] = sayac;/*float info arrayin [i][3] 3. indis = sales in NA*/
							break;
							
							case 5: 
								temp = strtod(control,&ptr);
								sayac = temp;
								other_info[i][c-1] = sayac;/*float info arrayin [i][4] 4. indis = sales in EU*/
							break;
							
							case 6: 
								if(strcmp(control,not_ava)!= 0)/*eger not available degilse sayiyi al ve yaz*/
								{
									temp = strtod(control,&ptr);
									sayac = temp;
									other_info[i][c-1] = sayac;/*float info arrayin [i][5] 5. indis = total_sales*/
								}
								else/*eger not available yazıyorsa o indis değerine -1 yaz*/
								{
									sayac = -1;
									other_info[i][c-1] = sayac;
								}
							break;
							
							case 7: 
								temp = strtod(control,&ptr);
								sayac = temp;
								other_info[i][c-1] = sayac;/*float info arrayin [i][6] 6. indis = user_score*/
							break;												
						}
						
				count = 0;	
				}		
		 c = 0;
		}
}



