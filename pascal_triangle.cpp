#include<iostream>
using namespace std;

int main(){
    int line;
    cout<<"Enter no of rows : "<<endl;cin>>line;
    // int *arr=new int(line*line);
    int arr[line][line];
    for(int i=0;i<line;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || i==j)  arr[i][j]=1;
            else{
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
            }
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}