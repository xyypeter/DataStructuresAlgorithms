
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }else if (nums[middle] < target) {
                left = middle + 1; 
            }else {
                return middle;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = { 1,2,3,4,5,6,7,8,9,10,12 };
    Solution solution;
    int result = solution.search(nums, 7);
    cout << "result=" << result;
}

