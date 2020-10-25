#include <iostream>

#define T cout << " Test " << endl;
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
    Node* zig(Node*&);
    Node* zag(Node*&);
    void inorder(Node*&);
    void print2DUtil(Node*, int);
    void splay(Node*&, int);
};

Tree :: Tree ()
{
    root = NULL;
}

Node* Tree :: zig (Node *&node)
{
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

Node* Tree :: zag (Node *&node)
{
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
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
    while(this->root->val != value)
    {
        splay(root, value);
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

void Tree :: splay(Node *&node, int value)
{
    if(node != NULL)
    {
        //zag-zag
        if(node->right != NULL && node->right->right != NULL && node->right->right->val == value)
        {
            node = zag(node);
            node = zag(node);
            return;
        }
        //zig-zig
        if(node->left != NULL && node->left->left != NULL && node->left->left->val == value)
        {
            
            node = zig(node);
            node = zig(node);
            return;
        }
        //zag
        if(node->right != NULL && node->right->val == value)
        {
            node = zag(node);
            return;
        }
        //zig
        if(node->left != NULL && node->left->val == value)
        {
            node = zig(node);
            return;
        }
        if(node->val > value)
            splay(node->left, value);
        if(node->val > value)
            splay(node->right, value);
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
        cout << "The tree is now " << endl;
        tree.print2DUtil(tree.root, 0);
        cout << "------------------------------------------------" << endl;
        
    }

    /*tree.insert(tree.root, 14);
    tree.insert(tree.root, 17);
    tree.insert(tree.root, 11);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 53);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 12);
    tree.insert(tree.root, 13);
    tree.insert(tree.root, 8);*/

    cout << "\nBefore deletion the tree is " << endl;
    tree.print2DUtil(tree.root, 0);
    
    cout << "Please enter the values ending with -1: " << endl;

    //tree.print2DUtil(tree.root, 0);

   while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        tree.deleteVal(tree.root, val);
        tree.print2DUtil(tree.root, 0);
        cout << "------------------------------------------------" << endl;
    }
    /*tree.deleteVal(tree.root, 53);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 11);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 12);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 7);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 13);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 14);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 4);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 8);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;

    tree.deleteVal(tree.root, 17);
    tree.print2DUtil(tree.root, 0);
    cout << "------------------------------------------------" << endl;*/

    return 0;
}
