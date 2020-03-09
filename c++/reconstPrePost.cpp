//rebuild a binary tree by preorder and postorder is only applicable in true binary tree
//which means, a totally complete tree
#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>
#include<stack>
using namespace std;

//define binary tree structure
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
	TreeNode* reConstructBT(vector<int> pre, vector<int> post){
		if(pre.empty() || post.empty()) return nullptr;
		TreeNode* root = new TreeNode(pre[0]);
		if(pre.size() == 1) return root;
		int length = 0;
		//find left tree interval in post traversal
		while(pre[1] != post[length]) length++;
		vector<int> pre_left, pre_right, post_left, post_right;
		for(int i = 0; i <= length; i++){
			post_left.push_back(post[i]);
			pre_left.push_back(pre[i+1]);
		}
		for(int i = length + 1; i < pre.size()-1; i++){
			post_right.push_back(post[i]);
			pre_right.push_back(pre[i+1]);
		}
		root->left = reConstructBT(pre_left,post_left);
		root->right = reConstructBT(pre_right,post_right);
		return root;
	}


	//preorder
	void preOrderTraverse(TreeNode* root){
		if(root){
			cout<<root->val<<" ";
			preOrderTraverse(root->left);
			preOrderTraverse(root->right);
		}
	}


	//inorder
	void inOrderTraverse(TreeNode* root){
		if(root){
			inOrderTraverse(root->left);
			cout<<root->val<<" ";
			inOrderTraverse(root->right);
		}
	}


	//postorder
	void postOrderTraverse(TreeNode* root){
		if(root){
			postOrderTraverse(root->left);
			postOrderTraverse(root->right);
			cout<<root->val<<" ";
		}
	}	
};

int main(){
	int nPre[] = {1,2,4,5,3,6,7};
	int nPost[] = {4,5,2,6,7,3,1};
   	vector<int> pre(nPre,nPre+7);
   	vector<int> post(nPost,nPost+7);

   	Solution reconstruct;
   	TreeNode *newRoot = reconstruct.reConstructBT(pre,post);
   	cout<<"pre order traverse: "<<endl;
   	reconstruct.preOrderTraverse(newRoot);
   	cout<<endl;
    cout<<"in order traverse: "<<endl;
   	reconstruct.inOrderTraverse(newRoot);
   	cout<<endl;
   	cout<<"post order traverse: "<<endl;
   	reconstruct.postOrderTraverse(newRoot);
   	cout<<endl;
    return 0;
}
