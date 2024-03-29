//Program to find the number of paths to reach end
#include<iostream>
using namespace std;

int possiblepath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        count += possiblepath(s+i,e);
    }
    return count;
}

int main(){
    int a,b;
    cout<<"Enter the starting and end point:\n";
    cin>>a>>b;
    cout<<"Number of possible ways = "<<possiblepath(a,b);
    return 0;
}