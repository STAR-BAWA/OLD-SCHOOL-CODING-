#include<stdlib.h>
#include<conio.h>
#define max 10
void main()
{
  int i,j,N[max][2],num,frequency;
  clrscr();
  printf("Enter Array-->\nNo. of Elements  ");
  scanf("%d",&num);     //Entering No of elements
  printf("\nEnter %d elements\n",num);
//  get_arr(num,N);      //Entering Array
  for(i=0;i<num;i++)
  {
    scanf("%d",&N[i][0]);
    N[i][1]=0;
  }
  for(i=0;i<num;i++)
  {
    if(N[i][1]) continue;
    frequency=1;
    for(j=i+1;j<num;j++)
    {

      if(N[i][0]==N[j][0])
      {
	N[j][1]=1;
	frequency++;
      }
    }
  }

 // printing array sorted according to frequency
 for(i=0;i<num;i++)
 {
   while(N[i][1]!=0)
   {
      printf("  %d  ",N[i][0]);
      N[i][1]--;
   }

 }
getch();
}