#include<iostream>
#include<string.h>
using namespace std;

int digitOfRoman(char ch){
    switch(ch){
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D': return 500; break;
        case 'M': return 1000; break;
        default : return 0;
    }
    
}

int roman_to_int(char s[]){
    int prev_val,cur_val,val=digitOfRoman(s[0]);
    for(int i=1;s[i]!='\0';i++){
        prev_val=digitOfRoman(s[i-1]);
        cur_val=digitOfRoman(s[i]);
        if(prev_val<cur_val){
            val=val-prev_val+(cur_val-prev_val);
        }
        else{
            val+=cur_val;
        }
    }
    return val;
}

int main(){
    char s[100];
    cout<<"Enter roman Letter : "; cin>>s;
    int value=roman_to_int(s);
    cout<<"The value of "<<s<< " is : "<<value<<endl;
    return 0;
}
