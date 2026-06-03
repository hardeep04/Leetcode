class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        while(n--){
            char c=s[0];
            s.erase(s.begin());
            s+=c;
            if(s==goal) return 1;
        }
        return 0;
    }
};