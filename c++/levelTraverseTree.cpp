//this file is used to biuld a binary tree
//and realize level traverse by recursion and iteration
#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>
#include<queue>
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
void levelTraverse(BiTree T, vector<char>& s){
	queue<BiTree> que;
	que.push(T);
	BiTree tmp;
	while(!que.empty()){
		tmp = que.front();
		s.push_back(tmp->data);
		que.pop();
		if(tmp->lchild) que.push(tmp->lchild);
		if(tmp->rchild) que.push(tmp->rchild);
	}
}


int main(){
   	vector<char> s;

   	BiTree T = NULL;
   	cout<<"input binary tree elements in preorder: "<<endl;
   	createBiTree(T);
   	cout<<"level traverse by recursion is: "<<endl;
   	levelTraverse(T, s);
   	for(int i = 0; i < s.size(); i++){
   		cout<<s[i];
   	}
   	cout<<endl;

    return 0;
}
