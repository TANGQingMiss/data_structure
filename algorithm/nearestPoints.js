//calculate nearest distances by divide and conquer
//left part, right part -> min = min(left,right,middle-min/+min)

const INF = 0x7fffffff;

function sortFromX(arr,n){
    let sorted;
    for(let i = 0; i < n; i++){
        sorted = true;
        for(let j = 0; j < n - i - 1; j++){
            if(arr[j][0] > arr[j+1][0]){
                let tmpS = arr[j][0];
                let tmpE = arr[j][1];
                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];
                arr[j+1][0] = tmpS;
                arr[j+1][1] = tmpE;
                sorted = false;
            }
        }
        if(sorted) break;
    }
}
function getDistance(x1, y1, x2, y2){
    return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

function nearestDistance(arr,l, r){
    let d = INF;
    if(l==r)
        return d;
    if(l + 1 == r){
        return getDistance(arr[l][0],arr[l][1],arr[r][0],arr[r][1]);
    }
    let q = Math.floor((l + r)/2);
    let d1 = nearestDistance(arr, l, q);
    let d2 = nearestDistance(arr, q, r);
    d = Math.min(d1,d2);
    //check middle part
    let k = 0;
    let tmp = new Array(r - l + 1);
    for(let i = l; i <= r; i++){
        if(Math.abs(arr[q][0] - arr[i][0]) <= d && i != q){//find q-min -> q + min
            tmp[k] = i;
            k++;
        }
    }
    for(let i = 0; i < k - 1; i++){
        for(let j = i + 1; j < k; j++){
            let d3 = getDistance(arr[tmp[i]][0],arr[tmp[i]][1],arr[tmp[j]][0],arr[tmp[j]][1]);
            d = Math.min(d,d3);
        }
    }
    return d;
}

let len = 5;
let points = [[0.0,0.0],[1.0,2.0],[2.5,2.1],[-1.4,1.2],[0.0,1.0]];

sortFromX(points,len);
console.log(nearestDistance(points,0,len-1));





