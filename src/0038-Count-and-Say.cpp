/**
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * - 1.     1
 * - 2.     11
 * - 3.     21
 * - 4.     1211
 * - 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a string.
 *
 * Example 1:
 * Input: 1
 * Output: "1"
 *
 * Example 2:
 * Input: 4
 * Output: "1211"
 */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string res{"1"};
        while (--n) {
            string ret{""};
            char pre = res[0];
            int cnt = 1;
            for (int i = 1; i <=  res.length(); ++i) {
                if (i == res.length()) {
                    ret += ('0' + cnt);
                    ret += pre;
                } else if (res[i] == pre) {
                    ++cnt;
                } else {
                    ret += ('0' + cnt);
                    ret += pre;
                    pre = res[i];
                    cnt = 1;
                }
            }
            res = ret;
        }
        return res;
    }
};

int main() {
    Solution s;
    int testId = 1;

    auto exeTest = [&](int &n) {
        std::cout << "Case " << testId++ << ": "
                << s.countAndSay(n) << std::endl;
    };

    for (int i = 1; i <= 30; ++i)
        exeTest(i);
}