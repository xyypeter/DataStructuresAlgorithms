#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)  return result;//因为经过排序，如果首元素大于0，不可能凑齐三元组，直接返回结果就可以了
            //正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;//注意b的起始位置
            int right = nums.size() - 1;
            while (right > left) {
                if ((nums[i] + nums[left] + nums[right]) > 0)right--;
                else if ((nums[i] + nums[left] + nums[right]) < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //去重逻辑添加至三元组之后
                    while ((right > left) && (nums[right] == nums[right - 1])) right--;
                    while ((right > left) && (nums[left] == nums[left + 1])) left--;
                    //找到答案时，双指针收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = { -1,0,1,2,-1,-4 };
    vector<vector<int>> result = s.threeSum(nums);
    for (auto nums : result) {
        for (auto value : nums) {
            cout << value << " ";
        }
        cout << endl;
    }
}

// 错误去重a方法，将会漏掉-1,-1,2 这种情况
//if (nums[i] == nums[i + 1]) {
//    continue;
//}
// 正确去重a方法
//if (i > 0 && nums[i] == nums[i - 1]) {
//    continue;
//}
// 举例如下:
//数组（已排序）：
//
//[-1, -1, 2]
//
//用错误写法会发生什么？
//i = 0：
//nums[0] = -1
//nums[1] = -1
//→ 相等 → continue
//*************************************************
// b和c的错误去重
//去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
//while (right > left && nums[right] == nums[right - 1]) right--;
//while (right > left && nums[left] == nums[left + 1]) left++;
//
//
//