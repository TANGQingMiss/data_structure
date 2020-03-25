function shellSort(arr,n){
    for(let gap = Math.floor(n / 2); gap > 0; gap = Math.floor(gap / 2)){
        for(let i = 0; i < gap; i++){
            for(let j = i + gap; j < n; j+= gap){
                if(arr[j] < arr[j - gap]){
                    let tmp = arr[j];
                    let k = j - gap;
                    while(k >= 0 && arr[k] > tmp){
                        arr[k+gap] = arr[k];
                        k -= gap;
                    }
                    arr[k+gap] = tmp;
                }
            }
        }
    }
}


let arr = [4,5,1,2,7,5,8,7,9];
console.log("before shell sort",arr);
shellSort(arr,arr.length);
console.log("after shell sort",arr);