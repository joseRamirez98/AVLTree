/*****************************************************

Jose Ramirez
CISP 430 - MW 6:00 pm
AVL Tree
November 15, 2018

*****************************************************/

#include <iostream>
#include <fstream>

using namespace std;


struct BinaryTree {
    int item;
    int height;
    BinaryTree *left;
    BinaryTree *right;
};

BinaryTree* rebalance(BinaryTree*);
BinaryTree* insert(BinaryTree*, int);
BinaryTree* leftRotate(BinaryTree*);
BinaryTree* rightRotate(BinaryTree*);
BinaryTree* newNode(int);

void printLevelOrder(BinaryTree*);
void printGivenLevel(BinaryTree*, int, int, ofstream&);
int  max(BinaryTree*, BinaryTree*);
int  height(BinaryTree*);
int  getBalance(BinaryTree*);

int main()
{
    int input = 0;
    BinaryTree *root = nullptr;
    ifstream in("input.txt", ios::in);

    while(in >> input)
    {
        root = insert(root, input);
    }

    in.close();

    printLevelOrder(root);

    return 0;
}

BinaryTree* rebalance(BinaryTree *node){

    node->height = max( height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);


    if(balance < -1)
    {
        int childBalance = getBalance(node->right);

        if(childBalance > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        else
        {
            return leftRotate(node);
        }
    }

    if(balance > 1)
    {
        int childBalance = getBalance(node->left);

        if(childBalance < 0)
        {
            node->left =  leftRotate(node->left);
            return rightRotate(node);
        }
        else
        {
            return rightRotate(node);
        }

    }

    return node;
}

BinaryTree* insert(BinaryTree* node, int key)
{
    if (node == NULL)
        return( newNode(key) );

    if (key < node->item)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node = rebalance(node);
    return node;
}


BinaryTree* leftRotate(BinaryTree *x) {
   BinaryTree* y = x->right;
   BinaryTree* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

BinaryTree* rightRotate(BinaryTree *y)
{
    BinaryTree* x = y->left;
    BinaryTree* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

BinaryTree* newNode(int key)
{
    BinaryTree *node = new BinaryTree;
    node->item   = key;
    node->height = 1;
    node->left = node->right = nullptr;

    return node;
}

void printLevelOrder(BinaryTree* root)
{
    ofstream out("output.txt", ios::out);

    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i, i, out);
    }

    out.close();
}

void printGivenLevel(BinaryTree* root, int currLevel, int realLevel, ofstream& out)
{
    if (root == NULL)
        return;
    if (currLevel == 1)
        out  << "Item: "      << root->item
             << ", Height: "  << height(root)
             << ", Balance: " << getBalance(root)
             << ", Level :"   << realLevel << '\n';
    else if (currLevel > 1)
    {
        printGivenLevel(root->left, currLevel-1, realLevel, out);
        printGivenLevel(root->right, currLevel-1, realLevel, out);
    }
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int height(BinaryTree *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalance(BinaryTree *node)
{
    if(node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}
