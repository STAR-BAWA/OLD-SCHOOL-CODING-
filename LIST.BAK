#include<stdio.h>
#include<stdlib.h>
typedef struct node_l     //Structure for simple linked list
{
 int data;
 struct node_l *next;
}node_l;
node_l *front=NULL;       //Pointer to simple linked list

typedef struct node_dl  //Structure for doubly linked list
{
 struct node_dl *prev;
 int data;
 struct node_dl *next;
}node_dl;
node_dl *head=NULL;  //Pointer to doubly linked list

typedef struct doubly_circular_list //Structure for circular doubly linked list
{
  struct doubly_circular_list *prev;
  int data;
  struct doubly_circular_list *next;
}node_dc;
node_dc *tail=NULL; //Pointer to circular doubly linked list

typedef struct polynomial//Structure for doubly linked list for dealing
{                                      //a polynomial
  struct polynomial *prev;
  int cof;
  int exp;
  struct polynomial *next;
}pol;
pol *A=NULL,*B=NULL;//Pointer to DLL of polynomial for operations +,-,*,/
pol* create_pol(pol *x);
pol* insert_pol(pol *x,int cof,int exp);
void print_pol(pol *x);
void add_pol(pol *a, pol *b);
void mul_pol(pol *a,pol *b);
void free_pol(pol *x)
{
  pol *del=x;
//  printf("\n\n");
  while(x!=NULL)
  {
//    printf("Deallocate %da^%d  ",x->cof,x->exp);
    del=x->next;
    free(x);
    x=del;
  }
//  printf("\n------------------------------------------------------------");
}

//////////////////////////////////////////////////
void main()
{
int c;
node_l  *nop;//
node_dl *fre;// Pointers to deallocate memory of Lists
node_dc *del;//

clrscr();
//textcolor(6);
while(1)
  {
   printf("\n\nWelcome to deal with Linked lists\n");
   printf("\n****Menu Driven****\n0 Exit\n1 Linked List.\n2 Doubly Linked List\n");
   printf("3 Circular Doubly Linked List.\n4 Application of Linked List (polynomial)\n");

   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
   {
       case 1: list(); break;
       case 2: dbl_list(); break;
       case 3: dbl_circular_list(); break;
       case 4: polynomial();free_pol(A);free_pol(B);break;

   default:printf("Exit\n");  goto mem;
   }
}
mem:{
      nop=front;
      while(front!=NULL)
	 {
	  nop=nop->next;
	  printf("Memory of Linked list Deallocated %d\n",front->data);
	  free(front);
	  front=nop;
	 }
      for(fre=head;fre!=NULL;fre=fre->next)
	 {
	   free(fre);
	   printf("Memory of Doubly linked list Deallocated\n");
	 }
      if(tail!=NULL)             //To deallocate the memory
	 {
	   for(del=tail->next;;del=del->next)
	     {
	       if(del==tail)
		{
		  free(tail);printf("Memory of Doubly Cicular Linked List  Deallocated\n");
		  break;
		}
	      free(del);printf("Memory of Doubly Cicular Linked List Deallocated.\n");
	     }
	 }
    }
getch();
}//main closed
int polynomial()
{
  int c;
  printf("\n*******************************************************");
  printf("\nWelcome to perform different operations on polynomials");
  printf("\nEnter two polynomials.");

  printf("\nFor first one ");
  A=create_pol(A);
  printf("Created first polynomial->  ");
  print_pol(A);

  printf("\nFor second one ");
  B=create_pol(B);
  printf("Created second polynomial->  ");
  print_pol(B);

  while(1)
  {
   printf("\n****Menu Driven****\n0 Return to previous menu");
   printf("\n1 Addition\n2 Substraction\n");
   printf("3 Multiplication\n4 Division\n");

   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
   {
       case 1: add_pol(A,B); break;
    //   case 2: sub_pol(A,B); break;
       case 3: mul_pol(A,B); break;
    //   case 4: div_pol(A,B); break;
       default:fflush(stdin);return;
   }
  }
}
void mul_pol(pol *a,pol *b)
{
  pol *resume=b,*product=NULL;
  while(a!=NULL)
  {
    b=resume;
    while(b!=NULL)
    {
      product=insert_pol(product,a->cof*b->cof,a->exp+b->exp);
      b=b->next;
    }
    a=a->next;
  }
  printf("We get->\n[");print_pol(A);printf("]  *  [");print_pol(B);
  printf("]\n= [");print_pol(product);printf("]");
  free_pol(product);
}

