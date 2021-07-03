#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tree*insert(struct tree*node,int key);
struct tree*newNode(int data);
void inorder(struct tree*node);
bool search(struct tree*node,int key);
int minimum(struct tree*node);
int maximum(struct tree*node);
struct tree*delete(struct tree*node,int key);

struct tree{
  int data;
  struct tree*left,*right;
};
int main(){
  int choice,exit,times,data,x,y;
  struct tree*root;
  root=NULL;  
do{
  printf("IMPLEMENTATION OF BINARY SEARCH TREE");
  printf("\n1.Insertion \n2.Deletion \n3.Searching \n4.Traversal \n5.Minimum and Maximum");
  printf("\nEnter your choice:");
  scanf("%d",&choice);
  switch (choice)  {
  case 1:
   printf("How many nodes do you want to insert? \nEnter a count:");
   scanf("%d",&times);
   for(int i=0;i<times;i++)   {
      printf("\nEnter a value:");
      scanf("%d",&data);
      root=insert(root,data);
    }
    break;
  case 2:
   printf("\nEnter the value to be deleted :");
   scanf("%d",&data);
   root=delete(root,data);
   break;
  case 3:
   printf("\nEnter the value to be searched:");
   scanf("%d",&data);
   printf("\nIn the Binary Search Tree, The given element is ");
   search(root,data)?printf("found"): printf("not found");break;
  case 4:
    printf("\nThe Binary Search Tree is :  ");
    inorder(root);break;
  case 5:
    x=minimum(root);
    printf("\nThe minimum value in the bst is : %d",x);
    y=maximum(root);
    printf("\nThe maximum value in the bst is : %d\n\n", y);
    break;  
  default:
    printf("\nERROR!! Enter the correct choice ");break;
  }
  printf("\nDo you want to continue(0 or 1):");
  scanf("%d",&exit);
}while(exit==1);
return 0;
}

struct tree*newNode(int data){
  struct tree*temp;
  temp=(struct tree*)malloc(sizeof(struct tree));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

struct tree*insert(struct tree*node,int key){
  if (node==NULL)
    return newNode(key);
  else if(key<=node->data)  {
    node->left=insert(node->left,key);
  }
  else  {
    node->right=insert(node->right,key);
  }  
  return node;
}

void inorder(struct tree*node){
  if(node==NULL)
    return;
  inorder(node->left);
  printf("\t%d",node->data);
  inorder(node->right);
}

bool search(struct tree*node,int key){
  if(node==NULL) return false;
  else if(node->data==key) return true;
  else if (key<node->data) search(node->left,key);
  else search(node->right,key);
}

int minimum(struct tree*node){
  if(node->left==NULL) return node->data;
  else minimum(node->left);
}

int maximum(struct tree*node){
  if(node->right==NULL) return node->data;
  else maximum(node->right);
}

struct tree*delete(struct tree*node,int key){
  if (node==NULL)
     return node;
  if (key<node->data) 
    node->left=delete(node->left,key);
  
  else if (key > node->data)
    node->right=delete(node->right,key);
  else  {
    if(node->right==NULL)     {
       struct tree*temp;
       temp=node->left;
       free(node);
       return temp;       
     }
     if(node->left==NULL)     {
       struct tree*temp;
       temp=node->right;
       free(node);
       return temp;
     }
     int min=minimum(node->right);
     node->data=min;
     node->right=delete(node->right,key);
  }
  return node;
}



































