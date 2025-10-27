class Bank {
public:
    vector<long long> acc;
    int n;
    Bank(vector<long long>& balance) {
        acc = balance;
        n=acc.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n) 
            return false;
        if(acc[account1-1] < money) 
            return false;
        acc[account1-1] -= money;
        acc[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n )
            return false;
        acc[account-1]+=money;
        return true;
    }
    
    
    bool withdraw(int account, long long money) {
        if(account > n)
            return false;
        if(acc[account-1] < money)
            return false;   
        acc[account-1] -= money;
        return true;
    }
};