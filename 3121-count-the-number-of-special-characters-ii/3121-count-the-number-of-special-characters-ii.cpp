class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        vector<int> last_lower(26, -1), first_upper(26, -1);
        
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (islower(ch)) last_lower[ch - 'a'] = i;
            else {
                if (first_upper[ch - 'A'] == -1) first_upper[ch - 'A'] = i;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (last_lower[i] != -1 && first_upper[i] != -1 &&
            last_lower[i] < first_upper[i]) {
                ans++;
            }
        }        
        return ans;
    }
};