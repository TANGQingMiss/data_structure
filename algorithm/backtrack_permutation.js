//find all permutation by back tracking
//input n = 3, -> out put 123 132 213 231 312 321

let n = 4;
let origin = [1,3,4,5];
let res = [];

function backtrack(n, origin, res, start, end){
    if(start == end){
        let help = origin.slice(0);
        res.push(help);
    }else{
        for(let i = start; i <= end; i++){
            let tmp = origin[i];
            origin[i] = origin[start];
            origin[start] = tmp;
            backtrack(n,origin,res,start+1,end);
            let tmp1 = origin[i];
            origin[i] = origin[start];
            origin[start] = tmp1;
        }
    }
}

function numberPermutation(n, origin, res){
    if(n == 1){
        res.push(origin);
        return;
    }
    backtrack(n,origin,res,0,n-1);
    return;
}

numberPermutation(n,origin,res);
console.log(res);