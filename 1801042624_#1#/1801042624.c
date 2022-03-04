#include <stdio.h>
#include <math.h>        

void find_root()
{
	int first_coef,second_coef,third_coef,delta;
	float eq_root_0,eq_root_1,temp;

		printf("Please enter the first coefficient:\n");
		scanf("%d",&first_coef);
		printf("Please enter the second coefficient:\n");
		scanf("%d",&second_coef);
		printf("Please enter the third coefficient:\n");   
		scanf("%d",&third_coef);

	delta=second_coef*second_coef-4*first_coef*third_coef;

			if (delta < 0)     /* DELTA İS LOWER THAN 0 THE OUTPUT FORMAT ARRANGED IF CONDITION BECAUSE THE NEGATIVE ASSIGNMENT AND POSITIVE ASSIGNMENT CAUSE OUTPUT TROUBLE*/
		{					                                 /*AND THE ALL POSSIBILITIES CAN FİX WITH THESE 4 CONDİTİONS*/	
					if (second_coef < 0 && third_coef < 0)
					{
						printf("\nYour equation is %dx^2 %dx %d and have any real roots.",first_coef,second_coef,third_coef); /*FİRST COEFFICIENT HAS NO MİNUS AND PLUS SİGN BECAUSE BOTH OUTPUT İMAGE CAN USEFUL  */        
					}                                                                                                         /*FOR EXAMPLE İN THİS CONDİTİON ALL COEF'S ARE LESS THAN ZERO OUR EQ. DON'T HAVE TO ANY SİGN */        
					
					if (second_coef < 0 && third_coef >= 0)
					{
						printf("\nYour equation is %dx^2 %dx +%d and have any real roots.",first_coef,second_coef,third_coef); /*WITH NEGATIVE NUMBERS WE DON'T NEED ANY ASSİGNMENT BECAUSE THE MİNUS SİGN ENTERS WİTH USER'S INPUT */        
					}      																									   /*WHEN THIRD COEF > 0 I HAVE TO WRITE PLUS SIGN THE THIRD_COEF'S PLACE*/
					                                                                                                          /*ALL OF OUTPUT ARRANGMENTS BASED ON THİS LOGİC*/
					if (second_coef >= 0 && third_coef < 0)                                                                    
					{
						printf("\nYour equation is %dx^2 +%dx %d and have any real roots.",first_coef,second_coef,third_coef);                                 
					}
					if( second_coef >= 0 && third_coef >= 0)													         /*THESE THREE CONDİTİON'S REASON IS  */
					{     																								             /*İF WE DON'T WRİTE FİRST_COEF PART THE EQ. IS ENTERS 2 İF CONDİTİONS*/
						printf("\nYour equation is %dx^2 + %dx +%d and have any real roots.",first_coef,second_coef,third_coef);     /*SO OUTPUT FORMAT WAS INCORRENT*/
					}

		}

			if (delta > 0)      
		{						
			eq_root_0=(-second_coef+sqrt(delta))/2*first_coef;    /* WHEN DELTA IS HIGHER THAN DELTA I CALCULATED TWO ROOTS OF EQUATION AND PRINT JUST LIKE THE OUTPUT FORMAT.*/
	        eq_root_1=(-second_coef-sqrt(delta))/2*first_coef;	  /* IN THESE IF CONDITIONS I FIXED ALL THE OUTPUT POSSİBİLİTİES*/

				if (eq_root_0<eq_root_1)           /*SMALL ROOT == EQ_ROOT_2*/
					{							   /*BIGGER ROOT == EQ_ROOT_1*/
						temp=eq_root_0;				/*IN THIS OPERATION THE "TEMP" HELPS US IT KEEPS SMALL ROOT'S VALUE AND IW WILL ASSIGN THE TEMP VALUE (WHICH IS SMALL ONE) EQ_ROOT_2*/
						eq_root_0=eq_root_1;
						eq_root_1=temp;
					}

					if (second_coef < 0 && third_coef < 0)
					{
						printf("\nYour equation is %dx^2 %dx %d and have real roots { %.2f , %.2f }.",first_coef,second_coef,third_coef,eq_root_0,eq_root_1);
					}
					if ( second_coef < 0 && third_coef >= 0)
					{
						printf("\nYour equation is %dx^2 %dx +%d and have real roots { %.2f , %.2f }.",first_coef,second_coef,third_coef,eq_root_0,eq_root_1);
					}
					if (second_coef >= 0 && third_coef < 0)
					{
						printf("\nYour equation is %dx^2 +%dx %d and have real roots { %.2f , %.2f }.",first_coef,second_coef,third_coef,eq_root_0,eq_root_1);
					}
					if (second_coef >= 0 && third_coef >= 0)
					{
						printf("\nYour equation is %dx^2 + %dx +%d and have any real roots. { %.2f , %.2f }",first_coef,second_coef,third_coef,eq_root_0,eq_root_1);
					}	        	

		}
			
			if (delta == 0)
		{
			eq_root_0 =(-second_coef+sqrt(delta))/2*first_coef; /*WHEN DELTA = 0 OUR EQUATİON'S ROOT IS JUST ONE.IN THESE IF CONDITIONS I ARRANGED ONE ROOT OUTPUT İMAGE. */


					if (second_coef < 0 && third_coef < 0)
					{
						printf("\nYour equation is %dx^2 %dx %d and have real roots { %.2f }.",first_coef,second_coef,third_coef,eq_root_0);
					}
					if (second_coef < 0 && third_coef >= 0)
					{
						printf("\nYour equation is %dx^2 %dx +%d and have real roots { %.2f }.",first_coef,second_coef,third_coef,eq_root_0);
					}
					if (second_coef >= 0 && third_coef < 0)
					{
						printf("\nYour equation is %dx^2 +%dx %d and have real roots { %.2f }.",first_coef,second_coef,third_coef,eq_root_0);
					}
					if ( second_coef >= 0 && third_coef >= 0)
					{
						printf("\nYour equation is %dx^2 + %dx +%d and have real roots.{ %.2f }",first_coef,second_coef,third_coef,eq_root_0);
					}				
		

		}
}
void find_newtonian_root()
{	
	float first_coef,second_coef,third_coef,init,delta;
	double iter1,iter2,iter3,iter4,iter5,func,deriv_func,differ,eq_root_1,eq_root_2,check_1,check_2;

		printf("\nPlease enter the first coefficient:\n");
		scanf("%f",&first_coef);
		printf("Please enter the second coefficient:\n");
		scanf("%f",&second_coef);
		printf("Please enter the third coefficient:\n");
		scanf("%f",&third_coef);
		printf("Please enter the initial:\n");
		scanf("%f",&init);
		
		delta=second_coef*second_coef-4*first_coef*third_coef;

		eq_root_1=(-second_coef+sqrt(delta))/(2*first_coef);       
		eq_root_2=(-second_coef-sqrt(delta))/(2*first_coef);	   /*ROOT FOUNDING TO USE NEWTONS ALGORİTHM (MEASURE THE DIFFERENCE WITH INITIAL NUMBER) */
		


		check_1=eq_root_1-init;         /*IN THIS CHECK SITUATION'S REASON TO UNDERSTAND WHICH ROOT IS CLOSER TO OUR INITIAL NUMBER THEN MOVE THE OPERATİONS */
		if (check_1<0)                  /*THIS IF CONDİTİONS MAKE THE CLOSER NUMBER'S DİSTANCE'S ABSOLUTE VALUE */
			{
				check_1=-check_1;
			}

		check_2=eq_root_2-init;          /*THİS CHECK_2 ALSO HAS SAME PURPOSE LIKE CHECK_1 */
		if (check_2<0)                   
			{
				check_2=-check_2;
			}
		

						   
	if (check_1<check_2)   /*IN THIS CHECK COMPARISON'S REASON İS THAT GIVEN EXAMPLE IN THE HOMEWORK SHEET CLOSER TO ROOT 10 BUT WE HAVE TO CLOSE OUR ROOT THE OTHER SIDE */
		{                  /*IN THIS IF CONDITION OUR INITIAL NUMBER'S DİSTANCE TO ROOT 1 IS BIGGER THAN ROOT 2(WHICH ONE İS SMALL*/
				func = first_coef*init*init+second_coef*init+third_coef;     /* I CALCULATE THE FUNCTION VALUE WİTH INIT TO USE İN NEWTON'S ALGORİTHM */
				deriv_func=2*first_coef*init+second_coef;                    /* I CALCULATE THE  DERİVATİVE FUNCTION VALUE WİTH INIT  */
				iter1  = init-(func/deriv_func);                             /*NEWTON'S ALGORITM IS = x(i+1)=x(i)-(f(x)/f'(x))  IN THIS */
				func = first_coef*iter1*iter1+second_coef*iter1+third_coef;  /*IN THE REQUESTED OUTPUT f(x) VALUE HAVE TO BE AN 1.ITERATION'S RESULT SO I PUT THE ITER1 RESULT IN THIS EQ. */
				differ = eq_root_1-iter1;                                    /*DIFFERENCE CALCULATION (ROOT-İTER) */

					if (differ<0)        /* THIS IF PART IS MAKE THE DİFFERENCE VALUE POSİTİVE TAKE THE ABSOLUTE VALUE  */
						{
							differ=-differ;
						}
				printf("Step\tx\t\tf(x)\t\tDifference\n");					/*THE OUTPUT DİSAGN WAS ARRANGED */	
				printf("x1\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter1,func,differ);        
                                                                            /*ALL THESE IF CONDITIONS ARE IN THE SAME IDEA AS THE ABOVE */
		
				deriv_func=2*first_coef*iter1+second_coef;
				func = first_coef*iter1*iter1+second_coef*iter1+third_coef;
				iter2  = iter1-(func/deriv_func);
				func   = first_coef*iter2*iter2+second_coef*iter2+third_coef;
				differ = eq_root_1-iter2;                        /*THIS PART OF ALGORITHM DIFFERENCE FOUND WİTH ROOT1 WHICH IS ((-b^2 + sqrt(delta)) /2a) .==> (DELTA WITH PLUS)*/
					if (differ<0)
						{
							differ=-differ;
						}				

				printf("x2\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter2,func,differ); /*I ARRANGED THE OUTPUT VİEW DISAGN WİTH USING TAB"\t"*/

				deriv_func=2*first_coef*iter2+second_coef;
				func = first_coef*iter2*iter2+second_coef*iter2+third_coef;
				iter3  = iter2-(func/deriv_func);
				func   = first_coef*iter3*iter3+second_coef*iter3+third_coef;
				differ = eq_root_1-iter3;
					if (differ<0)
						{
							differ=-differ;
						}		

				printf("x3\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter3,func,differ);


				deriv_func=2*first_coef*iter3+second_coef;
				func = first_coef*iter3*iter3+second_coef*iter3+third_coef;
				iter4  = iter3-(func/deriv_func);
				func   = first_coef*iter4*iter4+second_coef*iter4+third_coef;
				differ = eq_root_1-iter4;
					if (differ<0)
						{
							differ=-differ;
						}		

				printf("x4\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter4,func,differ);


				deriv_func=2*first_coef*iter4+second_coef;
				func = first_coef*iter4*iter4+second_coef*iter4+third_coef;
				iter5  = iter4-(func/deriv_func);
				func   = first_coef*iter5*iter5+second_coef*iter5+third_coef;
				differ = eq_root_1-iter5;
					if (differ<0)
						{
							differ=-differ;
						}		

				printf("x5\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter5,func,differ);
        }
    if(check_2<check_1)       /*IN THIS IF CONDITION ROOT2 IS CLOSER TO INITIAL NUMBER THAN ROOT1'S DISTANCE */
        {					  /*SO THIS PART OF ALGORITHM DIFFERENCE FOUND WİTH ROOT2 WHICH IS ((-b^2 - sqrt(delta)) /2a) .==> (DELTA WITH MINUS)*/
				func = first_coef*init*init+second_coef*init+third_coef;
				deriv_func=2*first_coef*init+second_coef;
				iter1  = init-(func/deriv_func);
				func = first_coef*iter1*iter1+second_coef*iter1+third_coef;
				differ = iter1-eq_root_2;
					if (differ<0)
						{
							differ=-differ;
						}
				printf("Step\tx\t\tf(x)\t\tDifference\n");
				printf("x1\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter1,func,differ);

		
				deriv_func=2*first_coef*iter1+second_coef;
				func = first_coef*iter1*iter1+second_coef*iter1+third_coef;
				iter2  = iter1-(func/deriv_func);
				func   = first_coef*iter2*iter2+second_coef*iter2+third_coef;
				differ = iter2-eq_root_2;
					if (differ<0)
						{
							differ=-differ;
						}		

				printf("x2\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter2,func,differ);

				deriv_func=2*first_coef*iter2+second_coef;
				func = first_coef*iter2*iter2+second_coef*iter2+third_coef;
				iter3  = iter2-(func/deriv_func);
				func   = first_coef*iter3*iter3+second_coef*iter3+third_coef;
				differ = iter3-eq_root_2;
					if (differ<0)
						{
							differ=-differ;
						}		

				printf("x3\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter3,func,differ);


				deriv_func=2*first_coef*iter3+second_coef;
				func = first_coef*iter3*iter3+second_coef*iter3+third_coef;
				iter4  = iter3-(func/deriv_func);
				func   = first_coef*iter4*iter4+second_coef*iter4+third_coef;
				differ = iter4-eq_root_2;
					if (differ<0)
						{
							differ=-differ;
						}		

				printf("x4\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter4,func,differ);


				deriv_func=2*first_coef*iter4+second_coef;
				func = first_coef*iter4*iter4+second_coef*iter4+third_coef;
				iter5  = iter4-(func/deriv_func);
				func   = first_coef*iter5*iter5+second_coef*iter5+third_coef;
				differ = iter5-eq_root_2;
					if (differ<0)
						{
							differ=-differ;
						}		

				printf("x5\t%.4lf\t\t%.4lf\t\t%.4lf\n",iter5,func,differ);
	    }
}
int find_multiple_closest(int a,int b)		
{
	int division,close_num,remain;

	division=a/b;         
	remain=a%b;      /*DISION TIMES SECOND NUMBER IS LOWER THAN (REMAİN /2) THE CLOSER MULTİPLE IS İNTEGER VALUE OF THİS DIVISION TIMES SECOND NUMBER BECAUSE OF THE ROLLİNG NUMBER*/
             
	if (remain<b/2)   
	{
		close_num=division*b;
	}
	 else           /*DISION TIMES SECOND NUMBER IS HIGHER AND EQUAL THAN (REMAİN /2) THE CLOSER MULTİPLE IS İNTEGER VALUE OF THİS DIVISION'S 1 MORE, TIMES SECOND NUMBER. BECAUSE OF THE ROLLİNG NUMBER*/
	{
		close_num=(division+1)*b;
	}
return(close_num); 
}

int main ()
{
	int first,sec,sol;


	find_root();
	find_newtonian_root();
		printf("\nEnter the first integer:\n");
		scanf("%d",&first);
		printf("\nEnter the second integer:\n");
		scanf("%d",&sec);
	sol = find_multiple_closest(first,sec);  /*I EQUALIZE SOME İNTEGER TO RETURNING NUMBER SO I CAN USE THIS VALUE WİTH MODULAR ARİTHMETİCHS */
	if (first%sec != 0)
	{

		printf("Closest number to %d that is multiple of %d is %d\n",first,sec,sol);
	}
	else 
		printf("Closest number to %d that is multiple of %d is itself\n",first,sec);
return 0;
}