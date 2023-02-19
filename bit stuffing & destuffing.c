#include<stdio.h>

void stuffing(int n, int arr[]){
    int i=0, k;
    int j=0;
    int brr[50];
    int count =1;

    while(i<n){
        if(arr[i]==1){

            brr[j]=arr[i];

            for(k= i+1; k<n && arr[k]==1 && count<5; k++){
                j++;
                brr[j] = arr[k];
                count++;
                if(count==5){
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }
        else{
            brr[j] = arr[i];
        }
        i++;
        j++;
    }


    for(i=0; i<j; i++) printf("%d",brr[i]);
}

void deStuffing(int n, int arr[]){
    int i=0,j=0,k;
    int brr[50];
    int count = 1;
    while(i<n){
        if(arr[i]==1){
            brr[j] = arr[i]; //brr0 =1

            for(k=i+1; k<n&&arr[k]==1&&count<5; k++){ //k=1,2,3,4
                j++;//1,2,3,4
                brr[j]= arr[k];//brr1,2,3,4=1,1,1,1
                count++;//2,3,4,5
                if(count==5){
                    k++;
                }
                i=k;//1,2,3
            }
        }
        else{
            brr[j]=arr[i];
        }
        i++;
        j++;
    }
    for(i=0; i<j; i++) printf("%d",brr[i]);
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];

    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    //stuffing(n,arr);
    deStuffing(n,arr);


    return 0;

}
