class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m=image[0].size();
        queue<pair<int,int>> q;
        
        int org_color = image[sr][sc];
        if(org_color == color) return image;

        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int r=p.first, c=p.second;
            if(r>0 && image[r-1][c]==org_color){
                image[r-1][c]=color;
                q.push({r-1,c});
            } 
            if(r<n-1 && image[r+1][c]==org_color){
                image[r+1][c]=color;
                q.push({r+1,c});
            } 
            if(c>0 && image[r][c-1]==org_color){
                image[r][c-1]=color;
                q.push({r,c-1});
            } 
            if(c<m-1 && image[r][c+1]==org_color){
                image[r][c+1]=color;
                q.push({r,c+1});
            } 
            image[r][c] = color;
        }
        return image;
    }
};