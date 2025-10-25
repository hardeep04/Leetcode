class Solution {
public:
    int totalMoney(int n) {
        int sum=0, j=1;
        for(int i=1; i<=n; i++){
            if(i>7 && i%7==1) j=i/7 + 1;
            sum+=j;
            j++;
        }
        return sum;
    }
};