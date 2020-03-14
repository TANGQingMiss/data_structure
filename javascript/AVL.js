//creation of AVL tree node
function AVLTreeNode(data){
    this.data = data;
    this.left = null;
    this.right = null;
    this.parent = null;
}

//creation of AVL tree
function AVLTree(key){
    this.root = null;
    //get height of current node
    let getHeight = function(node){
        if(node == null) return 0;
        else{
            return Math.max(getHeight(node.left),getHeight(node.right))+1;
        }
    };

    //left single rotation
    let rotateLL = function(node){
        let tmp = node.right;
        node.right = tmp.left;
        tmp.left = node;
        return tmp;
    };

    //right single rotation
    let rotateRR = function(node){
        let tmp = node.left;
        node.left = tmp.right;
        tmp.right = node;
        return tmp;

    };

    //left -> right
    let rorateLR = function(node){
        node.left = rotateLL(node.left);
        return rotateRR(node);
    };

    //right -> left
    let rotateRL = function(node){
        node.right = rotateRR(node.right);
        return rotateLL(node);
    };

    //check balance factor
    function chechIsBalance(node){
        if(node == null) return node;
        //node factor = 2
        if(getHeight(node.left) - getHeight(node.right) > 1){
            if(getHeight(node.left.left) >= getHeight(node.left.right)){
                node = rotateRR(node);
            }else{
                node = rorateLR(node);
            }
        }else if(getHeight(node.right) - getHeight(node.left) > 1){
            if(getHeight(node.right.right) >= getHeight(node.right.left)){
                node = rotateLL(node);
            }else{
                node = rotateRL(node);
            }
        }
        return node;
    }

        let insertNode = function(node,newNode){
            if(node == null){
                node = newNode;
                return node;
            }else if(newNode.data < node.data){
                if(node.left == null){
                    node.left = newNode;
                    return node;
                }else{
                    node.left = insertNode(node.left,newNode);
                    node = chechIsBalance(node);
                }
            }else if(newNode.data > node.data){
                if(node.right == null){
                    node.right = newNode;
                    return node;
                }else{
                    node.right = insertNode(node.right,newNode);
                    node = chechIsBalance(node);
                }
            }
            return node;
        };

        this.insert = function(data){
            let newNode = new AVLTreeNode(data);
            this.root = insertNode(this.root,newNode);
        };

        this.delete = function(data){
            this.root = deleteData(this.root,data);
        };

        function deleteData(node,data){
            if(node == null) return null;
            if(data < node.data){
                node.left = deleteData(node.left,data);
                node = chechIsBalance(node);
                return node;
            }else if(data > node.data){
                node.right = deleteData(node.right,data);
                node = chechIsBalance(node);
                return node;
            }else{
                if(node.left && node.right){
                    let tmp = node.right;
                    while(tmp.left){
                        tmp = tmp.left;
                    }
                    node.data = tmp.data;
                    node.right = deleteData(node.right,tmp.data);
                    node = chechIsBalance(node);
                    return node;
                }else if(node.left == null && node.right == null){
                    node = null;
                    return node;
                }else if(node.left == null && node.right){
                    node = node.right;
                    return node;
                }else{
                    node = node.left;
                    return node;
                }

            }
        }
         function preOrder(root){
            if(root == null) return;
            console.log(root.data);
            preOrder(root.left);
            preOrder(root.right);
        }

        this.preOrderTraverse = function(){
            preOrder(this.root);
        }
    }




    //test
    let avl = new AVLTree();
    let existData = [];
    let testNum = [2,4,6,5,8,32,17,9,0,3];
    for(let i = 0; i < testNum.length; i++){
        avl.insert(testNum[i]);
        console.log("current preorder result");
        avl.preOrderTraverse();
    }

    let deletion = [4,17,0,5];
    for(let i = 0; i < deletion.length; i++){
        avl.delete(deletion[i]);
        console.log("current preorder result");
        avl.preOrderTraverse();
    }
