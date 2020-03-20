#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void bucketSort(int arr[], int n,int min, int max){
	int bucket[max-min+1];
	memset(bucket, 0, sizeof(bucket));
	for(int i = 0; i < n; i++){
		bucket[arr[i]-min]++;
	}
	cout<<"current bucket is: "<<endl;
	for(int j = 0; j < max - min + 1; j++){
    	cout<<bucket[j]<<" ";
    }
    cout<<endl;
	for(int i = 0, j = 0; i < n && j < max - min + 1; ){
		while(bucket[j] > 0){
			arr[i++] = j+min;
			bucket[j]--;
		}
		j++;
	}
}


int main(){
	int min,max;
	cout<<"please input range from minimum to maximum: "<<endl;
	cin>>min>>max;
	int len;
	cout<<"input array length:"<<endl;
	cin>>len;
    int a[len];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < len; i++){
    	cin>>a[i];
    }

    cout<<"before bucket sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<a[j]<<" ";
    }
    cout<<endl;

    bucketSort(a,len,min,max);

    cout<<"after bubble sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<a[j]<<" ";
    }
    cout<<endl;

    return 0;
}


