#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

class maths
{
private:
public:
int square(int n);  //
int count_digit(int n);//
int powe(int n); //
int prime();         //
int fact();       //
void power();       //
void ceil(double num); //
void floor(double num ); //
void max() ;
void min();
void kap();     //
void automorphic( int num);
void happy(int num);
};
int maths:: powe(int n)
{
int f=1,i;
for(i=0;i<=n;i++)
{
f=f*n;
}
return f;

}
int count_digit(int n)
{
int c=0;
while(n>0)
{ c++;
n/=10;
}
return c;
}
int maths:: square(int n)
{
return n*n;
}

void maths::kap()
{
int n,s=0,p=0;
 cout<<"Enter the number: ";
 cin>>n;
 //c=count_digit(n);
 int r_dig,c_dig,eq_parts;//r_dig=right digit,c_dig=center digit
  s=square(n);
  p=powe(10);
  for(r_dig=1;r_dig<c_dig;r_dig++)
  {
  eq_parts=p;
  if(eq_parts==n)
  continue;
  int sum=s/eq_parts + s%eq_parts;
  if(sum==n)
  {
   cout<<"Kaprekar number";
  }
  else
  cout<<"Not a kaprekar number";
  }
}
int maths:: fact()
{
int f,n;
int i;

cout<<"Enter the number";
cin>>n;
for(i=n;i>0;i++)
{
f=f*i;
}
cout<<f;
return f;

}

int maths:: prime()
{
int flag=0,i,m,n;
cout<<"\nEnter the number you wanna check whether it is prime or not!!!!";
cin>>n;
m=n/2;
  for(i=2;i<=m;i++)
  {
    if(n%i==0)
    {
      cout<<"\nIt is not a prime number !!!! ";
      flag=1;
      break;
     }
   }
   if(flag==0)
   {
    cout<<n<<" is a prime number ";

   }return 0;

}
/*
void maths::powe()
{
double e,b,res=1;
cout<<"\nEnter the base and the exponent respectively";
cin>>b>>e;
while(e!=0)
{
res=res*b;
--e;
}
cout<<"Power of "<<b<<"^"<<e<<"is: "<<res;
}
*/
void maths::ceil(double num)
{
int n;
//cout<<"Enter the no.";
//cin>>num;
num=(int)n;
if(n>num)
{
cout<<num+1;
}
cout<<num;
}
void maths::floor(double num)
{
int n;
num=(int)n;
if(n<num)
{cout<<num-1;
}
cout<<num;
}

void maths::max()
{
int a[20],n,i;
cout<<"Enter the number of elements: \n";
cin>>n;
cout<<"\n";
for(i=0;i<n;i++)
{
cout<<"Enter Element : "<<endl;
cin>>a[i];
}
for(i=1;i<n;i++)
{
if(a[0]<a[i])
a[0]=a[i];
}
cout<<"Largest Number : "<<a[0];
}

void maths::min()
{
int a[20];
int n,i;
cout<<"Enter the number of elements: \n";
cin>>n;
cout<<"\n";
for(i=0;i<n;i++)
{
cout<<"Enter Element : "<<endl;
cin>>a[i];
}
for(i=1;i<n;i++)
{
if(a[i]<a[0])
a[0]=a[i];
}
cout<<"Smallest Number : "<<a[0];
}

void maths::automorphic(int num)
{
int num1=num*num;
int n=num1;
int i=0;
while(n!=0)
{
n/=10;
i++;
}
int c=pow(10,i);
int a=num1%c;
if(a==num)
{
cout<<"It is an automorphic number \n";
}
else
cout<<"Not an automorphic number!!!!";
}
void maths::happy(int num1)
{
int n=num1;
int sum,rem;
while(sum!=1&&sum!=4)
{
sum=0;
while(n!=0)
{
rem=n%10;
sum+=(rem*rem);
n=n/10;
}
n=sum;
}
if(sum==1)
{
cout<<"It is a happy number :)";
}
else cout<<"IT is not a happy number :( ";
}

