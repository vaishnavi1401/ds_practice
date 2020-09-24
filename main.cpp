#include<bits/stdc++.h>
using namespace std;
//defining a structure for bst with int datatype and two pointers left and right for child
typedef struct bst
{
  struct bst *left;
  int data;
  struct bst *right;
} bst;
// creating a function to make a new node
bst* newNode(int data)
{
    bst* temp = new bst;
 
    temp->data = data;//intializing structre data with data value
 
    temp->left = NULL;//intializing left pointer with null
    temp->right = NULL;//intializing left pointer with null
 
    return temp;//returning the new bst node created
}
 
//fucntion to insert a bst 
bst* insert_bst(bst* root,int x)
{
  if(root==NULL)//check if root is null then it is the first node created so no condition to be checked
  {
    root= newNode(x);
    return root;
  }
  else if(root->data>x)//check if the root data is greater than given value then insert new node at left pointer
  {
    root->left=insert_bst(root->left,x);
  }
  else //check if the root data is not greater than given value then insert new node at right pointer
  root->right=insert_bst(root->right,x);
  return root;

}
//printing the bst using recursion
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