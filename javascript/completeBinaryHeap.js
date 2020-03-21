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

//add a number to the max heap
function insert(arr,val){
    arr.push(val);//add to the last and go up
    let idx = arr.length - 1;
    while(Math.ceil(idx / 2) - 1 >= 0){
        let parent = arr[Math.ceil(idx / 2) - 1];
        if(val <= parent) break;
        else{
            arr[idx] = parent;
            arr[Math.ceil(idx / 2) - 1] = val;
            idx = Math.ceil(idx / 2) - 1;
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

let arr = [3,2,5,12];
console.log("before heapification, arr is: ",arr);
makeHeap(arr);
console.log("after heapification, arr is: ",arr);
let add = [1,19,8];
for(let i = 0; i < add.length; i++){
    console.log("add number ",add[i]);
    insert(arr,add[i]);
    console.log("after adding number, arr is: ",arr);
}
for(let i = 0; i < 4; i++){//remove the largest number 4 times
    console.log("remove largest number");
    remove(arr);
    console.log("after removing number, arr is: ",arr);
}

