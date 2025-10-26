class Bank {
public:
    vector<long long> b;
    int n;
    Bank(vector<long long>& balance) {
        b=balance;
        n = b.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > n || account2 < 1 || account2 > n) return 0;
        if(b[account1-1]>=money){
            b[account2-1] += money;
            b[account1-1] -= money;
            return 1;
        }
        return 0;
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > n) return 0;
        b[account-1]+=money;
        return 1;        
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > n) return 0;
        if(b[account-1]<money) return 0;
        b[account-1]-=money;
        return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */