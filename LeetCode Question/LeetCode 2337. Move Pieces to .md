# LeetCode 2337. Move Pieces to Obtain a String

You are given two strings ==start== and ==target==, both of length ==n==. Each string consists only of the characters =='L'==, =='R'==, and ==''== where:

* The characters =='L'== and =='R'== represent pieces, where a piece =='L'== can move to the **left** only if there is a **blank** space directly to its left, and a piece =='R'== can move to the **right** only if there is a **blank** space directly to its right.

* The character =='_'== represents a blank space that can be occupied by **any** of the =='L'== or =='R'== pieces.

Return ==true== if it is possible to obtain the string ==target== by moving the pieces of the string ==start== **any** number of times. Otherwise, return ==false==.

想法 :
由於不同的 L 與 R 之間並沒有辦法在移動的過程中交換彼此的順序，因此第一個想法為 ==start== 與 ==target== 中如果把 =="_"== 移除的話，應該會是相等的字串
這邊可以使用 two pointer 的方式分別指向兩個字串，遇到空白就跳過，直到遇到 =="L"== 或是 =="R"==，如果兩邊的字元相等，就開始比對字元的出現位置，可以注意到的是 =="L"== 只能往左移動，因此，如果 ==start== 中的 index 比 ==target== 中的 index 小，表示不可能移動到該位置，=="R"== 則相反。

C++ : 
```C++=
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length(), m = target.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            while (i < n && start[i] == '_') i++;
            while (j < m && target[j] == '_') j++;

            if (i >= n && j >= m) return true;
            if (i >= n || j >= m || start[i] != target[j]) return false;
            if (start[i] == 'L') {
                if (j > i) return false;
            }
            else {
                if (j < i) return false;
            }
            i++, j++;
        } 

        while (i < n) {
            if (start[i] != '_') return false;
            i++;
        }
        while (j < m) {
            if (target[j] != '_') return false;
            j++;
        }
        return true;
    }
};
```