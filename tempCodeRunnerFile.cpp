#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    int sum=0;
    for(int i=0;i<str.length();i++){
        sum+=(str[i]);
    }
    while(sum/10){
        int p=0;
        while(sum){
            p+=sum%10;
            sum/=10;
        }
        sum=p;
    }
    cout<<sum<<endl;
}

