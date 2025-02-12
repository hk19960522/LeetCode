class Solution {
public:
    int getDigitSum(int num) {
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }

        return res;
    }
    int maximumSum(vector<int>& nums) {
        int res = -1;
        vector<vector<int>> record(50, vector<int>(2, -1));

        for (int num : nums) {
            int sum = getDigitSum(num);
            if (num > record[sum][0]) {
                record[sum][1] = record[sum][0];
                record[sum][0] = num;
            }
            else if (num > record[sum][1]) {
                record[sum][1] = num;
            }

            if (record[sum][0] != -1 && record[sum][1] != -1) {
                res = max(res, record[sum][0] + record[sum][1]);
            }
        }

        return res;
    }
};
