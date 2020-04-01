//is file is used to solve minimum needs for several intervals
//lecture i start at si and finishes at fi
//goal: find minimum number of classrooms to schedule all lectures so that
//no two occur at the same time in the same room
#include <iostream>
#include <string>
#include <math.h>
#include<algorithm>
#include <vector>
using namespace std;

//sort lectures by start time so that s1<=s2<=s3...<=sn
void bubbleSort(int arr[][2], int n){
    bool sorted;
    for(int i = 0; i < n; i++){
        sorted = true;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j][0] > arr[j+1][0]){
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

//key observation: number of claarooms needed >= maximum number that contain any given
int greedyInterval(int lectures[][2], int num,vector<vector<int> > &resLectures){
    vector<int> tmp;
    if(num == 0) return 0;
    int res = 0;
    if(num == 1){
        tmp.push_back(lectures[0][0]);
        tmp.push_back(lectures[0][1]);//first and second element to note start time and end time
        tmp.push_back(0);//first classroom, later elements note index of lecture
        resLectures.push_back(tmp);
        tmp.clear();
        res++;
        return res;
    }

    for(int i = 0; i < num; i++){
        if(i == 0){
            res++;
            tmp.push_back(lectures[i][0]);
            tmp.push_back(lectures[i][1]);//first and second element to note start time and end time
            tmp.push_back(i);//first classroom, later elements note index of lecture
            resLectures.push_back(tmp);
            tmp.clear();
        }else{
            int curS = lectures[i][0];//check every start time
            bool flag = false;
            for(int j = 0; j < resLectures.size(); j++){
                if(curS >= resLectures[j][1]){//if this start time >= one of these endtimes // so it's compatible
                    resLectures[j].push_back(i);//add this lecture i to classroom j
                    resLectures[j][1] = lectures[i][1];//modify endtime
                    flag = true;
                    break;
                }
            }
            if(flag == false){//means all current classrooms aren't compatible
                res++;
                tmp.push_back(lectures[i][0]);
                tmp.push_back(lectures[i][1]);//first and second element to note start time and end time
                tmp.push_back(i);//first classroom, later elements note index of lecture
                resLectures.push_back(tmp);
                tmp.clear();
            }
        }
    }
    return res;
}

int main(){
    cout<<"input number of lectures: "<<endl;
    int num;
    cin>>num;

    cout<<"input start time and end time of each lecture: "<<endl;
    int lectures[num][2];
    for(int i = 0; i < num; i++){
        int start;
        int end;
        cin>>start>>end;
        lectures[i][0] = start;
        lectures[i][1] = end;
    }

    //sort by start time
    bubbleSort(lectures,num);

    vector<vector<int> > resLectures;

    cout<<"minimum classrooms needed is: "<<greedyInterval(lectures,num,resLectures)<<endl;
    cout<<"index of lectures for each classroom that are chosen is: ";
    for(int i = 0; i <resLectures.size(); i++){
        cout<<"for classroom "<<i+1<<": "<<endl;
        for(int j = 2; j < resLectures[i].size(); j++){
            cout<<resLectures[i][j]<<" ";
        }
        cout<<endl; 
    }
    
    return 0;
}