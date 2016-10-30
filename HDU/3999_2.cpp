#include <iostream>
#include <cstdio>
using namespace std;

typedef struct node{
    int num;
    struct node *left;
    struct node *right;
}Tree;

Tree *tree;

void Print(node *root)
{
    if(root!=NULL)
    {  
        cout<<" "<<root->num; 
        Print(root->left);
        Print(root->right);
    }
}

node *creat(node *root,node *n)
{
    if(root == NULL)
    {
        root = n;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else 
    {
        if(n->num < root->num)
            root->left = creat(root->left,n);
        else 
            root->right = creat(root->right,n);
        return root;
    }
}

void creat2(node *n)
{
    node *now = tree;
    n->left = NULL;
    n->right = NULL;
    while(1)
    {
    	if(n->num < now->num)
    	{
    		if(now->left == NULL)
    		{
    			now->left = n;
    			break;
			}
			else now = now->left;
			
		}
        else
        {
        	if(now->right == NULL)
    		{
    			now->right = n;
    			break;
			}
			else now = now->right;
		}
	}
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
        	node *n = new node;
            scanf("%d",&n->num);
            //tree = creat(tree,n);
            creat2(n);
        }
        cout<<tree->num;
        Print(tree->left);
        Print(tree->right);
        cout<<endl;
    }
    return 0;
}
