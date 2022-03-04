#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodes{

	int count;
	char letter;
	struct nodes *left,*right,*next;

}freq;

freq *countarr(freq *freqArr,char *filen);
freq *mintomax(freq *frequencies);
freq *drw_tree(freq *root, freq *arr);
void  minmaxcopy(freq **cpy);
void findcode(freq *root,char c,char *code,int i,char *transport);
void read_write_dat(freq *rootl, char *messagetxt, char *encodeddat,int *a);
void decodetxt(freq *root, char *decodetxt, char *encodedat);
freq *controlfunc(freq *root,char c);


int main()
{

	char*filename ="reference.txt";
	char *message = "message.txt";
	char *dat = "encoded.dat";
	char *decode = "decode.txt";
	int byte;

	freq *dynmcfreq=(freq*)malloc(sizeof(freq));
	freq *iter,*rootl = (freq*)malloc(sizeof(freq));

	FILE *fp;
	

	dynmcfreq  = countarr(dynmcfreq,filename);
	dynmcfreq = mintomax(dynmcfreq);
	rootl = drw_tree(rootl,dynmcfreq);
	read_write_dat(rootl,message,dat,&byte);
	printf("SIZEOF ENCODE.DAT = %d byte\n",byte);
	printf("WELL DONE\n(except decode.txt)\n");
	//decodetxt(rootl,decode,dat);

					/*NOTE TO TEACHER*/
	 
	/*Hocam iyi gunler decoded.txt dosyasini acarken fatal error veya encoded.dat dosyasina yazdiktan sonra
	okuma yaparken "rb" seklinde acildiginda segment fault hatasi aliyorum. Dosya acilirken olan bu hatayi
	decode.txt fonksiyonunu isleme katarak gorebilirsiniz. Fonksiyonun icinde sadece file acilirken sorun cikiyor
	ama yine de decode fonksiyonunun algoritmasini ve islemini yazdim yorum satiri halinde duruyor.Iyi gunler*/
	//printf("BASARILI");		



return 0;

}
freq *countarr(freq *freqArr, char *filen)
{
	int count = 0,a,control=0,i=1,sayac=1;
	char d;

	FILE *fp_ref;

		fp_ref = fopen(filen,"r");
		
		fscanf(fp_ref,"%c",&d);
		while(!feof(fp_ref) && d != '\0')// if I don't put these if conditions then there is a empty value in this array
		{		
				while(count != i)
				{
					
					if(freqArr[count].letter == d)
					{
						freqArr[count].count++;
						control = 1; 
					}
					count++;
				}
				
				if(control != 1)
				{
					sayac++;
					freqArr = (freq*)realloc(freqArr,sayac*sizeof(freq));
					
					freqArr[i-1].letter = d;
					freqArr[i-1].count  = 0; // ayrilan yerin değerini sifirlama
					freqArr[i-1].count++;
					freqArr[i].count = -1;
					i++;
				}	
			count = 0;
			control = 0;
			fscanf(fp_ref,"%c",&d);
		}
	fclose(fp_ref);

return freqArr;
}

