#include<stdio.h>
#include<math.h>

	int  draw_triangle(int side1, int side2, int side3);
	void type_triangle(int side1, int side2, int side3);
	int  perimeter_triangle(int side1,int side2, int side3);
	double area_triangle(int side1,int side2, int side3, int perimeter);

int main ()
{
   int leng1,leng2,leng3,check_tri,perimeter;
   double area;

	printf("The lenght of first side:\n");
	scanf("%d",&leng1);
	printf("The lenght of second side:\n");
	scanf("%d",&leng2);
	printf("The lenght of third side:\n");
	scanf("%d",&leng3);

	check_tri = draw_triangle( leng1, leng2, leng3);
		
		if(check_tri==0)
		{
		printf("\nAccording to the triangle inequality theorem, this triangle cannot be drawn.\n");
		return 0;
		}
        
                else
 		printf("\nAccording to the triangle inequality theorem, this triangle can be drawn.\n");
	
	type_triangle( leng1, leng2, leng3 );
	
	perimeter = perimeter_triangle(leng1, leng2, leng3);
	printf("The perimeter of the triangle :%d\n",perimeter);		
	
	area = area_triangle( leng1, leng2, leng3, perimeter);
	printf("The area of the triangle:%lf\n ",area);	

return 0;
}


int draw_triangle(int side1,int side2,int side3)
{
    int tri_check,temp;
	if( side1 > side2 )
	  {
		temp  = side1;        
		side1 = side2;       
		side2 = temp;        		
	  }
	 if( side1 > side3 )
	  {
		temp  = side1;       /*IN THIS PART OF IF CONDITIONS I CHECK THREE SIDES OF TRIANGLE*/
		side1 = side3;       /*SO I WANT TO KEEP THE SIDES ORDER FROM LOWER TO HIGH */
		side3 = temp;        /*THIS CONTROL OPERATION IS THE SAME IDEA LIKE COMPARING ALL THE SIDES EACH OTHER*/
				     /*AND THE SMALLEST SIDE IS "SIDE1" BIGGEST SIDE IS "SIDE3" SO WE CAN EASILY SUBSTRACT THEM WITHOUT MINUS SING*/

	  }
	 if( side2 > side3 )
	  {
		temp  = side2;
		side2 = side3;
		side3 = temp;

	  }
	
	tri_check=0;

	if( ( side3-side1 ) < side2 && side2 < ( side3+side1 ) )     /* IN THIS PART OF THE CODE THE INPUTS ARE CONTROLLING */
	{							     /* WHETHER THEY ARE SUITABLE TO TRİANGLE INEGUALITY THEOREM OR NOT */
	    tri_check=0;                                             /*IF ALL THESE CONDITIONS ARE CORRECT THE TRI_CHECK'S VALUE TURNS INTO 1 AND RETURN MAIN FUNC AS "1" */
								     /*IF ALL CONDITIONS AREN'T CORRECT THEN TRI_CHECK = 0 AND RETURN TO MAIN FUNC AS "0" */
		if((side2-side1) < side3 && side3 < (side1+side2))
		{
		    tri_check=0;	   
			
			if( (side3-side2 ) < side1 && side1 < ( side3+side2 ) )
			{
			    tri_check=1;
			}
		}
	}

return (tri_check);
}

void type_triangle(int side1, int side2, int side3)
{

	if(side1 == side2 && side2 == side3 )              /*COMPARING ALL THE SIDES LENGHT WİTH EACH OTHER TO EXPLAIN THE TRIANGLE'S TYPE*/
	{						   /*IN THIS PART THE CONDITIONS CONNECT WITH AND OPERAND TO IF 3 SIDES COMPARISON IS TRUE */
	   printf("It is a is Equilateral Triangle\n");	   /*IF CONDITIONS ARE WRONG ELSE IF CONDITIONS ACTIVATED*/
	}

	else if(side1 == side2 || side1 ==side3 || side2 == side3 )
	{
	   printf("It is a Isosceles Triangle\n");
	}	

	else if(side1 != side2 && side1 != side3 && side2 != side3 )
	{
	   printf("It is a Scalene Triangle\n");
	}

}

int  perimeter_triangle(int side1,int side2, int side3)
{
 	return (side1+side2+side3);
}

double area_triangle(int side1,int side2, int side3, int perimeter)
{
	double area,x1,x2,x3,p;
	p = perimeter/2.0;
	        /*  !!!!!! THERE IS A BIG PROBLEM IN HERE CHECK HERE !!!!!! */
	x1=p-side1;
	x2=p-side2;
	x3=p-side3;
	area = p*x1*x2*x3;
	

return (sqrt(area));
}












