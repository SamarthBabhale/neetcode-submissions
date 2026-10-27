class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {0};
        }
        vector<int> ans(n,0);
        int pro=1;
        int x=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                x=1;
                if (count > 1) {
                    return ans;
                }
                continue;
            }
            
            pro*=nums[i];
        }
       
        for(int i=0;i<n;i++){
            if(x==1 && nums[i]!=0){
                ans[i]=0;
                continue;

            }
            if(x==1 && nums[i]==0){
                ans[i]=pro;
                continue;
            }
            ans[i]=pro/nums[i];
        }
        return ans;
    }
};
