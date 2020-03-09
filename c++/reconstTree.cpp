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
	TreeNode* reConstructBT(vector<int> pre, vector<int> vin){
		if(pre.empty() || vin.empty()) return nullptr;
		TreeNode* root = new TreeNode(pre[0]);
		int length = 0;
		while(pre[0] != vin[length]) length++;
		vector<int> pre_left, pre_right, vin_left, vin_right;
		for(int i = 0; i < length; i++){
			pre_left.push_back(pre[i+1]);
			vin_left.push_back(vin[i]);
		}
		for(int i = length + 1; i < pre.size(); i++){
			pre_right.push_back(pre[i]);
			vin_right.push_back(vin[i]);
		}
		root->left = reConstructBT(pre_left,vin_left);
		root->right = reConstructBT(pre_right,vin_right);
		// int value = pre[0];
		// if(pre.size() == 1) return root;
		// auto pos = find(vin.begin(), vin.end(), value);
		// if(pos == vin.end()) return nullptr;
		// int leftSize = pos - vin.begin();
		// int rightSize = vin.end() - pos - 1;
		// root->left = reConstructBT(vector<int>(pre.begin()+1,pre.begin()+1+leftSize),
		// 							vector<int>(vin.begin(),vin.begin()+leftSize));
		// root->right = reConstructBT(vector<int>(pre.begin()+1+leftSize,pre.end()),
		// 							vector<int>(vin.begin()+leftSize+1, vin.end()));
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
	int nIn[] = {4,2,5,1,6,3,7};
   	vector<int> pre(nPre,nPre+7);

   	Solution reconstruct;
   	TreeNode *newRoot = reconstruct.reConstructBT(pre,vin);
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