void add_pol(pol *a, pol *b)  //Addition of a polynomial
{
  int cof;pol *rest,*sum=NULL;
  while(a!=NULL && b!=NULL)
  {
    if(a->exp > b->exp)
	  {
	    sum=insert_pol(sum,a->cof,a->exp);
	    a=a->next;
	  }
    else if(a->exp < b->exp)
	  {
	    sum=insert_pol(sum,b->cof,b->exp);
	    b=b->next;
	  }
    else
	  {
	    cof=a->cof+b->cof;
	    sum=insert_pol(sum,cof,a->exp);
	    a=a->next;
	    b=b->next;
	  }
  }
  if(a!=NULL)
       rest=a;
  else
       rest=b;
  while(rest!=NULL)
  {
    sum=insert_pol(sum,rest->cof,rest->exp);
    rest=rest->next;
  }
  printf("We get->\n[");print_pol(A);printf("] + [");print_pol(B);
  printf("]\n   = ");print_pol(sum);
  free_pol(sum);
}
pol* create_pol(pol *x)    //Creation of polynomial
{
 int i,n,exp;
 int cof;
 printf("enter number of terms  ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   printf("Enter coefficient for term %d-->  ",i+1);
   scanf("%d",&cof);
   printf("Enter exponent for term %d-->  ",i+1);
   scanf("%d",&exp);
   x=insert_pol(x,cof,exp);
   printf("\n");
 }
 return x;
}
pol* insert_pol(pol *x,int cof,int exp)//Inserting terms in polynomial
{
  pol *new,*ptr;
  new=(pol*)malloc(sizeof(pol));

  new->cof=cof;
  new->exp=exp;
  new->next=NULL;
  new->prev=NULL;

  if(x==NULL || x->exp < new->exp) //first term
  {                                //or a term with greator exponent
    new->next=x;
    x=new;
  }
  else
  {                  //term with smaller exponent
    ptr=x;
    while(ptr->next!=NULL && ptr->next->exp > new->exp)
				 ptr=ptr->next;
    if(ptr->exp==new->exp)
	{
	  ptr->cof+=new->cof;
	  free(new);
	}
   else {
	  new->next=ptr->next;
	  new->prev=ptr;
	  ptr->next=new;
	  if(new->next!=NULL)
	    new->next->prev=new;
	}
  }
  return x;
}
void print_pol(pol *x)      //Printing polynomial
{
  do
  {
    printf(" (%d a^%d) ",x->cof,x->exp);
    x=x->next;
    if(x!=NULL)
       printf("+");
  }while(x!=NULL);

}
/////////////////////////////////////////////////////////////////////////
int list()   //Simple Linked List
{

int c,tot;
printf("\n*******************************************************");
printf("\nWelcome to deal with a linked list");
  while(1)
  {
   printf("\n****Menu Driven****\n0 Return to previous menu\n1 Add a node\n");
   printf("2 Delete a node\n3 Count Nodes\n4 Print List.\n");

   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
    {
      case 1: add_l(); break;
      case 2: del_l(); break;
      case 3: tot=count_l();  printf("%d elements in list.\n",tot);  break;
      case 4: print_l();break;
      default:return 1;
    }

  }
}
int add_l()
{
 int c;
 while(1)
 {
   printf("\n\n0 Return to previous menu\n1 Add node at end.\n2 Add a node in starting\n");
   printf("3 Add a node at a position.");

   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
    {
      case 1: add_end_l(); break;
      case 2: add_beg_l(); break;
      case 3: add_pos_l(); break;
      default:return 1;
    }
  }
}
int add_end_l()
{
 int data;
 node_l *new,*ptr;
 printf("Enter data ");
 scanf("%d",&data);
 new=malloc(sizeof(node_l));
 new->data=data;
 new->next=NULL;
 if(front==NULL)
       front=new;
 else{
       ptr=front;
       while(ptr->next!=NULL)
	       ptr=ptr->next;
       ptr->next=new;
     }   return 1;
}
int add_beg_l()
{
 int data;
 node_l *new,*ptr;
 printf("Enter data ");
 scanf("%d",&data);
 new=malloc(sizeof(node_l));
 new->data=data;
 new->next=front;
 front=new;
 return 1;
}
int add_pos_l()
{
 int pos,data;
 node_l *new,*ptr;
 printf("Enter position ");
 scanf("%d",&pos);
 if(1>count_l()||pos>count_l()+1)
 {
   printf("Position Unavailable\n");
   return 1;
 }
 printf("Enter data ");
 scanf("%d",&data);
 new=malloc(sizeof(node_l));
 new->data=data;
 printf("%d entered at position %d\n\n",data,pos);

 if(pos==1)
 {
   new->next=front;
   front=new;
   return 1;
 }
 ptr=front;
 while(pos!=2)
 {
  pos--;
  ptr=ptr->next;
 }
new->next=ptr->next;
ptr->next=new;
return 1;
}


