#include<stdio.h>
#include<stdlib.h>
typedef struct doubly_circular_list     //Structure of a node
{
  struct doubly_circular_list *prev;
  int data;
  struct doubly_circular_list *next;
}node;
node *tail=NULL;
node* add_beg(node* tail)    //Adds a node in starting          Case 1
{
 node *new; int data;
 printf("Enter data  ");
 scanf("%d",&data);          //if there is 0 node
 if(tail==NULL)
 { tail=(node*)malloc(sizeof(node));
   tail->prev=tail;
   tail->data=data;
   tail->next=tail;
 } else
 { new=malloc(sizeof(node));   //if atleast 1 node present
   new->prev=tail;
   new->data=data;
   new->next=tail->next;
   new->next->prev=new;
   tail->next=new;
 } return tail;
}
void add_end()           //Add last node   Case 2
{
 node *new; int data;
 printf("Enter data  ");
 scanf("%d",&data);
 if(tail==NULL)
 {  tail=malloc(sizeof(node));
    tail->data=data;
    tail->next=tail;
    tail->prev=tail;
 }else
 {  new=malloc(sizeof(node));
    new->next=tail->next;
    new->data=data;
    new->prev=tail;
    tail->next=new;
    new->next->prev=new;
    tail=new;
 }
}
int add_pos()      //Adds node at given position    case 3
{
  node *new,*p,*p2;
  int pos,data;
  printf("Enter position  ");
  scanf("%d",&pos);
  if(pos>count()+1||pos==0)   //if invalid position is entered
  {
    printf("Position unavailable.\n");
    return 0;
  }
  printf("Enter data  ");
  scanf("%d",&data);
  new=malloc(sizeof(node));
  new->data=data;
  if(tail==NULL&&pos==1)
  {
   new->prev=new;
   new->next=new;
   tail=new;
   return 1;
  }
  if(pos==1)
  {
    new->next=tail->next;
    new->prev=tail;
    new->next->prev=new;
    tail->next=new;
    return 1;
  }
  p=tail->next;
  while(pos!=2)
  {
   pos--;
   p=p->next;
  }
  p2=p->next;
  if(p2==tail->next)
	  tail=new;
     new->prev=p;
     new->next=p2;
     p->next=new;
     p2->prev=new;
     return 1;
}
void del_beg()//deletes first node           Case 4
{
  node *del;
  if(tail==NULL)
       printf("List already empty.\n");
  else if(tail->next==NULL)
  {
       free(tail);
       tail=NULL;
       printf("Deleted\n");
  }
  else{
       del=tail->next;
       del->next->prev=tail;
       tail->next=del->next;
       free(del);
       printf("Deleted.\n");
      }
}
void del_end() //To Delete Last Node          Case 5
{
 node *del;
 if(tail==NULL)
      printf("List is already empty.\n");
 else if(tail==tail->next)
 {
      free(tail);
      tail=NULL;
      printf("Deleted\n");
 }
 else{
      del=tail;
      tail=del->prev;
      tail->next=del->next;
      del->next->prev=tail;
      free(del);
      printf("Deleted.\n");
     }
}
int del_pos()        //To delete a position         Case 6
{
  node *del,*p;
  int pos;
  if(tail==NULL){
		 printf("List already Empty\n");
		 return 0;
		}
  printf("Enter position to be deleted.\n");
  scanf("%d",&pos);
  if(pos>count()||pos==0){
			  printf("Invalid Position\n");
			  return 0;
			 }
  if(pos==1&&tail==tail->next){

	     free(tail);
	     tail=NULL;
	     printf("Deleted\n");
	     return 1;
	    }
  del=tail->next;
  while(pos>1){
	       pos--;
	       del=del->next;
	      }
  p=del->prev;
  p->next=del->next;
  del->next->prev=p;
  if(del==tail)
      tail=p;
  printf("Deleted\n");
  return 1;
}
int count()      //counts no. of nodes          Case 7
{
  node *p=tail->next;
  int c=0;
  if(tail==NULL)
     return 0;
  do{  c++;
       p=p->next;
    }while(p!=tail->next);
  return c;
}
void print(node* tail)              //Prints the nodes  Case 8
{
  node *p=tail->next;
  if(tail==NULL)
     printf("No nodes present.\n");
  else{ do{
	    printf("%d   ",p->data);
	    p=p->next;
	  } while(p!=tail->next);
	  printf("\n");
      }
}
void print_back() //Prints list in reverse order without reversing the list.
{                                                //Case 9
  node *p;
  if(tail!=NULL)
  {
    p=tail;
    do{
	printf("%d  ",p->data);
	p=p->prev;
      }while(p!=tail);
  }else printf("No nodes present.");
}
int reverse() //To reverse the list        Case 10
{
 node *p1,*p2;
 if(tail==NULL) {
    printf("List is empty.\n");
    return 0;   }
 p1=tail->next;
 p2=p1->next;

 p1->prev=p2;     //update first element
 p1->next=tail;

 tail=p1;
 while(p2!=tail){      //reversing rest of the list
		 p2->prev=p2->next;
		 p2->next=p1;

		 p1=p2;
		 p2=p2->prev;
		}
  printf("Reversed.\n");
  return 1;
}
node* sort(node*tail)           //To Sort the list        Case 11
{
   node *curent, *next;
   int temp;
   if(tail==NULL)
       printf("List is Empty\n");
   else{
	curent=tail->next;
	do{         //To select a node 1 by 1.
	   next=curent->next;
	   while(next!=tail->next)
	   {           //to compare each node with above selected node
	      if(curent->data>next->data)
	       {
		temp=curent->data;
		curent->data=next->data;
		next->data=temp;
	       }
	       next=next->next;
	     }
	  curent=curent->next;
	  }while(curent!=tail->next);
       printf("Sorted.\n");
       }  return tail;
}                                                  /*
void mid()       //To find data of middle node
{
   node *slow,*fast;

   if(tail==NULL||tail->next==tail||tail->next->next==tail)
		 printf("Only %d node(s) present.\n",count());

   else{
	slow=tail->next;
	fast=slow;
	do{
	     slow=slow->next;
	     fast=fast->next->next;
	  }while(fast->next!=tail->next&&fast->next->next!=tail);
	printf("Mid node has %d.\n",slow->data);
       }
}       */
int search() //To search entered data    Case 12
{
   int data,c=0;
   node *found;
   printf("Enter Number to be searched.\n");
   scanf("%d",&data);
   if(tail==NULL) {printf("List is empty.\n"); return 1;}

   found=tail->next;
   do{  c++;
	if(found->data==data)
	       {
		  printf("Found at position %d\n",c);
		  return 1;
	       }
	found=found->next;
     }while(found!=tail->next);
   printf("Not Found\n");
   return 1;
}
node* concatinate(node* T)
{
 node *temp,*t=NULL;
 int num=1;
 printf("To Concatinate strings in sorted way   ");
 printf("\nPrevious string enterd-->");print(T);

 printf("\n\nEnter Second String-> ");
   while(num)
   {
      t=add_beg(t);
      printf("Press 1 to Continue  ");scanf("%d",&num);
      printf("\n");
   }
 printf("You enterd-->");print(t);
 temp=T->next;
 T->next=t->next;
 T->next->prev=T;
 t->next=temp;
 temp->prev=t;


 t=sort(t);
 printf("\n Sorted And Concatinated the list  ");
 print(t);
 return t;
}
void main()                       //Main Driver Code
{
int c,menu,list;
node *del;
clrscr();
print_menu:{ menu=0;  //It prints menu again after entry of every 5 choices
printf("\n******Menu Driven******\n0 Exit.\n1 Add a node in beggning.\n");
printf("2 Add node at end.\n3 Add node at position.\n4 Delete first node\n");
printf("5 Delete last node.\n6 Delete a position.\n");
printf("7 Count nodes.\n8 Print Nodes.\n9 Print from end.\n10 Reverse List\n");
printf("11 Sort list.\n12 Search\n13 Concatinate\n");
while(1)
{
menu++;if(menu>5) goto print_menu;   /*
printf("On which List would you like to work upon? ");
redo:{printf("First or Second? Enter 1 or 2  ");
scanf("%d",&list);if(list!=1&&list!=2)goto redo;}
if(list==1)tail=t1;else tail=t2;       */

printf("\nEnter your choice.  ");
scanf("%d",&c);
switch(c)                     //To switch between choices
{
case 0:printf("Exit\n");goto free_mem;exit(1); break;
case 1:tail=add_beg(tail);break;
case 2:add_end();break;
case 3:add_pos();break;
case 4:del_beg();break;
case 5:del_end(); break;
case 6:del_pos();break;
case 7:printf("%d node(s) present.\n",count());break;
case 8:print(tail);break;
case 9:print_back();break;
case 10:reverse();break;
case 11:tail=sort(tail);break;
case 12:search();break;
case 13:tail=concatinate(tail);break;
//case  :mid();break;
default:goto free_mem;exit(1); break;
}//switch closed
}//while(1) closed

free_mem:if(tail!=NULL)             //To deallocate the memory
	 {
	   for(del=tail->next;;del=del->next)
	     {
	       if(del==tail)
		{
		  free(tail);printf("Memory Deallocated\n");
		  break;
		}
	      free(del);printf("Memory Deallocated.\n");
	     }
	 }
getch();
}//print_menu loop closed
}//main() closed