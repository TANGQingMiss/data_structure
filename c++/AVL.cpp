#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class AVLTreeNode{
    public:
        T key;                
        int height;         
        AVLTreeNode *left;
        AVLTreeNode *right;

        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
            key(value), height(0),left(l),right(r) {}
};

template <class T>
class AVLTree {
    private:
        AVLTreeNode<T> *mRoot;   

    public:
        AVLTree();
        ~AVLTree();
        //get height
        int height();
        int max(int a, int b);

        // pre order
        void preOrder();

        AVLTreeNode<T>* search(T key);
        T minimum();
        T maximum();

        void insert(T key);
        void remove(T key);

        void destroy();
    private:
        int height(AVLTreeNode<T>* tree) ;

        // pre order traverse
        void preOrder(AVLTreeNode<T>* tree) const;

        // search node with value key
        AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;

        AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
        AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

        AVLTreeNode<T>* rotateLL(AVLTreeNode<T>* k2);
        AVLTreeNode<T>* rotateRR(AVLTreeNode<T>* k1);
        AVLTreeNode<T>* rotateLR(AVLTreeNode<T>* k3);
        AVLTreeNode<T>* rotateRL(AVLTreeNode<T>* k1);

        AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);
        AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

        void destroy(AVLTreeNode<T>* &tree);
};

//constructor
template <class T>
AVLTree<T>::AVLTree():mRoot(NULL)
{
}
//deconstructor
template <class T>
AVLTree<T>::~AVLTree() 
{
    destroy(mRoot);
}

template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* tree) 
{
    if (tree != NULL)
        return tree->height;

    return 0;
}

template <class T>
int AVLTree<T>::height() 
{
    return height(mRoot);
}

template <class T>
int AVLTree<T>::max(int a, int b) 
{
    return a>b ? a : b;
}

template <class T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::preOrder() 
{
    preOrder(mRoot);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::search(T key) 
{
    return search(mRoot, key);
}

//find minimum node
template <class T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T AVLTree<T>::minimum()
{
    AVLTreeNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}
 
//find maximum node
template <class T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T AVLTree<T>::maximum()
{
    AVLTreeNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}


template <class T>
AVLTreeNode<T>* AVLTree<T>::rotateLL(AVLTreeNode<T>* k2)
{
    AVLTreeNode<T>* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height(k2->left), height(k2->right)) + 1;
    k1->height = max( height(k1->left), k2->height) + 1;

    return k1;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::rotateRR(AVLTreeNode<T>* k1)
{
    AVLTreeNode<T>* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height(k1->left), height(k1->right)) + 1;
    k2->height = max( height(k2->right), k1->height) + 1;

    return k2;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::rotateLR(AVLTreeNode<T>* k3)
{
    k3->left = rotateRR(k3->left);

    return rotateLL(k3);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::rotateRL(AVLTreeNode<T>* k1)
{
    k1->right = rotateLL(k1->right);

    return rotateRR(k1);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
    if (tree == NULL) 
    {
        tree = new AVLTreeNode<T>(key, NULL, NULL);
        if (tree==NULL)
        {
            cout << "ERROR: create avltree node failed!" << endl;
            return NULL;
        }
    }
    else if (key < tree->key)
    {
        tree->left = insert(tree->left, key);
        if (height(tree->left) - height(tree->right) == 2)
        {
            if (key < tree->left->key)
                tree = rotateLL(tree);
            else
                tree = rotateLR(tree);
        }
    }
    else if (key > tree->key)
    {
        tree->right = insert(tree->right, key);
        if (height(tree->right) - height(tree->left) == 2)
        {
            if (key > tree->right->key)
                tree = rotateRR(tree);
            else
                tree = rotateRL(tree);
        }
    }
    else
    {
        cout << "ERROR: failed to add the same value" << endl;
    }

    tree->height = max( height(tree->left), height(tree->right)) + 1;

    return tree;
}

template <class T>
void AVLTree<T>::insert(T key)
{
    insert(mRoot, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z)
{
    if (tree==NULL || z==NULL)
        return NULL;

    if (z->key < tree->key)
    {
        tree->left = remove(tree->left, z);
        if (height(tree->right) - height(tree->left) == 2)
        {
            AVLTreeNode<T> *r =  tree->right;
            if (height(r->left) > height(r->right))
                tree = rotateRL(tree);
            else
                tree = rotateRR(tree);
        }
    }
    else if (z->key > tree->key)
    {
        tree->right = remove(tree->right, z);
        if (height(tree->left) - height(tree->right) == 2)
        {
            AVLTreeNode<T> *l =  tree->left;
            if (height(l->right) > height(l->left))
                tree = rotateLR(tree);
            else
                tree = rotateLL(tree);
        }
    }
    else
    {
        if ((tree->left!=NULL) && (tree->right!=NULL))
        {
            if (height(tree->left) > height(tree->right))
            {
                AVLTreeNode<T>* max = maximum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);
            }
            else
            {
                AVLTreeNode<T>* min = maximum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min);
            }
        }
        else
        {
            AVLTreeNode<T>* tmp = tree;
            tree = (tree->left!=NULL) ? tree->left : tree->right;
            delete tmp;
        }
    }

    return tree;
}

template <class T>
void AVLTree<T>::remove(T key)
{
    AVLTreeNode<T>* z; 

    if ((z = search(mRoot, key)) != NULL)
        mRoot = remove(mRoot, z);
}

template <class T>
void AVLTree<T>::destroy(AVLTreeNode<T>* &tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        destroy(tree->left);
    if (tree->right != NULL)
        destroy(tree->right);

    delete tree;
}

template <class T>
void AVLTree<T>::destroy()
{
    destroy(mRoot);
}

int main()
{
    AVLTree<int>* tree=new AVLTree<int>();
    int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
    	cout << "add number: "<<arr[i]<<endl;
    	tree->insert(arr[i]);
    	cout<< "pre order traverse of current tree: "<<endl;
    	tree->preOrder();
    	cout<<endl;
    }

    int arr1[] = {5,7,9};
    for (size_t i = 0; i < sizeof(arr1) / sizeof(arr1[0]); ++i){
    	cout << "delete number: "<<arr1[i]<<endl;
    	tree->remove(arr1[i]);
    	cout<< "pre order traverse of current tree: "<<endl;
    	tree->preOrder();
    	cout<<endl;
    }
    tree->destroy();

    return 0;
}
