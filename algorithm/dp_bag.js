//this file is used to solve dynamic programming for bag question
//bag question: we have [a,b,c,d...] objects, their weight are [wa,wb,wc,wd...],their value are [va,vb,vc,vd,...]
//for a given size bag, find solution to make the values in the bag reach maximum while total weight <= bag size


function dpBag_01(size, weiObjects, valObjects,len){
    let dp = new Array(len+1);
    for(let i = 0; i <= len; i++){
        dp[i] = new Array(size+1).fill(0);
    }
    //dp[i][j] means for taking i+1 th objects(1-len), for size j+1 maximum value
    for(let i = 1; i <= len; i++){
        for(let j = 1; j <= size; j++){
            if(j >= weiObjects[i-1]){
                //if j >= weiObjects[i-1] -> choose max between choosing this one or not
                dp[i][j] = Math.max(dp[i-1][j],dp[i-1][j-weiObjects[i-1]] + valObjects[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    console.log("current dp: ",dp);
    console.log("maximum value is: ",dp[len][size]);
}


function dpBag_complete(size, weiObjects, valObjects, len){
    let dp = new Array(size+1).fill(0);
    //dp[i][j] means for taking i+1 th objects(1-len), for size j+1 maximum value
    for(let i = 0; i < len; i++){
        for(let j = weiObjects[i]; j <= size; j++){
            dp[j] = Math.max(dp[j],dp[j-weiObjects[i]]+valObjects[i]);
        }
    }
    console.log("current dp: ",dp);
    console.log("maximum value is: ",dp[size]); 
}

let len = 4;
let weiObjects = [2,3,4,5];
let valObjects = [3,4,5,6];
let size = 8;
dpBag_01(size,weiObjects,valObjects,len);
dpBag_complete(size,weiObjects,valObjects,len);





