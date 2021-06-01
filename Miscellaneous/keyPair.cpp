#include<iostream>
using namespace std;

int main(){

  int t,n,x;
  cin>>t;
  while(t--){
    int flg = 0;
  cin>>n>>x;
  int a[n];
  for(int k=0;k<n;k++){
    cin>>a[k];
  }
  int sum = 0;
  int i,j;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      sum = a[i] + a[j];
      if(sum==x){
        flg = 1;
      }
    }
  }

  if(flg){
      cout<<"Yes";
  }
  else{
    cout<<"No";
  }

}

return 0;
}
