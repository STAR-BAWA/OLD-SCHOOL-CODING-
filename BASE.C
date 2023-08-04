#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct stack
{
 int data;
 struct stack *link;   //Declaration of Stack Globaly
}stack;
stack *top=NULL;

void push(int data)
{
 stack *new;
 new=(stack*)malloc(sizeof(stack));
 new->data=data;
 new->link=top;
 top=new;
}
void display(int base)
{
 stack *print;
 if(top!=NULL)
 {
  print=top;
  while(print!=NULL)
   {
    if(base==16)
    {
      if(print->data==10)
      {
	printf("A");
	print=print->link;
	if(print==NULL)
	     break;
      }
      if(print->data==11)
      {
	printf("B");
	print=print->link;
	if(print==NULL)
	     break;
      }
     if(print->data==12)
      {
	printf("C");
	print=print->link;
	if(print==NULL)
	     break;
      }
      if(print->data==13)
      {
	printf("D");
	print=print->link;
	if(print==NULL)
	     break;
      }
      if(print->data==14)
      {
	printf("E");
	print=print->link;
	if(print==NULL)
	     break;
      }
      if(print->data==15)
      {
	printf("F");
	print=print->link;
	if(print==NULL)
	     break;
      }
    }
    printf("%d",print->data);
    print=print->link;
   }          printf("\n");
  freemem();
 }
}

void main()
{                    //Main()
  int c,b;
  long O,D;
  clrscr();
  printf("\1  \2  \1  \2  \1  \2  \1  \2  \1  \2");
  while(1)
  { printf("\n***********Menu Driven***********\n1 Decimal to Any other base\n");
    printf("2 Any Base to Decimal\n3 From some non-decimal base to other non decimal base\n");
    printf("\nEnter your choice  ");
    scanf("%d",&c);
    switch(c)
    {                                    //Menu
     case 1:D2O();break;
     case 2:printf("Enter a No. to get its Decimal equivalent  ");
	    scanf("%d",&O);
	    base:printf("Enter the base of the No. You entered ");
		 scanf("%d",&b);
		 if(b!=2&&b!=8&&b!=10)
			    goto base;
		 if(O==0){
			  printf("0\n");
			  break;
			 }
		 D=O2D(O,b);
		 if(D!=0)
		   printf("Decimal equivalent of (%d base %d)= (%d base 10)\n\n",O,b,D);
		   break;
     case 3:O2O();break;
      default:exit(1);break;
  } }
getch();
}
int freemem()
{
stack *del;
 while(top!=NULL)
       {
	del=top;
	top=top->link;
	free(del);
       } printf("Memory of Stack deallocated\n");return 1;
}
int O2O()        //Case 3
{
 int O,N,b,B,D,a,r;
  printf("Enter a No. to get its base changed  ");
  scanf("%d",&O);
  base:printf("Enter the base of the No. You entered ");
  scanf("%d",&b);
  if(b!=2&&b!=8&&b!=10)
	      goto base;

  D=O2D(O,b);
  if(D==0)
	return 0;
 L:printf("Enter the new base ");
 scanf("%d",&B);
 if(B!=2&&B!=8&&B!=10&&B!=16)
	      goto L;
 if(D==0) {
      printf("0\n");
      return 1;
	  }
 if(D<B){
	printf("\nEquivalent of decimal no. %d in base %d is %d",D,B,D);
      return 1;
	}
 printf("\nEquivalent of decimal no. %d in base %d is ",D,B);
 while(D!=0)
 {
   a=D/B;
   r=D%B;
   push(r);
   D=a;
 }
 display(B);
 return 1;
}
int O2D(long int O,int b)   //Case 2 Other base system to Decimal
{
 long int D=0;
 int i,count=0,p=0;

  for(i=O;i!=0;)  //To count no. of digits in the entered no.
   {
    count++;
    if(i%10>=b){
		printf("You enterd a wrong base\n\n");
		return 0;
	       }
    i/=10;
   }

  for(i=0;i<count;i++)
  {
     D+=(O%10)*pow(b,p);
     p++;
     O/=10;
  }

 return D;
}
int D2O()        //Case 1 Decimal to other bases
{
 int D,a,r,b;
 printf("Enter Decimal No. to get its base changed  ");
 scanf("%d",&D);

 base:printf("Enter the new base ");
 scanf("%d",&b);
 if(b!=2&&b!=8&&b!=10&&b!=16)
	      goto base;
 if(D==0) {
      printf("0\n");
      return 1;
	  }
 if(D<b){
	printf("\nEquivalent of decimal no. %d in base %d is %d",D,b,D);
      return 1;
	}
 printf("\nEquivalent of decimal no. %d in base %d is ",D,b);
 while(D!=0)
 {
   a=D/b;
   r=D%b;
   push(r);
   D=a;
 }
 display(b);
 return 1;
}