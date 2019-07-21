
#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
};

class AvlTree
{
public:
    avl_node* root;
    int height(avl_node *);
    int diff(avl_node *);
    avl_node* rr_rotation(avl_node *);
    avl_node* ll_rotation(avl_node *);
    avl_node* lr_rotation(avl_node *);
    avl_node* rl_rotation(avl_node *);
    avl_node* balance(avl_node *);
    avl_node* insert(avl_node *, int );
    avl_node* findMin(avl_node *);
    avl_node* findElement(avl_node *, int);
    void deleteElement( int, avl_node *);
    int deleteMin(avl_node* r);
    void display(avl_node *, int);
    void postOrder(avl_node *);
    int getSizeOfAvlTree(){ return sizeOfAvlTree;};
    AvlTree()
    {
        sizeOfAvlTree = 0;
        root = NULL;
    }

private:
    int sizeOfAvlTree;
};

#endif //AVLTREE_AVLTREE_H
