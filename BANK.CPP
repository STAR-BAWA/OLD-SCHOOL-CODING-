#include<iostream.h>
#include<conio.h>
class RBI
{
 public:
 int min_ir;
 int min_ba;
 double max_wl;
 RBI()
 {
  min_ir=4;
  min_ba=1000;
  max_wl=50000;
 }
 protected:
 void putRBI()
 {
  cout<<"\nRBI has predefined few functionalities as follows-\n";
  cout<<"\nMinimum Intrest Rate is "<<min_ir<<"%";
  cout<<"\nMinimum Balance Allowed is Rs "<<min_ba<<endl;
  cout<<"Maximum withdrawl allowed at a time is Rs "<<max_wl<<endl;
 }
};
class SBI:public RBI
{
 public:
 int mir;
 int mba;
 double mwl;

 void getSBI()
 {
  mir=min_ir;
  mba=min_ba;
  mwl=max_wl;
 }
 void putSBI()
 {
  putRBI();
  cout<<"SBI Uses functionalities predefined by RBI\n";
 }
};
class ICICI:public RBI
{
 public:
 int mir;
 int mba;
 double mwl;

 void getICICI()
 {
  mir=6;
  mba=500;
  mwl=70000;
 }
 void putICICI()
 {
  cout<<"\nICICI has following  functionalities -\n";
  cout<<"\nMinimum Intrest Rate is "<<mir<<"%";
  cout<<"\nMinimum Balance Allowed is Rs "<<mba;
  cout<<"\nMaximum withdrawl allowed at a time is Rs "<<mwl<<endl;
 }
};
class PNB:public RBI
{
 public:
 int mir;
 int mba;
 double mwl;

 void getPNB()
 {
  mir=6;
  mba=700;
  mwl=60000;
 }
 void putPNB()
 {
  cout<<"\nPNB has following  functionalities -\n";
  cout<<"\nMinimum Intrest Rate is "<<mir<<"%";
  cout<<"\nMinimum Balance Allowed is Rs "<<mba;
  cout<<"\nMaximum withdrawl allowed at a time is Rs "<<mwl<<endl;

 }
};
class CUSTOMER:public SBI,public ICICI,public PNB
{
 char name[7], add[20];
 long phn;
 public:
 void getCUSTOMER()
 {
  cout<<"\nEnter your name-  ";
  cin>>name;
  cout<<"\nEnter Address- ";
  cin>>add;
  cout<<"\nEnter your Phone No.-  ";
  cin>>phn;
 }
 void putCUSTOMER()
 {

  cout<<"\n**********\1 \2 OUTPUT \1 \2**************\n		Customer Details";
  cout<<"\nName- "<<name;
  cout<<"\nEnter Address- "<<add;
  cout<<"\nPhone No.-  "<<phn<<"\n";

 }

};
class ACCOUNT:public CUSTOMER
{
 long accno;
 char ifsc[7];
 public:
 int bank;
 long balance;
 void getACCOUNT()
 {
  cout<<"\nEnter your Bank details\nYour account belongs to which bank";
  cout<<"\n1 SBI\n2 ICICI\n3 PNB\nEnter - ";
  cin>>bank;
  cout<<"\nEnter your Account No.-  ";
  cin>>accno;
  cout<<"\nEnter IFSC Code of Bank.-  ";
  cin>>ifsc;
  cout<<"Enter your Bank Balance  ";
  cin>>balance;
 }
 void putACCOUNT()
 {
  cout<<"\n\n		Account Details";
  cout<<"\nAccount No.- "<<accno;
  cout<<"\nIFSC Code- "<<ifsc;
  cout<<"\nYou have balance Rs."<<balance;
 }
};

