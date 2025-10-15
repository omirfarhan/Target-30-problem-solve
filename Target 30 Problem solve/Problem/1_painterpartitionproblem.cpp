#include<iostream>
#include<vector>
#include <climits>
using namespace std;

bool isValid(vector<int>& arr,int mid, int paintman,int n){

    int time=0;
    int student=1;

    for(int i=0; i<n; i++){

        if(time+arr[i]<=mid){
            time=time+arr[i];      
        }else{

            student++;
            time=arr[i];

        }

    }

     if(student>paintman){
            return false;
        }

    return true;

}


int Allocatetime(vector<int>& arr, int painterman,int n){

    int sum=0, maxVal= INT_MIN;

    for(int i=0; i<n; i++){

        sum=sum+arr[i];
        maxVal=max(maxVal,arr[i]);

    }

    int start=maxVal, end=sum;
    int ans=-1;
    
    while(start<=end){

        int mid=start+(end-start)/2;

        
        if(isValid(arr,mid,painterman,n)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }

    return ans;

}


int main(){
    vector<int> arr={40,30,10,20};
    int painterman=2;
    int n=4;
    cout<<"the time is: "<<Allocatetime(arr,painterman,n)<<endl;
    return 0;
}