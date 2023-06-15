#include<iostream>
using namespace std;

int main()
{
    int n, i;
    cout<< "Enter number of bits: ";
    cin>>n;

    int arr[n];

    cout<< "Enter bit stream: ";
    for(i=0; i<n; i++) cin>> arr[i];

    int temp=1;

    for(i=0; i<n; i++){
        if(arr[i]==0) cout<< "z";

        else if(arr[i]==1){
            if(temp==1){
                temp=0;
                cout<< "p";
            }
            else if(temp==0){
                temp=1;
                cout<< "n";
            }
        }
    }

    return 0;
}
