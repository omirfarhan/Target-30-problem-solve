#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& arr, int student,int book,int mid){

    if(student>book){
        return false;
    }

    int secondstudent=1;
    int pages=0;

    for(int i=0;i<book; i++){

    if(pages+arr[i]<=mid){
        pages=pages+arr[i];
    }else{
        secondstudent++;
        pages=arr[i];
    }
    
    }

    

    if(secondstudent>student){
        return false;
    }else{
        return true;
    }

    return true;
}



int bookAllocate(vector<int>& arr,int student,int book){

    int answer=0;

    int pageSum=0;
    for(int i=0; i<book; i++){
        pageSum=pageSum+arr[i];
    }

    int start=0;
    int end=pageSum;
    
    while(start<=end){

        int mid=start+(end-start)/2;

        if(isValid(arr,student,book,mid)){
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }

    }
    
    return answer;

    
}



int main(){
    vector<int>arr={3,2,1,4,5};
    int student=2;
    int book=5;
    int result=bookAllocate(arr,student,book);
    cout<<"Book Pages: "<<result;
}