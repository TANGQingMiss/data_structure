//find all possible combinations whose sum == target
//example[1,1,2,4,5], target = 7 => [1,2,4],[2,5],but we can't have two [1,2,4]

let n = 4;
let origin = [2,1,3,4];
let target = 6;
let res = [];

function backtrack(array, res, start, tmp,target){
	if(target == 0){
	    let tmp2 = tmp.slice(0);
	    res.push(tmp2);
	    return;
	}
	if(target < 0) return;

    for(let i = start; i < array.length; i++){
    	if(i - 1 >= start && array[i-1] == array[i]) continue;
        tmp.push(array[i]);
        backtrack(array,res,i+1,tmp,target-array[i]);
        tmp.pop();
    }
}

function getSubsets(array,res,target){
	array.sort(function(x,y){return x - y;});
   let tmp = [];
    backtrack(array,res,0,tmp,target);
}

getSubsets(origin,res,target);
console.log(res);