freq *mintomax(freq *frequencies)
{
	char tempchar;
	int tempcount,count=0,j=1;

		while(frequencies[count].count != -1)
		{

				while(frequencies[j].count != -1)
				{
					if(frequencies[count].count > frequencies[j].count) 
					{
						tempcount = frequencies[j].count;
						tempchar  = frequencies[j].letter;
						
						frequencies[j].letter     = frequencies[count].letter;
						frequencies[j].count      = frequencies[count].count;
						
						frequencies[count].letter = tempchar;
						frequencies[count].count  = tempcount;
					}
					j++;
				}
				
			count++;
			j = count+1;
		}

		/*for(int i = 0 ; frequencies[i].count != -1 ; i++ )
		printf(" %c --> %d",frequencies[i].letter,frequencies[i].count);//abccddefaae*/

	printf("\n\n");

return frequencies;
}	
freq *drw_tree(freq *root, freq *arr)
{
	freq **copyarr=(freq**)malloc(sizeof(freq));
	int i,temp1,SIZE=0,incrcount=0;

	for ( i = 0; arr[i].count != -1 ; i++)
	{
		copyarr[i] = (freq*)malloc(sizeof(freq));

		copyarr[i]->count = arr[i].count;
		copyarr[i]->letter =arr[i].letter; 

		copyarr[i]->left = NULL;
		copyarr[i]->right = NULL;
		
			if(arr[i+1].count == -1 )
			{
				copyarr[i+1] = (freq*)malloc(sizeof(freq));
				copyarr[i+1]->count = -1;
			}
		SIZE++;
	}
	i = 0 ;

	while(copyarr[i+1]->count != -1)
	{		
		copyarr[SIZE+incrcount+1] = (freq*)malloc(sizeof(freq));
		
		copyarr[SIZE+incrcount]->left = copyarr[i];	
		copyarr[SIZE+incrcount]->right = copyarr[i+1];	
		copyarr[SIZE+incrcount+1]->count = -1; 

		/*ORNEK ILE ANLATIM */

		/*FIKIR = {3,4,5,6} --> ilk islem => 3+4 = 7 */ 	
		/*{5,6,7} 7->right = 4 - 7->left = 3 oluyordu*/	
		/* fakat 5 ve 6 sayilari bir agacin devamı degil yeni bir dal oldugu icin değerler
		kayboluyordu. Bunu da arrayden eleman eksiltmeden toplam degerini sona ekleyerek ve 2 eleman gittigi için de counter degerini
		ikişer arttirarak cozdum.*/
		/*ayni ornekten devam edersem --> 3 ve 4 elemanlarini silmeden toplamlari son eleman olacak sekilde devam ettim.*/
		/*{(3),4,5,6,*7*} --> sort edildikten sonra ayni sekilde kaliyor ve 7->left = 3 && 7->right = 4 islemlerini yaptim counteri 
		2 arttirdim artik counter degerim 0.indis degil 2.indisi gosteriyor */
		/*{3,4,(5),6,7} --> 5 + 6 = 11 ----> arrayin yeni hali = {3,4,5,6,7,11} siralama fonksiyonuna gonderildikten sonra da ayni kalir
		ve counter yine iki arttirilir artık counter 4.indiste */
		/*{3,4,5,6,(7),11} --> 7 + 11 = 18 ---> arrayin yeni hali {3,4,5,6,7,11,18} sort isleminden sonra da ayni kalir ve 18 in bir indis 
		fazlasi -1(stop) degerine esit olacagindan program burada sonlanir ve en sonra linkedliste esitlenip sadece agac elde edilir*/

		if(copyarr[i+1]->count != -1) copyarr[SIZE+incrcount]->count = copyarr[i]->count + copyarr[i+1]->count;

		/*printf("\n*%d*",copyarr[i]->count);*/	
		minmaxcopy(copyarr);
		
		i+=2;
		incrcount++;
	}
	root= copyarr[i];
return root;
}
void minmaxcopy(freq **cpy)
{
	int tempcount,count=0,j=1;

		while(cpy[count]->count != -1)
		{

				while(cpy[j]->count != -1)
				{
					if(cpy[count]->count > cpy[j]->count) 
					{
						tempcount = cpy[j]->count;
						cpy[j]->count      = cpy[count]->count;
						cpy[count]->count  = tempcount;
					}
					j++;
				}
				
			count++;
			j = count+1;
		}

}
void findcode(freq *root, char c, char *code, int i,char *transport)
{	
	if(root ==  NULL)
	{
		return ;
	}

	if(root ->right == NULL && root->left == NULL && c == root->letter)
	{
		
		strcpy(transport,code);
	}
	
	if(root->right != NULL) /*First letter's code shows 2 different icon (i didn't solve)*/
	{
		code = (char*)realloc(code,(i+1)*sizeof(char));
		code[i] = '1';
		i++;
		findcode(root->right,c,code,i,transport);/*If the right side is over then we will have to delete the last index of the array */
		i--;							/*If we won't delete then the codes shown the ruins of previous letter so it will be wrong */
	}									

	if(root->left != NULL)
	{
		code = (char*)realloc(code,(i+1)*sizeof(char));
		code[i] = '0';
		i++;
		findcode(root->left,c,code,i,transport);/*If the left side is over then we will have to delete the last index of the array */
		i--;						  /*If we won't delete then the codes shown wrong */
	}

}
void read_write_dat(freq *rootl, char *messagetxt, char *encodeddat,int *a)
{
	char *cod = (char*)malloc(10*sizeof(char));
	freq *iter;
	char d,*transport = (char*)calloc(10,sizeof(char));
	char *read = (char*)calloc(10,sizeof(char));
	char *copy = (char*)calloc(10,sizeof(char));
	char *copy2 = (char*)calloc(10,sizeof(char));
	int count = 0,i = 0,j=0,k =0;

	FILE *fpmessage,*fpencode,*fptry;
	iter = rootl;

	fpmessage = fopen(messagetxt,"r");
		while(!feof(fpmessage))
		{
			fscanf(fpmessage,"%c",&d);
			read[i] = d;
			i++;
			if(i %10 == 0)read = (char*)realloc(read,(i+10)*sizeof(char));

		}
		//fclose(fpmessage);--> if i close the file then it occurs an error(double free error)
		i = 0;
		while(read[i]!= '\0')
		{
			d = read[i];
			findcode(iter,d,cod,count,transport);
			
			k = 0;
			while(transport[k] == '1' || transport[k] == '0')
			{
				copy[j] = transport[k]; 
				if(j % 10 == 0)copy = (char*)realloc(copy,(j+10)*sizeof(char));
				j++;
				k++;
			}	
			i++;
		}

		*a = strlen(copy);
		*a = *a-k;
		i=0;
		copy2 = (char*)calloc((*a-k),sizeof(char));
		
		while(i!= *a-k)
		{
			copy2[i] = copy[i];
			i++;
		}

		fpencode = fopen(encodeddat,"wb");
		fputs(copy2,fpencode);
		fclose(fpencode);
		
		free(transport);
		free(copy);
		free(copy2);
		free(read);

}
/*void decodetxt(freq *root, char *decodetxt, char *encodedat)
{
	FILE *fp,*fp_2;
	freq *iter;
	char *d;

		iter = root;
		fp_2 = fopen(decodetxt,"w");

		fp = fopen(encodedat,"rb");

		while(!feof(fp))
		{
			fread(d,sizeof(char),1,fp);
			iter = controlfunc(iter,d[0]);

			if(root->right == NULL && root->left == NULL)
			{
				fputs(d,fp_2);
				iter = root;
			}
		}

		fclose(fp);
		fclose(fp_2);

}

freq *controlfunc(freq *root,char c)
{
	if(root->right == NULL && root->left == NULL) return root;

	if(c == '1') root = root->right;
	if(c == '0') root = root->left;

return root;
}*/



