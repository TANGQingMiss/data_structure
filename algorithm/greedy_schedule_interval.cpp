//this file is used to solve schedule interval
//suppose n schedules, each schedule i is represented by [startI, endI]
//at any time only one schedule could be happening
//choose schedules to do schdules as much as possible
#include <iostream>
#include <string>
#include <math.h>
#include<algorithm>
#include <vector>
using namespace std;

void bubbleSort(int arr[][2], int n){
    bool sorted;
    for(int i = 0; i < n; i++){
        sorted = true;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j][1] > arr[j+1][1]){
                int tmpS = arr[j][0];
                int tmpE = arr[j][1];
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

int greedyInterval(int schedules[][2], int &num,vector<int> &resSchedule){
    if(num == 0) return 0;
    int res = 0;
    if(num == 1){
        resSchedule.push_back(0);
        res++;
        return 1;
    }
    //sort by endtime
    bubbleSort(schedules,num);
    //from the earliest end schedule
    //check begin time whether included
    //use a number to note end time to overcome overlap interval
    int e = schedules[0][1];
    res++;
    resSchedule.push_back(0);
    for(int i = 1; i < num; i++){
        if(schedules[i][0] >= e){
            res++;
            resSchedule.push_back(i);
            e = schedules[i][1];
        }
    }
    return res;
}

int main(){
    cout<<"input number of schedules: "<<endl;
    int num;
    cin>>num;

    cout<<"input start time and end time of each schedule: "<<endl;
    int schedules[num][2];
    for(int i = 0; i < num; i++){
        int start;
        int end;
        cin>>start>>end;
        schedules[i][0] = start;
        schedules[i][1] = end;
    }

    vector<int> resSchedule;

    cout<<"maximum schedules result is: "<<greedyInterval(schedules,num,resSchedule)<<endl;
    cout<<"index of schedules that are chosen is: ";
    for(int i = 0; i < resSchedule.size(); i++){
        cout<<resSchedule[i]+1<<" ";
    }
    cout<<endl; 
    return 0;
}