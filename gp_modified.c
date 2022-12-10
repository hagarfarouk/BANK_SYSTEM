#include <stdio.h>
#include "STD_Types.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define Null ((void*)0)



typedef struct Node Node;

  void add(Node* ptr);
  //void get_grd_id(Node* ptr);
  //Node *create(char* , char* , u8 , u32 , u32  );
  Node *search(u32 value);
  void update_status(u32 _id,int st);
  void update_balance(u32 _id ,u32 cash ,char x );
  void update_pw(u32 _id,u32 password);
  int find_id(u32 _id);
  int find_balance(u32 _id);
  void create(char* n, char* add, u8 old, u32 value, char* national_id, char* gid );

struct Node{
	u32 data;
	u32 pw;
	char *status;
	u32 id;
	char na_id[15];
	char grd_id[15];
	char *name;
	char* address;
	u8 age;
	Node *Prev;
	Node *Next;
};

Node *first = Null;
Node *last = Null;

u32 Admin_pw = 9999;
u32 user_id(){
	int found; int n=0;
	u32 id=0;
	printf("Please Enter Account ID: ");
		scanf("%d", &id);
		found = find_id(id); //bool
		while ((!found) && (n<3))
		{
			printf("ID Not Found, Please Try again ");
			scanf("%d", &id);
			found = find_id(id); //bool
			n++;
			if (n==3 && !found) 
			{ 
			 printf("Invalid ID , No More Tries");
			 return 0;
			}
		}
	return id;	
}


void admin(){
	
	
	int c=0; //counter
	//int balance=0; 
	int pw=0; int x=0;  int t=1;
	printf("Enter Admin PW: \n");
	scanf("%d",&pw);
	while (pw!=Admin_pw && c<3)
	{
		printf("Wrong Password! , Please Try Again");
		c++;
		scanf("%d",&pw);
	}
	if (pw!=Admin_pw && c==3) {
		printf("You Have No Access! ");
		
		t=0; 
	} 
	//if (t==1) 
	while (t)
  { 
	printf("\n\t\t\t\t WELCOME TO ITI BANK \n");
	printf("For Creating New Account , Please Press 1\n");
	printf("For Openning Existing Account , Please Press 2\n");
	printf("Press 0 To Exit\n" );
	scanf("%d",&x);
	if (x==0) {  printf("                  THANK YOU\n");
		break;
	}
	
 
 if (x==1){
		char name[200]; char address[200];
		u8 age; char national_id[15]; char * status; u32 cash;  char gid[15];
		printf("Enter Full Name: ");
		   fflush(stdin);
		scanf("%[^\n]%*c", name);

		printf("Enter Full Address: ");
			fflush(stdin);
		 scanf("%[^\n]%*c", address);

		printf("Enter Age: ");
		scanf("%d", &age);
		int counter =0; int id_flag=0;
		printf("Enter National ID: ");
		scanf("%s",&national_id);
		while (counter<3 && id_flag<1)
		{
			if (strlen(national_id)!=14)
		{
			printf("incorret national id , please try again");
			scanf("%s",national_id);
			counter++;

		}
			else id_flag=1;
		}
		if (counter == 3 && id_flag == 0)
		{
			printf("\n\t\t\t you can't create account without National ID");
			continue;
		}
		if (age<21)
		{
			 int gcounter =0; int gid_flag=0;
			printf("Enter Guardian National ID: \n");

			
	 		scanf("%s",&gid);
	 		while (gcounter<3 && gid_flag<1)
	 		{
	 			if (strlen(gid)!=14)
	 		{
	 			printf("incorret national id , please try again");
	 			scanf("%s",gid);
	 			gcounter++;

	 		}
	 			else gid_flag=1;
	 		}
	 		if (gcounter == 3 && gid_flag == 0)
	 		{
	 			printf("\n\t\t\t you can't create account without National ID");
	 			continue;
	 		}

	 

		}
		printf("How Much Money For Deposit: ");
		scanf("%d",&cash);
		printf("\n");
		 //char *name = "hagar farouk";
		 //char *address = "lalalla la";
		// if (age <21)
		// {	printf("Enter Guardian National ID: \n");
			// scanf("%d", &g_id);
		// }

		create(name,address,age,cash,national_id,gid);
		
		printf("Congratulations! Your Account is Created Succsessfully  ");

		printf("%s\n",name);
		printf("\n");

	}
	
	if (x==2)
	{   u32 id;
		printf("Enter Your ID: ");
		id = user_id();	
		if (id==0)
		continue;
		int y=0;
		printf("For Making Transaction, Plesae Press 1:\n ");
		printf("For Changing Account Status , Please Press 2: \n");
		printf("For Getting Cash , Please Press 3: \n");
		printf("To Deposit in Account , Please Press 4:\n");
		printf("To Exit, Please Press 5:\n");
		scanf("%d", &y);
		if(y==1)
		{   
			u32 tran_id; u32 m=0; u32 balance=0;
			printf("How Much You Want for Transaction: \n");
			scanf("%d",&m);
			tran_id = user_id();
			balance = find_balance(id);    ////////
			if (balance<m)
			  continue;
			
	     update_balance( id,m,'n');
		 update_balance(tran_id,m,'p');
			
		
		}
		if (y==2)
		{	int st=0;
			printf("Enter 1 to Set Account to Active");
			printf("Enter 2 to Set Account to Restricted State");
			printf("Enter 3 to Set Account to Closed");
			scanf("%d",&st);
			update_status(id,st);

			
		}
		
		if (y==3)
		{
			u32 cash; u32 balance=0;
			printf("Enter amount of cash: \n");
			scanf("%d",&cash);
			balance = find_balance(id);
			if (balance < cash);
			{ printf("\n\t\t\t Sorry , Not Enough Balance \n");
			  continue;
			}
			update_balance(id,cash,'n');
			
			
		}
		if (y==4)
		{
			u32 depo=0;
			printf("Enter Amount of cash you want to add in this account: ");
			scanf("%f",&depo);
			update_balance(id,depo, 'p');
			
		}
	}
	
	}	
}

