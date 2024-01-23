#include<iostream>

using namespace std;


//inverted pyramid
int main(){
    int a;
    cin>>a;
    for(int i=a;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<" * ";
        }
       cout<<endl;
    }
    return 0;
}


//180 degree rotated inverted pyramid
// int main(){
//     int a;    
//     cin>>a;

//     for(int i=1;i<=a;i++){
//         for(int j=1 ; j<=a ; j++){
//             if(j <= a-i)
//              cout<<"   ";
//             else cout<<" * ";
//         }
        
//         cout<<endl;
//     }

//     return 0;
// }