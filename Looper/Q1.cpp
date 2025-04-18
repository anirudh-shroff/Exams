#include<iostream>

using namespace std;

int main(){

    cout<<"Enter a Alphabet : "<<endl;
    char alp;
    cin>> alp;
    
    for ( int i = 1; i < 7; i++)
    {
        alp=alp+4;
        cout<<alp<<endl;
    }

    


    return 0;
}