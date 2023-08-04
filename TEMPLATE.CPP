#include<iostream.h>
#include<conio.h>
template<typename T>
class A
{
 T fun(T a,T b)
 {
   return a+b;
 }
{;
void main()
{
 clrscr();
 A obj;
 cout<<obj.fun<int>(2,3);
 cout<<obj.fun<char>('a','b');
 cout<<obj.fun<float>(3.0,4.0);
 getch();
}