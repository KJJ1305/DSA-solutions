class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        if(nums[st]<nums[end])
            return nums[st];

        while (st <= end) {
            int mid = (st + end) / 2;
            if (nums[st] > nums[end]) {
                if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1])
                    return nums[mid];
                if(nums[mid]<nums[st]){
                    end=mid-1;
                }
                else
                    st=mid+1;
            }else
                return nums[st];
        }
        return 0;

    }
};