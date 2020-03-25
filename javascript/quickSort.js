function quickSort(arr,left,right){
    if(left >= right) return;
    let i = left;
    let j = right;
    let base = arr[left];
    let tmp;
    while(i < j){
        while(arr[j] >= base && i < j) j--;
        while(arr[i] <= base && i < j) i++;
        if(i < j){
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    arr[left] = arr[i];
    arr[i] = base;
    quickSort(arr,left,i-1);
    quickSort(arr,i+1,right);
}


let arr = [4,5,1,2,7,5,8,7,9];
console.log("before quick sort",arr);
quickSort(arr,0,arr.length-1);
console.log("after quick sort",arr);