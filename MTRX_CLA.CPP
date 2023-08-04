#include<iostream.h>
#include<conio.h>
class matrix
{
  public:
  int maxrow,maxcol,*ptr;

  public:
  matrix(int r,int c)  //constructer to allocate memory to matrix
  {
   maxcol=c;maxrow=r;
   ptr=new int[r*c];
  }

  void getmat()
  {
    int index,i,j;
    for(i=0;i<maxrow;i++)
    for(j=0;j<maxcol;j++)
    {
       index=i*maxcol+j;
       cout<<"\nEnter element no. "<<index+1<<"--> ";
       cin>>ptr[index];
    }
  }


  void putmat()
  {
    int index,i,j;
    cout<<endl;
    for(i=0;i<maxrow;i++)
    {
      for(j=0;j<maxcol;j++)
      {
       index=i*maxcol+j;

       cout<<ptr[index]<<"  ";
      }
    cout<<endl;
    }
  }
  matrix operator + (matrix b)
  {
    int i=0,j=0,index;
    matrix c(maxrow,maxcol);
    for(;i<maxrow;i++)
    {
       for(;j<maxcol;j++)
       {
	 //index=i*maxcol+j;
	// c.ptr[index]=ptr[index]+b.ptr[index];
	 *((c.ptr+i)+j)=*((ptr+i)+j)+*((b.ptr+i)+j);
     //  cout<<*(*(ptr+i)+j)+*(*(b.ptr+i)+j);
       }
    }
//    c.putmat();
    return (c);

  }

  matrix operator - (matrix b)
  {
    int i=0,j=0,index;
    matrix c(maxrow,maxcol);
    for(;i<maxrow;i++)
    {
       for(;j<maxcol;j++)
       {
	// index=i*maxcol+j;
	// c.ptr[index]=ptr[index]-b.ptr[index];
	*((c.ptr+i)+j)=*((ptr+i)+j)-*((b.ptr+i)+j);
       }
    }
    return (c);

  }
};
void main()
{
  clrscr();
  int ar,ac,bc,br;
  cout<<"Enter no. of rows and coloumns in first matrix  ";
  cin>>ar>>ac;
  matrix a(ar,ac);
  a.getmat();
  a.putmat();

  cout<<"Enter no. of rows and coloumns in second matrix  ";
  cin>>br>>bc;
  matrix b(br,bc);
  b.getmat();
  b.putmat();

  matrix sum(ar,ac);
  cout<<"\nSum of two matrices is->  ";
  sum=a+b;
  sum.putmat();

  matrix diff(ar,ac);
  cout<<"\nDiffrence of two matrices is->  ";
  diff=a-b;
  diff.putmat();

  getch();
}