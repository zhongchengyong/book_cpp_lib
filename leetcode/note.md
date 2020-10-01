# Leetcode刷题笔记
## 动态规划
91: Decode ways  
### 描述
`Given a non-empty string containing only digits, determine the total number of ways to decode it.`
注意初始化条件和循环开始开始节点
注意状态转移方程的实现
```
class Solution {
public:
    /** 要点：循环从1开始，因为无法判断前两个数的值，等于初始化了dp[0]和dp[1]
    /        注意判断条件，可以理解prev和cur为两个指针，分别指向dp[i-2]和dp[i-1]
    */
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int prev = 1, cur = 1; // dp[-1]=dp[0]=1
        int tmp;
        for (size_t i = 1; i < s.size(); ++i) {
            tmp = cur;
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') cur = prev;  // 只有dp[i-2]种方法
                else return 0; //不能解码
           } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <='6' && s[i] >= '1')) {
               cur = prev + cur; // 两种解法, dp[i] = dp[i-1] + dp[i-2]
           } else {
               cur = cur;  //只是推进指针更新cu，可以省略
           }
           prev = tmp;
        }
        return cur;
    }
}
```

## 字符串

## DFS
93： Restore IP Address
### Description
`Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.`
### Key
要点：
    1. 初始化vector并resize
    2. DFS找到可行解，并对0做特殊处理
### Solution
```
class Solution {
private:
    static constexpr int SEG_COUNT = 4;
    vector<int> segments;
    vector<string> ans;
    
    void dfs(const string &s, size_t seg_idx, size_t idx) {
        if (seg_idx == SEG_COUNT) {
            if (idx == s.size()) {
                string ip_str;
                for (size_t i = 0; i < segments.size(); ++i) {
                    ip_str += to_string(segments[i]);
                    if ((i + 1) != SEG_COUNT) {
                        ip_str += '.';
                    }
                }
                ans.push_back(ip_str);
            }
            return;
        }
        
        if (s[idx] == '0') {
            segments[seg_idx] = 0;
            dfs(s, seg_idx + 1, idx + 1);
            return;
        }
        
        int value = 0;
        for (size_t i = idx; i < s.size(); ++i) {
            value = value * 10 + (s[i] - '0');
            if (value > 0 && value <= 0xff) {
                segments[seg_idx] = value;
                dfs(s, seg_idx + 1, i + 1);
            } else {
                break;
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        if (s.size() < 4 || s.size() > 16) return {};
        dfs(s, 0, 0);
        return ans;
    }
};
```