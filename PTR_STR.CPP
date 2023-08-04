#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int getlen(char *a)
{
  int len=0;
  while(a[len]
}

void main()
{
  clrscr();
  int c;
  char A[20],B[0];
  cout<<"\nEnter 2 strings A[] & B[]  ";
  gets(A); gets(B);
  while(1)
  {
   cout<<endl<<"**********MENU************"<<endl;
   cout<<"\n1 getlen(A),getlen(B)\n";
   cin>>c;
   switch(c)
   {
     case 1: cout<<"Length of A[]= "<<getlen(A);
	     cout<<"Length of B[]= "<<getlen(B);

   }
  }
}