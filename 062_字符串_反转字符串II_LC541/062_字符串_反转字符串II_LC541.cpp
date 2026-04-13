#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main() {
    Solution solution;

    // 测试案例1：题目示例
    {
        string s1 = "abcdefg";
        string result1 = solution.reverseStr(s1, 2);
        cout << "s=\"abcdefg\", k=2 => " << result1 << endl;
        // 期望结果: "bacdfeg"
    }

    // 测试案例2：k=4
    {
        string s2 = "abcdefgh";
        string result2 = solution.reverseStr(s2, 4);
        cout << "s=\"abcdefgh\", k=4 => " << result2 << endl;
        // 期望结果: "dcbaefgh"
    }

    // 测试案例3：k=3
    {
        string s3 = "abcde";
        string result3 = solution.reverseStr(s3, 3);
        cout << "s=\"abcde\", k=3 => " << result3 << endl;
        // 期望结果: "cbad e" -> "cbade"
    }

    return 0;
}