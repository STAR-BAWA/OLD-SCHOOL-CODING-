#include<stdio.h>
#include<stdlib.h>

typedef struct leaf              //Leaf of Tree
{
 struct leaf *lchild;
 int data;
 struct leaf *rchild;
}leaf;

void postorder(leaf *tree)  //To print in postorder
{
 if(tree!=NULL)
 {
  postorder(tree->lchild);
  postorder(tree->rchild);
  printf("(%d) ",tree->data);
 }
}

void preorder(leaf *tree)   //To print in preorder
{
 if(tree!=NULL)
 {
  printf("(%d) ",tree->data);
  preorder(tree->lchild);
  preorder(tree->rchild);
 }
}
void inorder(leaf *tree)   //To print inorder
{
 if(tree!=NULL)
 {
  inorder(tree->lchild);
  printf("(%d)",tree->data);
  inorder(tree->rchild);
 }
}

void Tree(leaf *tree,int space) //To print as Tree
{ int i,COUNT=5;
  if(tree==NULL)
      return;
  space=space+COUNT;//Increase distance b/w levels
  Tree(tree->rchild,space);//to process right child first
  //Print current node after space
  printf("\n");
  for(i=COUNT;i<space;i++)
      printf(" ");
  printf("%d\n",tree->data);
  Tree(tree->lchild,space);//to process left child
}
leaf* insert() //insert leaf in Binary Tree
{
  int data; leaf *newtree=NULL;
  printf(" enter data {0 for no node}   ");
  scanf("%d",&data);
  if(data==0)
	 return NULL;
  newtree=(leaf*)malloc(sizeof(leaf));
  newtree->data=data;
  printf("For left child of %d",data);
  newtree->lchild=insert();

  printf("For right child of %d",data);
  newtree->rchild=insert();

  return newtree;
}
leaf* bstinsert(leaf* tree,int data)     //To add leaf in Binary Search Tree
{
  if(tree==NULL)
 {
   tree=(leaf*)malloc(sizeof(leaf));
   tree->data=data;
   tree->lchild=tree->rchild=NULL;

 }
 else
 {
 if(data>tree->data)
       tree->rchild=bstinsert(tree->rchild,data);

 if(data<tree->data)
       tree->lchild=bstinsert(tree->lchild,data);
 }
 return tree;
}
void BTree()  //Function to deal with Binary Tree
{
 int choice,data;
// clrscr();
 leaf *root=NULL;
 while (1)
 {
  printf("\n\2 \1 \2 \1 \2 Main Menu \1 \2 \1 \2 \1");
  printf("\n1 Insert a leaf.\n2 Display inorder\n3 Display preorder\n4 Display Postorder");
  printf("\n5 Print Tree\nEnter your Choice    ");scanf("%d",&choice);
  switch(choice)
  {
   case 1:root=insert();break;
   case 2:printf("\n\n");inorder(root);printf("\n\n");break;
   case 3:printf("\n\n");preorder(root);printf("\n\n");break;
   case 4:printf("\n\n");postorder(root);printf("\n\n");break;
   case 5:printf("\n\n");Tree(root,0);printf("\n\n");break;
   default:return;
  }
 }
}

leaf* search(leaf*tree,int data)
{
  while(tree!=NULL&&tree->data!=data)
  {
    if(tree->data>data)
	   tree=tree->lchild;
    else
	   tree=tree->rchild;
  }
  return tree;
}
leaf*chkmax(leaf*tree)
{
 while(tree!=NULL&&tree->lchild!=NULL)
    tree=tree->lchild;
 return tree;
}
leaf* del(leaf*tree,int data)
{
  leaf*temp;
  if(tree==NULL)
      {
      printf("\nElement to be deleted is not found!!\n");
      return NULL;
      }
  else if(tree->data>data)      //root > data
	 tree->lchild=del(tree->lchild,data);
  else if(tree->data<data)      //root < data
	  tree->rchild=del(tree->rchild,data);
  else {
	 if(tree->rchild==NULL&&tree->lchild==NULL)
	  {
	   free(tree);
	   return NULL;
	  }
	 else if(tree->rchild==NULL||tree->lchild==NULL)
	  {
	     if(tree->rchild!=NULL)
	     {
	       temp=tree->rchild;
	       free(tree);
	       return tree->rchild;
	     }
	     else
	     {
	       temp=tree->lchild;
	       free(tree);
	       return tree->lchild;
	     }
	  }
	 else
	  {
	    temp=chkmax(tree->rchild);
	    tree->data=temp->data;
	    tree->rchild=del(tree->rchild,temp->data);

	  }

       }
       return tree;
}
void BSTree() //Function to deal with Binary Search Tree
{
 int choice,data;
 leaf *bstroot=NULL,*found;
// clrscr();
 while (1)
 {
  printf("\n\2 \1 \2 \1 \2 Menu \1 \2 \1 \2 \1");
  printf("\n1 Insert  leaf.\n2 Display inorder\n3 Display preorder\n4 Display Postorder");
  printf("\n5 Print Tree\n6 Perform Binary Search\n7 Add a node\n8 Delete a leaf");
  printf("\nEnter your Choice    ");scanf("%d",&choice);
  switch(choice)
  {
   case 1:while(1)
	  {
	  printf("\nTo STOP entering enter 0\nEnter data.   ");
	  scanf("%d",&data);
	  if(data==0)  break;
	  else
	  bstroot=bstinsert(bstroot,data);
	  }break;
   case 2:printf("\n\n");inorder(bstroot);printf("\n\n");break;
   case 3:printf("\n\n");preorder(bstroot);printf("\n\n");break;
   case 4:printf("\n\n");postorder(bstroot);printf("\n\n");break;
   case 5:printf("\n\n");Tree(bstroot,0);printf("\n\n");break;
   case 6:printf("\nEnter data to be searched  ");
	  scanf("%d",&data);
	  found=search(bstroot,data);
	  if(found==NULL)
		 printf("\nElement not found!!\n");
	  else
		 printf("\nElement found at memory address %u!!\n",found);
		 break;
   case 7:printf("\nEnter data.   ");
	  scanf("%d",&data);
	  bstroot=bstinsert(bstroot,data);
	  break;
   case 8:printf("\nEnter data to be deleted  ");
	  scanf("%d",&data);
	  bstroot=del(bstroot,data);
	  break;
   default:return;
  }
 }
}
void main()
{
 int choice;
 clrscr();
 while (1)
 {
  printf("\n\2 \1 \2 \1 \2 Menu \1 \2 \1 \2 \1");
  printf("\n1 Binary Tree\n2 Binary Search Tree");
  printf("\nEnter your Choice    ");scanf("%d",&choice);
  switch(choice)
  {
   case 1:BTree(); break;
   case 2:BSTree();break;

   default:exit(1);
  }
 }
}