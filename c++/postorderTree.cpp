//this file is used to biuld a binary tree
//and realize postorder traverse by recursion and iteration
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

//postorder by recursion
void postOrderTraverse(BiTree T, vector<char>& s){
	if(T == NULL) return;
	postOrderTraverse(T->lchild,s);
	postOrderTraverse(T->rchild,s);
	s.push_back(T->data);
}


void postOrderTraverse2(BiTree T, vector<char> &s){
	stack<BiTree> stk;
	stack<int> is;
	BiTree p = T;
	int flag;
	if(T){
		do{
			while(p){
				stk.push(p);
				is.push(0);
				p = p->lchild;
			}
			p = stk.top();
			flag = is.top();
			stk.pop();
			is.pop();
			if(flag==0){
				stk.push(p);
				is.push(1);
				p = p->rchild;
			}else{
				s.push_back(p->data);
				p = NULL;
			}
		}while(p || !stk.empty());
	}
} 

int main(){
   	vector<char> s;
   	vector<char> s2;

   	BiTree T = NULL;
   	cout<<"input binary tree elements in preorder: "<<endl;
   	createBiTree(T);
   	cout<<"post order traverse by recursion is: "<<endl;
   	postOrderTraverse(T, s);
   	for(int i = 0; i < s.size(); i++){
   		cout<<s[i];
   	}
   	cout<<endl;

   	cout<<"post order traverse by iteration is: "<<endl;
   	postOrderTraverse2(T, s2);
   	for(int i = 0; i < s2.size(); i++){
   		cout<<s2[i];
   	}
   	cout<<endl;

    return 0;
}
