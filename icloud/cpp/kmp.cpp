#include<cstdio>
#include<cstring>
using namespace std;
const int MAXW=1e4+5,MAXT=1e6+5;
char W[MAXW],T[MAXT];
int next[MAXW];
int lenW,lenT;
void getnext(int lenW){
	int i=0,j=-1;
	next[i]=-1;
	while(i<lenW) {
		if(j==-1||W[i]==W[j]) {
			next[++i]=++j;
		}
		else j=next[j];
	}
}
int kmp(int pos,int lenW,int lenT){
	int i=pos,j=0,ans=0;
	while(i<lenT) {
		if(T[i]==W[j]||j==-1) ++i,++j;
		else j=next[j];
		if(j==lenW) {
			ans++;
			j=next[j-1];
			i--;
		}
	}
	return ans;
}
int main(){
    W[0]='e';W[1]='d';W[2]='g';W[3]='n';W[4]='b';
	scanf("%s",T);
	lenW=strlen(W);
	lenT=strlen(T);
	getnext(lenW);
	printf("%d\n",kmp(0,lenW,lenT));
	return 0;
}