void client(){
	u32 id=0; int t =1;
		printf("Please Enter Your ID: ");
	id = user_id();	
		if (id==0) t=0;
	if (t==1)  printf("\n\t\t\t\t Welcome To ITI Bank\n");
 while(t) 
  {	
	
		
	int y=0;
		printf("For Making Transaction, Plesae Press 1:\n ");
		printf("For Changing Account Password , Please Press 2: \n");
		printf("For Getting Cash , Please Press 3: \n");
		printf("To Deposit in Account , Please Press 4:\n");
		printf("To Exit, Please Press 0:\n");
		scanf("%d", &y);
		if(y==1)
		{  u32 balance=0;
			u32 tran_id=0; u32 m=0; 
			printf("Enter ID You Want To Transfer To it: \n");
			tran_id = user_id();
				if (tran_id==0)
		            continue;
			//Printf ("Enter Amount of Money Needed: \n");
			scanf("%d", &m);
			balance = find_balance(id);
			if (balance<m)
			{ printf("Sorry , Not Enough Balance \n");
				continue;
			 }
			update_balance( id,m,'n');
		 update_balance(tran_id,m,'p');
		
		}
		if (y==2)
		{	u32 pw =0;
	
			printf("Enter Your New Password: \n");
			scanf("%d",&pw);
			update_pw(id,pw);

			
		}
		
		if (y==3)
		{
			u32 cash; u32 balance=0;
			printf("Enter amount of cash: \n");
			scanf("%f",&cash);
			balance = find_balance(id);
			if (balance< cash);
			{ printf("Sorry , Not Enough Balance \n");
			continue;
			}
			update_balance(id,cash,'n');
			
		}
		if (y==4)
		{
			u32 depo=0;
			printf("Enter Amount of cash you want to add in this account: ");
			scanf("%f",&depo);
			update_balance(id,depo,'p');
			
		}
		
		if(y==0)
		{
			printf("\n\t\t\t\t\t HAVE A NICE DAY! \t\t Thank You ");
			break;
			
		}
  }
}



void main(){
	int x;
	while (1)
	{
	printf("\n\t\t\t\t Welcome To ITI Bank\n");
	printf("If you are one of our team Please Press 1: \n");
	printf("If You are One of our Custmers Please Press 2: \n");
	scanf("%d",&x);
	if (x==1)
		admin();
	else if (x==0) break;
	else client();
	
}}


void create(char* n, char* _address , u8 old , u32 value, char* national_id , char* gid )
{
	srand(time(NULL)); 
	Node *New = (Node*)malloc(sizeof(Node));
	New->data = value;
	for (int i=0; i<15; i++)
	{
		New->grd_id[i] = *(gid+i);
		New->na_id[i] = *(national_id+i);
		
	}
	New->age = old;
	New->status = "Active";
	New->name = n; 
	New->address = _address;
	New->id = rand();
	New->pw = (rand() % (100-0+1));
	New->Prev = Null;
	New->Next = Null;
	printf("Your Bank ID is:%d \n", New->id);
	//printf("Your national ID is %d \n",New->na_id);
	add(New);
	
	//return New;
}

 void add(Node* ptr){
	 
	 if(first==Null){
		 first = last = ptr;
	 }else{
		 ptr->Prev = last;
		 last->Next = ptr;
		 last = ptr;
	 }
 }
 // void get_grd_id(Node* ptr){
	 // u32 gid;
	 // printf("Enter Guardian National ID: \n");
	 // scanf("%d,&gid");
	 // ptr->grd_id = gid;
	 
 // }

// void DisaplyAll(void){
	// u8 count=0;
	
	// Node *display = first;
	
	// while(display!=Null){
		// count++;
	// printf("%d\n", display->data);
	// display=display->Next;
	// }
	
	// printf("number of elemets = %d\n", count);
	
	// if(count==0){
		// printf("Linked list empty");
	// }
	// /*if(first==Null){
		// printf("Linked list empty");
	// }*/
// }

Node *search(u32 value){
	Node *search = first;
	while(search!=Null){
		if(search->id == value){
			return search;
		}else{
			search= search->Next;
		}
	}
	return Null;	
}
void update_status(u32 _id,int st)
{
	Node * ptr= search(_id);
	if ( st == 1)
		ptr->status = "Active";
	else if(st==2)
	{
	   ptr->status = "Restricted";	
	}
	else
		ptr->status = "Closed";
}
 void update_balance(u32 _id ,u32 cash ,char x ){
	 Node * ptr = search(_id);
	 if (x == 'n' )
		 ptr->data -= cash;
	 else ptr->data +=cash;
	 printf("%s's", ptr->name);
	 printf(" balance is now: %d \n", ptr->data);
 }
 void update_pw(u32 _id,u32 password){
	  Node * ptr = search(_id);
	  ptr->pw = password;
	 
 }
 
 int find_id(u32 _id){
	 Node * ptr = search(_id);
	 if (ptr!=NULL)
		 return 1;
	 return 0;
 }
 int find_balance(u32 _id){
	  Node * ptr = search(_id);
	  return ptr->data;
	 
 }




