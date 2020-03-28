function dpChanges(cur, n, target){
    let dp = new Array(target+1);
    dp[0] = 0;
    for(let i = 1; i <= target; i++){
        dp[i] = 500;//suppose a maximum demand for 500
        for(let j = 0; j < n; j++){
            if(cur[j] == i){
                dp[i] = 1;
                break;
            }
        }
    }
    for(let i = 1; i <= target; i++){
        if(dp[i] == 1){
           console.log("result is ",dp[i]);
        }
        else{
            for(let j = 0; cur[j] < i && j < n; j++){
                dp[i] = Math.min(dp[i],dp[i - cur[j]]+1);
            }
            console.log("result is ",dp[i]);
        }

    }
    console.log("result is ",dp[target]);
}


let n = 8;
let currency = [1,2,5,10,20];
let target = 23;
dpChanges(currency,n,target);

