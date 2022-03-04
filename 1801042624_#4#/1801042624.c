#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void decrypt_and_print (char *file_path);
char decrypt_numbers(int number);
void deep_decrypt_and_print (char* file_path);
void track_machine () ;
void refresh_position (int *X, int *Y, double *D, double *R);
void encrypt_messages (char* message);  
int decrypt_chars(char o);
void menu();



int main(){ 

menu();

return 0;
}
void menu(){
	int choice;
	printf("1-) Decrypt and print encrypted_p1.img\n");
	printf("2-) Decrypt and print encrypted_p2.img\n");
	printf("3-) Switch on the tracking machine\n");
	printf("4-) Encrypt the message\n");
	printf("5-) Switch off\n\n");

	printf("Please make your choice:\n");
	scanf("%d",&choice);

	switch (choice){
		case 1 : decrypt_and_print("encrypted_p1.img");
		break;

		case 2: deep_decrypt_and_print ("encrypted_p2.img");
		break;

		case 3: track_machine () ;
		break;

		case 4 : encrypt_messages ("decrypted_p4.img");
		break;

		case 5: printf("Switching off ...\n");
		break;

		default : printf("İnvalid operand");
				  menu();
		break;
	}
}

void decrypt_and_print (char* file_path)
{
	char k;
	int a;
	FILE *fp;
		
		fp = fopen(file_path,"r");

		while(!feof(fp))
		{
			fscanf(fp,"%c",&k);
			 a = k - '0';    /*TURNS THE CHAR VALUE TO A INTEGER */
			 k = decrypt_numbers(a);
			 printf("%c",k);
		}
	fclose(fp);
	main();
}
void deep_decrypt_and_print (char* file_path){

	int i,counter=-1,k,check;
	char d,f;
	FILE *fp2;
	
	fp2 = fopen(file_path,"r");

	while (!feof(fp2))
	{
		fseek(fp2,counter,SEEK_SET);  /*IF WE START THE FOLDERS INITIAL POSITION WE CHECK THE C VALUE*/
		fscanf(fp2,"%c",&d);		 
		if (d == '\n')
		{
			printf("\n");
		}

		fseek(fp2,counter,SEEK_SET);	 /*IF C VALUE IS NOT EQUAL TO \n THE WE SCANF THE STEP 3 VALUE BY ADDİNG*/
		check = 0;


		for ( i = 0; i < 3; ++i)
		{

			fscanf(fp2,"%c",&d);	

			if (d != '\n')
			{
		    	k = d-'0';  /*WE WANT TO READ ONE BY ONE SO WE READ CHARACTER NOT AS INTEGER*/
		    	check += k;

			}
			else
			{
			   k = 0;  /*IF WE REACH THE END OF LINE THE THE K VALUE ASSIGNS AS A 0 */
			   check += k;
			   i = 3;

			}
		}
		check = check % 7;   
		f = decrypt_numbers(check); /*CHECKİNG AND PRINTING AREA*/
		printf("%c",f);
		counter++;

	}

fclose(fp2);	
main();
}
void track_machine(){
    int i,j,x_pos,y_pos;
    double dist_camp,dist_en;
    char c;
     c = 'R';
     while(c == 'R') /*WE WANT TO R OR E VALUE AS AN INPUT SO IF USER CANNOT ENTER ANY KIND OF THESE VALUES PROGRAM ALWAYS REFRESHES ITSELF*/
     {			   /*ALSO THIS WHILE LOOPS REASON IS WE DON'T WANT TO LOSE ENEMİES LAST POSITION */
     refresh_position(&x_pos,&y_pos,&dist_camp,&dist_en);
     

    for ( i = 1; i < 12; i++)
    {

        for ( j = 1; j < 12 ; j++)
        {
            
            if (i == 6 && j == 6)
            {
                printf("O\t");
            }
            else if (i == x_pos && j == y_pos)
            {
                printf("E\t");

            }
            else 
            {
                printf(".\t");
            }
            
         }
        printf("\n");
        
    }
    printf("Enemies X position: %d, Y position : %d, Displacement: %.2lf, Distance to our camp: %.2lf\n",x_pos,y_pos,dist_en,dist_camp);
    printf("Command waiting... ");
    scanf(" %c",&c);
    
   }
   if(c == 'E')
   {
     main(); /*THIS IS CALLS THE MAIN AND  MAIN TO MENU */
   }
    
}
void refresh_position(int *X, int *Y, double *D, double *R){

    int first_x,first_y;
    srand(time(NULL));
     
   
 
    if(*X > 11 ||*X < 0 || *Y > 11 || *Y < 0){ /*tTHIS IF PART IF THE *X VALUE ISN'T BETWEEN THE [0,11] */
    first_x = 0;                               /*THEN PROGRAM UNDERSTAND THE PROGRAM STARTING*/
    first_y = 0;							/*AND WE KNOW WHEN PROGRAM STARTS ENEMİES ARE AT POSİTİON (0,0)*/
    *X = rand() % 12;						/*THIS CONDITION ARRANGE THE STARTING POSITION*/
    
    *Y = rand() % 12;
    *R = sqrt((*X - first_x)*(*X - first_x) + (*Y - first_y)*(*Y - first_y));
    *D =sqrt((*X-6)*(*X-6)+(*Y-6)*(*Y-6));
    }
    else {
    first_x = *X;
    first_y = *Y;
    *X = rand() % 12;
    
    *Y = rand() % 12;
    *R = sqrt((*X - first_x)*(*X - first_x) + (*Y - first_y)*(*Y - first_y));
    *D =sqrt((*X-6)*(*X-6)+(*Y-6)*(*Y-6));
    }
    

}
void encrypt_messages (char* message){


	FILE *fp4;
	FILE *fp_e4;

	int i,k,p,counter = 0,add=0,deger;
	char c,d;

	fp4 = fopen(message,"r");				/*fp4 = decrypted_p4.img*/
	fp_e4 = fopen("encrypted_p4.img","w+"); /*fp_e4 = encrpted_p4.img*/
	
	while(!feof(fp4)){

    fscanf(fp4,"%c",&c);

    k = decrypt_chars(c);  /*k is our wanted value the sum of 3 numbers shold be equal to 'k'*/
   
    if( counter != 0 && k != -1){   /*IF WE ARE THE IN THE BEGINNIG OF THE FOLDER OR OUR K VALUE IS NOT EQUAL TO '\n' */
    	fseek(fp_e4,counter-2,SEEK_SET); /*tHEN WE GO BACK 2 STEPS BEFORE AND AND READ 2 VALUE FOR ADDING*/

    	    	for ( i = 0; i < 2; i++) /*THEN OUR THIRD VALUE AND LAST 2'S ADDITION SHOLD BE EQUAL TO RETURNING VALUE WHICH IS K*/
    	{		
    		fscanf(fp_e4,"%c",&d);
    		deger = d - '0';
    		add += deger;
    	}

    	
    }
    else { 

    	
    	if (k == -1)	
    	{   k = 0;		
    		fprintf(fp_e4,"%d\n",k);
    		counter++;
    		
    	}
    	counter++;
    	fseek(fp_e4,counter,SEEK_SET);
    	for ( i = 0; i < 2; i++)
    	{

    		 
              fprintf(fp_e4,"%d",add%7);
              counter ++;
        }
    }           	
    	
    
    if (add < k)/*THIS PART ARRANGE THE NEGATIVE VALUES BY TURNING THEM A POSITIVE */
    {
    	k = abs(k - add);   /*I THINK MY HOMEWORK'S THIS PART IS LITTLE BIT WRONG BECAUSE THERE ARE NEGATIVE NUMBERS IN THE CRYPTED MESSAGE FOLDER WHICH I CAN'T SOLVE*/
    }						/*THIS PART'S EXAMPLE IS */
    else if(add > k)		/*IF OUR FSCANF VALUES ADDITION IS 5 AND WANTED VALUE IS WHICH IS K =3 */
    {						/*THEN ADD > WANTED VALUE (K) */
    	k = 7 - abs((add-k)); /*K - ADDITION WHICH EQUALS TO --> 3-5 = -2 AND THIS VALUE MEANS NOTHING BECAUSE WE WANT 3 AS A RESULT */
    }						/*SO THIS -2 'ABSOLUTE VALUE WİLL SUBSTRACT WITH 7 */
    						/*THEN OUR VALUE IS 7-2 = 5 AND THEN THIS VALUE'S ADDITION WITH OUR 2 FSCANF VALUES OUR WANTED VALUE BECAUSE*/
    else if(add = k) 		
    {						/*------SAGLAMA YAPMA KISMI-----*/
    	k = 0;              /*REMEMBER FSCANF VALUES ADDITION IS 5 THEN ADDING '5' WHICH IS FOUND 5 + 5 = 10 */
    } 						/*THEN 10 % 7 = 3 SHOULD BE OUR WANTED VALUE ( -- 3 IS OUR WANTED VALUE--)*/

    
    fseek(fp_e4,counter,SEEK_SET);  /*AFTER THIS WE INCREASE THE COUNTER TO READ OTHER CHARACTER*/
    fprintf(fp_e4, "%d",k%7);
    
    add = 0;				                                
	counter ++;			    
    }						
							

  fclose(fp_e4);
  fclose(fp4);
  printf("\n*****THE MESSAGE MANIPULATION IS SUCCESSFUL.*****\n *****VICTORY WILL BE WITH US*****\n\n\n");
  main();
}

int decrypt_chars(char o)
{
	int k ;
				switch (o) 
			{
	    		case ' ' : k = 0;
	    		break; 
	   
	    		case '-' : k = 1;
	    		break; 
	    
			    case '_' : k = 2; 
			    break; 
	    
			    case '|' : k = 3; 
			    break; 
	    
			    case '/' : k = 4; 
			    break; 
	   
			    case '\\' : k = 5; 
			    break; 
	
			    case '0' : k = 6; 
	    		break;
	    
	   			 default : 
	   			 		   k= -1;
	   			 break;  
	
			}
return k; /*RETURNING K VALUE WHICH IS THE RESULT VALUE IN DECRYPTED FOLDER */
}
char decrypt_numbers(int number){
				
		char c;		
				switch (number)
			{
	    		case 0 : c = ' ';
	    		break; 
	   
	    		case 1 : c= '-';
	    		break; 
	    
			    case 2 : c = '_'; 
			    break; 
	    
			    case 3 : c = '|' ;
			    break; 
	    
			    case 4 : c ='/' ;
			    break; 
	   
			    case 5 : c = '\\';
			    break; 
	   
			    case 6 : c = '0';
	    		break;
	    
	   			 default : c = '\n' ;
	
			}
return c;
}


