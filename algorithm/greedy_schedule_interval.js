let num = 5;
let schedules = [[2,3],[1,2],[3,6],[2,8],[7,9]];
let resSchedule = [];

function bubbleSort(arr,n){
    let sorted;
    for(let i = 0; i < n; i++){
        sorted = true;
        for(let j = 0; j < n - i - 1; j++){
            if(arr[j][1] > arr[j+1][1]){
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

bubbleSort(schedules,num);

function greedyInterval(schedules,num,resSchedule){
    let res = 0;
    if(num == 0){
        console.log("maximum possible schedule numbers: ",res);
        return;
    }
    if(num == 1){
        resSchedule.push(0);
        res++;
        console.log("maximum possible schedule numbers: ",res);
        return;
    }
    let e = schedules[0][1];
    res++;
    resSchedule.push(0);
    for(let i = 1; i < num; i++){
        if(schedules[i][0] >= e){
            res++;
            resSchedule.push(i);
            e = schedules[i][1];
        }
    }
    console.log("maximum possible schedule numbers: ",res);
    return;
}

greedyInterval(schedules,num,resSchedule);
console.log("possible schedules index: ",resSchedule);