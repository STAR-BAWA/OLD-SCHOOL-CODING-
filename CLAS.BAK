#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include "My_String.h"

class String
{
  private:
  char a[20],b[20];char *c;
  int ans,start;char x;
  public:
  void string_list();

  protected:
  char* str_copy(char str1[20],char str2[20]);
  char* str_concatinate(char str1[20],char str2[20],char str[40]);
  int equals(char str1[20],char str2[20]);
  char* ToLower(char str[20]);
  char* ToUpper(char str[20]);
  int equalIgnoreCases(char str1[20],char str2[20]);
  int indexOf(char str[20],char x);
  int LastindexOf(char str[20],char x);
  char* del(char str[20],int start,int NoOfChar);
  char* insert(int pos,char *str,char *n);
  char* substring(int start,char *str);
  char* substring(int start,int end,char *str);
};

void String::string_list()
{              /*
  cout<<"*To get length of string-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<str_count(a)<<endl;           //1

  cout<<"*To copy string-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  str_copy(a,b);   puts(b);          //2
  cout<<endl;
	     */
  char* z;
  cout<<"*To concatinate strings-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter 2nd String  "; gets(b);
  z=str_concatinate(a,b,c);//puts(c);     //3
  cout<<*z;
  cout<<endl;
		 /*
  cout<<"*To get difference between ASCII values of strings-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter 2nd String  "; gets(b);
  cout<<str_cmpare(a,b)<<endl;              //4

  cout<<"*To cheak equality of strings-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter 2nd String  "; gets(b);
  ans=equals(a,b);cout<<ans<<endl;                  //5

  cout<<"* Change string's case to lower-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  ToLower(a);puts(a);cout<<endl;                  //6

  cout<<"* Change string's case to upper-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  ToUpper(a);puts(a);cout<<endl;                  //7

  cout<<"*To cheak equality of strings irrespective of cases-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter 2nd String  "; gets(b);
  ans=equalIgnoreCases(a,b);cout<<ans<<endl;     //8

  cout<<"*To get index of a character-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter 1 Character  "; cin>>x;
  cout<<indexOf(a,x);cout<<endl;			      //10

  cout<<"*To get last index of a character-->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter 1 Character  "; cin>>x;
  cout<<LastindexOf(a,x);cout<<endl;			      //11

  cout<<"*To delete characters from a certain index -->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter Index No. Less than tot. characters in string "; cin>>start;
  if(start>str_count(a)) cout<<"Invalid input";
  else
  {
   cout<<"Enter no. of characters to be deleted  ";cin>>ans;
   c=del(a,start,ans);puts(c);                 //12
  }
  cout<<endl;

  cout<<"*To insert characters from a certain index -->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter Index No. according to string "; cin>>start;
  if(start>str_count(a)) cout<<"Invalid Index";
  else {
	cout<<"Enter  String to be inserted "; gets(b);
	c=insert(start,a,b);                              //13th
	puts(c);
       }
  cout<<endl;

  cout<<"*To delete characters from a certain index -->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter Index No. according to string "; cin>>start;
  if(start>str_count(a)) cout<<"Invalid Index";
  else {
	c=substring(start,a);                           //14th
	puts(c);
       }
  cout<<endl;

  cout<<"*To delete characters from a certain index to a certain index -->"<<endl;
  cout<<"Enter  String  "; gets(a);
  cout<<"Enter Index No.  from where deletion is to be started "; cin>>start;
  if(start>str_count(a)) cout<<"Invalid Index";
  else
   {
    cout<<"Enter Index No. upto which string is to be deleted "; cin>>ans;
   if(ans>str_count(a)||start>ans) cout<<"Invalid Index";
    else{
	 c=substring(start-1,ans-1,a);                           //14th
	 puts(c);
	}
   }
  cout<<endl;
		   */
}
char* String::str_copy(char str1[20],char str2[20])
{ //This will copy str1 into str2           2nd
  int i=0;
  for(;i<str_count(str1);i++)
	  str2[i]=str1[i];
  str2[i]=NULL;
  return str2;
}
char* String::str_concatinate(char str1[20],char str2[20],char str[40])
{           //str=str1+str2                 3rd
   int i=0,k=0;
   while(i<str_count(str1))
      str[k++]=str1[i++];
      i=0;
   while(i<str_count(str2))
      str[k++]=str2[i++];
   str[k]='\n';
   puts(str);
   return str;
}
int String::equals(char str1[20],char str2[20])     //5th
{
   int i=0,j=str_count(str1);
   while(i<j)
      if(str1[i]!=str2[i++]) return 0;

   if(str_count(str2)!=i) return 0;
   else return 1;
}
char* String::ToLower(char str[20])                 //6th
{
  int i=0,j=str_count(str);
   while(i<j)
   {
   if((int)str[i]>64&&(int)str[i]<91)
	      str[i]=(char)((int)str[i]+32);
   i++;
   }
   return str;
}
char* String::ToUpper(char str[20])                  //7th
{
  int i=0,j=str_count(str);
   while(i<j)
   {
   if((int)str[i]>96&&(int)str[i]<123)
	      str[i]=(char)((int)str[i]-32);
   i++;
   }
   return str;
}
int String::equalIgnoreCases(char str1[20],char str2[20])
{                                           //8th
   int ans;
   ToUpper(str1);
   ToUpper(str2);
   ans=equals(str1,str2);
   return ans;
}
int String::indexOf(char str[20],char x)             //10th
{
  int i=0,j=str_count(str);
  for(;i<j;i++)
  {
    if(str[i]==x)
       return ++i;
  }
  return -1;
}

