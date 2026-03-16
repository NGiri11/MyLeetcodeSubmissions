class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0,k=0;
        while(l<nums.size()){
            if(nums[l]!=val){
                nums[k]=nums[l];
                k++;
                l++;
            }
            else{
                l++;
            }
        }
        return k;
    }
};