int del_l()
{
  int c;
 while(1)
 {
   printf("\n0 Return to previous menu\n1 Delete first node.\n2 Delete Last Node\n");
   printf("3 Delete node from a position.");
   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
   {
     case 1: del_beg_l(); break;
     case 2: del_end_l(); break;
     case 3: del_pos_l(); break;

     default:return 1;
   }
 }
}
int del_beg_l()
{
 node_l *ptr;
 if(front==NULL){
     printf("List is Empty\n");
     return 0;  }
 ptr=front;
 printf("%d deleted from first node\n\n",front->data);
 front=front->next;
 free(ptr);
 return 1;
}
int del_end_l()
{
 node_l *ptr,*del;
  if(front==NULL){
     printf("List is Empty\n");
     return 0;  }
 ptr=front;
 if(ptr->next==NULL)
     del=ptr;
 else{
      while(ptr->next->next!=NULL)
		      ptr=ptr->next;
      del=ptr->next;
      ptr->next=NULL;
     }
 printf("%d deleted from last node\n\n",del->data);
 free(del);
 return 1;
}
int del_pos_l()
{
 int pos;
 node_l *ptr,*del;
 printf("Enter position ");
 scanf("%d",&pos);
 if(1>count_l()||pos>count_l())
 {
   printf("Position Unavailable\n");
   return 1;
 }
 if(pos==1)
 {
   ptr=front;
   front=front->next;
   printf("%d deleted from position %d\n\n",ptr->data,pos);
   free(ptr);
   return 1;
 }
 ptr=front;
 while(pos!=2)
 {
  pos--;
  ptr=ptr->next;
 }
del=ptr->next;
ptr->next=del->next;
printf("%d deleted \n\n",del->data);
free(del);
return 1;
}
int count_l()
{
 int c=0;
 node_l *ptr;

 for(ptr=front;ptr!=NULL;ptr=ptr->next)
	       c++;
 return c;
}
int print_l()
{
  node_l *ptr;
  if(front==NULL){
     printf("List is Empty\n");
     return 0;  }
  for(ptr=front;ptr!=NULL;ptr=ptr->next)
     printf("%d <-- ",ptr->data);
  printf("\n\n");
 return 1;
}
///////////////////////////////////////////////
int dbl_list()       //Case 2      Function for Doubly Linked List
{

int c,tot;
printf("\n*******************************************************");
printf("\nWelcome to deal with a Doubly linked list\n");
  while(1)
  {
   printf("****Menu Driven****\n0 Return to previous menu\n1 Add a node\n");
   printf("2 Delete a node\n3 Count Nodes\n4 Print List.\n");

   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
    {
      case 1: add_dbl_list(); break;
      case 2: del_dbl_list(); break;
      case 3: tot=count_dbl_list();  printf("%d elements in list.\n",tot);  break;
      case 4: print_dbl_list();break;
      default:return 1;
    }

  }
}//dbl_list() closed
int add_dbl_list()
{
 int c;
 while(1)
 {
   printf("\n\n0 Return to previous menu\n1 Add node at end.\n2 Add a node in starting\n");
   printf("3 Add a node at a position.");

   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
    {
      case 1: add_at_end_dbl_list(); break;
      case 2: add_at_beg_dbl_list(); break;
      case 3: add_at_pos_dbl_list(); break;
      default:return 1;
    }
  }
}