int String::LastindexOf(char str[20],char x)             //11th
{
  int i=str_count(str)-1;
  for(;i>=0;i--)
  {
    if(str[i]==x)
       return ++i;
  }
  return -1;
}
char* String::del(char str[20],int start,int NoOfChar)   //12th
{
   int i=start-1;
   NoOfChar--;
   while(NoOfChar!=0)
   {
     NoOfChar--;
     start++;
   }
   while(str[start]!=NULL)
      str[i++]=str[start++];
   str[i]='\0';
   return str;
}
char* String::insert(int pos,char *str,char *n)      //13th
{
   char final[30];
   int i=0,count;
   while(i<pos)
	final[i]=str[i++];
   count=str_count(n);
   int j=0;
   while(j<count)
	 final[i++]=n[j++];
   count=str_count(str);
   while(pos<count)
	 final[i++]=str[pos++];
   final[i]='\0';
   str=final;
   puts(str);
   return str;
}
char* String::substring(int start,char *str)        //14th
{
   str[start]='\0';
   puts(str);
   return str;
}

char* String::substring(int start,int end,char *str)        //15th
{
   end+=1;
   while(str[end]!='\0')
	    str[start++]=str[end++];
   str[start]='\0';
   puts(str);
   return str;
}
class Math
{
   private:
   int a,b; float f;

   protected:
   void maths_list();
   int fact(int);     //1
   int prime(int n);  //2
   double power(int,int); //3
   int automorphic(int n);  //4
   int kaprekar(int n);    //5
   int ceil(float);   //6
   int floor(float);     //7


};
void Math::maths_list()
{
  cout<<"\n\n**********Maths Class**************\n\n";
  cout<<"*To Get Factorial, enter Number  ";
  cin>>a;cout<<fact(a)<<endl;                //1st

  cout<<"*To Cheak the no. is Prime or not, enter Number  ";
  cin>>a;cout<<prime(a)<<endl;                //2nd

  cout<<"*To raise a no. to some power, enter Base  ";
  cin>>b;
  cout<<"Enter Power  ";cin>>a;
  cout<<power(b,a)<<endl;                //3rd

  cout<<"*To cheak a no. is Automorphic No. or not, enter number  ";  cin>>a;
  cout<<automorphic(a)<<endl;                //4th

  cout<<"*To cheak a no. is Kaprekar No. or not, enter number  ";  cin>>a;
  cout<<kaprekar(a)<<endl;                   //5th

  cout<<"*To increament a floating point no. up to its nerest whole no. ";
  cout<<"\nEnter a floating no.  ";cin>>f;
  cout<<ceil(f)<<endl;                       //6th

  cout<<"*To decreament a floating point no. up to its nerest whole no. ";
  cout<<"\nEnter a floating no.  ";cin>>f;
  cout<<floor(f)<<endl;
}                         int NoOfDig(int n)
				{
				 int dig=0;
				 while(n>0) //Counting No. of digits
				 {
				   dig++;
				   n=n/10;
				 }
			    //	 cout<<dig<<endl;
				 return dig;
				}

int Math::floor(float f)
{
  int a=(int)f;
  if(a==f)
     return a;
  return --a;
}

int Math::ceil(float f)          //6th
{
  int a=(int)f;
  if(a==f)
     return a;
  return ++a;
}
int Math::kaprekar(int n)              //5th
{
   int sq=n*n,q,r,div;
   int len=NoOfDig(sq),i=1;

   for(;i<len;i++)
   {
    div=power(10,i);
    q=sq/div;
    r=sq%div;
    if(q+r==n)
	return 1;
   }
   return 0;
}
int Math::automorphic(int n)                     //4th
{
   int pow=NoOfDig(n),store=n,sum=0;
   while(n>0)
   {
     sum=sum+power(n%10,pow);
     n/=10;
   }
   if(store==sum)
       return 1;
   else
	return 0;
}
double Math::power(int base,int pow)        //3rd
{
  double n=1;int i=1;
  for(;i<=pow;i++)
  {
     n*=base;
  }
  return n;
}
int Math::prime(int n)         //2nd
{
    if(n<=1)
	  return 0;
    int i,mid=n/2;
    for(i=mid;i>0;i--)
      {
	if(n%i==0)
	   return 0;
      }
    return 1;
}
int Math::fact(int n)               //1
{
   if(n>1)
       return n*fact(n-1);
   else
       return 1;
}




class merge:public Math,public String
{
  public:
  void start()
  {
      string_list();
      maths_list();
  }

};
merge m;
void main()
{
  clrscr();
  m.start();
  getch();
}