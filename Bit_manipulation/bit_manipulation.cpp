#include<iostream>
using namespace std;

//getbit is used to get the bit present in number n in its kth position
int getbit(int n, int pos){
    return ((n>>pos)&1);
}

//to set 1 to the given position in a number
int setBit(int n, int pos){
    return (n | (1<<pos));
}

//to make the bit 0 in the position entered by the user in a number
int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n&mask);
}

//
int toggleBit(int n, int pos){
    return (n xor (1<<pos));
}

//updating the given position bit by the bit entered by the user in the given number
int updateBit(int n, int pos, int value){
    int mask = ~(1<<pos);
    n = n& mask;
    return (n| (value<<pos));
}

int main(){
    int n,k,value;
    cin>>n>>k>>value;
    cout<<getbit(n,k);
    cout<<endl;
    cout<<setBit(n,k)<<endl;
    cout<<clearBit(n,k)<<endl;
    cout<<toggleBit(n,k)<<endl;
    cout<<updateBit(n,k,value)<<endl;



    return 0;
}