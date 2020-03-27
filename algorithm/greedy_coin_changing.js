function greedyChanges(cur, n, target, res){
    let max;
    let idx = n - 1;//note idx of current max
    while(target > 0){
        for(let i = idx; i >= 0; i--){
            if(cur[i] <= target){
                max = cur[i];
                idx = i;
                break;
            }
        }
        res[idx]++;
        target -= max;
    }
}


let num = 8;
let currency = [1,2,5,10,20,50,100,500];
let targets = [13,45,76,89,672];
for(let i = 0; i < targets.length; i++){
	let target = targets[i];
	let res = new Array(8);
	res.fill(0);
	greedyChanges(currency,num,target,res);
	console.log("coin changes for ",target);
	for(let j = 0; j < res.length; j++){
		if(res[j] != 0){
			console.log("numbers of type",currency[j]);
			console.log("is",res[j]);
		}
	}
}
