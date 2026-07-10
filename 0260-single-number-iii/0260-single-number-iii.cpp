class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(int &num:nums) x^=num;
        int y=0;
        int rightmost = (x&(x-1)) ^ x;
        for(int &num : nums){
            if(num & rightmost) y^=num;
        }
        return {y, (int)(x^y)};
    }
};