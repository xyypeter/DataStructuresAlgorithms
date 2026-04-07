

//哈希表解决问题的场景为:一般哈希表都是用来快速判断一个元素是否出现集合里

//

//哈希表的三种结构
//1.数组
//2.set
// 在C++中，set 和 map 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：
//集合	                底层实现	   是否有序	 数值是否可以重复	能否更改数值	查询效率	    增删效率
//std::set	             红黑树	    有序	          否	           否	    O(log n)	O(log n)
//std::multiset          红黑树	    有序	          是	           否	    O(logn)	    O(logn)
//std::unordered_set	 哈希表	    无序	          否	           否	    O(1)	    O(1)
// 
// 
//3.map
//映射	                底层实现	   是否有序	数值是否可以重复	能否更改数值	查询效率	    增删效率
//std::map	             红黑树	   key有序	key不可重复	    key不可修改	O(logn)	    O(logn)
//std::multimap	         红黑树	   key有序	key可重复	    key不可修改	O(log n)	O(log n)
//std::unordered_map	 哈希表	   key无序	key不可重复	    key不可修改	O(1)	    O(1)
//
//
//
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // 测试用例1：是字母异位词
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Test1: " << (solution.isAnagram(s1, t1) ? "true" : "false") << endl;

    // 测试用例2：不是字母异位词
    string s2 = "rat";
    string t2 = "car";
    cout << "Test2: " << (solution.isAnagram(s2, t2) ? "true" : "false") << endl;

    // 测试用例3：长度不同
    string s3 = "hello";
    string t3 = "helloo";
    cout << "Test3: " << (solution.isAnagram(s3, t3) ? "true" : "false") << endl;

    // 测试用例4：相同字符串
    string s4 = "abc";
    string t4 = "abc";
    cout << "Test4: " << (solution.isAnagram(s4, t4) ? "true" : "false") << endl;

    return 0;
}
