#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a,b,c[30],d,r=0,dl;
    printf("Enter the No of Data Bits you want to Enter: ");
    scanf("%d",&a); //6

    while(a+r+1> pow(2,r)){
        r++;//1,2,3,4
    }
    printf("No of data bits to be added %d: total bits:%d\n",r,a+r);

    printf("Enter the Data bits one by one: ");
    for(int i=1; i<=a; i++) scanf("%d",&c[i]);

    printf("Data bits entered: ");
    for(int i=1; i<=a; i++) printf(" %d ",c[i]);
    printf("\n");

    int data[a+r];

    d=0;
    dl=1;

    for(int i=1; i<=a+r; i++){ //i=1,2,3,4,5,6,7,8,9,10
        if(i==pow(2,d)){ //1==1, 2==2, 3==4(f), 4==4, 5==8(f), 8==8, 9==16(f)
            data[i]=0; //data[1,2,4,8]=0,0,0,0
            d++;   //d=1,2,3,4
        }
        else{
            data[i]=c[dl]; //data[3,5,6,7,9,10]=c[1,2,3,4,5,6]
            dl++;//dl=2,3,4,5,6,7
        }
    }
    printf("Data bits are encoded with parity bits(0): ");
    for(int i=1; i<=a+r; i++) printf(" %d ",data[i]);
    printf("\n");

    dl=0;
    int min,max=0,parity,s,j;

    for(int i=1; i<=a+r; i=pow(2,dl)){
        dl++;
        parity=0;
        j=i;
        s=i;
        min = 1;
        max = i;
        for(j; j<=a+r; j++){
            for(s=j; max>=min && s<=a+r; min++, s++){
                if(data[s]==1) parity++;
            }
            j = s+i;
            min=1;
        }
        if(parity%2==0) data[i]=0;
        else data[i] = 1;
    }

    printf("Hamming codeword bits for even parity are: ");
    for(int i=1; i<=a+r; i++) printf(" %d ",data[i]);

    printf("\n");


    return 0;
}
