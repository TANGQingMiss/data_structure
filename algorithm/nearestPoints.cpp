//calculate inversion pairs by divide and conquer
//mergeSort -> merge
//left part, right part -> pairs: pairs in left + pairs in right + pairs in both
#include<iostream>
#include <math.h>
using namespace std;

const int INF = 0x7fffffff;

void sortFromX(double arr[][2],int n){
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

double getDistance(double x1,double y1, double x2, double y2){
    cout<<"distance is: "<<sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))<<endl;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double nearestDistance(double arr[][2], int l, int r){
    double d = INF;
    if(l==r)
        return d;
    if(l + 1 == r){
        return getDistance(arr[l][0],arr[l][1],arr[r][0],arr[r][1]);
    }
    int q = (l + r)/2;
    double d1 = nearestDistance(arr, l, q);
    cout<<"first d1: "<<d1<<endl;
    double d2 = nearestDistance(arr, q, r);
    cout<<"second d2: "<<d2<<endl;
    d = min(d1,d2);
    cout<<"current d: "<<d<<endl;
    //check middle part
    int k = 0;
    int tmp[r - l + 1];
    for(int i = l; i <= r; i++){
        if(abs(arr[q][0] - arr[i][0]) <= d && i != q){//find q-min -> q + min
            tmp[k] = i;
            k++;
        }
    }
    for(int i = 0; i < k - 1; i++){
        for(int j = i + 1; j < k; j++){
            double d3 = getDistance(arr[tmp[i]][0],arr[tmp[i]][1],arr[tmp[j]][0],arr[tmp[j]][1]);
            d = min(d,d3);
        }
    }
    cout<<"final d: "<<d<<endl;
    return d;
}
int main(){
	int len;
	cout<<"input points number:"<<endl;
	cin>>len;

    double points[len][2];
    cout<<"please input x and y coordinates for each points:"<<endl;
    for(int i = 0; i < len; i++){
    	cin>>points[i][0]>>points[i][1];
    }
    sortFromX(points,len);
    cout<<"nearest points distance is: "<<nearestDistance(points,0,len-1)<<endl;

    return 0;
}



