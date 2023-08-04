#include<stdio.h>
#include<stdlib.h>
#define N 5
struct node   //Node of priority Queue
{
 int data,pr;
 struct node *next;
};
struct node *head=NULL;
typedef struct dblq   //Node of Double Ended Queue
{
 int data;
 struct dblq *next;
} dblq;
dblq *first=NULL,*last=NULL;
typedef struct o
{
 int data;
 struct o *next;
}o;
o *front=NULL,*rear=NULL;

int f=-1,r=-1,a=-1,z=-1,arr[N],A[N];
int deal_static();
    int dbl_s();
	int s();         //Case 1
	int e();         //Case 2
	int del_s();     //Case 3
	int del_e();     //Case 4
	int print_dbl_s();//Case 5
    int circle_s();
	int nq_s();      //Case 1
	int print_peek();//Case 2
	int dq_s();      //Case 3
	int display_s(); //Case 4
int deal_dynamic();
    int priority();
	int insert();     //Case 1
	int print_h_p();  //Case 2
	int delete_h_p(); //Case 3
	int print();      //Case 4
    int dbl();
	int start();      //Case 1
	int end();        //Case 2
	int del_start();  //Case 3
	int del_end();    //Case 4
	int print_dbl();  //Case 5
    int cicle();
	int nq();         //Case 1
	int print_front();//Case 2
	int dq();         //Case 3
	int display();    //Case 4

///////////////////////////////////////////////////////////////////////
void main()
{
 int c;
 struct node *del;
 dblq *fre;
 o *n;
 clrscr();
 while(1)
 {
  printf("******Queue******\n1 Static memory allocation\n2 Dynamic memory allocation\n");
  printf("Enter your choice   ");
  scanf("%d",&c);
  printf("\n\n");
  switch(c)
  {
   case 1:deal_static();break;
   case 2:deal_dynamic();break;

   default:goto free_mem;exit(1);break;
  }
 }
  free_mem:{  printf("\n");
	      del=head;
	      while(del!=NULL)
	      {
		head=head->next;
		free(del);
		printf("Memory of a priority queue node Deallocated\n");
		del=head;
	      }
	      fre=first;
	      while(fre!=NULL)
	      {
		first=first->next;
		free(fre);
		printf("Memory of a Double ended Queue node Deallocated\n");
		fre=first;
	      }
	      if(front!=NULL){
	      while(1)
	      {
		{n=front->next;
		 free(front);
		 front=n;
		 printf("Memory of a Circular Queue node Deallocated\n");
		 if(front==rear)
				 break;
		}free(rear);
		printf("Memory of a Circular Queue node Deallocated\n");
	      }               }
	   }
    getch();
}//////////////////////////////////////////////////////////////////////
int deal_static()
{
 int c;
 while(1)
 {
  printf("******Queue (Static memory allocation)******\n1 Double ended Queue\n");
  printf("2 Circular Queue\nEnter your choice   ");
  scanf("%d",&c);
  printf("\n");
  switch(c)
  {
   case 1:dbl_s();break;
   case 2:circle_s();break;
   default:return 1;break;
  }
 }
}
int dbl_s()                //Function to deal with Double ended queue
{
 int c;
 while(1)
 {
  printf("Double Ended Queue\n1 Add a node in starting\n2 Add a node at the end\n");
  printf("3 Delete First Node\n4 Delete Last node\n5 Print\nEnter your choice  ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:s();break;
   case 2:e();break;
   case 3:del_s();break;
   case 4:del_e();break;
   case 5:print_dbl_s();break;
   default:return 0;break;
  }
 }
}
int s()            //Case 1 Double ended Queue
{
 int data;
 if(f==N-1){
     printf("Queue is full\n\n\n");
     return 1;}
 printf("Enter data to be entered in starting of queue   ");
 scanf("%d",&data);
 if(f==-1&&r==-1)
	     r++;
 f++;
 arr[f]=data;
 printf("Entered %d in starting of queue\n\n\n",data);
}
int e()              //Case 2 Double ended Queue
{
 int data,i,initial_f;
 if(f==N-1){
     printf("Queue is full\n\n\n");
     return 1;}
 printf("Enter data to be entered in ending of queue   ");
 scanf("%d",&data);
 if(f==-1&&r==-1){
	     f++; r++;
	     arr[f]=data;
	     printf("Entered %d in ending of queue\n\n\n",data);
	     return 1;
		 }
 initial_f=f;
 for(i=f+1;i>0;i--)
 {
  arr[i]=arr[f];
  f--;
 }
 arr[r]=data;
 f=initial_f+1;
 printf("Entered %d in ending of queue\n\n\n",data);
}
int del_s()               //Case 3 Double ended Queue
{
 if(f==-1){
     printf("Queue is Empty\n\n\n");
     return 1;}
 printf("Deleted %d from starting of the queue\n\n\n",arr[f]);
 f--;
 if(f==-1)
      r=f;
 return 1;
}
int del_e()                 //Case 4 Double ended Queue
{
 int i;
 if(f==-1){
     printf("Queue is Empty\n\n\n");
     return 1;}
 printf("Deleted %d from ending of the queue\n\n\n",arr[r]);
 for(i=r;i<f;i++)
       arr[i]=arr[i+1];
 f--;
 if(f==-1)
      r=f;
 return 1;
}

