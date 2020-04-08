//find all permutation by back tracking
//input n = 3, -> out put 123 132 213 231 312 321

let n = 4;
let origin = [2,1,3,1];
let res = [];

function backtrack(array, res, start, tmp){
    let tmp2 = tmp.slice(0);
    res.push(tmp2);
    for(let i = start; i < array.length; i++){
    	if(i - 1 >= start && array[i-1] == array[i]) continue;
        tmp.push(array[i]);
        backtrack(array,res,i+1,tmp);
        tmp.pop();
    }
}

function getSubsets(array,res){
	array.sort(function(x,y){return x - y;});
   let tmp = [];
    backtrack(array,res,0,tmp);
}

getSubsets(origin,res);
console.log(res);