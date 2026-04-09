#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] > target && nums[k] >= 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;//A级去重
            for (int i = k + 1; i < nums.size(); i++) {   //B级处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) break;
                if ((i > k + 1) && (nums[i] == nums[i - 1])) continue;//B级去重
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                        // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = { 1,0,-1,0,-2,2 };
    vector<vector<int>> result = s.fourSum(nums,0);
    for (auto nums : result) {
        for (auto value : nums) {
            cout << value << " ";
        }
        cout << endl;
    }
}

