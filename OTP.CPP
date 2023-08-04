#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"My_String.h"

int OTP();
void head_tail();
void main()
{
 clrscr();
 if(OTP()==0)
      {
	cout<<"Incorrect OTP entered,can't proceed";
	getch();
	exit(1);
      }
      cout<<"Correct OTP entered\n";

  head_tail();

 getch();
}
void head_tail()
{
  int arr[10],count=0;
  for(int i=0;i<10;i++)
  {
  //  randomize();
    arr[i]=random(2);
    cout<<endl<<arr[i];
    if(arr[i]==0)
	 count++;
  }
  cout<<endl;
  cout<<"Head(1) occured "<<10-count<<" times\nAnd Tail(0) occured "<<count<<" times";

}
int OTP()
{
  int OTP,otp;
  cout<<"This 4 digit OTP will help you to proceed--> ";
  randomize();
  OTP=random(10000);
  if(OTP<10)
     OTP*=1000;
  else if(OTP<100)
     OTP*=100;
  else if(OTP<1000)
     OTP*=100;
  cout<<OTP;
  getch();
  clrscr();
  cout<<"Enter 4 digit OTP to proceed--> ";
  cin>>otp;
  if(OTP==otp)
     return 1;
  else
     return 0;
}
