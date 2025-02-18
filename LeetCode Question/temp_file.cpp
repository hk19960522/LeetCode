class Solution {
public:
    string smallestNumber(string pattern) {
        deque<int> v, head;

        head.push_back(0);
        int cnt = 1;
        for (char ch : pattern) {
            if (ch == 'D') {
                head.push_back(cnt);
            }
            else {
                while (!head.empty()) {
                    v.push_front(head.back());
                    head.pop_back();
                }

                head.push_back(cnt);
            }
            cnt++;
        }

        string str;
        str.resize(pattern.size() + 1);

        while (!v.empty()) {
            str[v.front()] = cnt--;
        }
        return str;
    }
};
