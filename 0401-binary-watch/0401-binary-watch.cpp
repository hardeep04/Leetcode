class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> v;
        for(int h=0; h<12; h++){
            int minLights = turnedOn - __builtin_popcount(h);
            if(minLights<0) continue;
            string hour = to_string(h);

            for(int m=0; m<60; m++){
                if(__builtin_popcount(m) == minLights){
                    if(m<10) v.push_back(hour + ':' + '0' + to_string(m));
                    else v.push_back(hour + ':' + to_string(m));
                }
            }
        }
        return v;
    }
};