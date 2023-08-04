#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
void arrin(int *ptr,int num);
void arrout(int *ptr,int num);
void RotateByOne(int *ptr,int num);
void main()
{
  int arr[10]={0},c,num,ch;
  cout<<"Enter no. of elements to be entered  ";
  cin>>num;
  arrin(arr,num);
  while(1)
  {
   cout<<"\n1 Circulate arr. by 1 position\n";
   cin>>c;
   switch(c)
   {
    case 1:RotateByOne(arr,num); arrout(arr,num);break;
    default:{
	    cout<<"\nTo enter another array, press one ";
	    cin>>ch;
	    if(ch==1)
	       {
		 cout<<"Enter no. of elements to be entered  ";
		 cin>>num;
		 arrin(arr,num);
	       }
	    else exit(1);
	    }
   }
  }
}
void RotateByOne(int *ptr,int num)
{
 int temp=*(ptr);
 for(int i=0;i<num-1;i++)
    *(ptr+i)=*(ptr+i+1);
 *(ptr+i)=temp;
}
void arrin(int *ptr,int num)
{
  for(int i=0;i<num;i++)
  {
    cout<<"Enter element no. "<<i+1<<"->   ";
    cin>>*(ptr+i);
  }
}
void arrout(int *ptr,int num)
{
  for(int i=0;i<num;i++)
      cout<<*(ptr+i)<<"  ";
  cout<<endl;
}