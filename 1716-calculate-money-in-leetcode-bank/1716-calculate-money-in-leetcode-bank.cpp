class Solution {
public:
int ap(int a,int n){
    return (n*(2*a+n-1))/2;
}
    int totalMoney(int n) {
        int ans=0;
        int fullweeks=n/7;
        int dollar=1;
        int rem=n%7;
        for (int week=1;week<=fullweeks;week++){
            ans+=ap(dollar,7);
            dollar++;
        }
        ans+=ap(dollar++,rem);
        return ans;
    }
};