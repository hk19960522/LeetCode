class Solution {
public:
    string clearDigits(string s) {
        deque<char> dq;

        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            }
            else {
                dq.push_back(ch);
            }
        }

        string res;
        while (!dq.empty()) {
            res += dq.front();
            dq.pop_front();
        }

        return res;
    }
};
