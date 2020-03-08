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
BST.prototype.postOrder_v1 = function(node){
	if(node){
		this.postOrder_v1(node.left);
		this.postOrder_v1(node.right);
		console.log(node.show() + " ");
	}
}

BST.prototype.postOrder_v2 = function(node){
	let stack = [];
	let is = [];
	let p = node;
	let flag;
	if(node){
		do{
			while(p){
				stack.push(p);
				is.push(0);
				p = p.left;
			}
			p = stack.pop();
			flag = is.pop();
			if(flag==0){
				stack.push(p);
				is.push(1);
				p = p.right;
			}else{
				console.log(p.show() + " ");
				p = null;
			}
		}while(p || stack.length > 0);
	}

}

//test
var bst = new BST();
var nums = [10,3,18,2,4,13,21,9,8,7];
for(let i = 0; i < nums.length; i++){
	bst.insert(nums[i]);
}

bst.postOrder_v1(bst.root);
bst.postOrder_v2(bst.root);
