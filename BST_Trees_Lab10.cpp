#include <iostream>        
using namespace std;       

// NODE STRUCTURE 
struct Node
{
    int data;              // TO STORE DATA IN THE NODE
    Node* left;            // POINTER OF LEFT CHILD
    Node* right;           // POINTER OF RIGHT CHILD
};

// CREATE NEW NODE 
Node* createNode(int value)
{
    Node* newNode = new Node();   
    newNode->data = value;        // TO STORE VALUE IN NODE DATA
    newNode->left = NULL;         // FOR LEFT CHILD
    newNode->right = NULL;        // FOR RIGHT CHILD
    return newNode;               
}

// INSERT IN BST 
Node* insertBST(Node* root, int value)
{
    // IF TREE IS EMPTY
    if (root == NULL)
    {
        return createNode(value);   // MAKING ROOT FROM NEWNODE
    }

    // IF VALUE LESS THAN ROOT
    if (value < root->data)
    {
        // INSERT IN LEFT SUBTREE
        root->left = insertBST(root->left, value);
    }

    // IF VALUE GREATER THAN ROOT
    else if (value > root->data)
    {
        // INSERT IN RIGHT SUBTREE
        root->right = insertBST(root->right, value);
    }

    // IF THE VALUE IS DUPLICATE
    else
    {
        cout << "DUPLICATE VALUE IS NOT ALLOWED!\n";  
    }

    return root;    
}

// INORDER TRAVERSAL 
void inorder(Node* root)
{
    if (root != NULL)            // IF TREE IS NOT EMPTY
    {
        inorder(root->left);     // VISIT THE LEFT SUBTREE
        cout << root->data << " "; // PRINT THE DATA OF ROOT
        inorder(root->right);    // VISIT THE RIGHT SUBTREE
    }
}

//  PREORDER TRAVERSAL 
void preorder(Node* root)
{
    if (root != NULL)            // IF TREE IS NOT EMPTY
    {
        cout << root->data << " "; // PRINT ROOT
        preorder(root->left);    // VISIT THE LEFT SUBTREE
        preorder(root->right);   // VISIT RIGHT SUBTREE
    }
}

// POSTORDER TRAVERSAL 
void postorder(Node* root)
{
    if (root != NULL)            // IF TREE IS NOT EMPTY
    {
        postorder(root->left);   // VISIT LEFT SUBTREE
        postorder(root->right);  // VISIT RIGHT SUBTREE
        cout << root->data << " "; // PRINT ROOT IN END
    }
}

// MAIN FUNCTION 
int main()
{
    Node* root = NULL;           // TREE IS EMPTY
    int choice;                  
    int value;                   

    do
    {
        // Menu display
        cout << "\n====== TREE MENU ======\n";
        cout << "1. INSERT NODE\n";
        cout << "2. INORDER TRAVERSAL\n";
        cout << "3. PREORDER TRAVERSAL\n";
        cout << "4. POSTORDER TRAVERSAL\n";
        cout << "5. EXIT\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;           

        switch (choice)
        {
        case 1:
            cout << "ENTER VALUE TO INSERT: ";
            cin >> value;        
            root = insertBST(root, value); // INSERT IN BST
            break;

        case 2:
            if (root == NULL)    // IF TREE IS EMPTY
                cout << "TREE IS EMPTY!\n";
            else
            {
                cout << "INORDER TRAVERSAL: ";
                inorder(root);   
                cout << endl;
            }
            break;

        case 3:
            if (root == NULL)    
                cout << "TREE IS EMPTY!\n";
            else
            {
                cout << "PREORDER TRAVERSAL: ";
                preorder(root);  
                cout << endl;
            }
            break;

        case 4:
            if (root == NULL)    
                cout << "TREE IS EMPTY!\n";
            else
            {
                cout << "POSTORDER TRAVERSAL: ";
                postorder(root); 
                cout << endl;
            }
            break;

        case 5:
            cout << "EXITING PROGRAM.\n"; 
            break;

        default:
            cout << "INVALID CHOICE!TRY AGAIN.\n";
        }

    } while (choice != 5);        

    return 0;                     
}
