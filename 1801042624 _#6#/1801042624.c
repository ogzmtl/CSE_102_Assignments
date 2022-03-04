#include <stdio.h>
#include <stdlib.h>				/*NOTE TO TEACHER*/
#include <string.h>		/*There is a mistake which i couldn't solve in the output*/
#include <time.h> /* when the program first runs the commonly in 10 th or 11th column's letters writing attached each other */
				 /* But when program runs(second or third opening ) more than once this problem is doesn't appear.*/

#define ROW_NUM 20
#define COL_NUM 20

void read_file(char *file_path,char word[100][20]);
void random_word(char random_words[10][15],char words[100][20]);
void word_list(char word_list[10][15]);
int arrange_places(char random_w[10][15],char game_map[20][20]);
int up_down_straight(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*top to bottom writing*/
int up_down_reverse(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*bottom to top writing*/
int horizantal_straight(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*horizantal left to right writing*/
int horizantal_reverse(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*horizantal right to left writing*/
int diag_up_left(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*top to bottom &&left to right writing *//*top to bottom &&left to right writing */
int diag_up_right(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*top to bottom &&right to left writing */
int diag_down_left(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*bottom to top && left to right writing*/
int diag_down_right(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb);/*bottom to top && right to left writing*/
int check1(int row,int j,char random[10][15]);
int check2(int row,int j,char random[10][15]);
int check3(int col,int j,char random[10][15]);
int check4(int col,int j,char random[10][15]);
int check_empty(int row,int col,int i, char map[20][20],char words[10][15]);/*checks the map is it empty or not (top to bottom)*/
int check_empty2(int row,int col,int i, char map[20][20],char words[10][15]);
int check_empty3(int row,int col,int i, char map[20][20],char words[10][15]);
int check_empty4(int row,int col,int i, char map[20][20],char words[10][15]);
int check_empty5(int row,int col,int i, char map[20][20],char words[10][15]);
int check_empty6(int row,int col,int i, char map[20][20],char words[10][15]);
int check_empty7(int row,int col,int i, char map[20][20],char words[10][15]);
int check_empty8(int row,int col,int i, char map[20][20],char words[10][15]);
void random_letter(char game_map[20][20]);
int true_or_not(char gaming_map[20][20],char coor[5],char input[15]);
void op1(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for top to bottom*/
void op2(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for bottom to top*/
void op3(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for left to right*/
void op4(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for right to left*/
void op5(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for top to bottom && left to right*/
void op6(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for top to bottom && right to left*/
void op7(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for bottom to top && left to right*/
void op8(char map_game[20][20],int w_row,int w_col,char *word);/*uppercase op for bottom to top && right to left*/
void draw_map(char word_map[20][20]);




int main(){

    char *file_path="words.txt";
	char exit[5]="EXIT";
	char coordinant[5];
	char user_input[15];
    char map[20][20];
    char words[100][20];
    char rand_words[10][15];
    int all_done,sum = 0;
	int i,j,uzunluk=0,kontrol=0;
			for ( i = 0; i < 20; i++)/*Send the 0 to clean array area*/
			{
				for ( j = 0; j < 20; j++)
				{
					map[i][j] = '0';
				}		
			}
        read_file(file_path,words);
        random_word(rand_words,words);
        arrange_places(rand_words,map);
		random_letter(map);
		word_list(rand_words);
		draw_map(map);

		while(strcmp(coordinant,exit) != 0 && sum < 10)
		{ 
			printf("Please enter the coordinate and the word: ");
			scanf("%s",coordinant);
		if(strcmp(coordinant,exit) != 0 )
		{
			scanf("%s",user_input);
        		
				all_done = true_or_not(map,coordinant,user_input);	
				sum+=all_done;
				if (all_done == 1)
				{
					while (user_input[uzunluk] != '\0' )
					{
						uzunluk++;
					}
					for ( i = 0; i < 10; i++)
					{
						kontrol = 0;
						for ( j = 0; j < uzunluk-1; j++)
						{
							if (rand_words[i][j] == user_input[j])
							{
								kontrol++;
							}	
							
						}
						if (kontrol == uzunluk-1)
						{
							kontrol = i;
							i = 10; 
						}
					
					}
						
				}
				for ( i = 0; i < 10; i++)
				{
					
					if (kontrol == i)
					{ 
						for ( j = 0; j <uzunluk; j++)
						{
							rand_words[i][j] = rand_words[i][j] - 32; 
							
						}
						printf("%d. : %s",i+1,rand_words[i]);
						
					}
					else
					{
						printf("%d. : %s",i+1,rand_words[i]);
					}
						
				}
				draw_map(map);
		
	kontrol = 0;
	uzunluk = 0;
			if (sum == 10 )
			{
				printf("Winner winner chicken dinner ... Have a healthy day...\n");
			}
		}
		else
		{ 
			sum = 10;
			printf("HAVE AN HEALTHY DAY ...#STAYHOME...\n");
		}
	}               

return 0;
}

void read_file(char *file_path,char word[100][20]){
    int i = 0,j = 0;
    FILE *fp;
    fp = fopen(file_path,"r");

        while(!feof(fp))
        {
            fscanf(fp,"%c",&word[i][j]);
            j++;
                if(word[i][j-1] == '\n')
                { 
                    word[i][j]='\0';
                    j = 0;
                    i++;
                   
                }
                if(i == 99 && j == 4) word[i][j]='\0'; /*bu satir dosyadaki son kelime olan bait kelimesinin duzgun okunmasını saglıyor.*/
            
        }
    fclose(fp);

}/*dosyadan kelimeler arraya alindi*/

void random_word(char random_words[10][15],char words[100][20]){
    int random,i,j;
    srand(time(NULL));
    
    random  = rand() % 100 ;
        for(i = 0 ; i<10 ; i++)
        {
        random  = rand() % 100 ; 
            for(j = 0 ; j < 15 ; j++)
            { 
                random_words[i][j] = words[random][j];
            }
        }
}/*kelimeler random secildi*/
void word_list(char word_list[10][15]){
	int i;
	printf("\n");
		for ( i = 0; i < 10; i++)
		{ 
			printf(" %d. : %s",i+1,word_list[i]);	
		}
}
int arrange_places(char random_w[10][15],char game_map[20][20]){

    int i=0,arrange_func,map_col,map_row,check_lenght,check_lenght2;
	int check_emp1;
    FILE *fp;
	fp = fopen("coordinant.txt","w");
	srand(time(NULL));
	while (i != 10)
	{ 
    	arrange_func = rand() % 9 ;/*arrange the random words writing style vertical, diagonal or horizontal :)) */
	    map_row = rand() % 20 ;/*arrange random rows */
        map_col= rand() % 20 ; /*arrange random columns*/
            switch (arrange_func)
            {
                case 1: 
                 check_lenght = check1(map_row,i,random_w);
				 check_emp1 = check_empty(map_row,map_col,i,game_map,random_w);
					
					if (check_lenght == 0 && check_emp1 == 0)
					{
                		up_down_straight(random_w,map_row,map_col,game_map,i);
						fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
						i++;						

					}
                break ;

				case 2 :
				check_lenght = check2(map_row,i,random_w);
				check_emp1 = check_empty2(map_row,map_col,i,game_map,random_w);		

					if(check_lenght == 0 && check_emp1 == 0)
					{ 
						up_down_reverse(random_w,map_row,map_col,game_map,i);
						fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
						i++;
					} 
				break;
				
				case 3: 
			    check_lenght = check3(map_col,i,random_w);
				check_emp1 = check_empty3(map_row,map_col,i,game_map,random_w);

					if(check_lenght == 0 && check_emp1 == 0)
					{ 
						horizantal_straight(random_w,map_row,map_col,game_map,i);
						fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
						i++;
					}
				break;

				case 4: 
				check_lenght = check4(map_col,i,random_w);
				check_emp1 = check_empty4(map_row,map_col,i,game_map,random_w);

					if(check_lenght == 0 && check_emp1 == 0)
					{ 
						horizantal_reverse(random_w,map_row,map_col,game_map,i);
						fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
						i++;
					}
				break;

				case 5: 
				
				check_lenght = check1(map_row,i,random_w);
				check_lenght2 = check3(map_col,i,random_w);

				check_emp1 = check_empty5(map_row,map_col,i,game_map,random_w);

					if(check_lenght == 0 && check_lenght2 == 0 && check_emp1 == 0)
						{ 
							diag_up_left(random_w,map_row,map_col,game_map,i);
							fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
							i++;
						}
				break;

				case 6: 
				check_lenght = check1(map_row,i,random_w);
				check_lenght2 = check4(map_col,i,random_w);
				check_emp1 = check_empty6(map_row,map_col,i,game_map,random_w);
			
					if(check_lenght == 0 && check_lenght2 == 0 && check_emp1 == 0)
					{ 
						diag_up_right(random_w,map_row,map_col,game_map,i);
					fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
						i++;
					}
				break;

				case 7: 
				check_lenght = check2(map_row,i,random_w);
				check_lenght2 = check3(map_col,i,random_w);
				check_emp1 = check_empty7(map_row,map_col,i,game_map,random_w);
				
					if(check_lenght ==0 && check_lenght2 == 0 && check_emp1 == 0)
					{ 
						diag_down_left(random_w,map_row,map_col,game_map,i);
						fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
						i++;
					}
				break;

				case 8: 
				check_lenght = check2(map_row,i,random_w);
				check_lenght2 = check4(map_col,i,random_w);
				check_emp1 = check_empty8(map_row,map_col,i,game_map,random_w);
				
					if(check_lenght == 0 && check_lenght2 == 0 && check_emp1 == 0)
					{ 
						diag_down_right(random_w,map_row,map_col,game_map,i);
						fprintf(fp,"%s%d %d %d\n",random_w[i],map_row,map_col,arrange_func);
						i++;
					}
				break;
            }
	}

fclose(fp);
return 0;
}
int up_down_straight(char r_words[10][15], int rows, int columns, char map[20][20],int random_w_numb){/*top to bottom writing*/

	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows + i][columns] = r_words[random_w_numb][i];
					
			}	
return 0;
}
int up_down_reverse(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb){/*bottom to top writing*/

	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows - i][columns] = r_words[random_w_numb][i];
					
			}
return 0;
}
int horizantal_straight(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb){/*harizantal Left to right writing*/
	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows][columns+i] = r_words[random_w_numb][i];
					
			}
return 0;
}
int horizantal_reverse(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb){/* horizantal right to left writing*/
	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows][columns-i] = r_words[random_w_numb][i];
					
			}
return 0;
}
int diag_up_left(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb){/*top to bottom &&left to right writing */
	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows+i][columns+i] = r_words[random_w_numb][i];
					
			}
return 0;

}
int diag_up_right(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb){/*top to bottom && right to leftt writing */
	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows+i][columns-i] = r_words[random_w_numb][i];
					
			}
return 0;

}
int diag_down_left(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb){/*bottom to top && left to right writing*/
	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows-i][columns+i] = r_words[random_w_numb][i];
					
			}
return 0;

}
int diag_down_right(char r_words[10][15], int rows, int columns,char map[20][20],int random_w_numb){/*bottom to top && right to left writing*/
	int j=0,i=0;
	
		while (r_words[random_w_numb][j] != '\n')
		{
			j++;
		}
			for ( i = 0; i < j-1; i++)
			{
				map[rows-i][columns-i] = r_words[random_w_numb][i];
					
			}
return 0;

}
int check1(int row,int j,char random[10][15]){/*checks the vertical (up to down)&&(diagonal up to down) whether it fits or not */

	int i = 0, val;
		while (random[j][i] != '\n')
		{
			i++;
		}

			if (i-1 > ROW_NUM - row)
			{
				val = -1;
			}
			else
			{
				val = 0;
			}
return val;
}
int check2(int row,int j,char random[10][15]){/*checks the vertical (down to up)&&(diagonal down to up) whether it fits or not */
	int i = 0, val;
		while (random[j][i] != '\n')
		{
			i++;
		}
	
			if (i-1 > row - 0)
			{
				val = -1;
			}
			else
			{
				val = 0;
			}
return val;
}
int check3(int col,int j,char random[10][15]){/*checks the horizantal (letf to right)&&(diagonal left to right situations) whether it fits or not */
	int val,i=0;
		while (random[j][i] != '\n')
		{
			i++;
		}
			if (i-1 > COL_NUM - col)
			{
				val = -1;
			}
			else
			{
				val = 0;
			}
return val;
}
int check4(int col,int j,char random[10][15]){/*checks the vertical (right to left ) &&(diagonal left to right situations) whether it fits or not */
		int val,i=0;
		while (random[j][i] != '\n')
		{
			i++;
		}

			if (i-1 > col- 0)
			{
				val = -1;
			}
			else
			{
				val = 0;
			}
return val;
}
int check_empty(int row,int col,int i, char map[20][20],char words[10][15]){/*up to down operations map checking operation 
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/

	int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row+k][col] != '0')
		{
			ret_val = -1;
		}		
	}	
return ret_val;		
}
int check_empty2(int row,int col,int i, char map[20][20],char words[10][15]){/*down to up vertical operations map checking  
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/

	int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row-k][col] != '0')
		{
			ret_val = -1;
		}		
	}	

return ret_val;		
}
int check_empty3(int row,int col,int i, char map[20][20],char words[10][15]){/*left to right horizantal operation's, map checking
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/

	int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row][col+k] != '0')
		{
			ret_val = -1;
		}		
	}	
return ret_val;		
}
int check_empty4(int row,int col,int i, char map[20][20],char words[10][15]){/*right to left horizantal operation's, map checking
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/

	int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row][col-k] != '0')
		{
			ret_val = -1;
		}		
	}	
return ret_val;
}	
int check_empty5(int row,int col,int i, char map[20][20],char words[10][15]){/*left to right and up to down diagonal operation's, map checking
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/
	
	int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row+k][col+k] != '0')
		{
			ret_val = -1;
		}		
	}	
return ret_val;	
}
int check_empty6(int row,int col,int i, char map[20][20],char words[10][15]){/*right to left and up to down diagonal operation's, map checking
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/
		int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row+k][col-k] != '0')
		{
			ret_val = -1;
		}		
	}	
return ret_val;	
}
int check_empty7(int row,int col,int i, char map[20][20],char words[10][15]){/*left to right and down to up diagonal operation's, map checking
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/
		int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row-k][col+k] != '0')
		{
			ret_val = -1;
		}		
	}	
return ret_val;	
}
int check_empty8(int row,int col,int i, char map[20][20],char words[10][15]){/*right to left and down to up diagonal operation's, map checking
																			if random coordinants are full then refreshes this function and place 
																			by returning -1*/
		int j = 0,k = 0;
	int ret_val=0;
    
	while(words[i][j] != '\n')
	{
		j++;
	}

	for ( k = 0; k < j-1; k++)
	{
		if (map[row-k][col-k] != '0')
		{
			ret_val = -1;
		}		
	}	
return ret_val;	
}
void random_letter(char game_map[20][20]){ /*97-123 ASCII numbers presents a-z letters*/ 

	int i,j,a;
	srand(time(NULL));

	for ( i = 0; i < ROW_NUM; i++)
	{
		for ( j = 0; j < COL_NUM; j++)
		{
			if (game_map[i][j] == '0')
			{
				a = 0;
				a = rand() % 26;
	            a = a + 97;
				game_map[i][j] = a;
				/*game_map[i][j] = '.';*/  /*This line printf '.' instead of random letter*/
			}	
		}		
	}		
}
int true_or_not(char gaming_map[20][20],char coor[5],char input[15]){

    FILE *fp;
    char denee[15];
    int deger=0,inp_row,inp_col,row=-1,col=-1,func=-1,i=0,val=0,j=0,true_answer=0;
	

            while (coor[i] != '\0')
            {
                i++;
            }
	    while (input[j] != '\0')
            {
                j++;
            }
		
    
        inp_row = coor[0] - '0';
        inp_row = inp_row - 17;
		
            
            if (i > 2)/*this if else conditions arrange the coordinants which  higher than number 9 */
            {
                inp_col = coor[2]-'0';
                inp_col +=10;
            }
            
            else if(i == 2)
            {
                inp_col=coor[1]-'0';
            }
		fp = fopen("coordinant.txt","r");/*I write the random choose words in a file */
	    while(!feof(fp))				/*in coordinant.txt words are listed like this*/
            							/*words\n*/
	    {								/*row number , column number , how they write*/
            fscanf(fp,"%s",denee);
 
					if (strcmp(input,denee) == 0)
					{
						deger = 1;
					}

				
                
                
                if (deger == 1)
                { 
                    fscanf(fp,"%d",&row);
                    fscanf(fp,"%d",&col);
                    fscanf(fp,"%d",&func);/*this func value keeps the words writing type (horizantal,vertical,diagonal)*/
                    val = 1;
                    deger = 0;
                }
                
                else/*if the words aren't match than read empty and skip*/
                {
                    fscanf(fp,"%s",denee);
					fscanf(fp,"%s",denee);
					fscanf(fp,"%s",denee);
                }
        
	    
		}
		fclose(fp);

    	if(inp_row == row && inp_col == col && val == 1)
		{
			true_answer = 1;
			switch(func)
			{
				case 1: op1(gaming_map,row,col,input);/*uppercase operation in up to down*/
				break;
				case 2: op2(gaming_map,row,col,input);
				break;
				case 3: op3(gaming_map,row,col,input);
				break;
				case 4: op4(gaming_map,row,col,input);
				break;
				case 5: op5(gaming_map,row,col,input);
				break;
				case 6: op6(gaming_map,row,col,input);
				break;
				case 7: op7(gaming_map,row,col,input);
				break;
				case 8: op8(gaming_map,row,col,input);
				break;
			}
		}

return true_answer;
}
void op1(char map_game[20][20],int w_row,int w_col,char *word){ /*uppercase operation in up to down*/
												/*This op1...op8 functions enlarge the letters if the input is corrent*/
												/*this enlarge operations is done by substract 32*/
	int i=0,j;
		while (word[i] != '\0')		
		{
			i++;
		}
		printf("%d",i);
		for ( j = 0; j < i; j++)
		{
			map_game[w_row+j][w_col] = map_game[w_row+j][w_col] - 32; 
		}
}
void op2(char map_game[20][20],int w_row,int w_col,char *word){/*uppercase operation in down to up*/

	int i=0,j;
		while (word[i] != '\0')
		{
			i++;
		}
		for ( j = 0; j < i; j++)
		{
			map_game[w_row-j][w_col] = map_game[w_row-j][w_col] - 32; 
		}
}
void op3(char map_game[20][20],int w_row,int w_col,char *word){/*uppercase operation in horizantal left to right*/

	int i=0,j;
		while (word[i] != '\0')
		{
			i++;
		}
		for ( j = 0; j < i; j++)
		{
			map_game[w_row][w_col+j] = map_game[w_row][w_col+j] - 32; 
		}
}
void op4(char map_game[20][20],int w_row,int w_col,char *word){/*uppercase operation in horizantal right to left*/

	int i=0,j;
		while (word[i] != '\0')
		{
			i++;
		}
		for ( j = 0; j < i; j++)
		{
			map_game[w_row][w_col-j] = map_game[w_row][w_col-j] - 32; 
		}
}
void op5(char map_game[20][20],int w_row,int w_col,char *word){ /*uppercase operation in diagonal up to down and left to right*/

	int i=0,j;
		while (word[i] != '\0')
		{
			i++;
		}
		for ( j = 0; j < i; j++)
		{
			map_game[w_row+j][w_col+j] = map_game[w_row+j][w_col+j] - 32; 
		}
}
void op6(char map_game[20][20],int w_row,int w_col,char *word){/*uppercase operation in diagonal up to down and right to left*/

	int i=0,j;
		while (word[i] != '\0')
		{
			i++;
		}
		for ( j = 0; j < i; j++)
		{
			map_game[w_row+j][w_col-j] = map_game[w_row+j][w_col-j] - 32; 
		}
}
void op7(char map_game[20][20],int w_row,int w_col,char *word){/*uppercase operation in diagonal down to up and left to right*/

	int i=0,j;
		while (word[i] != '\0')
		{
			i++;
		}
		for ( j = 0; j < i; j++)
		{
			map_game[w_row-j][w_col+j] = map_game[w_row-j][w_col+j] - 32; 
		}
}
void op8(char map_game[20][20],int w_row,int w_col,char *word){/*uppercase operation in diagonal down to up and right to left*/

	int i=0,j; 
		while (word[i] != '\0')
		{
			i++;
		}
		for ( j = 0; j < i; j++)
		{
			map_game[w_row-j][w_col-j] = map_game[w_row-j][w_col-j] - 32; 
		}
}
void draw_map(char word_map[20][20]){
	int i,j;
	printf("   ");
	for ( i = 0; i < 20; i++)
	{
		printf("%d\t",i);/*arrange the column coordinant*/
	}
	printf("\n");
	printf("   ");
	for ( i = 0; i < 20; i++)
	{
		printf("_\t");
	}
	printf("\n\n");	
	for ( i = 0; i < 20; i++)
	{
		printf("%c |",65+i);/*This part arrange the row coordinant as letter ( ASCII )*/
		for ( j = 0; j < 20; j++)
		{
			printf("%c\t",word_map[i][j]);
		}
		printf("\n\n");		
		

	}
}
