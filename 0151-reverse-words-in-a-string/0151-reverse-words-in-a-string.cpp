class Solution {
public:
    string reverseWords(string s) {
        int i1=-1,i2=-1;
        while(s[0]==' ') s.erase(s.begin());
        while(s.back()==' ') s.pop_back();
        int n= s.length();
        for(int i=0; i<n-1; i++){
            if(s[i]==' ' && s[i+1]==' '){
                s.erase(s.begin()+i+1);
                n--;
                i--;
            }
        }           
        for(int i=0; i<n; i++){
            if(i>=n) break;
            if(i1==-1 && i==0) i1=i;
            else if(i1==-1 && i<n-1) i1=i+1;
            if(i2==-1 && (i==n-1 || s[i+1]==' ')){
                i2=i;
                reverse(s.begin()+i1, s.begin()+i2+1);
                i1=-1; i2=-1;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};