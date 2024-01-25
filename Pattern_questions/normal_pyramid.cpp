#include<iostream>

using namespace std;



//Floyd's Triangle
int main(){
    int a,count=1;
    cin>>a;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}





//constant number pyramid
// int main(){
//     int a;
//     cin>>a;

//     for(int i=1;i<=a;i++){
//         for(int j=1;j<=i;j++){
//             cout<<i<<" ";
//         }
//     cout<<endl;
//     }

//     return 0;
// }