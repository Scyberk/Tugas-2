#include <stdio.h>
#include <math.h>

int main(){
    int T;
    scanf("%d",&T);

    for(int t=1; t<=T; t++){
        long long M;
        scanf("%lld",&M);

        long long upperBound=(long long)ceil(cbrt((6.0*M)/(double)1)); 

        long long low=1,high=upperBound;
        long long mid,sum;

        while(low<=high){
            mid=(low+high)/2;
            sum=(mid*(mid+1)*(2*mid+1))/6; 
            if(sum>=M){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        printf("Case #%d: %lld\n",t,low);
    }
    return 0;
}
