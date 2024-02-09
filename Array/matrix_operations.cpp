#include<iostream>

using namespace std;

int main(){
    int m,n,o;
    cout<<"Enter No. of Rows\n";
    cin>>m;
    cout<<"Enter No. of Columns\n";
    cin>>n;
    cout<<"Enter No. of Coloums of Second matrix\n";
    cin>>o;
    int a[m][n],b[n][o],c[m][o];
    cout<<"First matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<"Second matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            cin>>b[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            c[i][j] = 0;
            for(int k=0;k<n;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    cout<<"Result\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}