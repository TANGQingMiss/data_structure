/*
*realize splay function based on AVL rotation
*/
#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class SplayTreeNode{
    public:
        T key;                        
        SplayTreeNode *left;
        SplayTreeNode *right;

        SplayTreeNode():left(NULL),right(NULL){}

        SplayTreeNode(T value, SplayTreeNode *l, SplayTreeNode *r):
            key(value),left(l),right(r) {}
};

template <class T>
class SplayTree {
    private:
        SplayTreeNode<T> *mRoot;   

    public:
        SplayTree();
        ~SplayTree();

        // pre order
        void preOrder();

        SplayTreeNode<T>* search(T key);

        void splay(T key);

        void insert(T key);
        void remove(T key);

        void destroy();
    private:

        // pre order traverse
        void preOrder(SplayTreeNode<T>* tree) const;

        // search node with value key
        SplayTreeNode<T>* search(SplayTreeNode<T>* x, T key) const;
        //splay tree
        SplayTreeNode<T>* splay(SplayTreeNode<T>* tree, T key);

        SplayTreeNode<T>* insert(SplayTreeNode<T>* &tree, SplayTreeNode<T>* z);
        SplayTreeNode<T>* remove(SplayTreeNode<T>* &tree, T key);

        void destroy(SplayTreeNode<T>* &tree);
};

template <class T>
SplayTreeNode<T>* SplayTree<T>::search(SplayTreeNode<T>* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::search(T key) 
{
    return search(mRoot, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::splay(SplayTreeNode<T>* tree, T key){
    SplayTreeNode<T> N, *l, *r, *c;
    if(tree == NULL) return tree;
    N.left = N.right = NULL;
    l = r = &N;
    for(;;){
        if(key < tree->key){
            if(tree->left == NULL){
                break;
            }
            if(key < tree->left->key){
                c = tree->left;
                tree->left = c->right;
                c->right = tree;
                tree = c;
                if(tree->left == NULL) break;
            }
            r->left = tree;
            r = tree;
            tree = tree->left;
        }else if(key > tree->key){
            if(tree->right == NULL) break;
            if(key > tree->right->key){
                c = tree->right;
                tree->right = c->left;
                c->left = tree;
                tree = c;
                if(tree->right == NULL) break;
            }
            l->right = tree;
            l = tree;
            tree = tree->right;
        }else{
            break;
        }
    }
    l->right = tree->left;
    r->left = tree->right;
    tree->left = N.right;
    tree->right = N.left;
    return tree;
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::insert(SplayTreeNode<T>* &tree, SplayTreeNode<T>* z)
{
    SplayTreeNode<T> *y = NULL;
    SplayTreeNode<T> *x = tree;

    // find place to put z
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else
        {
            cout << "not allowed the same value(" << z->key << ")!" << endl;
            delete z;
            return tree;
        }
    }

    if (y==NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    return tree;
}

template <class T>
void SplayTree<T>::insert(T key)
{
    SplayTreeNode<T> *z=NULL;

    if ((z=new SplayTreeNode<T>(key,NULL,NULL)) == NULL)
        return ;

    mRoot = insert(mRoot, z);
    mRoot = splay(mRoot, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::remove(SplayTreeNode<T>* &tree, T key)
{
    SplayTreeNode<T> *x;

    if (tree == NULL) 
        return NULL;

    if (search(tree, key) == NULL)
        return tree;

    tree = splay(tree, key);

    if (tree->left != NULL)
    {
        x = splay(tree->left, key);
        x->right = tree->right;
    }
    else
        x = tree->right;

    delete tree;

    return x;

}

template <class T>
void SplayTree<T>::remove(T key)
{
    mRoot = remove(mRoot, key);
}

//constructor
template <class T>
SplayTree<T>::SplayTree():mRoot(NULL)
{
}
//deconstructor
template <class T>
SplayTree<T>::~SplayTree() 
{
    destroy(mRoot);
}

template <class T>
void SplayTree<T>::preOrder(SplayTreeNode<T>* tree) const
{
    if(tree != NULL)
    {   
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void SplayTree<T>::preOrder() 
{
    preOrder(mRoot);
}


template <class T>
void SplayTree<T>::destroy(SplayTreeNode<T>* &tree)
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
void SplayTree<T>::destroy()
{
    destroy(mRoot);
}

int main()
{
    SplayTree<int>* tree=new SplayTree<int>();
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
