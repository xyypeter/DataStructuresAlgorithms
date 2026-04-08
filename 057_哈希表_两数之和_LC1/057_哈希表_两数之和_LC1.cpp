#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            //遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return { iter->second,i };
                //上述内容等价于
                // return vector<int>{ iter->second, i }; 
                // iter->second的含义为unordered_map<int, int> map;，保存的内容为key   → value(数字 → 下标)
            } 
            //如果没有找到匹配的，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<int> nums = { 2,7,11,15 };
    vector<int> result = s.twoSum(nums, 17);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}
