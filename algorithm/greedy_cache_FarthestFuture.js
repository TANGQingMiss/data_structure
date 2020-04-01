
let num = 5;
let cache = ['a','b','c','d','e','f'];
let requests = ['a','g','b','b','d','f','a','c','f','h','a'];

//if not matched - delete a most farthest needed element in cache
function cacheFF(cache, num, requests){
    let cnt = 0;//initialize count of operation times
    for(let i = 0; i < requests.length; i++){
        let idx = cache.indexOf(requests[i]);
        if(idx != -1){
            console.log("able to find element in current cache",requests[i]);
        }else{//else FF
            console.log("this element not exist in cache, modify cache");
            let max = requests.indexOf(cache[0]);
            let curIdx = 0;//initialize as the first element
            if(max == -1){
                console.log("need to modify element", cache[curIdx]);
                cache[curIdx] = requests[i];
                console.log("modify cache by replacing by ",requests[i]);
                console.log("able to find element in modified cache",requests[i]);
                cnt++;       
            }else{
                for(let j = 1; j < num; j++){
                    if(requests.indexOf(cache[j]) == -1){//first whether there is an element never called
                        curIdx = j;
                        break;
                    }
                    //check which element is the farthest to be visited
                    else if(requests.indexOf(cache[j]) > max){
                        //modify max number and note curIdx in cache
                        max = requests.indexOf(cache[j]);
                        curIdx = j;
                    }
                }
                //after find index, modify cache
                console.log("need to modify element: ",cache[curIdx]);
                cache[curIdx] = requests[i];
                console.log("modify cache by replacing by",requests[i]);
                console.log("able to find element in modified cache");
                cnt++;
            }
        }
    }
    console.log("total needed modify operation is: ",cnt);
}

cacheFF(cache, num, requests);