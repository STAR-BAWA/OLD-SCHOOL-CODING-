		 /*		  CUSTOMER
				     |
				     |
				  ACCOUNT
	     ------------------------------------------------
	     |			     |                      |
	     |			     |                      |
	   SAVING                    FD                 CURRENT
				     |
object->    save		     |                     cur     <--object
			-----------------------------
			|	     |		    |
		       SFD          MFD            LFD
object->               sfd          mfd            lfd


		      Short         Mid           Long
		      Term         Term          Term
		     Deposite     Deposite      Deposite  */
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
class CUSTOMER
{
 char name[10],add[10],phn[10];
 protected:
 void iCUSTOMER()
 {
  cout<<"\nEnter your name-  ";
  cin>>name;
  cout<<"Enter Address- ";
  cin>>add;
  cout<<"Enter your Phone No.-  ";
  cin>>phn;
 }
 void oCUSTOMER()
 {
  cout<<"\n**********\1 \2 OUTPUT \1 \2**************\n		Customer Details";
  cout<<"\nName- "<<name;
  cout<<"\nEnter Address- "<<add;
  cout<<"\nPhone No.-  "<<phn<<"\n";
 }

};
class ACCOUNT:public CUSTOMER
{

  char *accno,*ifsc;int no;
  public:
  int acctyp,subtyp;
  protected:
  long balance;
  void iACCOUNT()
  {
    label:
    cout<<"Enter Balance According to your Account ";  cin>>balance;

     switch(acctyp)
      {
	case 1:no=cur.chk_balCURRENT();break;
	case 2:switch(subtyp)
	       {
	       case 1:no=sfd.chk_balFD(1);  break;
	       case 2:no=mfd.chk_balFD(2);  break;
	       case 3:no=lfd.chk_balFD(3);  break;
	       }
	       break;
	case 3:no=save.chk_balSAVING();break;

      }if(no==0)goto label;

    accno="998774498";
    ifsc="s84041i";
  }
  void oACCOUNT()
  {
    cout<<"\n******Details of your ";
    if(acctyp==1)cout<<"Current Account";
    if(acctyp==2)cout<<"Fixed Deposit";
    if(acctyp==3)cout<<"Saving Account";
    cout<<"*****\nAccount NO. "<<accno;
    cout<<"\nIFSC Code  "<<ifsc;
    cout<<"\nBalance-  Rs "<<balance;
  }
};
class SAVING:public ACCOUNT
{
  private:
  int mir,mba,c;
  double mwl,money;

  public:
  SAVING()
  {
   mir=6;
   mwl=50000;
   mba=1000;
  }

  int chk_balSAVING()
  {
    if(balance<mba)
	return 0;
    else return 1;
  }
  void iSAVING()
  {
     iCUSTOMER();
     iACCOUNT();
  }
  void oSAVING()
  {
     oCUSTOMER();
     oACCOUNT();
     cout<<"\n***************************************************************";
     cout<<"\nIn your Saving Account-\nInterest rate is "<<mir<<" % per annum";
     cout<<"\nMaximum withdrawl at a time can be Rs "<<mwl;
     cout<<"\nMinimum balance must be Rs "<<mba;
     cout<<"\n***************************************************************";
     while(1)
     {
     cout<<"\n\nYou can-\n1 Cheak Balance\n2 Withdraw\n3 Deposite\nChoice- ";
     cin>>c;
      switch(c)
      {
       case 1:cout<<"Balance Rs"<<balance; break;
       case 2:wdSAVING();break;
       case 3:dpSAVING();break;
       default:return;
      }
     }
  }
  void wdSAVING()
   {
      cout<<"\nEnter Amount to be Withdrawn "; cin>>money;
      if(balance-money<mba)
	 cout<<"\nCan't Withdraw, as minimum balance should be Rs "<<mba;
      else if(balance>mwl)
	 cout<<"\nCan't withdraw more than Rs "<<mwl;
      else{
	     balance-=money;
	     cout<<"\nRs "<<balance<<" left after withdrawing Rs "<<money;
	  }
   }
  void dpSAVING()
     {
       cout<<"\nEnter Amount to be deposited  "; cin>>money;
       balance+=money;
       cout<<"\nFinal Balance is Rs "<<balance<<" after depositing Rs "<<money;
     }

}save;
class CURRENT:public ACCOUNT
{
  private:
  int mir,mba,c;
  long mwl,money;

  public:
  CURRENT()
  {
   mir=2;
   mwl=10000000;
   mba=20000;
  }

