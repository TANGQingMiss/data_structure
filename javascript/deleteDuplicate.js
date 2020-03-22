//realize delete duplicate terms by hash
let arr = [1,2,4,6,5,7,8,9,7,3,4,5,10];
let res = [];
let hash = {};
for(let i = 0; i < arr.length; i++){
    if(!hash[arr[i]]){
        res.push(arr[i]);
        hash[arr[i]] = 200;
    }
}
console.log(res);
console.log(hash);