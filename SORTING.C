#include<stdlib.h>
#include<conio.h>
#define max 10
void get_arr(int NoOfEle,int *N)
{
  int i=0;
  for(;i<NoOfEle;i++)
  {
    scanf("%d",&N[i]);
  }
}
void put_arr(int NoOfEle,int *N)
{
  int i=0;
  for(;i<NoOfEle;i++)
  {
    printf("%d  ",N[i]);
  }
}
void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
void bubble(int *N,int num)            //case 5
{
  int i,j;
  for(i=0;i<num;i++)
  {
    for(j=0;j<i+1;j++)
    {
      if(N[i]>N[j])
	 swap(&N[i],&N[j]);
    }
  }
}
void merge(int *N,int *temp,int lb,int ub,int mid) //case 6
{
   int i=lb,j=mid+1,k=lb;
   while(i<=mid&&j<=ub)
   {
      if(N[i]<=N[j])
	    temp[k++]=N[i++];
      else
	     temp[k++]=N[j++];
   }
   while(i<=mid)
	  temp[k++]=N[i++];
   while(j<=ub)
	  temp[k++]=N[j++];
   i=0;
   while(i!=ub+1)
	  N[i]=temp[i++];

}


void ms(int *N,int *temp,int lb,int ub)
{
   int mid;
   if(lb<ub)
   {
     mid=(lb+ub)/2;
     ms(N,temp,lb,mid);
     ms(N,temp,mid+1,ub);
     merge(N,temp,lb,ub,mid);
   }
}
//////////////////////////////////////////////////////////////
int qs(int *N,int l,int h)           //case 7
{
  int key=N[(l+h)/2],temp,start=l,end=h;
  do
  {
   while(N[l]<key)
	      l++;
   while(N[h]>key)
	      h--;
   if(l<=h)
   {
     temp=N[l];
     N[l++]=N[h];
     N[h--]=temp;

   }
  } while(l<=h);
  if(start<h)
	qs(N,start,h);
  if(l<end)
	qs(N,l,end);

}

///////////////////////////////////////////////////////////////////////////
void rs(int *N,int num)            //case 8
{
  int big=N[0],i,dig=0,pass;
  void radix_sort(int*,int,int);

  for(i=0;i<num;i++)  //getting greatest element
	if(N[i]>big)
	   big=N[i];

  while(big>0)
     {
      dig++;        //counting no. of digits in greatest element
      big/=10;
     }

  radix_sort(N,num,dig);
}

void radix_sort(int *N,int num,int dig)
{
  int pass,i,buckets[max][max]={0},divisor=1,colm,row[max]={0},r,c;
  for(pass=0;pass<dig;pass++)
  {
     for(i=0;i<num;i++) //to fill elements in buckets
     {
       colm=(N[i]/divisor)%10;
       buckets[row[colm]++][colm]=N[i];
     }
     i=0;
     for(c=0;c<10;c++) //to update array according to buckets
     {
       for(r=0;r<row[c];r++)
	 N[i++]=buckets[r][c];
     }
     divisor*=10;// div=div*10;    //to update divisor

     r=0;
     while(r<10)      //to reset row[] array
	 row[r++]=0;
  }

}  //////////////////////////
void minheap(int *A,int n,int data)
{
  int i,parent;
  n++;
  A[n]=data;
  i=n;
  while(i!=0)
  {
   parent=i/2;

   if(A[parent]>A[i])
     {
     swap(&A[parent],&A[i]);
     i=parent;
     }
   else
      return;
  }
}
void minhsort(int *A,int root,int till)
{
 int l,r,small;
 while(1)
 {
  l= (root*2)+1;
  r=(root*2)+2;
  if(l>till)
	return;
  if(r>till)		     //selecting the greator child
	  small=l;
  else
  {
    if(A[l]>A[r])
	small=r;
    else
	small=l;
  }
  if(A[root]>A[small])
     {
       swap(&A[root],&A[small]);
       root=small;
     }
  else
       return;
 }
}

void heap(int *A,int n,int data)
{
  int i,parent;
  n++;
  A[n]=data;
  i=n;
  while(i!=0)
  {
   parent=i/2;

   if(A[parent]<A[i])
     {
     swap(&A[parent],&A[i]);
     i=parent;
     }
   else
      return;
  }
}
void hsort(int *A,int root,int till)
{
 int l,r,big;
 while(1)
 {
  l= (root*2)+1;
  r=(root*2)+2;
  if(l>till)
	return;
  if(r>till)		     //selecting the greator child
	  big=l;
  else
  {
    if(A[l]>A[r])
	big=l;
    else
	big=r;
  }
  if(A[root]<A[big])
     {
       swap(&A[root],&A[big]);
       root=big;
     }
  else
       return;
 }
}
void hs(int *N,int n)
{
 int i,j,till,A[max];
 for(i=0,j=-1;i<n;i++,j++)
      heap(A,j,N[i]);     //creation of a min heap

 for(till=n-1;till>0;)    //sorting min heap
 {
     swap(&A[0],&A[till]);
     till--;
   hsort(A,0,till);
 }
  for(i=0;i<n;i++)//updating original array
      N[i]=A[i];
}
void main()
{

  int c,N[max],num,temp[max];
  clrscr();
  while(1)
  {
    printf("\n     	*********Sorting & Earching in Arrays*******\n");
    printf("Enter Array-->\nNo. of Elements  ");scanf("%d",&num);
    printf("\nEnter %d elements\n",num);get_arr(num,N);

    printf("\n\nMenu Driven");
    printf("\n1 Linear Search\n2 Binary Search\n");
    printf("3 Insertion Sort\n4 Selection Sort\n");
    printf("5 Bubble Sort\n6 Merge Sort\n");
    printf("7 Quick Sort\n8 Radix (Bucket) Sort\n9 Heap Sort\n");
    printf("\nEnter Your Choice  "); scanf("%d",&c);
    printf("\nYou Entered  ");put_arr(num,N);
    switch(c)
    {

      case 5:bubble(N,num);
	     printf("\nAfter Bubble Sorting  ");put_arr(num,N);
	     break;
      case 6:ms(N,temp,0,num);
	     printf("\nAfter Merge Sorting  ");put_arr(num,N);
	     break;
      case 7:qs(N,0,num-1);
	     printf("\nAfter Quick Sorting  ");put_arr(num,N);
	     break;
      case 8:rs(N,num);
	     printf("\nAfter Radix Sorting  ");put_arr(num,N);
	     break;
      case 9:hs(N,num);
	     printf("\nAfter Heap Sorting  ");put_arr(num,N);
	     break;
      default:getch();exit(1);
    }
  }
}