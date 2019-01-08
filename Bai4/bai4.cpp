#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
// Con chuot


int n=5; // Kich thuoc that me cung
int t,d,c;
int x,y;

FILE *f;

int mt [7][7] =
 { 0,0,0,0,0,0,0,
   0,1,0,1,1,0,0,
   0,1,1,0,1,1,0,
   0,0,1,0,1,0,0,
   0,0,1,1,1,0,0,
   0,1,1,0,1,1,0,
   0,0,0,0,0,0,0};

void In_nghiem();
void thu(int i);
 
 int main()
 {     for (t=1;t<=5;t++)
      if (mt[t][1]==1)
      {  x=t;y=1;mt[t][1]=2;
	 thu(1);
	 mt[t][1]=1; }
    getch();
    return 0;}
      


// ma tran gia so
  int h[4]={1,0,0,-1};
  int v[4]={0,-1,1,0};

// In nghiem
 void In_nghiem()
 { 
 f=fopen("output4.txt","wt");
 printf("-------------------------------------\n");
   for (d=1;d<=5;d++)
   { for (c=1;c<=5;c++)
    if (mt[d][c]==2){
	printf(" c");
	 fprintf(f,"c");
	 }
	else
	printf("%2d",mt[d][c]);
	 fprintf(f,"%2d",mt[d][c]);
      printf("\n");
	fprintf(f,"\n");
	  }
   printf("-------------------------------------\n");
   fprintf(f,"-------------------------------------\n");
   fclose(f);
      }

// Thu di
 void thu(int i)
{ int j;
  int p,q;

     for(j=0;j<=3;j++)
     {
      p=x+h[j];
      q=y+v[j];
       if (mt[p][q]==1)
	  { x=p;y=q;
	    mt[p][q]=2;
	    if (y!=n)
	      thu(i+1);
	    else
	      In_nghiem();
	      mt[p][q]=1;
	      x=x-h[j];
	      y=y-v[j];
	   }
       }

 }


      
 

