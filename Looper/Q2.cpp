#include <iostream>

using namespace std;

int main(){
    
    int n,count = 0;
    cout<<"Enter a Number : "<<endl;
    cin>>n;
    
    while (n!=0)
    {
        n=n/10;
        count++;
    }
    cout << count;    

    return 0;
}