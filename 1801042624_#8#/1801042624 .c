#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <math.h>

#define MAX_SIZE 500
#define N 8

void generate_hofstadters_sequence (int *arr, int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
double std_array (int arr[], double *mean, int n, int index);
char* remove_duplicates (char* str);
void install_pipes (int visited[N][N], int x, int y, int orientation);
void menu ();
void part1menu();

int main(){
		
	menu ();
}
void menu (){

	int select,counter=0,check;
	char str_i[100];
	int visit[N][N];
	int x=0,y=0,orien=-1,i,j;
while(select != 4)
	{
		printf("Welcome to homework 8, please choose one of the part to continue\n");
		printf("_________________________\n");
	
			printf("1) Execute part 1\n");
			printf("2) Execute part 2\n");
			printf("3) Execute part 3\n");
			printf("4) Exit\n");
			scanf("%d",&select);
			switch (select)
			{
				case 1 : 
					
					part1menu();
				
				break;
				case 2 :
					for(i = 0 ; i<N ; i++)// to make all visited index = 0
					{
						for(j = 0 ; j<N ; j++)
						{
							visit[i][j] = 0;
						}
					}
					install_pipes(visit,x,y,orien);
					printf("\n\n");
				break;
				
				case 3: 
						printf("Please enter a sentence :\n");
						scanf(" %[^\n]s",str_i);
						remove_duplicates(str_i);
						printf("\n\n");
				break;
				
				default : printf("HAVE A HEALTHY DAY \n");
				break;
			
		}
	}
}
void part1menu(){
	int number ;
	int fill_arr[MAX_SIZE];
	int ind=0,max,sum;
	double mean=0,dene;
	int choice,i;
		while(choice != 5)
		{ 
			printf("Please make your choice \n");
			printf("----------------------\n");
			printf("1) Fill array\n");
			printf("2) Find Biggest Number\n");
			printf("3) Calculate Sum\n");
			printf("4) Calculate the standart Deviation\n");	
			printf("5) Exit\n");
			scanf("%d",&choice);

				switch(choice) 
				{
					case 1: 
						for( i = 0 ; i<MAX_SIZE ; i++)// to make all indexes as 0
						{
						fill_arr[i] = '\0';
						}
						printf("Please enter a number to find N number of hofstader sequence :\n");
						scanf("%d",&number);
						generate_hofstadters_sequence (fill_arr,number-1);
						
					break;
					
					case 2: 
						max = fill_arr[number-1];
						max = find_max(fill_arr,number-1,max);
						printf("Biggest number is : %d \n",max);
					break;
					
					case 3: 
						sum = sum_array(fill_arr);
						printf("sum : %d\n",sum);
					break;
					
					case 4: 
						ind=0;
						mean = 0;	
						dene = std_array(fill_arr,&mean,number,ind);
						dene = dene/(number-1);
						printf("standart deviation : %lf\n ",sqrt(dene));
						printf("mean : %lf \n",mean);
					break;
				}
		}
}
void generate_hofstadters_sequence (int *arr, int n){

		if(n == 1 ) 
		{
			arr[0] = 1 ;
			arr[1] = 1 ;
		}
		if (n >1 )
		{
			generate_hofstadters_sequence(arr,n-1);
			arr[n] = arr[(n)-arr[n-1]]+arr[(n)-arr[n-2]];
			
		}
}
int find_max (int arr[], int index, int max_value){
	
	int temp;
	
		if(index > 0)
		{
			if(arr[index]>= max_value) max_value = arr[index];

			temp = find_max(arr,index-1,max_value);
			if(temp > max_value) max_value = temp ;
		}
return max_value;
}
int sum_array (int arr[]){
	
	int sum;	

		if(arr[0] != 0) sum = arr[0] + sum_array(arr+1);		
	
		else return 0;

return sum;
}
double std_array (int arr[], double *mean, int n, int index){/*There is a problem in here !!! 24.04 !!!*/

 	
 	double res,sum ; 
		if(*mean == 0) 
		{
			if(arr[index] != 0) sum = arr[index] + std_array(arr,mean,n,index+1);		
			else return 0;
			
			if(index == 0)*mean = sum/n;// mean degeri doğru fakat return hep sum oluyor karelerinin farkı hesaplanmıyor
			
			return sum;
		}	
		if(index < n) res  = pow((*mean - arr[index]),2) + std_array(arr,mean,n,index+1);
					
return res;// error!!! toplam değeri donuyor (sum degeri sadece)!!!
}
char* remove_duplicates (char* str){

	if(str[0] != str[1])
	{
		printf("%c",str[0]);
	}
	if(*str == '\0') return 0;

return remove_duplicates(str+1);
}
void install_pipes (int visited[N][N], int x, int y, int orientation){

		
		if(visited[x+2][y+1] == 0 && x+2 < N && y+1 < N && 0 <= x+2 && y+1 >= 0){
			x = x+2;
			y = y+1;
			orientation = 1;
			visited[x][y] = 1;
			if(visited[x][y] != 0 )	printf("O%d, ",orientation);
			install_pipes(visited, x, y, orientation);
		}
		 if(visited[x+1][y-2] == 0 && x+1 < N && y-2 < N && 0 <= x+1 && y-2 >= 0){
		 	orientation = 2 ;
		 	x+=1;
		 	y-=2;
		 	visited[x][y] = 2;
		 	if(visited[x][y] != 0  )	printf("O%d, ",orientation);
		 	install_pipes(visited, x, y, orientation);
		 }
		 if(visited[x-2][y-1] == 0 && x-2 < N && y-1 < N && 0 <= x-2 && y-1 >= 0) { 
			orientation = 3;
			x -= 2 ;
			y -= 1 ;
			visited[x][y] = 3;
			if(visited[x][y] != 0 )	printf("O%d, ",orientation);
			install_pipes(visited, x, y, orientation);
		}
		 if(visited[x-1][y+2] == 0 && x-1 < N && y+2 < N && 0 <= x-1 && y+2 >= 0) {
			orientation = 4;
			x -= 1;
			y += 2;
			visited[x][y] = 4;
			if(visited[x][y] != 0 )	printf("O%d, ",orientation);
			install_pipes(visited, x, y, orientation);
		}
		  if(visited[x+1][y+2] == 0 && x+1 < N && y+2 < N && 0 <= x+1 && y+2 >= 0) {
			orientation = 5;
			x += 1;
			y += 2;
			visited[x][y] = 5;
			if(visited[x][y] != 0 )	printf("O%d, ",orientation);
			install_pipes(visited, x, y, orientation);
		}
		 if(visited[x+2][y-1] == 0 && x+2 < N && y-1 < N && 0 <= x+2 && y-1 >= 0) {
			orientation = 6;
			x += 2;
			y -=1;
			visited[x][y] = 6;
			if(visited[x][y] != 0 )	printf("O%d, ",orientation);
			install_pipes(visited, x, y, orientation);
		}
		 if(visited[x-1][y-2] == 0 && x-1 < N && y-2 < N && 0 <= x-1 && y-2 >= 0) {
			orientation = 7;
			x -= 1;
			y -= 2 ;
			visited[x][y] = 7;
			if(visited[x][y] != 0 )	printf("O%d, ",orientation);
			install_pipes(visited, x, y, orientation);
		}
		 if(visited[x-2][y+1] == 0 && x-2 < N && y+1 < N && 0 <= x-2 && y+1 >= 0) {
			orientation = 8;	
			x -=2 ; 
			y += 1;
			visited[x][y] = 8;
			if(visited[x][y] != 0 )	printf("O%d,",orientation);
			install_pipes(visited, x, y, orientation);
			
		}			

		
}












