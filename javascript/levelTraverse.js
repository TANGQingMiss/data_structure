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

BST.prototype.levelOrder = function(node){
	let stack = [];
	stack.push(node)
	while(stack.length > 0){
		let tmp = stack.shift();
		console.log(tmp.show() + " ");
		if(tmp.left) stack.push(tmp.left);
		if(tmp.right) stack.push(tmp.right);
	}
}

//test
var bst = new BST();
var nums = [10,3,18,2,4,13,21,9,8,7];
for(let i = 0; i < nums.length; i++){
	bst.insert(nums[i]);
}

bst.levelOrder(bst.root);
