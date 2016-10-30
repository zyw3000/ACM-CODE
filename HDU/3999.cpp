#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    int num;
    struct node *left;
    struct node *right;
}*tree;

node *build(node *root,int num)
{
    if(root==NULL)
    {
        root=new node;
        root->left=NULL;
        root->right=NULL;
        root->num=num;
        return root;
    }
    else 
    {
        int t=root->num-num;;
        if(t>0)
            root->left = build(root->left,num);
        else 
            root->right = build(root->right,num);
        return root;
    }
}

void Print(node *root)
{
    if(root!=NULL)
    {  
        cout<<" "<<root->num; 
        Print(root->left);
        Print(root->right);
    }
}

int main()
{
    int n,num;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&num);
            tree = build(tree,num);
        }
        cout<<tree->num;
        Print(tree->left);
        Print(tree->right);
        cout<<endl;
    }
    return 0;
}
