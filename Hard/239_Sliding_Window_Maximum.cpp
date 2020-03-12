/*  239. Sliding Window Maximum
 *
 *  Given an array nums, there is a sliding window of size k 
 *  which is moving from the very left of the array to the very right. 
 *  You can only see the k numbers in the window. Each time the sliding 
 *  window moves right by one position. Return the max sliding window.
 *
 *	Example:
 *
 *	Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 *  Output: [3,3,5,5,6,7] 
 *
 * 	Explanation:
 * 
 *  Window position                Max
 *  ---------------               -----
 *  [1  3  -1] -3  5  3  6  7       3
 *   1 [3  -1  -3] 5  3  6  7       3
 *   1  3 [-1  -3  5] 3  6  7       5
 *   1  3  -1 [-3  5  3] 6  7       5
 *   1  3  -1  -3 [5  3  6] 7       6
 *   1  3  -1  -3  5 [3  6  7]      7
 *
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k == 0)
            return nums;
        int n = nums.size();
        int max_value = *max_element(nums.begin(), nums.begin() + k);
        result.push_back(max_value);
        for (int i = 0; k < n; i++, k++) {
            if (nums[i] == max_value)
                max_value = *max_element(nums.begin() + i + 1, nums.begin() + k + 1);
            else
                max_value = max(max_value, nums[k]);
            result.push_back(max_value);
        }
        return result;
    }
};