int print_dbl_s()                   //Case 5 Double ended Queue
{
 int i;
 if(f==-1){
     printf("Queue is empty\n\n\n");
     return 1;
	  }
 for(i=f;i>=r;i--){
      printf("%d <-- ",arr[i]);}
 printf("\n\n\n");
}
////////////////////////////////////////////////////////////////////////////
int circle_s()                //Function to deal with Circular queue
{
 int c;
 while(1)
 {
  printf("Circular Queue\n1 Add a node at end\n2 Print front element\n");
  printf("3 Delete First Node\n4 Print Queue\nEnter your choice  ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:nq_s();break;
   case 2:print_peek();break;
   case 3:dq_s();break;
   case 4:display_s();break;

   default:return 0;break;
  }
 }
}
int nq_s()
{
 int data;
 if((z==N-1&&a==0)||(z==a-1))
 {
     printf("Queue is full\n\n\n");
     return 1;}
 printf("Enter data to be entered in starting of queue   ");
 scanf("%d",&data);
 if(a==-1)
 {
    a=0;
    z=0;
 }
 else if(z==N-1&&a!=0)
	 z=0;

 else
	 z++;
 A[z]=data;
 printf("Entered %d in starting of queue\n\n\n",data);
 return 1;
}
int print_peek()
{
   if(a==-1&&z==-1)
	    printf("Circular Queue is empty\n\n\n");
   else
	    printf("%d is in front of circular queue\n\n\n",A[a]);
   return 1;
}
int dq_s()
{
 if(a==-1&&z==-1){
	    printf("Circular Queue is empty\n\n\n");
	    return 1;}
 printf("%d deleted from circular queue\n\n\n",A[a]);
 if(a==z)    {
	a=-1;
	z=-1;
	return 1;}
 if(a==N-1)
     a=0;
 else a++;
 return 1;
}
int display_s()
{
 int i;
 if(a==-1&&z==-1){
	    printf("Circular Queue is empty\n\n\n");
	    return 1;}
 i=a;
 while(1)
 {
  if(i==z){
	   printf("%d \n\n\n",A[z]);
	   break;
	  }
  printf("%d <-- ",A[i]);
  i++;
  if(i==N)
       i=0;
 }
 return 1;
}
/////////////////////////////////////////////////////////////////////////////
int deal_dynamic()
{
 int c;
 while(1)
 {
  printf("******Queue (Dynamic memory allocation)******\n1 Priority Queue\n2 Double ended Queue\n");
  printf("3 Circular Queue\nEnter your choice   ");
  scanf("%d",&c);
  printf("\n\n");
  switch(c)
  {
   case 1:priority();break;
   case 2:dbl();break;
   case 3:circle();break;

   default:return 1;break;
  }
 }
}
int priority()             //Function to operate on priority queue
{
 int c;
   while(1)
 {
  printf("Priority Queue\n1 Add a node\n2 Print Highest Priority data\n");
  printf("3 Delete Highest Priority Data\n4 Print Queue\nEnter your choice  ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:insert();break;
   case 2:print_h_p();break;
   case 3:delete_h_p();break;
   case 4:print();break;
   default:return 0;break;
  }
 }
}
int insert()                            //Case 1 of Priority Q
{
 int data,p;
 struct node *new,*ptr;
 printf("Enter data  ");
 scanf("%d",&data);
 printf("Enter priority  ");
 scanf("%d",&p);
 new=malloc(sizeof(struct node));
 new->data=data;
 new->pr=p;
 if(head==NULL||head->pr<p)
    {
	  new->next=head;
	  head=new;
    }
 else{
	  ptr=head;
	  while(ptr->next!=NULL&&ptr->next->pr>=p)
		    ptr=ptr->next;
	  new->next=ptr->next;
	  ptr->next=new;

     }
 printf("%d entered with priority %d\n\n",data,p);
 return 1;
}
int print_h_p()                  //Case 2 of Priority Q
{
 if(head==NULL){
	 printf("Priority Queue is empty\n\n");
	 return 1;}
 printf("%d is at peek with priority %d.\n\n",head->data,head->pr);
 return 1;
}
int delete_h_p()                      //Case 3 of Priority Q
{
 struct node *del;
 if(head==NULL){
	 printf("Priority Queue is empty\n\n");
	 return 1;}
 del=head;
 head=head->next;
 printf("%d with priority %d is deleted.\n\n",del->data,del->pr);
 free(del);
 return 1;
}
int print()                          //Case 4 of Priority Q
{
 struct node *temp;
 if(head==NULL){
	 printf("Priority Queue is empty\n\n");
	 return 1;}
 temp=head;
 while(temp!=NULL)
 {
   printf("(data %d, priority %d) <-- ",temp->data,temp->pr);
   temp=temp->next;
 }
 printf("\n\n");
 return 1;
}
/////////////////////////////////////////////////////////////////////////////
int dbl()                //Function to deal with Double ended queue
{
 int c;
 while(1)
 {
  printf("Double Ended Queue\n1 Add a node in starting\n2 Add a node at the end\n");
  printf("3 Delete First Node\n4 Delete Last node\n5 Print\nEnter your choice  ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:start();break;
   case 2:end();break;
   case 3:del_start();break;
   case 4:del_end();break;
   case 5:print_dbl();break;
   default:return 0;break;
  }
 }
}
int start()              //Case 1 of Dbl ended Queue
{
 int data;
 dblq *new=malloc(sizeof(dblq));
 printf("Enter data to be entered in starting of queue   ");
 scanf("%d",&data);
 new->data=data;
 new->next=first;
 first=new;
 if(last==NULL)
	 last=first;
 printf("%d entered in first node.\n\n\n",data);
 return 1;
}
int end()                 //Case 2 of Dbl ended Queue
{
 int data;
 dblq *new=malloc(sizeof(dblq));
 printf("Enter data to be entered in ending of queue   ");
 scanf("%d",&data);
 new->data=data;
 new->next=NULL;
 last->next=new;
 last=new;
 if(first==NULL)
	 first=last;
 printf("%d entered in last node.\n\n\n",data);
 return 1;

}
int del_start()             //Case 3 of  Double ended Q
{
 dblq *temp=first;
 if(last==NULL){
      printf("Queue is empty\n\n\n");
      return 1;}
 printf("Deleted %d from first node of queue.\n\n\n",temp->data);
 first=first->next;
 free(temp);
 if(first==NULL)
	 last=first;
 return 1;
}
int del_end()              //Case 4 of Double ended Q
{
 dblq *del;
 if(last==NULL){
      printf("Queue is empty\n\n\n");
      return 1;}

 del=first;
 if(first->next==NULL)
	 first=NULL;
 while(del->next->next!=NULL)
	del=del->next;
 del->next=NULL;
 printf("Deleted %d from first node of queue.\n\n\n",last->data);
 free(last);
 last=del;
 if(first==NULL)
	last=NULL;
 return 1;
}
int print_dbl()             //Case 5 To print Double ended Q
{
 dblq *ptr;
 if(last==NULL){
      printf("Queue is empty\n\n\n");
      return 1;}
 ptr=first;
 while(ptr!=NULL)
      {
       printf("%d <-- ",ptr->data);
       ptr=ptr->next;
      }
 printf("\n\n\n");
 return 1;
}
///////////////////////////////////////////////////////////////////////////
int circle()          //Function to deal with circular queue
{
 int c;
   while(1)
 {
  printf("Circular Queue\n1 Add a node\n2 Print Peek\n");
  printf("3 Delete Peek\n4 Print Queue\nEnter your choice  ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:nq();break;
   case 2:print_front();break;
   case 3:dq();break;
   case 4:display();break;
   default:return 0;break;
  }
 }
}
int nq()                   //Case 1 of Circular Queue
{
 int data;
 o *new=malloc(sizeof(o));
 printf("Enter Data  ");
 scanf("%d",&data);
 new->data=data;
 if(front==NULL&&rear==NULL)
       { front=new; rear=new; }
 new->next=front;
 rear->next=new;
 rear=new;
 printf("Entered %d\n\n\n",data);
 return 1;
}
int print_front()                //Case 2 of Circular Queue
{
 if(front==NULL&&rear==NULL)
 {
    printf("Circular Queue is Empty\n\n\n");
    return 1;
 }
 printf("%d is in front.\n\n\n",front->data);
 return 1;
}
int dq()                   //Case 3 of Circular Queue
{
 o *del;
 if(front==NULL&&rear==NULL)
 {
    printf("Circular Queue is Empty\n\n\n");
    return 1;
 }
 if(rear->next==rear)
 {
   printf("%d deleted\n\n\n",rear->data);
   free(rear);
   rear=NULL;
   front=NULL;
   return 1;
 }
 del=rear;
 while(rear->next!=del)
      rear=rear->next;
 printf("%d deleted\n\n\n",del->data);
 free(del);
 rear->next=front;
 return 1;
}
int display()                      //Case 4 of Circular Queue
{
 o *ptr;
 if(front==NULL&&rear==NULL)
 {
    printf("Circular Queue is Empty\n\n\n");
    return 1;
 }
 printf(" <-- ");
 ptr=front;
 do{
    printf("%d <-- ",ptr->data);
    ptr=ptr->next;
   }while(ptr!=front);
 printf("\n\n\n");

 return 1;
}
//////////////////////////////////////////////////////////////////////////
