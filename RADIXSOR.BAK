#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int a[10],i,n;
void create();
void radixsort(int a[10],int n);
int getmax(int a[10],int n);
void countsort(int a[10],int n,int pos);
void display();
void main()
{
int ch;
clrscr();
while(1)
{
printf("****searching****");
printf("\n1.create\n2.Radix sort\n3.Display\n4.Exit");
printf("\nEnter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
radixsort(a,n);
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("wrong choice");
}
getch();
}
}
void create()
{
printf("enter the number of elements you want to enter");
scanf("%d",&n);
for(i=0;i<n;i++)
  scanf("%d",&a[i]);
}
void radixsort(int a[10],int n)
{
int max=getmax(a,n),pos;
for(pos=1;max/pos>0;pos*=10)
   {
     countsort(a,n,pos);
   }
}


int getmax(int a[10],int n)
{
int largest=a[0];
for(i=0;i<n;i++)
{
if(a[i]>largest)
largest=a[i];
}
return largest;
}


void countsort(int a[10],int n,int pos)
{
int b[10],count[10]={0},k=9;

for(i=0;i<n;i++)
   ++count[(a[i]/pos)%10];

for(i=1;i<=k;i++)
   count[i]+=count[i-1];

for(i=n-1;i>=0;i--)
     b[--count[(a[i]/pos)%10]]=a[i];

for(i=0;i<n;i++)
    a[i]=b[i];
}


void display()
{
printf("The numbers in ascending order are:\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
}





