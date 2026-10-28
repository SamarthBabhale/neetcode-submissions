class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=1;
        int maxcount=1;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            else if(nums[i]+1==nums[i+1]){
                count++;
            }
            else{
               maxcount=max(count,maxcount);
               count=1;
              
            }
        }
        
        return max(maxcount,count);
    }
};
