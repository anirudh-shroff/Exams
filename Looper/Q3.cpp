#include<iostream>

using namespace std;

int main(){

    int n,first,last;
    cout<<"Enter a number"<<endl;
    
    cin>>n;
    
    last=n%10;
    
    while (n>=10)
    {
        n=n/10;
    }
    first=n;
    
    cout<<"----------------------------------"<<endl;
    cout<<"Sum of first and last digit is : "<<first + last<<endl;

    return 0;
}