#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int n;
	cin>>n;
	char str[1001];
	getchar();//吸收回车键 
	for(int i=0; i<n; i++) {
		cin.getline(str,1001);
		int l=strlen(str);
		int b=-1;
		for(int j=0; j<=l; j++) {
			if(str[j]==' '||j==l) {
				for(int k=j-1; k>=0&&k!=b; k--)
					cout<<str[k];
				b=j;
				if(j!=l)
					cout<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}

