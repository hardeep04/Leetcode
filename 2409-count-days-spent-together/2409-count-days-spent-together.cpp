class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        if(arriveBob > leaveAlice || arriveAlice > leaveBob) return 0;

        vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
        int B_arriveMon = stoi(arriveBob.substr(0,2));
        int B_arriveDay = stoi(arriveBob.substr(3,2));
        int B_leaveMon = stoi(leaveBob.substr(0,2));
        int B_leaveDay = stoi(leaveBob.substr(3,2));

        int A_arriveMon = stoi(arriveAlice.substr(0,2));
        int A_arriveDay = stoi(arriveAlice.substr(3,2));
        int A_leaveMon = stoi(leaveAlice.substr(0,2));
        int A_leaveDay = stoi(leaveAlice.substr(3,2));
        
        if(arriveBob > arriveAlice){
            if(leaveBob <= leaveAlice){
                // return bob span
                if(B_arriveMon == B_leaveMon) return B_leaveDay - B_arriveDay + 1;
                int ans=v[B_arriveMon-1] - B_arriveDay + 1 + B_leaveDay;
                for(int i=B_arriveMon + 1; i<B_leaveMon; i++) ans+=v[i-1];
                return ans;
            }
            else{
                // return start bob , to leave alice 
                if(B_arriveMon == A_leaveMon) return A_leaveDay - B_arriveDay + 1;
                
                int ans=v[B_arriveMon-1] - B_arriveDay + 1 + A_leaveDay;
                for(int i=B_arriveMon + 1; i<A_leaveMon; i++) ans+=v[i-1];
                return ans;
            }
        }
        else{
            if(leaveBob <= leaveAlice){
                // return alice to bob
                if(A_arriveMon == B_leaveMon) return B_leaveDay - A_arriveDay + 1;
                
                int ans=v[A_arriveMon-1] - A_arriveDay + 1 + B_leaveDay;
                for(int i=A_arriveMon + 1; i<B_leaveMon; i++) ans+=v[i-1];
                return ans;
            }
            else{
                // return alice span
                if(A_arriveMon == A_leaveMon) return A_leaveDay - A_arriveDay + 1;
                
                int ans=v[A_arriveMon-1] - A_arriveDay + 1 + A_leaveDay;
                
                for(int i=A_arriveMon + 1; i<A_leaveMon; i++) ans+=v[i-1];
                return ans;
            }
        }
        return 0;
    }
};