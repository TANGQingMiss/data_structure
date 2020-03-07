//this file is used to biuld a binary tree
//and realize inorder traverse by recursion and iteration
#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>
#include<stack>
using namespace std;

//define binary tree structure
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool createBiTree(BiTree &T){
	char ch;
	cout<<"input character in preorder"<<endl;
	cin>>ch;
	if(ch == '0') T = NULL;
	else{
		if(!(T = (BiTNode*) malloc (sizeof(BiTNode)))) return false;
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
	return true;
}

//inorder by recursion
void inOrderTraverse(BiTree T, vector<char>& s){
	if(T == NULL) return;
	inOrderTraverse(T->lchild,s);
	s.push_back(T->data);
	inOrderTraverse(T->rchild,s);
}


//iteration top-bottom-top
void longTraverseLeft(BiTree x, stack<BiTree> &stk){
	while(x){
		stk.push(x);
		x = x->lchild;
	}
}
void inOrderTraverse2(BiTree T, vector<char> &s){
	stack<BiTree> stk;
	while(true){
		longTraverseLeft(T,stk);
		if(stk.size() == 0) break;
		T = stk.top();
		stk.pop();
		s.push_back(T->data);
		T = T->rchild;
	}
}

int main(){
   	vector<char> s;
   	vector<char> s2;

   	BiTree T = NULL;
   	cout<<"input binary tree elements in preorder: "<<endl;
   	createBiTree(T);
   	cout<<"in order traverse by recursion is: "<<endl;
   	inOrderTraverse(T, s);
   	for(int i = 0; i < s.size(); i++){
   		cout<<s[i];
   	}
   	cout<<endl;

   	cout<<"in order traverse by iteration is: "<<endl;
   	inOrderTraverse2(T, s2);
   	for(int i = 0; i < s2.size(); i++){
   		cout<<s2[i];
   	}
   	cout<<endl;

    return 0;
}
