#include<iostream>
 
using namespace std;
 
void Merge(int arr[], int l, int q, int r){
    int n=r-l+1;
    int* tmp=new int[n];
    int i=0;
    int left=l;
    int right=q+1;
    while(left<=q && right<=r)
        tmp[i++] = arr[left]<= arr[right]?arr[left++]:arr[right++];
    while(left<=q)
        tmp[i++]=arr[left++];
    while(right<=r)
        tmp[i++]=arr[right++];
    for(int j=0;j<n;++j)
        arr[l+j]=tmp[j];
    delete [] tmp;
}
 
void MergeSort(int arr[], int l, int r){
    if(l==r)
        return;
    int q = (l + r)/2;
    MergeSort(arr, l, q);
    MergeSort(arr, q + 1, r);
    Merge(arr, l, q, r);
    
}

int main(){
	int len;
	cout<<"input array length:"<<endl;
	cin>>len;
    int a[len];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < len; i++){
    	cin>>a[i];
    }
    MergeSort(a,0,len-1);
    cout<<"after merge sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<a[j]<<" ";
    }
    cout<<endl;
    return 0;
}