  int chk_balCURRENT()
  {
    if(balance<mba)
	return 0;
    else return 1;
  }
  void iCURRENT()
  {
     iCUSTOMER();
     iACCOUNT();
  }
  void oCURRENT()
  {
     oCUSTOMER();
     oACCOUNT();
     cout<<"\n***************************************************************";
     cout<<"\nIn your Current Account-\nInterest rate is "<<mir<<" % per annum";
     cout<<"\nMaximum withdrawl at a time can be Rs "<<mwl;
     cout<<"\nMinimum balance must be Rs "<<mba;
     cout<<"\n***************************************************************";
     while(1)
     {
     cout<<"\n\nYou can-\n1 Cheak Balance\n2 Withdraw\n3 Deposite\nChoice- ";
     cin>>c;
      switch(c)
      {
       case 1:cout<<"Balance Rs "<<balance; break;
       case 2:wdCURRENT();break;
       case 3:dpCURRENT();break;
       default:return;
      }
     }
  }
  void wdCURRENT()
   {
      cout<<"\nEnter Amount to be Withdrawn  "; cin>>money;
      if(balance-money<mba)
	 cout<<"\nCan't Withdraw, as minimum balance should be Rs "<<mba;
      else if(balance>mwl)
	 cout<<"\nCan't withdraw more than Rs "<<mwl;
      else{
	     balance-=money;
	     cout<<"\nRs "<<balance<<" left after withdrawing Rs "<<money;
	  }
   }
  void dpCURRENT()
     {
       cout<<"\nEnter Amount to be deposited  "; cin>>money;
       balance+=money;
       cout<<"\nFinal Balance is Rs "<<balance<<" after depositing Rs "<<money;
     }

}cur;
class FD:public ACCOUNT
{
  int chk;

  public:
  int chk_balFD(int styp)
  {
    switch(styp)
    {
      case 1:chk=sfd.chk_balSFD();break;
      case 2:chk=mfd.chk_balMFD();break;
      case 3:chk=lfd.chk_balLFD();break;
    }
    return chk;
  }
};
class SFD:public FD
{
  private:
  int ir,year,yr,c;
  long money,mba;

  public:

  SFD()
  {
   ir=3;
   year=5;
   mba=10000;
  }
  int chk_balSFD()
  {
    if(balance<mba)
	return 0;
    else return 1;
  }
  void iSFD()
  {
     iCUSTOMER();
     iACCOUNT();

  }
  void oSFD()
  {
     oCUSTOMER();
     oACCOUNT();
     cout<<"\n***************************************************************";
     cout<<"\nIn your Short term FD-\nInterest rate is "<<ir<<" % per annum";
     cout<<"\nThis FD is made for minimum "<<year<<" years";
     cout<<"\nIf refund is asked before this time, only principal intrest ";
     cout<<"\nwill be given istead of COMPOUND INTREST";
     cout<<"\nMinimum balance must be Rs "<<mba;
     cout<<"\n***************************************************************";
     while(1)
     {
     cout<<"\n\nYou can-\n1 Cheak Balance after certain no. of years\n";
     cout<<"2 Calculate Intrest gained after certain no. of years\nChoice- ";
     cin>>c;
      switch(c)
      {
       case 1:
	      int_SFD();
	      cout<<"\nBalance after "<<yr<<" years will be Rs"<<balance+money;
	      break;
       case 2:int_SFD();
	      cout<<"\nAfter "<<yr<<" years, Rs "<<money<<" will be added to your balance as intrest";
	      break;

       default:return;
      }
     }
  }
  void int_SFD()
   {
      cout<<"\nEnter No. of years after which intrest is to be calculate ";
      cin>>yr;
      if(yr>=year)
      money=(balance*(pow((1+ir),yr))-balance);//Compund Intrest
      else
      {
      money=(balance*ir*yr)/100;
      cout<<"\nCalculating intrest before "<<year<<" years,Fine charged only PRINCIPAL INTREST";
      cout<<" will be given on your balance";
      }
   }
}sfd;
class MFD:public FD
{
  private:
  int ir,year,yr,c;
  long money,mba;