class String
{
  private:
  char ch[50];
  int i;
  public:
  int length();
  int length(char *m);
  void strcpy(char *m);
  void strcon(char *m,char *n);
  void substring(char *m ,int a);
  void substring(char *m,int a , int b);
  char* toUpperCase(char *m);
  char* toLowerCase(char *m);
  void  del(char *m,int a, int b);//to delete
  void  ins(char m[50], int a);
  int indexof(char *m , char a);
  int indexof(char *m,int b,char a);
  int CompareTo(char *m,char *n);
  int equal(char *m,char *n);
  int equalignorecase(char *m,char *n);
};
void String::strcon( char *m , char *n)
{
    int j =0;
    for(i= 0; m[i]!= '\0'; i++)
    {
        ch[j]= m[i];
        j++;
    }
    for(i= 0; n[i]!= '\0' ; i++)
    {
        ch[j]= n[i];
        j++;
    }
    ch[j] = '\0';
    puts(ch);
}
int String :: length()
{
 int j = 0;
 cout<<"enter a string";
 cin.getline(ch,50);
 for(int i=0 ; ch[i] !='\0' ; i++)
 {
     j++;
 } 
 return j;
}

int String :: length(char *m)
{
 int j = 0;
 for(int i=0 ; m[i] !='\0' ; i++)
 {
     j++;
 } 
 return j;
}

void String :: strcpy(char *m)
{
   int j = 0;
 for(int i=0 ; m[i] !='\0' ; i++)
 {
     ch[j] = m[i];
     j++;
 } 
 cout<<"\n";
 puts(ch);
}

void String :: substring(char *m,int a)
{
 int j=0;
 for(int i=a+1 ; m[i] !='\0' ; i++)
 {
     ch[j] = m[i];
     j++;
 } 
 ch[j]='\0';
 cout<<"\n";
 puts(ch);
}

void String :: substring(char *m,int a , int b)
{
 int j=0;
 for(int i=a+1 ; i< b ; i++)
 {
     ch[j] = m[i];
     j++;
 } 
 ch[j]='\0';
 cout<<"\n";
 puts(ch);
}

char* String :: toUpperCase(char *m)
{
     for( int i = 0 ; m[i] != '\0' ;i++)
    {
    
        if(m[i] >= 'a' && m[i] <= 'z')
        m[i] = (int)m[i]-32;
         
    }
    return m;
    /*int j = 0 ;
    for( int i = 0 ; m[i] != '\0' ;i++)
    {
        if(m[i] >='a' && m[i] <= 'z')
        {
        ch[j] = m[i] -32;
        }
        else
        {
        ch[j] = m[i];
        }
        j++;
    }
      ch[j] = '\0';
    puts(ch);*/
}

char* String :: toLowerCase(char *m)
{
   //int j=0;
    for( int i = 0 ; m[i] != '\0' ;i++)
    {
    
        if(m[i] >= 'A' && m[i] <= 'Z')
        m[i] = (int)m[i]+32;
        
         
    }
    return m;
    //ch[j] = '\0';
    /*for( int i = 0 ; ch[i] != '\0' ;i++)
    {
    cout<<ch[i];
    }*/
}

void String :: del(char *m,int a , int b)
{
    int j=0;
    for( int i = 0 ; m[i] != '\0' ;i++)
    {
        if(i>=a && i<=b)
        {
            continue;
        }
        else
        {
            ch[j]=m[i];
        }
        j++;
        
    }
    ch[j]='\0';
    cout<<"\n";
    puts(ch);
}

void String :: ins(char m[50], int a)
{
    int j=0,i,z;
    char n[20];
    cout<<"\nEnter the string to insert";
    cin.getline(n,20);
    for( int i = 0 ; m[i] != '\0' ;i++)
    {
    if(i==a)
    {
       for( int z = 0 ; n[z] != '\0' ;z++) 
       {
           ch[j] = n[z];
           j++;
       }
    }
    else
    {
      ch[j] = m[i];
      j++;  
    }
    
    }
    ch[j] = '\0';
    puts(ch);
}

int String :: indexof(char *m,char a)
{
    int j;
    for( int z = 0 ; m[z] != '\0' ;z++) 
    {
        if(m[z] == a)
        {
            return z;
        }  
    }
    return -1;
}

int String :: indexof(char *m,int b,char a)
{
    int j;
    for( int z = b+1 ; m[z] != '\0' ;z++) 
    {
        if(m[z] == a)
        {
            return z;
        }  
    }
    return -1;
}