int add_at_end_dbl_list()
{
   node_dl *temp,*p;
   int data;
   p=head;
   printf("Enter data.  ");
   scanf("%d",&data);
   if(head==NULL)
   {
     head=malloc(sizeof(node_dl));
     head->prev=NULL;
     head->data=data;
     head->next=NULL;
     printf("%d Entered \n",data);
   }
   else{
   temp=malloc(sizeof(node_dl));
   temp->prev=NULL;
   temp->data=data;
   temp->next=NULL;
   while(p->next!=NULL)
	   p=p->next;
   temp->prev=p;
   p->next=temp;
   printf("%d Entered \n",data);
   }
   return 1;
}
int add_at_beg_dbl_list()
{
  int data;
  node_dl *temp;
  printf("Enter data.  ");
  scanf("%d",&data);
  if(head==NULL)
  {
     head=malloc(sizeof(node_dl));
     head->prev=NULL;
     head->data=data;
     head->next=NULL;
     printf("%d Entered \n",data);
  }
  else
  {
  temp =malloc(sizeof(node_dl));
  temp->prev=NULL;
  temp->data=data;
  temp->next=head;
  head->prev=temp;
  printf("%d Entered \n",data);
  head=temp;
  }
  return 1;
}
int add_at_pos_dbl_list()                           //Add at a position
{
   int data,pos,tot;
   node_dl *temp,*p1,*p2;
   printf("Enter the position.  ");
   scanf("%d",&pos);
   printf("Enter data.  ");
   scanf("%d",&data);
   temp=malloc(sizeof(node_dl));
   temp->data=data;
   if(pos==1&&head!=NULL)                  //Add. in node 1
   {                                            //of a non-empty list
      temp->next=head;
      temp->prev=NULL;
      head->prev=temp;
      head=temp;
      printf("%d Entered \n",data);
      return 1;
   }
   if(pos==1&&head==NULL)              //Add in node 1
   {                                       //of a empty list
      head=temp;
      head->prev=NULL;
      head->next=NULL;
      printf("%d Entered \n",data);
      return 1;
   }
   tot=count_dbl_list();
   if(pos>tot+1)                          //Given position unavailable
   {
    printf("Position does not exists.\n");
    free(temp);
    return 0;
   }
   p1=head;
   while(pos!=2)
   {
      pos--;
      p1=p1->next;
   }
   p2=p1->next;
   if(p2==NULL)                        //Add at last pos
   {
     temp->prev=p1;
     temp->next=NULL;
     p1->next=temp;
     printf("%d Entered \n",data);
     return 1;
   }
   else
   {
      temp->next=p2;                 //Add at given pos
      temp->prev=p1;
      p1->next=temp;
      p2->prev=temp;
      printf("%d Entered \n",data);
      return 1;
   }
}
//////////////////////////////////////////////////
int del_dbl_list()
{
 int c;
 while(1)
 {
   printf("\n0 Exit\n1 Delete first node.\n2 Delete Last Node\n");
   printf("3 Delete node from a position.");
   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
   {
     case 1: del_beg_dbl_list(); break;
     case 2: del_end_dbl_list(); break;
     case 3: del_pos_dbl_list(); break;

     default:return 1;
   }
 }
}