void main()
{
 clrscr();
 int c=1,s;
 long money;
 ACCOUNT obj;
 obj.getCUSTOMER();
 obj.getACCOUNT();
 switch(obj.bank)
 {
  case 1:obj.SBI::getSBI();break;
  case 2:obj.ICICI::getICICI();break;
  case 3:obj.PNB::getPNB();break;
 }
 obj.putCUSTOMER();
 obj.putACCOUNT();
 switch(obj.bank)
 {
  case 1:obj.SBI::putSBI();
	 while(c!=0)
	{
	 cout<<"\n\n		MENU\n1 Withdraw money\n2 Deposite money";
	 cout<<"\n3 Calculate intrest you will get if you maintain your present balance for next one year.\n";
	 cout<<"Enter your choice ";cin>>s;
	 switch(s)
	 {
	 case 1:cout<<"\nHow much you want to withdraw? ";
		cin>>money;
		if(obj.balance-money<obj.SBI::mba)
		cout<<"\nCannot Withdraw, as your balance will go below minimum allowed balance\n";
		else if(money>obj.SBI::mwl)
		cout<<"\nCan't Withdraw more than Rs"<<obj.SBI::mwl<<" at a time";
		else {
		     obj.balance=obj.balance-money;
		     cout<<"\nAfter Withdrawing Rs"<<obj.balance<<" left in your account\n";
		     }
		break;
	 case 2:cout<<"\nHow much you want to Deposite? ";
		cin>>money;
		obj.balance+=money;
		cout<<"\nAfter dipositing Rs"<<money<<" Your balance is Rs"<<obj.balance;
		break;
	 case 3:money=obj.balance*obj.SBI::mir/100;
		cout<<"\nAfter 1 year you will get intrest of Rs"<<money<<" on your present balance, if maintained.";
		break;
	 default:c=0;
	 }
	}
  break;
  case 2:obj.ICICI::putICICI();
	 while(c!=0)
	{
	 cout<<"\n\n		MENU\n1 Withdraw money\n2 Deposite money";
	 cout<<"\n3 Calculate intrest you will get if you maintain your present balance for next one year.\n";
	 cout<<"Enter your choice ";cin>>s;
	 switch(s)
	 {
	 case 1:cout<<"\nHow much you want to withdraw? ";
		cin>>money;
		if(obj.balance-money<obj.ICICI::mba)
		cout<<"\nCannot Withdraw, as your balance will go below minimum allowed balance\n";
		else if(money>obj.ICICI::mwl)
		cout<<"\nCan't Withdraw more than Rs"<<obj.ICICI::mwl<<" at a time";
		else{
		    obj.balance=obj.balance-money;
		    cout<<"\nAfter Withdrawing Rs"<<obj.balance<<" left in your account\n";
		    }
		break;
	 case 2:cout<<"\nHow much you want to Deposite? ";
		cin>>money;
		obj.balance+=money;
		cout<<"\nAfter dipositing Rs"<<money<<" Your balance is Rs"<<obj.balance;
		break;
	 case 3:money=obj.balance*obj.ICICI::mir/100;
		cout<<"\nAfter 1 year you will get intrest of Rs"<<money<<" on your present balance, if maintained.";
		break;
	 default:c=0;
	 }
	}
  break;
  case 3:obj.PNB::putPNB();
	 while(c!=0)
	{
	 cout<<"\n\n		MENU\n1 Withdraw money\n2 Deposite money";
	 cout<<"\n3 Calculate intrest you will get if you maintain your present balance for next one year.\n";
	 cout<<"Enter your choice ";cin>>s;
	 switch(s)
	 {
	 case 1:cout<<"\nHow much you want to withdraw? ";
		cin>>money;
		if(obj.balance-money<obj.PNB::mba)
		cout<<"\nCannot Withdraw, as your balance will go below minimum allowed balance\n";
		else if(money>obj.PNB::mwl)
		cout<<"\nCan't Withdraw more than Rs"<<obj.PNB::mwl<<" at a time";
		else{
		    obj.balance=obj.balance-money;
		    cout<<"\nAfter Withdrawing Rs"<<obj.balance<<" left in your account\n";
		    }
		break;
	 case 2:cout<<"\nHow much you want to Deposite? ";
		cin>>money;
		obj.balance+=money;
		cout<<"\nAfter dipositing Rs"<<money<<" Your balance is Rs"<<obj.balance;
		break;
	 case 3:money=obj.balance*obj.PNB::mir/100;
		cout<<"\nAfter 1 year you will get intrest of Rs"<<money<<" on your present balance, if maintained.";
		break;
	 default:c=0;
	 }
	}
  break;
 }

 getch();
}