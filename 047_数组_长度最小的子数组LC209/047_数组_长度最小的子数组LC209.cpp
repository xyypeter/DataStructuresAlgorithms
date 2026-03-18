#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = INT_MAX;     //记录最小长度
        int start = 0, end = 0;//窗口的左右边界指针
        int sum = 0;           //当前窗口内的和
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];               //关键步骤-调整窗口内的元素和
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main(){
    vector<int> nums = { 2,3,1,2,4,3 };
    Solution solution;
    int result = solution.minSubArrayLen(7,nums);
    cout << result << endl;
}

