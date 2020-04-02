//calculate inversion pairs by divide and conquer
//mergeSort -> merge
//left part, right part -> pairs: pairs in left + pairs in right + pairs in both
#include<iostream>
using namespace std;
 
int merge(int arr[], int tmp[], int l, int m, int r){
    int count = 0;
    int i,j;
    for(i = l; i <= r; i++){
        tmp[i] = arr[i];
    }
    int k = l;
    for(i = l, j = m + 1; i <= m && j <= r; k++){
        if(tmp[i] > tmp[j]){//choose smaller one to put in tmp[]
            count += m - i + 1;
            arr[k] = tmp[j];
            j++;
        }else{
            arr[k] = tmp[i];
            i++;
        }
    }
    if(i > m){
        while(j <= r){
            arr[k] = tmp[j];
            j++;
            k++;
        }
    }else{
        while(i <= m){
            arr[k] = tmp[i];
            i++;
            k++;
        }
    }
    return count;
}

int inversionPair(int arr[], int tmp[], int l, int r){
    if(l==r)
        return 0;
    int q = (l + r)/2;
    int ln = inversionPair(arr, tmp, l, q);
    int rn = inversionPair(arr, tmp, q + 1, r);
    int mn = merge(arr, tmp, l, q, r);
    return ln + rn + mn;
    
}

int main(){
	int len;
	cout<<"input array length:"<<endl;
	cin>>len;
    int a[len];
    int tmp[len];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < len; i++){
    	cin>>a[i];
        tmp[i] = 0;
    }
    
    cout<<"inversion pairs: "<<inversionPair(a,tmp,0,len-1)<<endl;

    return 0;
}



