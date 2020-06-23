#include <iostream>

using namespace std;

typedef int object;
class tree_element
{
private:
    /* data */
public:
    object val; // Wert des Knotens
    tree_element *left; // Linker Nachfolger
    tree_element *right; // Rechter Nachfolger

    tree_element(/* args */);
    ~tree_element();
};

tree_element::tree_element(/* args */)
{
}

tree_element::~tree_element()
{
}

class searchtree
{
private:
    tree_element *root; // Wurzel des Baumes
    void Insert(tree_element *currRoot, tree_element *elem);
    void DeleteTree(tree_element *root);
    void Print(tree_element *root);
public:
    searchtree(/* args */);
    ~searchtree();

    void Insert(object o); // Wert einfügen
    bool Contains(object o); // Wert erhalten

    void DeleteValueIterativ(object o); // Wert löschen iterativ
    void DeleteValueRecursiv(object o); // Wert löschen recursiv

    void DeleteValueRecursivHelper(object o, tree_element* curElement); // rekursiv helper
    tree_element* HelperSearch(object o, tree_element* curElement, bool* bToDeleteNodeIsLeft); // helper
    tree_element* HelperSmallestLeft(tree_element* curElement); // helper

    void Print(); // Baum ausgeben
};

searchtree::searchtree(/* args */){ root = NULL; }

searchtree::~searchtree()
{
    DeleteTree(root);
    root = NULL;
}

void searchtree::DeleteTree(tree_element *root)
{
    if (root != NULL)
    {
        if (root->left != NULL) DeleteTree(root->left);
        if (root->right != NULL) DeleteTree(root->right);
        delete root;
    }
}

bool searchtree::Contains(object o)
{
    tree_element *curr = root;
    while (curr != NULL)
    {
        if (curr->val == o) return true;
        else
        {
            if (o <= curr->val) curr = curr->left;
            else curr = curr->right;            
        }
    }
    return false;
}

void searchtree::Insert(object o)
{
    tree_element *elem = new tree_element;
    elem->val=o;
    elem->left = NULL;
    elem->right = NULL;
    if (root == NULL) root = elem;
    else Insert(root, elem);
}

void searchtree::Insert(tree_element *currRoot, tree_element *elem)
{
    if (elem->val <= currRoot->val)
    {
        if (currRoot->left == NULL) currRoot->left = elem;
        else Insert(currRoot->left, elem);        
    }
    else
    {
        if(currRoot->right == NULL) currRoot->right = elem;
        else Insert(currRoot->right, elem);
    }
}

void searchtree::Print(tree_element *root)
{
    if (root != NULL)
    {
        cout << "(";
        Print(root->left);
        cout << "," << root->val << ",";
        Print(root->right);
        cout << ")";
    }
    else cout << "n";
}

void searchtree::Print()
{
    Print(root); cout << endl;
}

tree_element* searchtree::HelperSearch(object o, tree_element* curElement, bool* bToDeleteNodeIsLeft) 
{
    if (o == curElement->val) return curElement;
    else if (o < curElement->val) 
    {
        *bToDeleteNodeIsLeft = true;
        HelperSearch(o, curElement->left, bToDeleteNodeIsLeft);
    }
    else 
    {
        *bToDeleteNodeIsLeft = false;
        HelperSearch(o, curElement->right, bToDeleteNodeIsLeft);
    }
}

tree_element* searchtree::HelperSmallestLeft(tree_element* curElement) 
{
    if (curElement->left == NULL) return curElement;
    else HelperSmallestLeft(curElement->left);
}

void searchtree::DeleteValueIterativ(object o) 
{
    if (Contains(o))
    {
        tree_element* curElement = root;
        tree_element* prevElement = curElement;
        tree_element* deleteElement = curElement;
        bool bToDeleteNodeIsLeft = false;
        bool bIsRootToDelete = false;
        // suchen
        while (o != curElement->val) 
        {
            prevElement = curElement;
            if (o < curElement->val) 
            {
                bToDeleteNodeIsLeft = true;
                curElement = curElement->left;
            }
            else 
            {
                bToDeleteNodeIsLeft = false;
                curElement = curElement->right;
            }
        }
        deleteElement = curElement;
        bIsRootToDelete = deleteElement == root;

        // entnehmen
        // kein Nachfolger
        if (curElement->left == NULL && curElement->right == NULL) 
        {
            if (bToDeleteNodeIsLeft) prevElement->left = NULL;
            else prevElement->right = NULL;
            if (bIsRootToDelete) root = NULL;
        }
        // ein Nachfolger, links oder rechts
        else if (curElement->left == NULL || curElement->right == NULL)
        {
            if (bToDeleteNodeIsLeft) 
            {
                prevElement->left = curElement->left == NULL ? curElement->right : curElement->left;
                if (bIsRootToDelete)
                root = prevElement->left;
            }
            else 
            {
                prevElement->right = curElement->left == NULL ? curElement->right : curElement->left;
                if (bIsRootToDelete)
                root = prevElement->right;
            }
        }
        // zwei Nachfolger
        else 
        {
            curElement = curElement->right;
            while (curElement->left != NULL) 
            {
                curElement = curElement->left;
            }
            if (bToDeleteNodeIsLeft) 
            {
                prevElement->left = curElement->left;
                if (bIsRootToDelete)
                root = prevElement->left;
            }
            else 
            {
                prevElement->right = curElement;
                if (bIsRootToDelete)
                root = prevElement->right;
            }
            curElement->left = deleteElement->left;
        }
        // endgültig löschen
        delete(deleteElement);
    }
}

void searchtree::DeleteValueRecursiv(object o) 
{
    if (Contains(o))
    DeleteValueRecursivHelper(o, root);
}

void searchtree::DeleteValueRecursivHelper(object o, tree_element* curElement) 
{
    tree_element* prevElement = curElement;
    tree_element* deleteElement = curElement;
    bool bToDeleteNodeIsLeft = false;
    bool bIsRootToDelete = false;
    // suchen
    curElement = HelperSearch(o, curElement, &bToDeleteNodeIsLeft);
    deleteElement = curElement;
    bIsRootToDelete = deleteElement == root;

    // entnehmen
    // kein Nachfolger
    if (curElement->left == NULL && curElement->right == NULL) 
    {
        if (bToDeleteNodeIsLeft)
        prevElement->left = NULL;
        else
        prevElement->right = NULL;
        if (bIsRootToDelete)
        root = NULL;
    }
    // ein Nachfolger, links oder rechts
    else if (curElement->left == NULL || curElement->right == NULL) 
        {
        if (bToDeleteNodeIsLeft) 
            {
                prevElement->left = curElement->left == NULL ? curElement->right : curElement->left;
                if (bIsRootToDelete)
                root = prevElement->left;
            }
        else 
        {
            prevElement->right = curElement->left == NULL ? curElement->right : curElement->left;
            if (bIsRootToDelete)
            root = prevElement->right;
        }
        }
    // zwei Nachfolger
    else 
    {
        curElement = curElement->right;
        curElement = HelperSmallestLeft(curElement);
        if (bToDeleteNodeIsLeft)
        {
            prevElement->left = curElement->left;
            if (bIsRootToDelete)
            root = prevElement->left;
        }
        else 
        {
            prevElement->right = curElement;
            if (bIsRootToDelete)
            root = prevElement->right;
        }
        curElement->left = deleteElement->left;
    }
    // endgültig löschen
    delete(deleteElement);
}