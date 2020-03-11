//creation of binary tree
function Node(data,left,right){
    this.data = data;
    this.left = left;
    this.right = right;
}

function BST(data){
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

BST.prototype.search = function(root,target){
    let current = this.root;
    while(current){
        if(current.data == target) return true;
        else if(target < current.data) current = current.left;
        else current = current.right;
    }
    return false; 
}

BST.prototype.delete = function(root,target){
    if(this.root == null){
        console.log('delete not finished because root is null');
        return this.root;
    }
    if(this.root.data > target){
        this.root.left = delete(this.root.left,target);
    }else if(this.root.data < target){
        this.root.right = delete(this.root.right,target);
    }else{
        if(this.root.left == null && this.root.right == null) this.root = null;
        else if(this.root.left == null && this.root.right != null) this.root = this.root.right;
        else if(this.root.left != null && this.root.right == null) this.root = this.root.left;
        else{
            let prevNode = this.root.left;//find value closest to target
            while(prevNode.right){
                prevNode = prevNode.right;
            }
            this.root.data = prevNode.data;
            this.root.left = delete(this.root.left,prevNode.data);
        }
    }
    return this.root;
}

//inorder by recursion
BST.prototype.inOrder = function(node){
    if(node){
        this.inOrder(node.left);
        console.log(node.data);
        this.inOrder(node.right);
    }
}


//test
var bst = new BST();
var nums = [10,3,18];
for(let i = 0; i < nums.length; i++){
    bst.insert(nums[i]);
    bst.inOrder(bst.root);
}

//bst.search(bst.root,13);

var deletion = [3,10];
for(let i = 0; i < deletion.length; i++){
    bst.delete(bst.root,deletion[i]);
    bst.inOrder(bst.root);
}

