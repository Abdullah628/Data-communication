#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void decToBin(int dec)
{
    vector<int>bin;
    while(dec!=0)
    {
        bin.push_back(dec%2);
        dec/=2;
    }
    for(int i=bin.size()-1; i>=0; i--) cout<<bin[i];
    bin.clear();
}

int main()
{
    int x;
    vector<char>name;

    string ip;
    cin>> ip;
    int cnt=0;

    while(cnt != ip.size()){

        for(int i=cnt; i<ip.size(); i++)
        {
            cnt++;
            if(ip[i]=='.')
            {
                break;
            }
            name.push_back(ip[i]);
        }

        x=0;
        for(int i=0; i<name.size(); i++)
        {
            x += (name[i]-'0')*pow(10,name.size()-i-1);
        }
        name.clear();

        decToBin(x);
        if(cnt<ip.size()) cout<< ".";
    }
    cout<< endl;

    return 0;
}
