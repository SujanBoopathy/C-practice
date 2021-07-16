#include<iostream>
using namespace std;

void zeroAtEnd(int a[],int n){
   int count=0;
   for(int i=0;i<n;i++){
       if(a[i]!=0)
          a[count++]=a[i];
   }
   for(;count<n;count++){
       a[count]=0;
   }
}

void print(int a[],int n){
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
}

int main(){
    int size;
    cout<<"Enter size of the array :"<<endl;cin>>size;
    int arr[size];
    cout<<"Enter the element of the array :"<<endl;
    for(int i=0;i<size;i++)   cin>>arr[i];
    zeroAtEnd(arr,size);
    print(arr,size);
    return 0;
}