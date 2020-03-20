    let test = [1,4,5,3,2,2,5,7,8,9,5,6,8,5,3,6,0,1,3];
    let bucket = new Array(10);
    bucket.fill(0);
    let res = new Array();

    let n = test.length;
    for(let i = 0; i < n; i++){
        bucket[test[i]]++;
    }
    for(let i = 0; i < bucket.length; i++){
        while(bucket[i] > 0){
            res.push(i);
            bucket[i]--;
        }
    }
    console.log(res);
    