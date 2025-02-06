class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0, n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            for (int j = i + 3; j < n; j++) {
                int target = nums[i] * nums[j];
                int l = i + 1, r = j - 1;

                while (l < r) {
                    int mul = nums[l] * nums[r];
                    if (mul == target) {
                        res ++;
                        l ++;
                        r --;
                    }
                    else if (mul > target) {
                        r --;
                    }
                    else {
                        l ++;
                    }
                }
            }
        }

        return res * 8;
    }
};
