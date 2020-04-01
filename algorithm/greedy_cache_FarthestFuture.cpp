//optimal offline caching
//cache with capacity to store only k items
//search sequence of m item requests r1,r2,r3,r4...
//if cache hits -> return true
//if not, delete a farthest future element and add this new into cache, note operation + 1
#include <iostream>
#include <string>
#include <math.h>
#include<algorithm>
#include <vector>
using namespace std;

int findElement(vector<int> arr, int target){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;//no matching element
}

//if not matched - delete a most farthest needed element in cache
int cacheFF(vector<int> &cache, int num, vector<int> requests, int need){
    int cnt = 0;//initialize count of operation times
    for(int i = 0; i < need; i++){
        int idx = findElement(cache,requests[i]);
        if(idx != -1){
            cout<<"find element "<<requests[i]<<" in current cache!"<<endl;
        }else{//else FF
            cout<<"this element not exist in cache, modify cache"<<endl;
            int max = findElement(requests,cache[0]);
            int curIdx = 0;//initialize as the first element
            for(int j = 1; j < num; j++){
                //check which element is the farthest to be visited
                if(findElement(requests,cache[j]) > max){
                    //modify max number and note curIdx in cache
                    max = findElement(requests,cache[j]);
                    curIdx = j;
                }
            }
            //after find index, modify cache
            cache[curIdx] = requests[i];
            cout<<"modify cache by replacing by "<<requests[i]<<endl;
            cout<<"able to find element "<<requests[i]<<" in modified cache"<<endl;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    cout<<"input capacity of cache: "<<endl;
    int num;
    cin>>num;

    cout<<"input initial value of cache: "<<endl;
    vector<int> cache;
    for(int i = 0; i < num; i++){
        int item;
        cin>>item;
        cache.push_back(item);
    }
    cout<<"input number of requests: "<<endl;
    int need;
    cin>>need;
    cout<<"input each request: "<<endl;
    vector<int> requests;
        for(int i = 0; i < need; i++){
        int request;
        cin>>request;
        requests.push_back(request);
    }
    
    cout<<"total needed changes in cache is: "<<cacheFF(cache,num,requests,need)<<endl;
    
    return 0;
}