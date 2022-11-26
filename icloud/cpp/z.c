#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000010
int check(char a){return (a>='0' && a<='9');}
int main(){
    int num1=0,num2=0;
    char a[MAXN];
    int al=0;
    int f=1;
    int pos;
    while(1){
        char c=getchar();
        if(c=='\n') break;
        a[al++]=c;
    }
    for(int i=0;i<al;++i){
        if(a[i]==' ') {pos=i;break;}
    }
    for(int i=0;i<pos;i++){
        if(!check(a[i])){f=0;break;}
    }
    if(f){
        num1=atoi(a);
    }f=1;
    for(int i=pos+1;i<al;i++){
        if(!check(a[i])){f=0;break;}
    }
    if(f){
        num2=atoi(a+pos);
    }
    //printf("%d %d\n",num1,num2);
    if(num1>1000 || num1 < 1) num1=0;
    if(num2>1000 || num2 < 1) num2=0;
    if(num1!=0 && num2!=0)
        printf("%d + %d = %d",num1,num2,num1+num2);
    else{
        if(num1==0 && num2!=0) printf("? + %d = ?",num2);
        else if(num2==0 && num1!=0) printf("%d + ? = ?",num1);
        else printf("? + ? = ?");
    }
    return 0;
}