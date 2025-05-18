#include<iostream> 
#include<vector> 
#include<algorithm> 

using namespace std; 

class Solution{
public: 
      vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size(); 
        vector<vector<int>> result; 
        sort(nums.begin() , nums.end()); 

        for(int i=0; i< n-2; ++i){
          int left = i+1; 
          int right = n-1; 
          while(left<right){
            int sum = nums[i]+nums[left]+nums[right]; 
            if(sum<0) ++left; 
            else if(sum>0) --right; 
            else{
              result.push_back({nums[i],nums[left],nums[right]}); 
              while(left<n-1 && nums[left]==nums[left+1]) ++left; 
              while(right>0 && nums[right]==nums[right-1]) --right; 
              ++left; 
              --right; 
            }
          }
          while(i<n-2 && nums[i]==nums[i+1]) ++i; 
        }
        return result; 
      }
};
int main(){
  vector<int> nums = {-1,0,1,2,-1,-4}; 
  Solution sol; 
  vector<vector<int>> result = sol.threeSum(nums); 
  for(auto vec: result){
    cout << "[" ; 
    for(auto num: vec){
      cout << num << " ";
    }
    cout << "]" << endl; 
  }
  return 0; 
}
