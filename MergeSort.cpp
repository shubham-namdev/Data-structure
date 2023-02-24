#include<iostream>
#include<vector>

using namespace std;

void mergeVect(vector<int>& arr, int s, int mid, int e){

    vector<int> temp;

    int left, right;
    left = s;
    right = mid+1;

    while(left <= mid && right <=e){

        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            ++left;
        }

        else{
            temp.push_back(arr[right]);
            ++right;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        ++left;
    }
    while(right <= e){
        temp.push_back(arr[right]);
        ++right;
    }

    for(int i=s; i<=e; ++i){

        arr[left] = temp[left-s]; 
    }

}

void mergeSort(vector<int>& arr, int s, int e){
    if(s<e){
        int mid = s+(e-s)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr, mid + 1, e);
        mergeVect(arr, s, mid, e);
    }
}


int main(){

    int sz;
    vector<int> vact;

    cout<<"enter size: ";
    cin>>sz;
    vact = vector<int>(sz);

    cout<<"Push Elements : ";
    for(int i=0; i<sz; i++){
        cin>>vact[i];
        
    }

    mergeSort(vact, 0 , sz-1);

    cout<<"--------The Updated vactor is-------"<<endl<<endl;

    for(int i=0; i<sz; i++){
        cout<<vact[i]<<" ";
    }

    return 0;
}