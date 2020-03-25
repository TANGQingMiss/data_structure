function insertSort(arr){
    let tmp = [];
    for(let i = 0; i < arr.length; i++){
        if(tmp.length == 0) tmp.push(arr[i]);
        else{
            for(let j = tmp.length - 1; j >= 0; j--){
                if(arr[i] >= tmp[j]){
                    insert(tmp,j+1,arr[i]);
                    break;
                }else if(j == 0){
                    insert(tmp,0,arr[i]);
                }
            }
        }
    }
    for(let i = 0; i < arr.length; i++){
        arr[i] = tmp[i];
    }
}

function insert(arr,idx,val){
    if(idx == arr.length){
        arr.push(val);
    }else{
        arr.push(0);
        let tmp = arr[idx];
        for(let j = arr.length - 1; j > idx; j--){
            arr[j] = arr[j - 1];
        }
        arr[idx] = val;
    }

}

let arr = [4,5,1,2,7,5,8,7,9];
console.log("before insert sort",arr);
insertSort(arr);
console.log("after insert sort",arr);