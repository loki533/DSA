#include<bits/stdc++.h>
using namespace std;

void  subsequences_with_sum_k(int target , vector<int> &og ,int index){

    vector<int> result;
    int sum=0;

    if (index == og.size()){
        if(sum == target){
            for(auto it:result){
                cout<<it<<"";
                cout<<endl;
            }
            return;
        }

    result.push_back(og[index]);
    subsequences_with_sum_k(target,og,index+1);

    result.pop_back();

    subsequences_with_sum_k(target,og,index+1);
    }
        
}

int main(){
    vector<int> og ={1,2,1};
    int target = 2;
    subsequences_with_sum_k(2,og,0);
}