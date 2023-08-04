#include<stdio.h>
void main()
{
int a[5][5],i,j,N=3;
clrscr();
printf("Enter %d elements\n",(N)*(N));
for(i=0;i<N;i++)
{
   for(j=0;j<N;j++)
   {
       scanf("%d",&a[i][j]);
   }
}
printf("OUTPUT\n");
for(i=0;i<N;i++)
{
   for(j=0;j<N;j++)
   {
      printf("%d  ",a[i][j]);
   }
   printf("\n");
}
printf("Diagonal Matrix\n");
for(i=0;i<N;i++)
{
   for(j=0;j<N;j++)
   {
       if(i==j)
	  printf("%d  ",a[i][j]);
       else
	  printf("0  ");
   }
   printf("\n");
}
printf("Upper triangular matrix.\n");
for(i=0;i<N;i++)
{
  for(j=0;j<N;j++)
  {
     if(i>j)
       printf("   ");
     else
       printf("%d  ",a[i][j]);

  }
  printf("\n");
}
printf("Lower triangular matrix.\n");
for(i=0;i<N;i++)
{
   for(j=0;j<N;j++)
   {
     if(j>i)
	printf("   ");
     else
	printf("%d  ",a[i][j]);
   }
   printf("\n");
}
printf("Tridiagonal Matrix\n");
for(i=0;i<N;i++)
{
    for(j=0;j<N;j++)
	{
	   if(i==j||j==i+1||i==j+1)
	      printf("%d  ",a[i][j]);
	   else
	      printf("0  ");
	}
    printf("\n");
}
printf("2nd Tridiagonal matrix\n");
for(i=0;i<N;i++)
{
    for(j=0;j<N;j++)
    {
       if(i+j==N||i+j==N-1||i+j==N-2)
	   printf("%d  ",a[i][j]);
       else
	   printf("0  ");
    }
    printf("\n");
}
getch();
}