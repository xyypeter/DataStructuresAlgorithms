
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int n = s.size(), i = 0;
        for (int j = 0; j < n;)
        {
            if (s[j] != ' ')
            {
                int idx = i;
                while (j < n && s[j] != ' ') s[i++] = s[j++];
                reverse(s.begin() + idx, s.begin() + i);
                s[i++] = ' ';
            }
            ++j;
        }
        s.resize(i - 1);
        reverse(s.begin(), s.end());
        return s;
    }
};

//核心解题思路:对原字符串进行一个整体反转，然后在对每个单词进行局部反转---双指针解法
class Solution2 {
public:
    //整体反转
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    //取出所有空格并在相邻单词之间添加空格，快慢指针
    void removeExtraSpaces(string& s) {
        int slow = 0;//慢指针
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {//遇到非空格就处理，即删除所有空格
                if (slow != 0) s[slow++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);     //去除多余空格，保证单词之间只有一个空格，且字符串首位没空格
        reverse(s,0,s.size() - 1);//进行整体翻转
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);//进行局部翻转
                start = i + 1;           //局部翻转完成后，移动至下一个单词
            }
        }
        return s;
    }
};


int main() {
    //Solution solution;

    //string s = " the sky is blue";
    //string result = solution.reverseWords(s);

    Solution2 solution2;

    string s = " the sky is blue";
    string result = solution2.reverseWords(s);

    cout << result << endl;

}
