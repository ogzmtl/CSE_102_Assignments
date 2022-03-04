#include<stdio.h>

void read_news(char buffer[500], char file_path[11], int is_Only_Title);
void append_file(char* file_path, char c);
void read_magic_numbers(char buffer_magic[11], char buffer_news[500]);
double g_func(double f(int x), int a);
double f_func(int x);

int read_or_not(char file_name[20],int h);
double helper_magic_func(char buff[500],char magic_file[10], int NEWS_NUMB);
void read_title(char file_path[10]);
int reading_operation(char buff[500],char file_path[10],int NEWS_NUM);
int reading_control_func();

void menu();

int main(){

 menu();
}

void menu(){

	char buff[500],file_path[11] = "news/1.txt";//I arrange the folders change the 0.th index of the file_path array 
	char k,d,z;
	char *readed_check = "readed_news_id.txt";
	int  only_title=-1,i,select;
	FILE *file_title;
	

		printf("\n\n*******DAILY NEWS*******\n\n");
		printf("Today's news are listed for you : \n\n");
		
        read_news(buff,file_path,only_title);

	printf("\nWhat do you want to do : \n");
	printf("a.Read news\n");
	printf("b.Listed the readed news\n");
	printf("C.Get decrypted information from the news\n");
	scanf(" %c",&d);
	
	
			switch(d){
			
			case 'a':
					only_title = 1; 
					read_news(buff,file_path,only_title);
			break;
			
			case 'b':
					z = '0';// the answer is why z = '0' is if user just want to see the readed news list then special '0' value sending the func.
					append_file(readed_check,z);
				
				printf("\n\n Go back to the menu (1) / Exit(0)\n\n"); //End of the user's every choice program ask that would you want to return the menu? 
				scanf("%d",&select);
			
				if (select == 1) menu();
				else printf("\n\nHave a health day ... \n\n");	
			
			break;
			
			case 'c' : read_magic_numbers(file_path, buff);
			break;
			
			default: printf("\n\nInvalid Operand... Exiting the program.GOOD BYE...\n\n");
			break;			
			
			
			}
	

}
void read_news(char buffer[500], char file_path[11], int is_Only_Title){
	
	int news,i,check=1,j=0,go,l,o=1;
	char k,z;
	char *read_check = "readed_news_id.txt";
	FILE *news_file;

		if(is_Only_Title == -1){
			
			read_title(file_path);
		}
		
		else if (is_Only_Title == 1){
		
		while(check > 0){
			printf("Which news do you want to read : ");
			scanf("%d",&news);
			
			
				switch(news){
				
				case 1: 
					
					
					file_path[5] = news + '0';
					z = file_path[5];
					l = read_or_not(read_check,news);//read_or_not function just say the file is readed or not or not
					if (l == 1 ) o = reading_control_func();// L value is 1 so the file is readed then ask the user continue or not in this func.
                    										// if o is 1 then the user want to read new again so secomd if part works.                    
                    append_file(read_check,z);// this function works just a writing in file.
					
					if( o == 1 ) 
						{
						reading_operation(buffer,file_path,news);/*this part prints the new*/
						}
					check = -1;
					

				break;
				case 2: 
					
					file_path[5] = news + '0';
					z = file_path[5];
					l = read_or_not(read_check,news);//read_or_not function just say the file is readed or not or not
					if (l == 1 ) o = reading_control_func();// L value is 1 so the file is readed then ask the user continue or not in this func.
                    										// if o is 1 then the user want to read new again so secomd if part works.
                    append_file(read_check,z); // this function works just a writing in file.
					
					if( o == 1 )
					{ 
						reading_operation(buffer,file_path,news); /*this part if user want to read new again or not*/			
					}
					check = -1;			
				break;
				case 3: /*This case part works like other 2 of them*/
					
					file_path[5] = news + '0';
					z = file_path[5];
					l = read_or_not(read_check,news);
					if (l == 1 ) o = reading_control_func();
                    
                    append_file(read_check,z);
					
					if( o == 1 ) 
						{
						reading_operation(buffer,file_path,news);	
						}
					
					check = -1;

				break;
				case 4:
					 
					file_path[5] = news + '0';
					z = file_path[5];
					l = read_or_not(read_check,news);
					if (l == 1 ) o = reading_control_func();
                    
                    append_file(read_check,z);
					
					if( o == 1 ) reading_operation(buffer,file_path,news);
					check = -1;

				break;
				default: printf("Invalid new number... \nPlease try again . \n ");
				break;
				
				}
				
				}

				printf("\n\n Go back to the menu (1) / Exit(0)\n\n"); //End of the user's every choice ask that would you want to return the menu? 
				scanf("%d",&go);
				if (go == 1) menu();
				else printf("\n\nHave a health day ... \n\n");							
		}
}

