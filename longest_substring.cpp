#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int lenghtOfLongestSubstring (string s) {

        unordered_map<char, int> m;
        int result = 0, len = s.length();

        for (int i = 0, j = 0; j < len; ++j) {

            if (m.find(s[j]) != m.end()) {
                i = max(m[s[j]], i);
                m.erase (s[j]);
            }

            result = max (result, j-i+1);
            m.insert (make_pair (s[j], j+1));
        }
        return result;
    }
};

int main() {

    Solution obj;

    cout << obj.lenghtOfLongestSubstring("abcabcbb");
    return 0;
}