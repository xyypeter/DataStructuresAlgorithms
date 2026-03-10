#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size();fast++) {//注意fast的边界问题
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main()
{
    vector<int> nums = { 1,2,3,4,5,7,7,7,7,7,12 };
    Solution solution;
    int result = solution.removeElement(nums, 7);
    cout << "result=" << result;
}