void append_file(char* file_path, char c){
	
	char check[5];
	FILE *fp_read;
	int i=0,j,read_control=0,search_list,yes_no,num_cont,h;

		fp_read = fopen(file_path,"a+");
		if(c == '0' )// this part just checks the 'b' case of the menu.
		{
			h=0;// if the h = 0 then read_or_not listed like this:
			read_or_not(file_path,h); // 1.st readed
		}							  // 2.nd readed 
									  // 3.rd readed or like this...
		

		else if (c == '1'|| '2'||'3'||'4')// *** this else if part check the new whether is this new in file or not .
		{   		
			num_cont = c -'0';
			i=0;
				while(!feof(fp_read))
				{
					fscanf(fp_read,"%c",&check[i]);
						if(check[i] != '\n')
						{	
							i++;
						}      /*This if part's reason is when we scan the file we don't want new line character in our compare array so
						this condition check that value */
				
				
				}
			
				for(j = 0 ; j < i ; j++)
				{
					search_list = check[j] - '0'; 
						if(search_list == num_cont)
						{
							read_control = 1; /*Search_list is the check value which compare with the new's number if the new number which is num_cont
							is equal to search_list then program understands this new is readed before so I shouldn't write this new again
							so program makes read control value = 1*/
						}
				}
				
				if(read_control != 1)//If the read control value is not equal to 1 then program says this new weren't read before
				{					//and if new weren't programs shows the news and print it in the file (readed_news_id).
					check[i]=c;
					fprintf(fp_read,"%c",check[i]);
				}

		}


fclose(fp_read);

}
void read_magic_numbers(char buffer_magic[11], char buffer_news[500]){

	char d;
	int a=1,choice,k,i=0;
	double res_func,sum;
	
	printf("Which news do you want to decrypt : ");
	scanf("%d",&choice);
			switch (choice)
			{
				case 1 : sum = helper_magic_func(buffer_news,buffer_magic,choice);
						 printf("* Number of tests performed : %.2lf \n",sum);
				break;
				
				case 2 : sum = helper_magic_func(buffer_news,buffer_magic,choice);
						 printf("* Number of sick people : %.2lf \n",sum);
				break;
				
				case 3 : sum = helper_magic_func(buffer_news,buffer_magic,choice);
						 printf("* Number of deaths :%.2lf \n",sum);
				break;
				
				case 4 : sum = helper_magic_func(buffer_news,buffer_magic,choice);
						 printf("* Number of sick people : %.2lf \n,",sum);
				break; 						
			}
	

}
double f_func(int x){

	double res_fx;
	
	res_fx = ((x*x*x) - (x*x) + 2);
return res_fx;
}
double g_func(double f(int x), int a){
	
	double res_gx;
		
		res_gx = f(a)*f(a);
		
return res_gx;
}

void read_title(char file_path[11]){
	int i ;
	char k;
	FILE *news_file;

	for( i = 1 ; i < 5 ; i++){
			
				file_path[5] = i + '0';
				news_file = fopen(file_path,"r");
				fscanf(news_file,"%c",&k);
			
				printf("Title of %d.news : ",i);
			
					while(k != '\n'){ // reading the 1.txt || 2.txt ... until the new line character
			
					   printf("%c",k);
					   fscanf(news_file,"%c",&k);
					 }
			
				 printf("\n");
				 fclose(news_file);
			 }
	
} 

