class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), l = 0, r = n - 1;
        vector<int> res(n, pivot);

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                res[l++] = nums[i];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > pivot) {
                res[r--] = nums[i];
            }
        }

        return res;
    }
};
