bool isPrefixAndSuffix(const string & str1, const string & str2)
    {
        if (str1.length() > str2.length()) return false;

        int n = str1.length(), m = str2.length();
        return str2.substr(0, n) == str1 && str2.substr(m - n, n) == str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j]) {
                    res++;
                }
            }
        }
        return res;
    }
