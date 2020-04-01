
let num = 5;
let lectures = [[1,3],[4,6],[7,9],[2,5],[1,3]];
let resLectures = [];
console.log("before bubble sort, lectures is: ",lectures);
//sort lectures by start time
function bubbleSort(arr,n){
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

bubbleSort(lectures,num);
console.log("after bubble sort, lectures is: ",lectures);

function greedyInterval(lectures,num,resLectures){
    let res = 0;
    if(num == 0){
        console.log("maximum possible classroom numbers: ",res);
        return;
    }
    if(num == 1){
        resLectures.push([lectures[0][0],lectures[0][1],0]);//push current start time, end time and index of lectures
        res++;
        console.log("maximum possible classroom numbers: ",res);
        return;
    }
    //initialize the first lecture with first classroom
    res++;
    resLectures.push([lectures[0][0],lectures[0][1],0]);
    for(let i = 1; i < num; i++){
        let flag = false;//note whether compatible
        for(let j = 0; j < resLectures.length; j++){
            let curEnd = resLectures[j][1];//the second element stores current end time
            if(lectures[i][0] >= curEnd){
                resLectures[j].push(i);
                resLectures[j][1] = lectures[i][1];
                flag = true;
                break;
            }
        }
        if(flag == false){
            resLectures.push([lectures[i][0],lectures[i][1],i]);//create a new classroom
            res++;
        }
    }
    console.log("maximum possible classroom numbers: ",res);
    return;
}

greedyInterval(lectures,num,resLectures);
console.log("possible schedules index: ",resLectures);