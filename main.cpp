#include<bits/stdc++.h>
using namespace std;
typedef struct bst
{
  struct bst *left;
  int data;
  struct bst *right;
} bst;
bst* newNode(int data)
{
    bst* temp = new bst;
 
    temp->data = data;
 
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}
 

bst* insert_bst(bst* root,int x)
{
  if(root==NULL)
  {
    root= newNode(x);
    return root;
  }
  else if(root->data>x)
  {
    root->left=insert_bst(root->left,x);
  }
  else
  root->right=insert_bst(root->right,x);
  return root;

}
void print_bst(bst *r)
{
  if(r==NULL)
  return;
  else{
    
  print_bst(r->left);
cout<<r->data<<" ";
  print_bst(r->right);
  }
}
int main()
{
  bst *root;
  root=insert_bst(root,10);
  root=insert_bst(root,13);
  root=insert_bst(root,16);
  root=insert_bst(root,1);
  root=insert_bst(root,5);
  print_bst(root);
}