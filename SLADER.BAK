#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void mark(int n,char c) //To print c n times
{
  int i=0;
  cout<<endl;
  for(;i<n;i++)
      cout<<c;
  cout<<endl;
}
void game()
{
  cout<<"		Board Details		\n";
  cout<<"\n\n  		Snakes from->";mark(50,'~');
  cout<<"98 to 3,	93 to 68,	85 to 27,	89 to 51,\n";
  cout<<"62 to 23,	65 to 25,	46 to 13\n\n";

  cout<<"\n\n		Ladders from->";mark(50,'^');
  cout<<"8 to 26,	17 to 35,	19 to 38\n";
  cout<<"21 to 82,	30 to 53,	36 to 57\n";
  cout<<"43 to 77,	50 to 91,	54 to 88\n";
  cout<<"61 to 99,	66 to 87";
  mark(50,'_');
}
void score(char *N1,char* N2,int p1,int p2)
{
  mark(50,'*');
  cout<<endl<<N1<<" -> You are at position "<<p1;
  mark(50,'@');
  cout<<endl<<N2<<" -> You are at position "<<p2<<endl;
  if(p1>p2){
	    cout<<N1<<" is "<<p1-p2<<" blocks ahead "<<N2;
	    mark(50,'\2');
	    cout<<"\n\nCongo "<<N1;
	    cout<<"\nBetter Luck Next Time "<<N2;
	   }
  else if(p1<p2){
	    cout<<N2<<" is "<<p2-p1<<" blocks ahead "<<N1;
	    mark(50,'\2');
	    cout<<"\n\nCongo "<<N2;
	    cout<<"\nBetter Luck Next Time "<<N1;
	   }
  else{
       mark(50,'=');
       cout<<"\n\nYou both stand at equal positions "<<N1<<" & "<<N2;
      }
  cout<<endl;
}
int dice(char *N,int &point)
{
  int d;
  cout<<endl;
  cout<<endl<<endl<<N<<" You are at position "<<point<<" its your turn to play dice.";
  getch();
  d=random(6)+1;cout<<"\n\nYou got "<<d<<endl;
  if(d+point<=100)
  {
  cout<<"\n\nNow u are at position "<<point+d;
  point+=d;
  if (d==6)
       point=dice(N,point);
  switch(point)
     {
       case 98:point=3;break;
       case 93:point=68;break;
       case 89:point=51;break;
       case 85:point=24;break;
       case 62:point=23;break;
       case 65:point=25;break;
       case 46:point=13;break;

       case  8:point=26;break;
       case 17:point=35;break;
       case 19:point=38;break;
       case 21:point=82;break;
       case 30:point=53;break;
       case 36:point=57;break;
       case 43:point=77;break;
       case 50:point=91;break;
       case 54:point=88;break;
       case 61:point=99;break;
       case 66:point=87;break;

       default: point=point;
     }
   }
   else cout<<"\n\nYou must get "<<100-point<<" to win, no improve in your position ";
   return point;
}

void main()
{
  clrscr();
  int p1=0,p2=0,lastpos;
  char name1[20],name2[20];
  mark(50,'!');
  cout<<"		Welcome in Snakes & Ladders\n";
  cout<<"\n\nName of Player 1-> ";gets(name1);
  cout<<"\n\nName of Player 2-> ";gets(name2);
  cout<<"\nPress Enter Throughout the Game to continue\n";
  mark(50,'%');
  cout<<" \n\n  	Start Playing\n";
  getch();
  clrscr();
  while(p1<100&&p2<100)
  {
    game();
    getch();
    clrscr();
A:  lastpos=p1;
    p1=dice(name1,p1);
    if(p1<lastpos)
       cout<<"\nOhh!! You got Snake, Now you are at position "<<p1;
    if(p1>lastpos+6)
	{
	cout<<"\nWow!! You got Ladder, Now you are at position "<<p1;
	cout<<"\nFor getting Ladder you will get another chance "<<name1;
	goto A;
	}

B:  lastpos=p2;
    p2=dice(name2,p2);
    if(p2<lastpos)
       cout<<"\n\n\nOhh!! You got Snake, Now you are at position "<<p2;
    if(p2>lastpos+6)
	{
	cout<<"\n\n\nWow!! You got Ladder, Now you are at position "<<p2;
	cout<<"\nFor getting Ladder you will get another chance "<<name2;
	goto B;
	}

    getch();
    clrscr();
    score(name1,name2,p1,p2);
    getch();
    clrscr();
  }
  mark(50,'*');
  cout<<"\n\n\n			RESULTS\n";
  score(name1,name2,p1,p2);
  if(p1>p2)
  cout<<name1<<"\n\n\n You Won!!!\n\n"<<name2<<" Better Luck Next Time ";
  else
  cout<<name2<<"\n\n\n You Won!!!\n\n"<<name1<<" Better Luck Next Time ";
  getch();


}