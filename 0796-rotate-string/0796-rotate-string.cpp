class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return 0;
        string t = s + s;
        return t.find(goal) != string::npos;
    }
};