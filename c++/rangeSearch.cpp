#include<iostream>
 
using namespace std;

//return the first element >= target
int searchLow(int arr[], int n, int val){
    for(int i = 0; i < n; i++){
        if(arr[i] >= val) return i;
    }
    return -1;
}

//return the firdt element <= target
int searchHigh(int arr[], int n, int val){
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] <= val) return i;
    }
    return -1;
}


int getRange(int arr[], int n, int l, int r){
	 int leftIdx = searchLow(arr,n,l);
     int rightIdx = searchHigh(arr,n,r);
     if(leftIdx == -1 || rightIdx == -1) return 0;
     if(rightIdx < leftIdx) return 0;
     else if(rightIdx >= leftIdx){
        return rightIdx - leftIdx + 1;
     }
}

int main(){
	int n;
	cout<<"input array length:"<<endl;
	cin>>n;

	int times;
	cout<<"input query times:"<<endl;
	cin>>times;

    int s[n];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < n; i++){
    	cin>>s[i];
    }

    int query[times][2];
    cout<<"input query index:"<<endl;
    for(int i = 0; i < times; i++){
        for(int j = 0; j < 2; j++){
            cin>>query[i][j];
        }
    }

    cout<<"search result is: "<<endl;
    for(int i = 0; i < times; i++){
        cout<<getRange(s,n,query[i][0],query[i][1])<<endl;
    }

    
    return 0;
}