int reading_operation(char buff[500],char file_path[11],int NEWS_NUM){
	
	FILE *news_file;
	int j=0;
					
			file_path[5] = NEWS_NUM + '0';
			
			news_file = fopen(file_path,"r");
				
				while(!feof(news_file))
				{
					fscanf(news_file,"%c",&buff[j]);
					j++;
				}
				
				printf("\n %s \n",buff);
			
			fclose(news_file);
			
			
return -1;
}
int read_or_not(char file_name[20],int h){
	char contr[5];
	int i = 0,j,search_list,read_control=0;
	FILE *read_or_not;
	
	if(h == 0) // when h = 0 works this if statement works for just case 'b' part
	{ 
		read_or_not = fopen(file_name,"r");
				while(!feof(read_or_not))
				{
					fscanf(read_or_not,"%c",&contr[i]); // scans the readed_news_id file and save the values in array
						if(contr[i] != '\n')          
						{	
							i++;
						
						}
				
				}
		
				
			if(contr[0] == '\0') //IF THE READED_NEWS_ID FILE IS EMPTY THEN THIS IF CONDITION IS PRINTS THIS MESSAGE
			{
				printf("You haven't read any news anymore.\n");
			}
			else 
			{
				if(i >= 1)
				{

					printf("%c.new is readed.\n",contr[0]);//FIRST NUMBER MAKES FAULT IN MY CODE SO THIS IF SOLVE THAT ERROR.
				}


				 if(i >= 1)
				{
					for ( j = 1 ; j < i-1 ; j++ )// THE REASON OF SUBSTRACT -1 IS WE DON'T WANT TO NULL CHARACTER 
					{						
						printf("%c.new is readed.\n",contr[j]);
										
					}
				}	
			}
		fclose(read_or_not);
	}
	else if(h > 0 ) // if 'h' is not equal to 0 than this part checks the readed or not 
	{
		read_or_not = fopen(file_name,"r");
             while(!feof(read_or_not))
				{
					fscanf(read_or_not,"%c",&contr[i]);
						if(contr[i] != '\n')
						{	
							i++;
						
						}
				
				}
			
				for(j = 0 ; j < i ; j++)
				{
					search_list = contr[j] - '0'; 
						if(search_list == h)
						{
							read_control = 1;
							/*If this new is readed than read_control value is 1 and return this value to the menu because if the user want to
						    continue the reading or not This return value is arranged for continue or not situation.*/
							/*When the new is readed than return 1 so in the read_news func if l value is 1 program says "this new is readed..."*/
						}
				}		
	fclose(read_or_not);
	}
return read_control;
}
int reading_control_func(){
	int yes_no, return_value=1; // in read_news function's "l" value is 1 than this function works.
	
		printf("This new is readed.Do you want to read again ? Yes(1) / No (0)\n");
		scanf(" %d",&yes_no);
			switch(yes_no)
			{
				case 1: printf("The new is opening...\n\n");
						return_value = 1;
				break;
							    
				case 0: printf("Exiting the program...\n\nGOOD BYE !!!\n\n");
				        return_value = 0;
				break;

							
			}

return return_value;
}

double helper_magic_func(char buff[500],char magic_file[11], int NEWS_NUMB){
						
	int i=0,k,result_gof;
	double add=0;
	FILE *fp_magic;
	
	magic_file[5] = NEWS_NUMB +'0';
	fp_magic  = fopen(magic_file,"r");
						
			while(!feof(fp_magic))
			{
				fscanf(fp_magic,"%c",&buff[i]);
		
				
					if(buff[i] =='#')//when read the # than other character must be magic number 
					{
						i++;
						fscanf(fp_magic,"%c",&buff[i]);//this fscanf read the character after '#' sign 
						k = buff[i] -'0';
						result_gof = g_func(f_func,k);
						add = add + result_gof;						
					}
					else
						i++;
			}

	fclose(fp_magic);

return add;
}











































































