//realize heap sort
//establish a heap from an array
function makeHeap(arr){
    for(let i = arr.length - 1; i >= 0; i--){
        let idx = i;
        let tmp = arr[idx];
        while(idx * 2 + 1 < arr.length - 1){
            let left = arr[idx*2+1];
            let right = arr[idx*2+2];
            if(arr[idx] >= left && arr[idx] >= right){
                break;
            }else{
                if(left >= right){
                    arr[idx] = left;
                    arr[idx*2+1] = tmp;
                    idx = idx * 2 + 1;
                }else{
                    arr[idx] = right;
                    arr[idx*2+2] = tmp;
                    idx = idx * 2 + 2;
                }
            }
        }
        //consider only left
        if(idx * 2 + 1 == arr.length - 1){
            if(arr[idx] < arr[arr.length - 1]){
                arr[idx] = arr[arr.length - 1];
                arr[arr.length - 1] = tmp;
            }
        }
    }
    return arr;
}

//remove the largest number
function remove(arr){
    if(arr.length == 1){
        arr.pop();
        return arr;
    }
    //put the last number to the root position -> first
    //go down for change
    let tmp = arr[arr.length-1];
    arr.pop();
    arr[0] = tmp;
    let len = arr.length;
    let idx = 0;
    //no left and no right
    while(idx * 2 + 1 < len - 1){
        let left = arr[idx*2+1];
        let right = arr[idx*2+2];
        if(arr[idx] >= left && arr[idx] >= right){
            break;
        }else{
            if(left >= right){
                arr[idx] = left;
                arr[idx*2+1] = tmp;
                idx = idx * 2 + 1;
            }else{
                arr[idx] = right;
                arr[idx*2+2] = tmp;
                idx = idx * 2 + 2;
            }
        }
    }
    //consider only left
    if(idx * 2 + 1 == len - 1){
        if(arr[idx] < arr[len - 1]){
            arr[idx] = arr[len - 1];
            arr[len - 1] = tmp;
        }
    }
    return arr;

}

let arr = [3,2,5,12,6,4,8,13,2];
let res = [];
console.log("before heapification, arr is: ",arr);
makeHeap(arr);
console.log("after heapification, arr is: ",arr);
while(arr.length > 0){
    let tmp = arr[0];
    res.unshift(tmp);
    remove(arr);
    console.log("current array is: ",arr);
    console.log("current result is: ",res);
}