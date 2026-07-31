class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;
        st.push(ast[0]);
        for(int i=1; i<n; i++){
            while(1){
                if(st.empty()){
                    st.push(ast[i]);
                    break;
                }
                if(!st.empty() && ((ast[i]>0 && st.top()>0) || (ast[i]<0 && st.top()<0) || (ast[i]>0 && st.top()<0))){
                    st.push(ast[i]); break;
                }
                else{
                    if(!st.empty() && st.top() == abs(ast[i])){
                        st.pop(); break;
                    }
                    else if(!st.empty() && st.top() < abs(ast[i])){
                        st.pop();
                    }
                    else break;
                }
            }
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};