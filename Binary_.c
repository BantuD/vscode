#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *tree;
void create_tree(struct node *tree)
{
    tree=NULL;
}
struct node *insert_element(struct node *tree,int val)
{
    struct node *ptr,*parentptr,*nodeptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    if(tree==NULL)
    {
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data)
            nodeptr=nodeptr->left;
            else
            {
                nodeptr=nodeptr->right;
            }
            
        }
        if(val<parentptr->data)
        parentptr->left=ptr;
        else
        {
            parentptr->right=ptr;
        }
        
    }
    return tree;
}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
struct node *delete_element(struct node *tree,int val)
{
    struct node *ptr,*suc,*psuc,*parent,*cur;
    if(tree->left==NULL)
    {
        printf("\nTree is empty");
        return tree;
    }
    parent=tree;
    cur=(val<tree->data)?tree->left:tree->right;
    while(cur!=NULL&& cur->data!=val)
    {
        parent=cur;
        cur=(val<cur->data)?cur->left:cur->right;
    }
    if(cur==NULL)
    {
        printf("\nThere is no element found like that");
    }
    else if(cur->left==NULL)
    {
        ptr=cur->right;
    }
    else
    {
        psuc=cur;
        suc=cur->right;
        while(suc->left!=NULL)
        {
            psuc=suc;
            suc=suc->left;

        }
        if(psuc==cur)
        {
            suc->left=cur->left;
        }
        else
        {
            suc->left=cur->left;
            psuc->left=suc->right;
            suc->right=psuc;
        }
       ptr=suc; 
    }
    if(parent->left==cur)
    parent->left=ptr;
    else
    {
        parent->right=ptr;
    }
    free(cur);
 return tree;
}
///Inorder Traversal///
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%d\t",tree->data);
        inorder(tree->right);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t",tree->data);
    }
}
///Find the largest Element///
struct node *findlargest(struct node *tree)
{
    if(tree==NULL || tree->right==NULL)
    {
        return tree;
    }
    else
    {
     return findlargest(tree->left);  
    }
}
struct node *findsmallest(struct node *tree)
{
    if(tree==NULL || tree->left==NULL)
    {
        return tree;
    }
    else
    {
       return findsmallest(tree->left);
    }
    
}
int totalnode(struct node *tree)
{
    if(tree==NULL)
    {
        return 0;
    }
    else
    {
        return ((totalnode(tree->left))+(totalnode(tree->right))+1);
    }
    
}
int TotalExternalNodes(struct node *tree)
{   
    if(tree==NULL)
    {
        return 0;
    }
    else if(tree->left==NULL&&tree->right==NULL)
    {
        return 1;
    }
    else
    {
        return (TotalExternalNodes(tree->left)+TotalExternalNodes(tree->right));
    }
}
int TotalInternalNodes(struct node *tree)
{
 if(tree==NULL ||(tree->left==NULL&&tree->right==NULL))
 {
     return 0;
 }
 else
 {
     return (TotalInternalNodes(tree->left)+TotalInternalNodes(tree->right)+1);
 }
 
}
int height(struct node *tree)
{
    int leftheight,rightheight;
    if(tree==NULL)
    {
        return 0;
    }
    else
    {
        leftheight=height(tree->left);
        rightheight=height(tree->right);
        if(leftheight>rightheight)
        {
            return (leftheight+1);
        }
        else
        {
            return (rightheight+1);
        }
        
    }
    
}
struct node *mirror(struct node *node)
{
    struct node *ptr,*node;
    if(node!=NULL)
    {
        mirror(node->left);
        mirror(node->right);
        ptr=node->left;
        node->left=node->right;
        node->right=ptr;
    }
}
struct node *DeleteTree(struct node *tree)
{
    if(tree!=NULL)
    {
        DeleteTree(tree->left);
        DeleteTree(tree->right);
        free(tree);
    }
}
int main()
{
    create_tree(tree);
    struct node *ptr;
    int option,val;
    do
    {
        printf("\n******Main Menu*******\n");
        printf("1.Insert an Element\n");
        printf("2.Preorder traversal");
        printf("\n3.Delete the element");
        printf("\n4.Inorder Traversal");
        printf("\n5.Postorder Traversal");
        printf("\n6.Find Largest Node");
        printf("\n7.Find Smallest");
        printf("\n8.Total Number of nodes");
        printf("\n9.Total number of external nodes");
        printf("\n10.Total number of Internal nodes");
        printf("\n11.Height of the tree");
        printf("\n12.Mirror");
        printf("\n13.Delete Tree");
        printf("\nEnter>>");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
        printf("\nEnter Value:>");
        scanf("%d",&val);
        tree=insert_element(tree,val);
        break;
        case 2:
        preorder(tree);
        break;
        case 3:
          printf("\nEnter the value to delete:>");
          scanf("%d",&val);
          tree=delete_element(tree,val);
          break;
        case 4:
          inorder(tree);
          break;
        case 5:
          postorder(tree);
          break;
        case 6:
          ptr=findlargest(tree);
          printf("\nThe largest element is:%d",ptr->data);
          break;
        case 7:
          ptr=findsmallest(tree);
          printf("\nThe Largest element is:%d",ptr->data);
          break;
        case 8:
          val=totalnode(tree);
          printf("\nTotal number of nodes:>%d",val);
          break;
        case 9:
          val=TotalExternalNodes(tree);
          printf("\nTotal Number of external nodes:>%d",val);
          break;
        case 10:
          val=TotalInternalNodes(tree);
          printf("\nTotal number of internal nodes:>%d",val);
          break;
        case 11:
        val=height(tree);
        printf("\nHeight of the tree is:%d",val);
        break;
        case 12:
        tree=mirror(tree);
        break;
        case 13:
        tree=DeleteTree(tree);
        break;
        default:
            break;
        }
        
    } while (option!=5);
    
    return 0;
}
