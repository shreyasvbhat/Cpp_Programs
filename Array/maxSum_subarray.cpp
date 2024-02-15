//Program to find the subarray with maximum sum
#include<iostream>
#include<climits>

using namespace std;

//Brut force with time complexity O(N^3)
int main(){
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
            }
            maxSum = max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}


//optimized method with time complexity of O(N^2)
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int currSum[n+1];
//     currSum[0] = 0;

//     for(int i=1;i<=n;i++){
//         currSum[i] = currSum[i-1] + a[i-1];
//     }
//     int maxSum = INT_MIN;
//     for(int i=1;i<=n;i++){
//         int sum = 0;
//         for(int j=0;j<i;j++){
//             sum = currSum[i] - currSum[j];
//             maxSum = max(maxSum,sum);
//         }
//     }
//     cout<<maxSum<<endl;
//     return 0;
// }



//kadane method with time complexity O(n)
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int maxSum = INT_MIN;
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum += a[i];
//         if(sum<0){
//             sum = 0;
//         }
//         maxSum = max(maxSum, sum);
//     }

//     cout<<maxSum<<endl;
//     return 0;
// }