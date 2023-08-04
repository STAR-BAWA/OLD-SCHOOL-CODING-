#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
class String
{
public:
void del()
{
char str1[100];
char str[100];
int i,k=0,a,b;
cout<<"enter string\n";
cin>>str1;
cout<<"enter index to be deleted\n";
cin>>a;
cout<<"enter last index to be delete\n";
cin>>b;
for(i=0;str1[i]!='\0';i++)
{
if((i>=a)&&(i<=b))
{
continue;
}
else
{
str[k]=str1[i];
}
k++;
}
str[k]='\0';
cout<<"string after deleting is "<<str<<"\n";
}

void insert()
{
char str1[100];
char str2[100];
char str[100];
int i,j,k=0,a;
cout<<"enter string\n";
cin>>str1;
cout<<"enter string to insert\n";
cin>>str2;
cout<<"enter index where to insert\n";
cin>>a;
for(i=0;str1[i]!='\0';i++)
{
if(i==a)
{
for(j=0;str2[j]!='\0';j++)
{
str[k]=str2[j];
k++;
}
}
else
{
str[k]=str1[i];
k++;
}
}
str[k]='\0';
cout<<"string after inserting is "<<str<<"\n";
}

void substring()
{
char str[100];
int n,n1,i=0;
clrscr();
cout<<"enter a string\n";
cin>>str;
cout<<"enter index for substring\n";
cin>>n;
cout<<"enter index for substring\n";
cin>>n1;
for(i=n;i<n1;i++)
{
cout<<str[i];
}
}
void compare()
{
char str1[100];
char str2[100];
int sum,i=0,j=0;
cout<<"enter string 1\n";
cin>>str1;
cout<<"enter string 2\n";
cin>>str2;
for(i=0,j=0;str1[i]!='\0',str2[j]!='\0';i++,j++)
{
if((int)str1[i]-(int)str2[j]<0)
{
sum=-1;
break;
}
else if((int)str1[i]-(int)str2[j]>0)
{
sum=1;
break;
}
else
sum=0;
}
if(sum==-1)
cout<<str2<<" is greater\n";
if(sum==1)
cout<<str1<<" is greater\n";
if(sum==0)
cout<<str1<<" and "<<str2<<" are equal\n";
}
void length()
{
char s[100];
int i,b=0;
cout<<"--function to find length--\n";
cout<<"Enter a string \n";
cin>>s;
for(i=0;s[i]!='\0';++i)
{
b++;
}
cout<<"Length of string : "<<b<<"\n";
}
void copy()
{
int i;
char s1[100];
char s2[100];
cout<<"--function to copy string--\n";
cout<<"Enter a string \n";
cin>>s1;
for(i=0;s1[i]!='\0';i++)
{
s2[i]=s1[i];
}
s2[i]='\0';
cout<<"copied string s2 is :"<<s2<<"\n";
}
void concat()
{
char str1[100];
char str2[100];
char str3[100];
int i=0,j=0;
cout<<"--function to concatenation--\n";
cout<<"enter string 1 : \n";
cin>>str1;
cout<<"enter string 2 : \n";
cin>>str2;
while(str1[i]!='\0')
{
str3[j]=str1[i];
i++;
j++;
}
i=0;
while(str2[i]!='\0')
{
str3[j]=str2[i];
i++;
j++;
}
str3[j]='\0';
cout<<"Concatenated string : "<<str3<<"\n";
}
void equals()
{
char str1[50],ch1;
char str2[50],ch2;
int i=0,j=0,flag;
cout<<"--function to check string are equal or not--\n";
cout<<"enter string 1 : \n";
cin>>str1;
cout<<"enter string 2 : \n";
cin>>str2;
for(i=0,j=0;str1[i]!='\0',str2[j]!='\0';i++,j++)
{
ch1=str1[i];
ch2=str2[j];
if((int)ch1!=(int)ch2)
{
flag=0;
break;
}
else
flag++;
}
if(flag==0)
cout<<"strings are not equal\n";
else
cout<<"strings are equal\n";
}
void equalsignorecase()
{
{
int f,i,j,x=0;char b[50],a[50];
cout<<"enter the string 1:\n";
gets(b);
cout<<"enter the string 2:\n";
gets(a);
for(f=0,i=0;b[f]!=NULL,a[i]!=NULL;f++,i++)
{
if(a[i]==b[f]||a[i]+32==b[f]||a[i]==b[f]-32)
{
++x;
}
}
if(x==0)
cout<<"\nunequal strings\n";
else
cout<<"\n equal\n";
}
}
}
void lastindexOf()
{
char str1[100];
char ch;
int index=-1;
cout<<"--function to find last index of character--\n";
cout<<"Enter string :\n";
cin>>str1;
cout<<"enter character :\n";
cin>>ch;
int l=strlen(str1);
for(int i=0;i<l ;i++)
{
if(str1[i]==ch)
index=i;
}
if(index==-1)
cout<<"character not found\n";
else
cout<<"last index of character is present at "<<index<<"\n";
}
void indexOf()
{
char str1[100];
char ch;
int index=-1;
cout<<"--function to find index of character--\n";
cout<<"Enter string :\n";
cin>>str1;
cout<<"enter character :\n";
cin>>ch;
int l=strlen(str1);
for(int i=0;i<l ;i++)
{
if(str1[i]==ch)
{
index=i;
break;
}
else
continue;
}
if(index==-1)
cout<<"character not found\n";
else
cout<<"index of character is present at "<<index<<"\n";
}
void touppercase()
{
char str1[100];
cout<<"--function to convert string to uppercase--\n";
cout<<"Enter a string :\n";
cin>>str1;
for(int i=0;str1[i]!='\0';i++)
{
if(str1[i]>='a'&&str1[i]<='z')
str1[i]=str1[i]-32;
}
cout<<"string in uppercase "<<str1<<"\n";
}
void tolowercase()
{
char str1[100];
cout<<"--function to convert string to lowercase--\n";
cout<<"Enter a string :\n";
cin>>str1;
for(int i=0;str1[i]!='\0';i++)
{
if(str1[i]>='A'&&str1[i]<='Z')
str1[i]=str1[i]+32;
}
cout<<"string in lowercase "<<str1<<"\n";
};
class Maths
{
public:
//factorial function.
int fact()
{
int n,i;
int factorial=1;
cout<<"Enter a no.: ";
cin>>n;


for(i=1;i<=n;i++)

factorial*=i;

//cout<<"FACTORIAL of: "<< n <<"is"<<factorial;
return factorial;
}
//prime function.
void prime()
{
int n,i;
int flag=0;
int m=0;
cout<<"Enter the no.: ";
cin>>n;
m=n/2;
for(i=2;i<=m;i++)
{
if(n%i==0)
{
cout<<n<<"is not a PRIME no.";
flag=1;
break;
}
}
if(flag==0)
{
cout<<n<<"is a PRIME no.";
}
}
//power function.
double pow()
{
double x;
int num=1,expo;
cout<<"Enter the no.: ";
cin>>x;
cout<<"Enter the power: ";
cin>>expo;
for(int i=1;i<=expo;i++)
{
num*=x;
x=num;
}
return x;
}
//ciel function.
double ceil()
{
double x;
cout<<"Enter the no.: ";
cin>>x;
int result=x;
if(x>result)
{
result=x+1;
x=result;
}
cout<<"No. is: "<<result;
return x;
}
//floor function.
double floor()
{
double x;
int result;
cout<<"Enter the no.: ";
cin>>x;
result=x;
if(x>result)
{
x=result;
}
cout<<"Floor is" << result;
return result;
}
//max function.
int max()
{
int a,b,result;
cout<<"Enter the no.: ";
cin>>a>>b;
if(a>b)
{
result=a;
}
else
{
result=b;
}
cout<<"MAX:"<<result;
}
//min function.
int min()
{
int a,b,result;
cout<<"Enter the no.: ";
cin>>a>>b;
if(a<b)
{
result=a;
}
else
{
result=b;
}
cout<<"MIN:"<<result;
}
//kaprekar function.
int kaprekar()
{
int n;
cout<<"Enter the no.: ";
cin>>n;
if(n==1)
{
return 1;//return true if n is kaprekar.
}
int n_sq=n*n;         //counting no. of
int count_digits=0;   // digits in square
while(n_sq)
{
count_digits++;
n_sq/=10;
}
n_sq=n*n;
for(int i=1;i<=count_digits;i++)
{
int j=pow(10,i);
if(j==n)
{
continue;
}
int sum=n_sq/j+n_sq%j;
if(sum==n)
{
return 1;
}
}
cout<<"Kaprekar : "<<n;
return 0;
}
//int happy function.
int happy()
{
/*int n,result,sum,rem;
cout<<"Enter the no.: ";
cin>>n;
rem=sum=0;
while(n>0)
{
rem=n%10;
sum+=rem*rem;
n/=10;
return sum;
}
result=sum;
while(result!=1&&result!=4)
{
result=happy(result);
}
if(result==1)
{
cout<<n<<"is a HAPPY   NO.";
}
else
{
cout<<n<<"is not a HAPPY no.";
} */
   int rem,s,r,a;
   while(a>9)
    {
       s=0;
       while(a!=0)
	 {
	     r=a%10;
	     s+=r*r;
	     a/=10;
	  }
	a=s;
     }
   if(a==1)
     return 0;
   else
     return 1;

}
//automorphic function.
int automorphic()
{
int n,flag=0;
cout<<"Enter a no.";
cin>>n;
int sq=n*n;
int store=n;
while(n>0)
{
if(n%10!==sq%10)
{
flag=1;
break;
}
n/=10;
sq/=10;
}
if(flag==1)
{
cout<<store<<"is not an AUTOMORPHIC no.";
}
else
{
cout<<store<<"is an AUTOMORPHIC no.";
}
return 0;
}
};
class merge: public String, public Maths
{
public:
};
void main()
{
clrscr();
merge merge;
merge.length();
merge.copy();
merge.concat();
merge.compare();
merge.equals();
merge.equalsignorecase();
merge.substring();
merge.indexOf();
merge.lastindexOf();
merge.del();
merge.insert();
merge.touppercase();
merge.tolowercase();
int fact=merge.fact();
cout<<"Factorial: "<<fact;
merge.prime();
double pow=merge.pow();
cout<<"POWER: "<<pow;
merge.ceil();
merge.floor();
merge.max();
merge.min();
merge.kaprekar();
merge.happy();
merge.automorphic();
getch();
};