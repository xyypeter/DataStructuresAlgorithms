#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
            //swap的核心原理:
            //int tmp=s[i];
            //s[i]=s[j];
            //s[j]=tmp;
        }
    }
};

int main() {
    //输入：s = ["h", "e", "l", "l", "o"]
    //输出：["o", "l", "l", "e", "h"]

    Solution solution;
    vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
    cout << "输入: [";
    for (size_t i = 0; i < s.size(); i++) {
        cout << "\"" << s[i] << "\"";
        if (i != s.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    solution.reverseString(s);

    cout << "输出: [";
    for (size_t i = 0; i < s.size(); i++) {
        cout << "\"" << s[i] << "\"";
        if (i != s.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

}

