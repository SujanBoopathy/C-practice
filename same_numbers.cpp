#include<iostream>
using namespace std;

bool checkSimilar(int arr[],int n){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i]==arr[j])
               return true;  
    return false;
}

int main()
{
    int n;
    cout<<"Enter size :"<<endl;cin>>n;
    int *numsArray=new int(n);
    cout<<"Enter "<<n<<" elements :"<<endl; 
    for(int i=0;i<n;i++)
        cin>>numsArray[i];   
    checkSimilar(numsArray,n)?cout<<"true":cout<<"false";
    return 0;
}