int String ::CompareTo(char *m,char *n)
{
    int sum1=0,sum2=0;
 if(m[0] > n[0])
 {
   return 1;
 }
 if(m[0] < n[0])
 {
   return -1;
 }
 

   for(int i = 0 ; m[i]!='\0' ; i++)
   {
      sum1+=(int)m[i];
      sum2+=(int)n[i];
    
   }
   if(sum1==sum2)
   {
       cout<<"\nthey are equal"<<endl;
       return 0;
   }
   cout<<"\nthey are not completely equal\n their ASCII value: ";
   return sum1-sum2;
}

int String :: equal(char *m,char *n)
{
    int sum1=0,sum2=0;
  for(int i = 0 ; m[i]!='\0' ; i++)
   {
      sum1+=(int)m[i];
      sum2+=(int)n[i];
    
   }
   if(sum1==sum2)
   {
       cout<<"they are equal"<<endl;
       return 0;
   }
   cout<<"they are not equal"<<endl;
   return -1;
}

int String :: equalignorecase(char *m,char *n)
{
    toLowerCase(m);
    toLowerCase(n);
    int sum1 =0,sum2=0;
    for(int i = 0 ; m[i]!='\0' ; i++)
   {
      sum1+=(int)m[i];
      sum2+=(int)n[i];
    
   }
   if(sum1==sum2)
   {
       
       cout<<"they are equal"<<endl;
       return 0;
    }

   cout<<"they are not equal"<<endl;
   return -1;
}
class merge:public maths,public String
{
public:
};

void main()
{
int ch,c;
clrscr();
 char p[50],a[50],b[50];
 merge me;
 cout<<"\nEnter the character"<<endl;
 cin.getline(p,50);

 cout<<"\nEnter the character again"<<endl;
 cin.getline(a,50);


cout<<"\n**************************STRING*************************"<<endl;
//  comparing of two strings
 int compare=me.CompareTo(p,a);
 cout<<compare<<endl;
//find the equal strings using 0 and 1
 int equal=me.equal(p,a);
 cout<<equal<<endl;
// this function basically ignores the capital and small letters
 int ignoreCase=me.equalignorecase(p,a);
 cout<<ignoreCase<<endl;
//  Concatination
cout<<"\nEnter the character"<<endl;
cin.getline(b,50);
m.strcon(p,a);
cout<<"\n";

//copying a string
m.strcpy(a);
//finding the length of an strings
int d = me.length(b);
cout<<d<<endl;
// no parameter input the string
int f = me.length();
cout<<f<<endl;
// to the find string after certion position
me.substring(a,3);
cout<<"\n";
// between two string
me.substring(a,3,5);
//uppercase
char*upper =me.toUpperCase(p);
puts(upper);
//lowercase
m.toLowerCase(a);
puts(a);
cout<<"\n";
//deleting a string
m.del(p,2,4);
//insering a string
m.ins(p,8);
// finding the index
int index= m.indexof(p,'a');
cout<<"\n"<<index;
// finding the index after certain position
int index1 = m.indexof(p,1,'a');
cout<<"\n"<<index1;


cout<<"\n***********************************MATHS*****************************************";
cout<<"\n1.Maths\n2.String\n3.exit";
cout<<"Enter your choice";
cin>>ch;
switch(ch)
{
case 1:
   do{
   cout<<"\n1.Factorial\n2.Prime\n3.pow\n4.Ceil\n5.floor\n6.max\n7.min\n8.kaprekar\n9.automorphic\n10.happy\n11.Exit";
   cout<<"ENTER YOUR CHOICE";
   cin>>c;
   switch(c)
   {
     maths m;
       case 1:
       m.fact();
       break;
       case 2:
       m.prime();
       break;
      case 3:
      m.powe(10);
      break;
      case 4:
      {
      double num;
      cout<<"Enter the number";
      cin>>num;
      m.ceil(num);
      }
      break;
      case 5:
      {
      double n;
      cout<<"Enter the number";
      cin>>n;
      m.floor(n);
      }
      break;
      case 6:
      m.max();
      case 7:
      m.min();
      break;
      case 8:
      m.kap() ;
      break;
      case 9:
      {
      int num;
      cout<<"Enter the number : ";
      cin>>num;
      m.automorphic(num);
      }
      break;
      case 10:
      {
      int num;
      cout<<"Enter the number";
      cin>>num;
      m.happy(num);
      }
      break;

      case 11:
      exit(0);

   }       //end of inner switch
      }while(1);       //end of do while loop
  }    //end of outer switch
 getch();
}