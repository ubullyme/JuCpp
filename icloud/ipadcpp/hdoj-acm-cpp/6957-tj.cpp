#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 3e3+10;
int a[maxn][maxn], b[maxn][maxn], h[maxn];
int p, s[maxn], w[maxn];

int main(){
	ios::sync_with_stdio(false);
	int T;  cin>>T;
	while(T--){
		int n, m;  cin>>n>>m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin>>a[i][j];
				if(i==1)continue;
				b[i][j] = (a[i][j]>=a[i-1][j]);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			//统计高度
			for(int j = 1; j <= m; j++){
				if(b[i][j]==0)h[j] = 1;
				else h[j]++;
			}
			//单调栈
			p = 0;  h[m+1] = 0;
			for(int j = 1; j <= m+1; j++){
				if(h[j]>s[p])s[++p]=h[j], w[p] = 1;
				else{
					int width = 0;
					while(s[p]>h[j]){
						width += w[p];
						ans = max(ans, width*s[p]);
						p--;
					}
					s[++p] = h[j], w[p] = width+1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
