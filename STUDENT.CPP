#include<iostream.h>
#include<conio.h>
class student
{
 public:
 int formno,clas,studentid;
 char *name;
 public:
 void enter_student()
 {
  cout<<"Enter Name of the student   ";
  cin>>name;cout<<endl;
  cout<<"Enter form number of student   ";
  cin>>formno;cout<<endl;
  cout<<"Enter class of student   ";
  cin>>clas;cout<<endl;
  cout<<"Enter form student ID of student   ";
  cin>>studentid;cout<<endl;
 }
}
class subject:public student
{
 int m1,m2,m3,m4,m5;
 float percent;
 char *sub1,*sub2,*sub3,*sub4,*sub5;
 public:
 void enter_subject()
 {
   cout<<"Enter name of subject  ";
   cin>>sub1;
   cout<<"Marks ";cin>>m1;cout<<endl;

   cout<<"Enter name of subject  ";
   cin>>sub2;
   cout<<"Marks ";cin>>m2;cout<<endl;

   cout<<"Enter name of subject  ";
   cin>>sub3;
   cout<<"Marks ";cin>>m3;cout<<endl;

   cout<<"Enter name of subject  ";
   cin>>sub4;
   cout<<"Marks ";cin>>m4;cout<<endl;

   cout<<"Enter name of subject  ";
   cin>>sub5;
   cout<<"Marks ";cin>>m5;cout<<endl;
   percent=(m1+m2+m3+m4+m5)/5;
   cout<<"\n This student scored "<<percent<<"% marks\n";
 }
}
void main()
{
 clrscr();
 subject obj;
 obj.student::enter_student();
 obj.enter_subject();
 getch();
}