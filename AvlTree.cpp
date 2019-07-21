
#include "AvlTree.h"
#include <iostream>
#include <fstream>
using namespace std;

int AvlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/*
 * Height Difference 
 */
int AvlTree::diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

/*
 * Right- Right Rotation
 */
avl_node *AvlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
avl_node *AvlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
avl_node *AvlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

/*
 * Right- Left Rotation
 */
avl_node *AvlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

/*
 * Balancing AVL Tree
 */
avl_node *AvlTree::balance(avl_node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

avl_node* AvlTree::findMin(avl_node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

avl_node* AvlTree::findElement(avl_node *root, int a) {

    if (root == NULL) {
        return NULL;
    } else if (a < root->data) {
        findElement(root->left, a);
    } else if (a > root->data) {
        findElement(root->right, a);
    } else {
        return root;
    }
}

/*
 * Insert Element into the tree
 */
avl_node *AvlTree::insert(avl_node *root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        sizeOfAvlTree++;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

void AvlTree::deleteElement(int x, avl_node* p)
{

    avl_node* d;
    if (p==NULL){
        return ;
        //"Element not found"
    }
    else if ( x < p->data)
        deleteElement(x,p->left);
    else if (x > p->data)
        deleteElement(x,p->right);
    else if ((p->left == NULL) && (p->right == NULL))
    {
        d=p;
        free(d);
        p=NULL;
        sizeOfAvlTree--;
       // Element deleted
    }
    else if (p->left == NULL)
    {
        d=p;
        free(d);
        p=p->right;
        sizeOfAvlTree--;
        // Element deleted
    }
    else if (p->right == NULL)
    {
        d=p;
        p=p->left;
        free(d);
        sizeOfAvlTree--;
        // "Element deleted
    }
    else
        p->data = deleteMin(p->right);
}


int AvlTree::deleteMin(avl_node* p)
{
    int c;
    if (p->left == NULL)
    {
        c=p->data;
        p=p->right;
        return c;
    }
    else
    {
        c=deleteMin(p->left);
        return c;
    }
}

/*
 * Display AVL Tree
 */
void AvlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}

/*
 * Postorder Traversal of AVL Tree
 */
void AvlTree::postOrder(avl_node *tree)
{
    if (tree == NULL)
        return;
    postOrder ( tree ->left );
    postOrder ( tree ->right );
    cout<<tree->data<<"  ";
}






