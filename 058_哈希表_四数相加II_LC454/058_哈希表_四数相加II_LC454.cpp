#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//容器决策树选择如下:
//是否需要排序？
//├── 是（红黑树）
//│   ├── 是否允许重复？
//│   │     ├── 是
//│   │     │     ├── 只要key → multiset
//│   │     │     └── key - value → multimap
//│   │     │
//│   │     └── 否
//│   │           ├── 只要key → set
//│   │           └── key - value → map
//│
//└── 否（哈希表）
//    ├── 是否允许重复？
//    │     ├── 是
//    │     │     ├── 只要key → unordered_multiset
//    │     │     └── key - value → unordered_multimap
//    │     │
//    │     └── 否
//    │           ├── 只要key → unordered_set
//    │           └── key - value → unordered_map
//
//
//总结:先看要不要排序 → 再看要不要重复 → 最后看要不要 value

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;//key:a+b的数值 value: a+b数值出现的次数
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0;//统计a+b+c+d=0出现的次数
        //然后遍历C和D的数组，找到0-(C+D)在umap中出现过，即可以统计key对应的value
        for (int c : nums3) {
            for (int d : nums4) {
                count += umap[0 - (c + d)];
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {  1,2 };
    vector<int> nums2 = { -2,-1 };
    vector<int> nums3 = { -1,2 };
    vector<int> nums4 = {  0,2 };
    int result=s.fourSumCount(nums1,nums2,nums3,nums4);
    cout << "result=" << result <<endl;
}
