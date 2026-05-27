class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> m;
        int n=word.size();
        for(int i=0; i<n; i++){
            if(isupper(word[i]) && m.count(word[i])==0){
                m[word[i]] = i;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(islower(word[i])){
                if(m.count(toupper(word[i])) == 0) continue; 
                if(m.count(word[i])==0) m[word[i]]=1;
                if(i > m[toupper(word[i])]) m[word[i]] = 0;
            }
        }
        int ans=0;
        for(auto &[c,x] : m){
            if(islower(c)) ans+=x;
        }
        return ans;
    }
};