#include <iostream>
using namespace std;
namespace AcWing{
    void print(int a[],int l,int r){
        for(int i=l;i<=r;++i)
            printf("%d ",a[i]);
        printf("\n");
    }
    void sort(int a[],int l,int r){
        if(l>=r) return;
        int i=l-1,j=r+1;
        int mid=(l+r)>>1;
        while(i<j){ 
            while(a[++i]<a[mid]);
            while(a[--j]>a[mid]);
            if(i<j) swap(a[i],a[j]);
        }
        sort(a,l,j);sort(a,j+1,r);
    }
    int BinSearch(int a[],int l,int r,int key){
        int i=l,j=r;
        while(l<=r){
            int mid=(i+j)>>1;
            int midVal=a[mid];
            if(midVal<key)
                i=mid+1;
            else if(midVal>key)
                j=mid-1;
            else 
                return mid;
        }
        return -1;
    }
} // namespace SORT
int main(){
    int a[11]={-1,3,1,0,5,9,7,0,10,11,4};
    AcWing::sort(a,1,10);
    AcWing::print(a,1,10);
    int t=AcWing::BinSearch(a,1,10,7);
    cout<<t<<endl;
    cout<<a[t]<<endl;
    return 0;
}