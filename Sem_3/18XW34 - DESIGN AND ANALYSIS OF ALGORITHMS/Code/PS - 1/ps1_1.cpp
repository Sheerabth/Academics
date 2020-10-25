#include <iostream>

#define COUNT 10
using namespace std;

class Node
{
    int val;
    Node* right;
    Node* left;
public:
    Node(int);
    friend class Tree;
};

Node :: Node(int val)
{
    right = NULL;
    left = NULL;
    this -> val = val;
}

class Tree
{
public:
    Node *root;
    Tree();
    void insert(Node*&, int);
    void deleteVal(Node*&, int);
    int deleteMinNode(Node*&);
    void deleteMinValue(Node*&);
    int returnMinValue(Node*&);
    int returnMaxValue(Node*&);
    Node*& returnLeftNode(Node*&, int);
    Node*& returnRightNode(Node*&, int);
    void inorder(Node*&);
    void postorder(Node*&);
    void preorder(Node*&);
    void print2DUtil(Node*, int);
    bool findElement(Node*&, int);
};

Tree :: Tree ()
{
    root = NULL;
}


void Tree :: print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->val <<"\n";

    // Process left child
    print2DUtil(root->left, space);
}

void Tree :: inorder(Node *&node)
{
    if(node != NULL)
    {
        inorder(node->left);
        cout << node->val << " " ;
        inorder(node->right);
    }
}

void Tree :: preorder(Node *&node)
{
    if(node != NULL)
    {
        cout << node->val << " " ;
        preorder(node->left);
        preorder(node->right);
    }
}

void Tree :: postorder(Node *&node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " " ;
    }
}

void Tree :: insert(Node *&node, int value)
{

    if(node == NULL)
    {
        node = new Node (value);
        return;
    }
    else if(node->val > value)
    {
        insert(node->left, value);
    }
    else
    {
        insert(node->right, value);
    }
}

int Tree :: deleteMinNode(Node *&node)
{
    if(node->left != NULL)
    {
        return deleteMinNode(node->left);
    }
    else
    {
        int temp = node->val;
        Node* temp_node = node;
        node = node->right;
        delete temp_node;
        return temp; 
    } 
}

void Tree :: deleteVal(Node *&node, int value)
{
    if(node == NULL)
        return;
    else
    {
        if(node->val < value)
            deleteVal(node->right, value);
        else if(node->val > value)
            deleteVal(node->left, value);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                Node* temp = node;
                node = NULL;
                delete temp;
            }
                
            else if(node->left == NULL && node->right != NULL)
            {
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if(node->left != NULL && node->right == NULL)
            {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                int minimum = deleteMinNode(node->right);
                node->val = minimum;
            }
        }
    }
    
}

int Tree :: returnMinValue(Node *&node)
{
    if(node->left == NULL)
        return node->val;
    else
    {
        returnMinValue(node->left);
    }
    
}

int Tree :: returnMaxValue(Node *&node)
{
    if(node->right == NULL)
        return node->val;
    else
    {
        returnMaxValue(node->right);
    }
    
}


void Tree :: deleteMinValue(Node *&node)
{
    int val = returnMinValue(node);
    deleteVal(root, val);
}

bool Tree :: findElement(Node *&node, int value)
{
    if(node->val == value)
        return true;
    if(node->left == NULL && node->right == NULL)
        return false;    
    if(node->val > value)
          findElement(node->left, value);
    if(node->val < value)
        findElement(node->right, value);  
}

Node*& Tree :: returnLeftNode(Node *&node, int value)
{
    if(findElement(root, value))
    {
        if(node->val == value)
            return node->left; 
        if(node->val > value)
            returnLeftNode(node->left, value);
        if(node->val < value)
            returnLeftNode(node->right, value); 
    }
}

Node*& Tree :: returnRightNode(Node *&node, int value)
{
    if(findElement(root, value))
    {
        if(node->val == value)
            return node->right; 
        if(node->val > value)
            returnRightNode(node->left, value);
        if(node->val < value)
            returnRightNode(node->right, value); 
    }
}

int main()
{
    Tree tree;
    
    int val;
    cout << "Please enter the values ending with -1: " << endl;
    while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        tree.insert(tree.root, val);
        tree.print2DUtil(tree.root, 0);
        cout << endl << "----------------------------------------------" << endl;
    }
//1.a DELETE THE NODE WITH MINIMUM VALUE N THE TREE
    /*cout << "After deletion of minimum element the tree is" << endl;
    tree.deleteMinValue(tree.root);
    tree.print2DUtil(tree.root, 0);*/

//1.B FINDING A ELEMENT
    /*if(tree.findElement(tree.root, 1232))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }*/

//1.C FINDING MAXIMUM ELEMENT
       //cout << "The Maximum value is " << tree.returnMaxValue(tree.root) << endl;

//1.F PRINT THE TREE IN INORDER POST ORDER AND PRE ORDER 
    /*tree.inorder(tree.root);
    cout << endl;
    tree.postorder(tree.root);
    cout << endl;
    tree.preorder(tree.root);
    cout << endl;*/

 


    
    //cout << "Please enter the values ending with -1: " << endl;

   /*while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        tree.deleteVal(tree.root, val);
        tree.print2DUtil(tree.root, 0);
        cout << "------------------------------------------------" << endl;
    }*/
    return 0;
}