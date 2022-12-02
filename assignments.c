//// ***********assignments of lecture 1 *************///////////////
#include <stdio.h>
void main() {
   int i, space, rows, stars = 0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i, stars = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      while (stars != 2 * i - 1) {
         printf("* ");
         ++stars;
      }
      printf("\n");
   }
   
}
////////////////// assignment 2 /////////////////////
#include <stdio.h>
void main() {
  int x , y , z;
  printf("Please Enter Number 1: ");
  scanf("%d",&x);
   printf("Please Enter Number 2: ");
  scanf("%d",&y);
   printf("Please Enter Number 3: ");
  scanf("%d",&z);
  printf("number 3: %d\n",z);
  printf("number 2: %d\n",y);
  printf("number 1: %d\n",x);
}
//////////////////// assignment 3 ///////////////
#include <stdio.h>
 void main() {
	int x , y;
	printf("enter 2 numbers: ");
	scanf("%d",&x);
	scanf("%d",&y);
	printf("a+b= %d\n",x+y);
	printf("a-b= %d\n",x-y);
	printf("a*b= %d\n",x*y);
	printf("a/b= %d\n",x/y);
	printf("a|b= %d\n",x|y);
	printf("a^b= %d\n",x^y);
}


//// ***********assignments of lecture 2 *************///////////////

#include <stdio.h>
void main(){
	int arr[10];
	for(int i=0; i<10; i++)
	{printf("Enter Number %d  :  ",i+1);
		scanf("%d",&arr[i]);
}
 int x=0,f=0;
 printf("enter a value to search: ");
 scanf("%d",&x);
 for (int i=0; i<10; i++)
 {
	 if (arr[i]==x)
	 {	 printf("it exists in element %d \n ",i+1);
			f = 1;
 }
} if (f==0)
	printf("it doesn't exist");
}
//////////////// assignment 2 //////////////////
#include <stdio.h>
void main(){ float i; float password ;
	float id = 7777;
	float pw = 0000;
	char s[20] = "hagar farouk";
	printf("Please Enter Your ID: ");
	scanf("%f",&i);
	if(i==id)
	{
		printf("enter your password : ");
		scanf("%f",&password);
		if (pw==password)
			printf("hello %s\n ",s);
		else printf("incorrect password");
		
	}
		
	else printf("incorrect ID ");
}
////////////// assignment 3 /////////////

#include <stdio.h>
void main (){
	int arr[3] , max =0;
	for (int i =0; i<3; i++)
	{
		printf("enter number %d ",i+1);
		scanf("%d",&arr[i]);
		if (max<arr[i])
			max = arr[i];
	}
	printf("the maximum = %d", max);
}


//// ***********assignments of lecture 3 *************///////////////
#include <stdio.h>
 void main(){
	 int x , y;
	 while (1){
		 printf ("enter number 1: ");
		 scanf("%d",&x);
		 printf ("enter number 2: ");
		 scanf("%d",&y);
		 printf("the result =  %d \n", x+y);
		 
	 }
 }
 ////////////////// assignment 2 ////////////////////
 #include <stdio.h>
 void main()
 {	float i , pw;	
	 int c =0;
	 float id = 7777;
	 float password = 1111;
	 char s[20] = "hagar farouk ";
	 printf("Please Enter Your ID: ");
	scanf("%f",&i);
	if(i==id)
	{    
		printf("enter your password : ");
		scanf("%f",&pw);
		while (pw!=password && c<3){ ++c;
			printf("incorrect password, try again ");
			scanf("%f",&pw);
		}
	    if (pw!=password && c==3)   printf("incorrect password, no more tries");
		else printf("hello %s\n ",s);
		
	}
		
	else printf("incorrect ID ");
}
	 //// ***********assignments of lecture 4 *************///////////////
 
 #include <stdio.h>
void main (){
	int arr[10] , max =0 , min =99;
	for (int i =0; i<10; i++)
	{
		printf("enter number %d ",i+1);
		scanf("%d",&arr[i]);
		if (max<arr[i])
			max = arr[i];
	    if (arr[i]<min)
			min = arr[i];
	}
	printf("the maximum = %d \n", max);
	printf("the minimum = %d  \n", min);
	
}

 //// ***********assignments of lecture 6 *************///////////////
 /////////// assignment 1 bubble sorting ///////////
  #include <stdio.h>
 void main (){ int tmp =0;
	 int arr[5];
	 for (int i=0; i<5; i++)
	 {
		 printf("enter number %d  ",i+1);
		 scanf("%d",&arr[i]);
		 
	 }
	 for (int i=0; i<5;i++)
	 {
		 for (int j=1; j<5-i;j++)
		 {
			 if (arr[j]<arr[j-1])
			 {
				 tmp = arr[j];
				 arr[j]= arr[j-1];
				 arr[j-1]= tmp;
			 }
		 }
	 }
 
 for (int i=0; i<5; i++)
	 printf("number %d = %d  \n",i+1, arr[i]);

 }


 
 
 /////// assignment 2 ///////////
 #include <stdio.h>
 void main(){
	 int x =0 ,y=1 ,z=2;
	 int *p=&x , *q=&y, *r=&z;
	 printf("%d \n", x);
	 printf("%d \n", y);
	 printf("%d \n", z);
	 printf("%d \n", p);
	 printf("%d \n", q);
	 printf("%d \n", r);
	 printf("%d \n", *p);
	 printf("%d \n", *q);
	 printf("%d \n", *r);
	 printf("swapping pointers: \n ");
	 r = p;
	 p=q;
	 q=r;
	 printf("%d \n", x);
	 printf("%d \n", y);
	 printf("%d \n", z);
	 printf("%d \n", p);
	 printf("%d \n", q);
	 printf("%d \n", r);
	 printf("%d \n", *p);
	 printf("%d \n", *q);
	 printf("%d \n", *r);
	 
	 
 }


//// ***********assignments of linkedlist *************///////////////

void insertAfter(Node *after, Node *new){
	new->prev = after;
	new->Next =  after->Next;
	after->Next->prev = new;
	after->Next = new;
}


void delete(Node *delete){
	if(delete==first){
		if(delete==last){
			first = last = Null;
		}else{
			first = first->Next;
			first->Prev = Null;
		}
	}else if(delete == last){
		last=last->Prev;
		last->Next = Null;
	}else{
		delete->Prev->Next = delete->Next;
		delete->Next->Prev = delete->Prev;
	}
	free(delete);
}


