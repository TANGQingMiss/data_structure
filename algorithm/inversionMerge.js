//calculate inversion pairs by divide and conquer
//mergeSort -> merge
//left part, right part -> pairs: pairs in left + pairs in right + pairs in both
 
function merge(arr, tmp, l, m, r){
    let count = 0;
    let i,j;
    for(i = l; i <= r; i++){
        tmp[i] = arr[i];
    }
    let k = l;
    for(i = l, j = m + 1; i <= m && j <= r; k++){
        if(tmp[i] > tmp[j]){//choose smaller one to put in tmp[]
            count += m - i + 1;
            arr[k] = tmp[j];
            j++;
        }else{
            arr[k] = tmp[i];
            i++;
        }
    }
    if(i > m){
        while(j <= r){
            arr[k] = tmp[j];
            j++;
            k++;
        }
    }else{
        while(i <= m){
            arr[k] = tmp[i];
            i++;
            k++;
        }
    }
    return count;
}

function inversionPair(arr, tmp, l, r){
    if(l==r)
        return 0;
    let q = Math.floor((l + r)/2);
    let ln = inversionPair(arr, tmp, l, q);
    let rn = inversionPair(arr, tmp, q + 1, r);
    let mn = merge(arr, tmp, l, q, r);
    return ln + rn + mn;  
}

let len = 4;
let a = [1,3,4,2];
let tmp = new Array(4);
console.log("inversion pairs: ",inversionPair(a,tmp,0,len-1));



