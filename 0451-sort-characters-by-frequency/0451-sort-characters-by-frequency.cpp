class Solution {
public:
    static bool compare(const pair<int, char>& a, const pair<int, char>& b){
        return a.first > b.first;
    }
    string frequencySort(string s) {
        int n=s.length();
        vector<pair<int,char>> v(62);
        char c = 'A';
        for(int i=0; i<26; i++){
            v[i] = {0, c};
            c++;
        }
        c = 'a';
        for(int i=26; i<52; i++){
            v[i] = {0, c};
            c++;
        }
        c = '0';
        for(int i=52; i<62; i++){
            v[i] = {0, c};
            c++;
        }
        for(int i=0; i<n; i++){
            if(isupper(s[i])) v[s[i]-'A'].first++;
            else if(islower(s[i])) v[s[i]-'a'+26].first++;
            else v[s[i]-'0'+52].first++;
        }
        sort(v.begin(), v.end(), compare);
        string t;
        for(int i=0; i<62; i++){
            int f = v[i].first; 
            while(f--){
                t+=v[i].second;
            }
        }
        return t;
    }
};