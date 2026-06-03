class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        int n=s.length();
        if(n!=t.length()) return 0;
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        for(int i=0; i<n; i++){
            if(m.find(t[i])==m.end()) return 0;
            m[t[i]]--;
        }
        for(auto i:m){
            if(i.second!=0) return 0;
        }
        return 1;
    }
};