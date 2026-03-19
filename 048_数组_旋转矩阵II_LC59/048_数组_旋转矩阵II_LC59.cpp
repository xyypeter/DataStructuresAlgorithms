#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++)
                res[i][j] = num++;
            for (int j = i; j < n - i - 1; j++)
                res[j][n - i - 1] = num++;
            for (int j = i; j < n - i - 1; j++)
                res[n - i - 1][n - j - 1] = num++;
            for (int j = i; j < n - i - 1; j++)
                res[n - j - 1][i] = num++;
        }
        if (n % 2 == 1)
            res[n / 2][n / 2] = num;
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> result = solution.generateMatrix(3);
    for (auto nums : result) {
        for (auto value : nums) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

