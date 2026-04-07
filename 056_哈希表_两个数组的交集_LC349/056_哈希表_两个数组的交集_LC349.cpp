// 056_哈希表_两个数组的交集_LC349.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//需要排序？
//├── 是 → set / map
//│       ├── 只要key → set
//│       └── key - value → map
//│
//└── 否 → unordered_ *
//├── 只要key → unordered_set
//└── key - value → unordered_map

//需要重复？
//├── 是 → multiset / multimap
//└── 否 → set / map

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (auto num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main(){
    Solution s;
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2};
    vector<int> result=s.intersection(nums1,nums2);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}