  public:
  MFD()
  {
   ir=5;
   year=20;
   mba=70000;
  }
  int chk_balMFD()
  {
    if(balance<mba)
	return 0;
    else return 1;
  }
  void iMFD()
  {
     iCUSTOMER();
     iACCOUNT();

  }
  void oMFD()
  {
     oCUSTOMER();
     oACCOUNT();
     cout<<"\n***************************************************************";
     cout<<"\nIn your Mid term FD-\nInterest rate is "<<ir<<" % per annum";
     cout<<"\nThis FD is made for minimum" <<year<<" years";
     cout<<"\nIf refund is asked before this time, only principal intrest ";
     cout<<"\nwill be given instead of COMPOUND INTREST";
     cout<<"\nMinimum balance must be Rs "<<mba;
     cout<<"\n***************************************************************";
     while(1)
     {
     cout<<"\n\nYou can-\n1 Cheak Balance after certain no. of years\n2 Calculate Intrest gained after certain no. of years\nChoice- ";
     cin>>c;
      switch(c)
      {
       case 1:
	      int_MFD();
	      cout<<"Balance after "<<yr<<" years will be Rs "<<balance+money;
	      break;
       case 2:int_MFD();
	      cout<<"After "<<yr<<" years, Rs "<<money<<" will be added to your balance as intrest";
	      break;

       default:return;
      }
     }
  }
  void int_MFD()
   {
      cout<<"\nEnter No. of years after which intrest is to be calculate "; cin>>yr;
      if(yr>year)
      money=(balance*(pow((1+ir),yr))-balance);//Compund Intrest
      else{
	    money=(balance*ir*yr)/100;
	    cout<<"\nCalculating intrest before "<<year<<" years,Fine charged only PRINCIPAL INTREST";
	    cout<<" will be given on your balance";
	  }
   }
}mfd;
class LFD:public FD
{
  private:
  int ir,year,yr,c;
  long money,mba;

  public:
  LFD()
  {
   ir=7;
   year=50;
   mba=50000;
  }
  int chk_balLFD()
  {
    if(balance<mba)
	return 0;
    else return 1;
  }
  void iLFD()
  {
     iCUSTOMER();
     iACCOUNT();

  }
  void oLFD()
  {
     oCUSTOMER();
     oACCOUNT();
     cout<<"\n***************************************************************";
     cout<<"\nIn your Mid term FD-\nInterest rate is "<<ir<<" % per annum";
     cout<<"\nThis FD is made for minimum" <<year<<" years";
     cout<<"\nIf refund is asked before this time, only principal intrest ";
     cout<<"\nwill be given instead of COMPOUND INTREST";
     cout<<"\nMinimum balance must be Rs "<<mba;
     cout<<"\n***************************************************************";
     while(1)
     {
     cout<<"\n\nYou can-\n1 Cheak Balance after certain no. of years\n2 Calculate Intrest gained after certain no. of years\nChoice- ";
     cin>>c;
      switch(c)
      {
       case 1:
	      int_LFD();
	      cout<<"\nBalance after "<<yr<<"years will be Rs "<<balance+money;
	      break;
       case 2:int_LFD();
	      cout<<"\nAfter "<<yr<<" years, Rs "<<money<<" will be added to your balance as intrest";
	      break;

       default:return;
      }
     }
  }
  void int_LFD()
   {
      cout<<"\nEnter No. of years after which intrest is to be calculate "; cin>>yr;
      if(yr>year)
      money=(balance*(pow((1+ir),yr))-balance);//Compund Intrest
      else  {
	      money=(balance*ir*yr)/100;
	      cout<<"\nCalculating intrest before "<<year<<" years,Fine charged";
	      cout<<"only PRINCIPAL INTREST will be given on your balance";
	    }

   }
}lfd;


void main()
{
 clrscr();
 int c,ch;

 cout<<"                   1                    2                      3 \n";
 cout<<"Acc.Type->      Current Acc.		FD		Saving Acc.\n";
 cout<<"Good For->      Business      Long term investment     Individual\n";
 cout<<"Intrest->       Low             Compound Intrest         Moderate\n";
 cout<<"Min.Balance->   Rs20000         Rs 50000-100000            1000\n";
print:
  cout<<"Which type of Account You want?  ";    cin>>c;
  switch(c)
  {
    case 1:
	   cur.acctyp=c;
	   cur.iCURRENT();
	   cur.oCURRENT();
	   break;
    case 2:

	   cout<<"**************Fixed Deposite *****************";
	   cout<<"\n         1               2               3";
	   cout<<"\n     Short term       Mid term       Long term ";
	   cout<<"\n       (5 yrs)        (20 yrs)        (50 yrs)";
	   cout<<"\nMin.FD";
	   cout<<"\nof Rs. 100000          70000           50000";
	   cout<<"\nHere you will get compound intrest.";
     label:cout<<"\nChoose- ";cin>>ch;
	   switch(ch)
	   {
	     case 1:
		    sfd.acctyp=c;
		    sfd.subtyp=ch;
		    sfd.iSFD();
		    sfd.oSFD();
		    break;
	     case 2:
		    mfd.acctyp=c;
		    mfd.subtyp=ch;
		    mfd.iMFD();
		    mfd.oMFD();
		    break;
	     case 3:
		    lfd.acctyp=c;
		    lfd.subtyp=ch;
		    lfd.iLFD();
		    lfd.oLFD();
		    break;
	     default:goto label;
	   }
	   break;
    case 3:
	   save.acctyp=c;
	   save.iSAVING();
	   save.oSAVING();
	   break;
    default:
	   goto print;
  }

 getch();
}

