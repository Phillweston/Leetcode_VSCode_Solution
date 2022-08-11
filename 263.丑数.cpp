/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    // 丑数是任意个2,3,5相乘得到的。每个丑数都可以乘以一个2,3,5得到一个新的丑数。根据这个思想，我们可以递推出所有的丑数。
    bool isUgly(int n) {
        if(n==0)return false;
        while(n!=1){ //n=1时直接返回true，n>=2时执行判断
            if(n%2==0)n=n/2;
            else if(n%3==0)n=n/3;
            else if(n%5==0)n=n/5;
            else return false;
        }
        return true;
    }
};
// @lc code=end

