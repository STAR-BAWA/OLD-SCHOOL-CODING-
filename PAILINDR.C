#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
 char data;
 struct node *link;
}stack;
stack *top=NULL;
char ch;
void palindrome()
{
 int i,len,mid;
 char str[20];
 printf("Enter the string   ");
 gets(str);
 len=strlen(str);
 mid=len/2;
 for(i=0;i<mid;i++)
       push(str[i]);
 if(len%2!=0)
    i++;
 for(i;i<len;i++)
 {  pop();
    if(str[i]!=ch)
	  {
	   printf("Not Pailindrome\n");
	   return;
	  }
 }
 printf("Pailindrome\n");
}

int push(char c)
{
  stack *new=malloc(sizeof(char));
  if(top==NULL)
	  new->link=NULL;
  else
	  new->link=top;
  new->data=c;
  top=new;
  return 0;
}

int pop()
{

 stack *del;

   ch=top->data;
   del=top;
   top=top->link;
   free(del);
   return 1;
}


int main()
{
 clrscr();
 printf("To cheak Palindrome\n");
 palindrome();


 getch();
 return 0;
}
