class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            if (num < k) {
                pq.push(num);
                n++;
            }
        }

        while (n >= 2) {
            int a = pq.top(), b;
            pq.pop();
            b = pq.top();
            pq.pop();

            if (a * 2 + b >= k) {
                n -= 2;
            }
            else {
                n -= 1;
                pq.push(a * 2 + b);
            }
            res ++;
        }

        return res;

    }
};
