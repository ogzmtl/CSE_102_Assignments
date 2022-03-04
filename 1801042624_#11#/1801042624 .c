#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct node{
    int x;
    struct node *next;
}nodes;

typedef struct secnode{
    int val;
    struct secnode *next;
}sn;
struct difference{
	int n1,n2;
};

long int * read_array(char *filename, long int f_array[],int *N);/*N value hold the total number in the array*/
nodes * read_linkedlist(char *filename, nodes *Root, int *counter);/*counter value hold the total number in the linkedlist*/
float * stats_array(long int arrayList[]);
float * stats_linkedlist(nodes *rootA,float results[4] );

struct difference * compare_arr_list(sn *Root, int *arr,struct difference diff[],int *counter);/*(Part2)finding difference*/

int main() {
  
  	nodes *root = (nodes*)malloc(sizeof(nodes));
    sn *inplist_root = NULL;
    
    char *file_name = "list.txt";
    
    struct difference *dif_ll_arr = (struct difference*)malloc(10*sizeof(struct difference));
    int *inpArr,counter = 1,byte_a=1,byte_list =0;
    long int byte,byte2;
    double time1,time2,time3,time4,time5,time6;
    float *ret_val,*res_arr=(float*)malloc(sizeof(float)); ;
    long int *farray = (long int*)malloc(200*sizeof(long int));
 	clock_t start,end;   
 		
 		start = clock();
        farray = read_array(file_name,farray,&byte_a);   /*writing file to dynamic array*/ 
      	end = clock();
      	time1 = end-start;
      	printf("\n\nFirst Time Taken of read_array func    => %f seconds\n", time1 / CLOCKS_PER_SEC);
      	
      	start = clock();
        ret_val = stats_array(farray);     /*Aritmethic operations by using array*/
        end = clock();
        
        printf("First Time Taken of *stats_array func  => %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        start = clock();
        root = read_linkedlist(file_name,root,&byte_list);  /*writing file to the linkedlist*/ 
        end = clock();
        time2 = end-start;
        printf("\nTime read_linkedlist   => %f seconds\n", time2 / CLOCKS_PER_SEC);
        
        start = clock();
        res_arr = stats_linkedlist(root,res_arr); /*Aritmethic operations by using list*/
        end = clock();
        printf("Time *stats_linkedlist => %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\nArray Values\n");
        printf("------------\n");
        byte = byte_a*200*sizeof(int);
        printf("BYTE    --> %ld\n",byte);
        printf("Maximum --> %.3lf\nMinimum --> %.3lf\nMean    --> %.3lf\nStd Dev --> %.3lf\n\n",ret_val[0], ret_val[1], ret_val[2], ret_val[3]);
        
        printf("\nList Values\n");
        printf("------------\n");
        byte2 = byte_list*sizeof(nodes);
        printf("Byte    --> %ld\n",byte2);
        printf("Maximum --> %.3lf\nMinimum --> %.3lf\nMean    --> %.3lf\nStd Dev --> %.3lf\n\n",res_arr[0], res_arr[1], res_arr[2], res_arr[3]);
              
        free(farray);
        free(root);
        byte_list = 0;
        
        start = clock();
        root = (nodes*)malloc(sizeof(nodes));	/*Calculate the time 2nd time*/
        root = read_linkedlist(file_name,root,&byte_list);  /*writing file to the linkedlist*/ 
        end = clock();							
        time4 = end-start;
        byte_a = 1;
        
        start = clock();  						/*Calculate the time 2nd time*/
        farray = (long int*)malloc(200*sizeof(long int)); 
        farray = read_array(file_name,farray,&byte_a);   /*writing file to dynamic array*/ 
      	end = clock();
      	time3 = end-start;
      	
      	free(farray);
        free(root);
        byte_a = 1;
        byte_list = 0 ;
        
        start = clock();				/*Calculate the time 3rd time*/
        farray = (long int*)malloc(200*sizeof(long int)); 
        farray = read_array(file_name,farray,&byte_a);   /*writing file to dynamic array*/ 
      	end = clock();
      	time5 = end-start;   
        
        start = clock();					/*Calculate the time 3rd time*/
        root = (nodes*)malloc(sizeof(nodes));
        root = read_linkedlist(file_name,root,&byte_list);  /*writing file to the linkedlist*/ 
        end = clock();
        time6 = end-start;
        
        free(farray);
        free(root);
        
        printf("\nAverage time of read_array func      - 3 times - = %lf\n",(time1+time3+time5)/(3*CLOCKS_PER_SEC));
        printf("Average time of read_linkedlist func - 3 times - = %lf\n\n",(time2+time4+time6)/(3*CLOCKS_PER_SEC));
 
  /*---------------------------------------------PART 2----------------------------------------------------------------*/
  /*---------------------------------------------PART 2---------------------------------------------------------------*/
  /*---------------------------------------------PART 2--------------------------------------------------------------*/
  /*---------------------------------------------PART 2-------------------------------------------------------------*/
  
        printf("\n--------------------------------------------------------------------------------\n");
        printf("\n--------------------------------------------------------------------------------\n");
        printf("	***** PART 2 *****\n\n");      
        
        dif_ll_arr = compare_arr_list(inplist_root,inpArr,dif_ll_arr, &counter); /*Part 2*/
        
		
		if(counter -1 == 0)printf("All elements are the same ...(There is no difference )");
		else
		{
			for(int j = 0 ; j<counter-1; j++)printf("Difference %d - %d \n",dif_ll_arr[j].n1,dif_ll_arr[j].n2);
		}
		printf("\n\n *****  HAVE A HEALTHY DAY  ***** \n\n");

 return 0;
}

long int* read_array(char* filename,long int f_array[],int *N){

    int counter = 1,count_for=1;
    long int ret;
    char *ptr,d;
    char *checkArr;/*CheckArr --> read character from file  */
    
    FILE *fp;

        fp = fopen(filename,"r");
        fscanf(fp,"%c",&d);
        while(!feof(fp))
        {
            if(count_for == 1)checkArr = (char*)malloc(10*sizeof(char));
            
            if(d != ',')
            {
                if(count_for %10 == 0)checkArr = (char*)realloc(checkArr,(count_for+10)*sizeof(char));
                checkArr[count_for-1] = d;
                count_for++;
            }
            else 
            {
                count_for = 1;
                ret = strtol(checkArr, &ptr, 10);
                
                    if (counter % 200 == 0)
                    {
                        *N = *N+1 ;
                        f_array = (long int*)realloc(f_array, ((*N)*200)*sizeof(long int));             
                    }
                f_array[counter-1] = ret; 
                f_array[counter] = -1;   
                counter++;
                free(checkArr);
            }
            
            fscanf(fp,"%c",&d);
        }       
    
    fclose(fp);

return f_array;
}
float * stats_array(long int arrayList[]){
    
    int i = 0,counter = 0;
    float temp_max,temp_min,mean=0,sum=0,std=0;
    float *stats_arr = (float*)malloc(5*sizeof(float));

    	temp_max = arrayList[i]; 
    		while(arrayList[i] != -1)
    		{	
       	 		sum = sum + arrayList[i];
        		if(arrayList[i] > temp_max) temp_max = arrayList[i];
        		i++;
    		}
    	mean = (sum)/(i); 
    	i = 0 ;
    	temp_min = arrayList[i];
   
    		while(arrayList[i] != -1)
    		{       
       			if(arrayList[i] < temp_min) temp_min = arrayList[i];
        
        		std = std + ((mean-arrayList[i])*(mean-arrayList[i]));
        		i++;
    		}
    	std = sqrt(std/(i-1));
    
    	stats_arr[0] = temp_max;
    	stats_arr[1] = temp_min;
    	stats_arr[2] = mean;
    	stats_arr[3] = std;

return stats_arr;
}
nodes* read_linkedlist(char *filename, nodes* Root,int *counter){

    nodes *iter = Root,*add,*current;
    FILE *fp;
    int comma = 1,ret;
    float *res_arr=(float*)malloc(sizeof(float));
    char d,*checkArr,*ptr;			/*CheckArr --> read character from file  */
    
    	fp = fopen(filename,"r");
    	    fscanf(fp,"%c",&d);
        
    	    while(!feof(fp))
    	    {
    	        if(comma== 1)checkArr = (char*)malloc(10*sizeof(char));
    	        if(d != ',')
    	        {
    	            if(comma %10 == 0)checkArr = (char*)realloc(checkArr,comma*sizeof(char));
    	            checkArr[comma-1] = d;
    	            comma++;
    	        }
            
    	        else
    	        {
    	            comma = 1;
    	            *counter = *counter + 1;
    	            ret = strtol(checkArr, &ptr, 10);
    	            
    	        	iter-> x = ret;
    	        	iter->next = NULL;    
    	        	iter ->next = (nodes*)malloc(sizeof(nodes));  	          	
    	        	iter = iter->next;
    	               
    	            free(checkArr);
    	        }
    	        fscanf(fp,"%c",&d);
        	}          
    fclose(fp);  
return Root;    
}

float * stats_linkedlist(nodes *rootA,float results[4] )
{

    int counter = 0; 
    nodes *iter;
    iter = rootA;
    
    results[0] = iter->x;/*result [0] == max value*/
    results[1] = iter->x;/*result [1] == min value*/
    results[2] = 0 ;	 /*result [2] == mean value*/
    results[3] = 0 ;	 /*result [3] == std deviation value*/	
 
    	while(iter->next != NULL)
    	{ 
        	counter++;
        	if(iter->x > results[0]) results[0] = iter->x;
        	if(iter->x < results[1]) results[1] = iter->x;
        	results[2] = results[2]+iter->x;
        	iter = iter->next;
    	}

    	iter = rootA ;
    	results[2] = results[2]/counter;
    
    	while(iter->next != NULL)
   		{	 
        	results[3] = results[3] + ((results[2]-iter->x)*(results[2]-iter->x));
        	iter = iter->next;
    	}
    	results[3] = sqrt(results[3]/(counter-1));
  
return results;
}
struct difference * compare_arr_list(sn *Root, int *arr,struct difference diff[],int *count)
{
    int i = 0,inp,a=0,k=0,b=0;
    sn *New,*iter;
    
    arr = (int*)malloc(sizeof(int));
    arr[i] = 0 ;
    i++;
    
    	while(arr[i-2] != -1)
    	{
        	printf("%d.Index of Arr (Enter -1 to finish) : ",i);
        	scanf("%d",&arr[i-1]);
        
        	if(arr[i-1] != -1)arr = (int*)realloc(arr,(i+1)*sizeof(int));
        	i++;
    	}
    	
    printf("\n\n");

		do{
		
            printf("%d.Value of Llist (Enter -1 to finish): ",a+1);
            scanf("%d",&inp);
            
            New = (sn*)malloc(sizeof(sn));
            New->val = inp;
            New->next = NULL;
            
            a++;
           if(Root == NULL) Root = New;
           
           else
           {
               iter = Root;
               while(iter->next != NULL)iter = iter->next;
               iter->next = New;
           }
        }while(inp != -1);
        iter = Root;
      		
      		if(i > a)/*If the array element's number higher than linkedlist elements number*/
      		{			 /*increase the k when reach the low one*/
          		while(k != a-1)		/*And we create a 10 size of dynamic array*/
          		{
          			if (arr[k] != iter->val)
          			{     		
          				diff[b].n1 = arr[k];
          				diff[b++].n2 = iter->val;
          				*count= *count+1;
          				if(*count % 10 == 0) diff = (struct difference*)realloc(diff,(*count+10)*sizeof(struct difference));
          			}
          		iter = iter -> next;
          		k++;
          	}
          
          	while(k != i-2) /*linkedlist eleman sayisi kadar sayac sayildiktan sonra kalan elemanlar sayilir*/
          	{				/*Ayni sayıda girilmeyen elemanlar için yapildi*/

            	diff[b].n1 = arr[k];
            	diff[b++].n2 = 0;
            	*count = *count +1;   
            	if(*count % 10 == 0) diff = (struct difference*)realloc(diff,(*count+10)*sizeof(struct difference)); 
            	k++;    
          	}

      	}
      
      else/*If the linkedlist element's number higher than array elements number*/
      {
          while(k != i-2)
          {
              if (arr[k] != iter->val)
          	  {
          		  diff[b].n1 = arr[k];
          		  diff[b++].n2 = iter->val;
          	  }
          	iter = iter -> next;
          	k++;
          }
          
          while(k != a-1)
          {  	
              diff[b].n1 = 0;
              diff[b].n2 = iter->val;
              *count = *count+1;   
                  if(*count % 10 == 0) diff = (struct difference*)realloc(diff,(*count+10)*sizeof(struct difference)); 
              iter= iter->next;
              k++;
              b++;
          }
                    
     }
     iter = Root;
     a = 0;
     
     printf("\n\nDynamic Arr ==> ");/*Printing the array (user's input )*/
     if(arr[a] == -1) printf("This array is empty ");
     else printf("{");
     while(arr[a]!= -1)
     {
     	printf(" %d",arr[a]);
     	if(arr[a+1] != -1)printf(",");
     	a++;
     }
     printf(" }\n");  
    
     printf("Linkedlist  ==> ");/*Printing the Linked list(user's input )*/
     if(iter->val == -1) printf("This linkedlist is empty \n");
     else printf("{");
     while(iter->next != NULL)
     {
     	printf(" %d",iter->val);
     	if(iter->next->next != NULL)printf(",");
     	else printf(" }\n");
     	iter = iter->next;
     }
     free(arr);
     free(Root);
  return diff;
}













