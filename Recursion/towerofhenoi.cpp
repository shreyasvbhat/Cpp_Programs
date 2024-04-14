//Program to implement tower of henoi
#include<iostream>
using namespace std;

void towerofhenoi(int n, char src, char dest, char helper){
    if(n==0){
        return;
    }

    towerofhenoi(n-1, src, helper, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofhenoi(n-1, helper, dest, src);
}

int main(){
    int n;
    cout<<"Enter the number of blocks:\n";
    cin>>n;
    towerofhenoi(n, 'A', 'C', 'B');
    return 0;
}