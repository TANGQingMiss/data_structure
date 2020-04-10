//make parenthese permutation

let n = 4;
let res = [];
getPermutation(res,n);

function backtrack(res, left, right, s){
    if(left == 0 && right == 0) res.push(s);
    if(right > left) backtrack(res,left,right-1,s+")");
    if(left > 0) backtrack(res,left-1,right,s+"(");
}

function getPermutation(res, n){
    let s = "";
    backtrack(res,n,n,s);//left ( n, right ) n
}

console.log(res);