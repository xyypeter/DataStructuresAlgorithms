
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



int main() {
    Solution solution;

    string s = "the sky is blue";
    string result = solution.reverseWords(s);

    cout << result << endl;

}
