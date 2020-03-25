#include <iostream>
#include <string>
using namespace std;

void quickSort(int arr[], int left, int right){
    if(left >= right) return;
    int i = left;
    int j = right;
    int base = arr[left];
    int tmp;
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

int main(){
	int len;
    cout<<"input array length:"<<endl;
    cin>>len;
    int nums[len];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < len; i++){
        cin>>nums[i];
    }

	cout<<"before quick sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;

    quickSort(nums,0, len-1);

    cout<<"after quick sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;
    return 0;
}

