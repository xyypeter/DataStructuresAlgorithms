#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;
    //回朔信息
    void backtrack(string current, int open, int close, int n) {
        if (open == n && close == n) {// 如果已经用完 n 对括号，加入结果
            result.push_back(current);
            return;
        }

        // 如果还能加 '('
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // 如果还能加 ')'（不能超过 '(' 的数量）
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<string> res = s.generateParenthesis(n);
    for (auto& str : res) {
        cout << str << endl;
    }
    return 0;
}

