#include<iostream>
#include<string.h>
using namespace std;

class resString{    
    public:
       string s;
    
    void func(int n){
        if(n%5==0 && n%3==0)
            s="FizzBuzz";
        else if(n%5==0)
            s="Buzz";
        else if(n%3==0)
            s="Fizz";
        else 
            s=to_string(n);
    }
};

int main(){    
    int i,n;
    cout<<"Enter a number :"<<endl;cin>>n;
    resString obj[n];
    for(i=0;i<n;i++)
        obj[i].func(i); 
    for(i=0;i<n;i++)
        cout<<"\n"<<obj[i].s;   
}