int del_beg_dbl_list()                         //Delete first node
{
    node_dl *temp;
    temp=head;
    if(head==NULL)
	printf("List already empty.\n");
    else
    {
	head=head->next;
	printf("%d Deleted\n",temp->data);
	free(temp);

    }
 return 1;
}
int del_end_dbl_list()                            //Delete End Node
{
    node_dl *temp,*del;
    temp=head;
    if(head==NULL)
       printf("List already empty\n");
    else if(head->next==NULL)
    {
      printf("%d Deleted\n",head->data);
      free(head);
      head=NULL;
    }
    else
    {
    while(temp->next->next!=NULL)
	 temp=temp->next;
    del=temp->next;
    temp->next=NULL;

    printf("%d Deleted\n",del->data);
    free(del);
    }
  return 1;
}
int del_pos_dbl_list()                          //Delete from a position
{
    node_dl *temp,*del,*temp2;
    int pos,tot=count_dbl_list();
    temp=head;
    printf("Enter position to be deleted.");
    scanf("%d",&pos);
    if(pos>tot||pos<=0)
       printf("Position does not exists\n");
    else
    {
       if(pos==1)
	 {
	   head=head->next;                   //del first pos
	   free(temp);
	   printf("Deleted.\n");
	 }
       else{
		while(pos!=2)
		 {
		     pos--;
		     temp=temp->next;
		 }
		 del=temp->next;
		 temp2=del->next;
		 if(temp2==NULL)
		 {
		   temp->next=NULL;          //del last pos.
		   free(del);
		   printf("Deleted.\n");
		 }
		 else
		 {
		    temp->next=temp2;             //del given pos.
		    temp2->prev=temp;
		    free(del);
		    printf("Deleted.\n");
		 }
	    }
    }return 1;
}
int count_dbl_list()
{                                 //to count
   int c=0;
   node_dl *temp;
   temp =head;
   if(temp==NULL)
	  return 0;
   else
   {
      while(temp!=NULL)
      {
	c++;
	temp=temp->next;
      }
      return c;
   }
}
int print_dbl_list()                      //to print
{
  node_dl *temp;
  if(head==NULL)
    printf("         List is empty");
  else
    {
    temp=head;
    printf("\n                   ");
    while(temp!=NULL)
      {
	 printf("%d  ",temp->data);
	 temp=temp->next;
      }
    }
      printf("\n");
  return 1;
}
///////////////////////////////////////
dbl_circular_list()     // Case 3 Doubly Cicular Linked List
{
 int c;
while (1)
{
 printf("\n*******************************************************");
 printf("\n******Menu Driven******\n0 Return to previous menu.\n1 Add a node\n");
 printf("2 Delete a node\n");
 printf("3 Count nodes.\n4 Print Nodes.\n");

 printf("\nEnter your choice.  ");
 scanf("%d",&c);
 switch(c)                     //To switch between choices
 {
    case 1:add_dc();break;
    case 2:del_dc();break;
    case 3:printf("%d node(s) present.\n",count_dc());break;
    case 4:print_dc();break;
    default:return 1;
 }//switch closed
}//while(1) closed
}
int add_dc()
{
int c;
while(1)
{
 printf("\n\n0 Return to previous menu\n1 Add a node in beggning.\n");
 printf("2 Add node at end.\n3 Add node at position.\n");

 printf("\nEnter your choice.  ");
 scanf("%d",&c);
 switch(c)                     //To switch between choices
  {
    case 1:add_beg_dc();break;
    case 2:add_end_dc();break;
    case 3:add_pos_dc();break;
    default:return 1;
  }//switch closed
}//while(1) closed
}
int add_beg_dc()    //Adds a node in starting
{
 node_dc *new; int data;
 printf("Enter data  ");
 scanf("%d",&data);          //if there is 0 node
 if(tail==NULL)
 { tail=(node_dc*)malloc(sizeof(node_dc));
   tail->prev=tail;
   tail->data=data;
   tail->next=tail;
 } else
 { new=malloc(sizeof(node_dc));   //if atleast 1 node present
   new->prev=tail;
   new->data=data;
   new->next=tail->next;
   new->next->prev=new;
   tail->next=new;
 }
return 1;
}
int add_end_dc()           //Add last node
{
 node_dc *new; int data;
 printf("Enter data  ");
 scanf("%d",&data);
 if(tail==NULL)
 {  tail=malloc(sizeof(node_dc));
    tail->data=data;
    tail->next=tail;
    tail->prev=tail;
 }else
 {  new=malloc(sizeof(node_dc));
    new->next=tail->next;
    new->data=data;
    new->prev=tail;
    tail->next=new;
    new->next->prev=new;
    tail=new;
 }return 1;
}
int add_pos_dc()      //Adds node at given position
{
  node_dc *new,*p,*p2;
  int pos,data;
  printf("Enter position  ");
  scanf("%d",&pos);
  if(pos>count_dc()+1||pos==0)   //if invalid position is entered
  {
    printf("Position unavailable.\n");
    return 0;
  }
  printf("Enter data  ");
  scanf("%d",&data);
  new=malloc(sizeof(node_dc));
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
int del_dc()
{
int c;
while(1)
{
printf("\n\n0 Return to previous menu\n1 Delete first node\n");
printf("2 Delete last node.\n3 Delete a position.\n");
printf("\nEnter your choice.  ");
scanf("%d",&c);
switch(c)                     //To switch between choices
{
  case 1:del_beg_dc();break;
  case 2:del_end_dc(); break;
  case 3:del_pos_dc();break;
  default:return 1;
}//switch closed
}//while(1) closed
}
int del_beg_dc()//deletes first node
{
  node_dc *del;
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
      } return 1;
}
int del_end_dc() //To Delete Last Node
{
 node_dc *del;
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
     }return 1;
}
int del_pos_dc()        //To delete a position
{
  node_dc *del,*p;
  int pos;
  if(tail==NULL){
		 printf("List already Empty\n");
		 return 0;
		}
  printf("Enter position to be deleted.\n");
  scanf("%d",&pos);
  if(pos>count_dc()||pos==0){
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
int count_dc()      //counts no. of nodes
{
  node_dc *p=tail->next;
  int c=0;
  if(tail==NULL)
     return 0;
  do{  c++;
       p=p->next;
    }while(p!=tail->next);
  return c;
}
int print_dc()              //Prints the nodes
{
  node_dc *p=tail->next;
  if(tail==NULL)
     printf("No nodes present.\n");
  else{ do{
	    printf("%d   ",p->data);
	    p=p->next;
	  } while(p!=tail->next);
	  printf("\n");
      }return 1;
}




