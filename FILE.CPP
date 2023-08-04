#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
 clrscr();
 char name[30];
 int marks;
 fstream file;
 file.open("xyz.txt",ios::out);
// ofstream file("mamama.out");
 cout<<"\nEnter 1st Name: ";
 cin>>name;
 cout<<"\nEnter Marks Scored: ";
 cin>>marks;
 file<<name<<"  "<<marks<<endl;

 cout<<"\nEnter 2nd Name: ";
 cin>>name;
 cout<<"\nEnter Marks Scored: ";
 cin>>marks;
 file<<name<<"  "<<marks<<endl;
 file.close();

// ifstream file("mamama.out");
 file.open("xyz.txt",ios::in);
 if(!file)
    cout<<"\n ERROR\n";
 cout<<"\n1st Name: ";
 file>>name;puts(name);
 cout<<"\n Marks Scored: ";
 file>>marks;cout<<marks;


 cout<<"\n2nd Name: ";
 file>>name;puts(name);
 cout<<"\n Marks Scored: ";
 file>>marks;cout<<marks;
 file.close();

 getch();
}