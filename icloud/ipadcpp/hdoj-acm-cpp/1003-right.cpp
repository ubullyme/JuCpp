#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
	int t,left,right;
	cin>>t;
	for(int l=1;l<=t;l++){
		int n;
		int max=-3000;
		cin>>n;
		left=right=1;
		int m=1;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			if(sum>max){
				max=sum;
				right=i;
				left=m;
			}
			if(sum<0){
				sum=0;
				m=i+1;	
			}
		}
		cout<<"Case "<<l<<':'<<endl;
		cout<<max<<' '<<left<<' '<<right<<endl;
		if(l!=t) cout<<endl;
	}
	return 0;
}

