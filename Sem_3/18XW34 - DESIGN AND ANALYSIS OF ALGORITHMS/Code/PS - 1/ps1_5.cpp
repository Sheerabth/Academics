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
    void inorder(Node*&);
    void print2DUtil(Node*, int);
    int returnNumberOfNodes(Node*);
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

int Tree :: returnNumberOfNodes(Node* node)
{
    if(node != NULL)
    {
        int count = 1;
        count += (returnNumberOfNodes(node->left) + returnNumberOfNodes(node->right));
        return count;
    }
    
}

void Tree :: insert(Node *&node, int value)
{

    if(node == NULL)
    {
        node = new Node (value);
        return;
    }
    if(node->val > value)
    {
        insert(node->left, value);
    }
    if(node->val < value)
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



int main()
{
    Tree tree;
    
    int val;
    
    /*for (int i = 1; i < 11; i++)
    {
        tree.insert(tree.root, i);
    }

    for (int i = 1; i < 11; i++)
    {
        tree.insert(tree.root, i);
    }*/

    cout << "Please enter the value of X: ";
    int x;
    cin >> x;

   cout << "Please enter the values of the array ending with -1: " << endl;
    while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        tree.insert(tree.root, val);
    }

    int number = tree.returnNumberOfNodes(tree.root);

    if(number == x)
        cout << "This tree is Good :)" << endl;
    else if (number > x)
        cout << "This tree is AVERAGE :/" << endl;
    else
        cout << "This tree is BAD :(" << endl;
    
    

    /*tree.insert(tree.root, 2);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 3);*/

    cout << "The number of elements is " << tree.returnNumberOfNodes(tree.root);

    return 0;
}
