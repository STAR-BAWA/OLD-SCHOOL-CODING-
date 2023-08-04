#include<stdio.h>
#include<stdlib.h>
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
//void sub_pol(pol *a, pol *b);
void mul_pol(pol *a,pol *b);
void free_pol(pol *x);

void main()
{
  int c,m;

  clrscr();
  printf("Welcome to perform different operations on polynomials\n");
  printf("Enter two polynomials.");
  fflush(stdin);
  printf("\nFor first polynomial ");
  A=create_pol(A);
  printf("Created first polynomial->  ");
  print_pol(A);

  printf("\nFor second polynomial ");
  B=create_pol(B);
  printf("Created second polynomial->  ");
  print_pol(B);

  while(1)
  {

   printf("\n****Menu Driven****\n0 Exit\n1 Addition\n2 Substraction\n");
   printf("3 Multiplication\n4 Division\n");

   printf("\nEnter your choice ");
   scanf("%d",&c);
   switch(c)
   {
       case 1: add_pol(A,B);break;
   /*    case 2: sub_pol(A,B);
	       printf("We get->\n[");print_pol(A);printf("]-[");print_pol(B);
	       printf("]\n= ");print_pol(diff);
	       diff=free_pol(diff);
	       break;       */
       case 3: mul_pol(A,B);break;
    //   case 4: div_pol(A,B); break;
       default:free_pol(A);
	       free_pol(B);
	       getch();exit(1);
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
  printf("We get->\n[");print_pol(A);printf("]* [");print_pol(B);
  printf("]\n= [");print_pol(product);printf("]");
  free_pol(product);
}
 /*
void sub_pol(pol *a, pol *b)
{
  int cof;pol *rest;
  while(a!=NULL && b!=NULL)
  {
    if(a->exp > b->exp)
	  {
	    diff=insert_pol(diff,a->cof,a->exp);
	    a=a->next;
	  }
    else if(a->exp < b->exp)
	  {
	    diff=insert_pol(diff,b->cof,b->exp);
	    b=b->next;
	  }
    else
	  {
	    cof=a->cof-b->cof;
	    diff=insert_pol(diff,cof,a->exp);
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
    diff=insert_pol(diff,rest->cof,rest->exp);
    rest=rest->next;
  }
}                         */
void free_pol(pol *x)
{
  pol *del=x;
  printf("\n");
  while(x!=NULL)
  {
    printf("Deallocate %da^%d  ",x->cof,x->exp);
    del=x->next;
    free(x);
    x=del;
  }
  printf("\n------------------------------------------------------------");
}
void add_pol(pol *a, pol *b)         //CASE 1
{
  int cof;
  pol *rest,*sum=NULL;
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
  printf("We get->\n[");print_pol(A);printf("]+[");print_pol(B);
  printf("]\n= ");print_pol(sum);
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
  else if(x->exp==new->exp) //new exp==exp of first term
  {
     x->cof+=new->cof;
     free(new);
  }
  else
  {                  //term with smaller exponent
    ptr=x;
    while(ptr->next!=NULL && ptr->next->exp > new->exp)
				 ptr=ptr->next;
    if(ptr->next->exp==new->exp)   //new exp == exp of some intermediate term
	{
	  ptr->next->cof+=new->cof;
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
       printf(" + ");

  }while(x!=NULL);

}



