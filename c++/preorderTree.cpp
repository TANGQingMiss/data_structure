//this file is used to biuld a binary tree
//and realize preorder traverse by recursion and iteration
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

//preorder by recursion
void preOrderTraverse(BiTree T, vector<char>& s){
	if(T == NULL) return;
	s.push_back(T->data);
	preOrderTraverse(T->lchild,s);
	preOrderTraverse(T->rchild,s);
}

//preOrder by iteration,using stack
void preOrderTraverse2(BiTree T, vector<char> &s){
	stack<BiTree> stk;
	if(T != NULL) stk.push(T);
	while(stk.size() > 0){
		BiTree x = stk.top();
		s.push_back(x->data);
		stk.pop();
		if(x->rchild) stk.push(x->rchild);
		if(x->lchild) stk.push(x->lchild);
	}
}

//second mehod for iteration top-bottom-top
void longTraverseLeft(BiTree x, stack<BiTree> stk, vector<char> &s){
	while(x){
		s.push_back(x->data);
		stk.push(x->rchild);
		x = x->lchild;
	}
}
void preOrderTraverse3(BiTree T, vector<char> &s){
	stack<BiTree> stk;
	while(true){
		longTraverseLeft(T,stk,s);
		if(stk.size() == 0) break;
		T = stk.top();
		stk.pop();
	}
}

int main(){
   	vector<char> s;
   	vector<char> s2;
   	vector<char> s3;

   	BiTree T = NULL;
   	cout<<"input binary tree elements in preorder: "<<endl;
   	createBiTree(T);
   	cout<<"pre order traverse by recursion is: "<<endl;
   	preOrderTraverse(T, s);
   	for(int i = 0; i < s.size(); i++){
   		cout<<s[i];
   	}
   	cout<<endl;

   	cout<<"pre order traverse by iteration is: "<<endl;
   	preOrderTraverse(T, s2);
   	for(int i = 0; i < s2.size(); i++){
   		cout<<s2[i];
   	}
   	cout<<endl;

   	cout<<"pre order traverse by iteration version2 is: "<<endl;
   	preOrderTraverse(T, s3);
   	for(int i = 0; i < s3.size(); i++){
   		cout<<s3[i];
   	}
   	cout<<endl;

    return 0;
}
