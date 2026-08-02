#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int nth_root(int n,int m){
            
            int low = 1;
            int high = m;
            while(low<high)
            {
                int mid = (low+high)/2;
                long long  ans =1;

                for (int i=1;i<=n;i++){
                    ans *= mid; //checks for mid^n
                    if(ans>m){
                        break;
                    }
                }

                if(ans == m){
                    return mid;
                }
                else if(ans < m){
                    low = mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            return -1;
        }
};

int main(){
    Solution obj;
    int result = obj.nth_root(3,125);
    printf("%d",result);

}