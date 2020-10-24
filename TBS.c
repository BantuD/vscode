#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int val;
    struct tree *left;
    struct tree *right;
    int thread;
};
struct tree *root=NULL;
struct tree *insert_node(struct tree *root,struct tree *ptr,struct tree *rt)
{
if(root==NULL)
{
    root=ptr;
    if(rt!=NULL)
    {
        root->right=rt;
        root->thread=1;
    }
}
    else if(ptr->val<root->val)
    {
        root->left=insert_node(root->left,ptr,root);
    }
    else if(root->thread==1)
    {
        root->right=insert_node(NULL,ptr,rt);
    }
    else
    {
        root->right=insert_node(root->right,ptr,rt);
    }
    return root;
}
struct tree *create_tree()
{
    struct tree *ptr;
    int val;
    printf("\nEnter Value to insert:>");
    scanf("%d",&val);
    while(val!=-1)
    {
        ptr=(struct tree*)malloc(sizeof(struct tree));
        ptr->val=val;
        ptr->left=NULL;
        ptr->right=NULL;
        ptr->thread=0;
        root=insert_node(root,ptr,NULL);
        printf("\nEnter another next value:>");
        fflush(stdin);
        scanf("%d",&val);
    }
return root;
}
struct tree *inoder(struct tree *root)
{
    struct tree *ptr,*prev;
    ptr=root;
    do
    {
        while(ptr!=NULL)
        {
            prev=ptr;
            ptr=ptr->left;
        }
        if(prev!=NULL)
        {
            printf("%d\t",prev->val);
            ptr=prev->right;
            while(prev!=NULL && prev->thread)
            {
                printf("%d\t",ptr->val);
                prev=ptr;
                ptr=ptr->right;
            }
        }
    }while (ptr!=NULL);
    
}
int main()
{
    create_tree();
    printf("\n\n");
    inoder(root);
return 0;
}