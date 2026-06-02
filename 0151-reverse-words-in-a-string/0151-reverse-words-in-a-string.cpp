class Solution {
public:
    string reverseWords(string s) {
        int n= s.length();
        int i1=-1,i2=-1;
        for(int i=0; i<n; i++){
            while(i<n && s[i]==' '){
                s.erase(s.begin()+i);
                n--;
            }
            if(i1==-1 && i>0 && i<n && s[i]!=' '){
                s.insert(s.begin()+i, ' ');
                i++;
                n++;
            }
            
            if(i>=n) break;
            if(i1==-1) i1=i;
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