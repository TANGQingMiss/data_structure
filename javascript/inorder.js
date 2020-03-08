//creation of binary tree
function Node(data,left,right){
	this.data = data;
	this.left = left;
	this.right = right;
}
Node.prototype.show = function(){
	return this.data;
}

function BST(){
	this.root = null;
}

BST.prototype.insert = function(data){
	var node = new Node(data,null,null);
	if(this.root == null){
		this.root = node;
	}else{
		var current = this.root;
		var parent;
		while(true){
			parent = current;
			if(data < current.data){
				current = current.left;
				if(current == null){
					parent.left = node;
					break;
				}
			}else{
				current = current.right;
				if(current == null){
					parent.right = node;
					break;
				}
			}
		}
	}
}

//inorder by recursion
BST.prototype.inOrder_v1 = function(node){
	if(node){
		this.inOrder_v1(node.left);
		console.log(node.show() + " ");
		this.inOrder_v1(node.right);
	}
}

BST.prototype.inOrder_v2 = function(node){
	let stack = [];
	while(true){
		while(node){
			stack.push(node);
			node = node.left;
		}
		if(stack.length == 0) break;
		node = stack.pop();
		console.log(node.show() + " ");
		node = node.right;
	}
}

//test
var bst = new BST();
var nums = [10,3,18,2,4,13,21,9,8,7];
for(let i = 0; i < nums.length; i++){
	bst.insert(nums[i]);
}

bst.inOrder_v1(bst.root);
bst.inOrder_v2(bst.root);