class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total=0,lsum=0,rsum=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            rsum=total-nums[i]-lsum;
            res.push_back(abs(rsum-lsum));
            lsum+=nums[i];
        }
        return res;
    }
};