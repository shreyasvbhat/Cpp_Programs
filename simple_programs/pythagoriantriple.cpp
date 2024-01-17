#include<iostream>
#include<math.h>

using namespace std;

int max(int a, int b){
    if(a>b)
       return a;
    else return b;
}

bool palindrome(int x, int y, int z){
    int a,b,c;
    a = max(x,max(y,z));
    if(a==x){
        b=y;
        c=z;
    }else if(a==y){
        b=x;
        c=z;
    }else {
        b=x;
        c=y;
    }

    if(pow(a,2) == (pow(b,2)+pow(c,2)))
      return true;
    else return false;

}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(palindrome(a,b,c))
     cout<<"They are pythagorian triplets";
    else cout<<"Not pythagorian triplets";
}