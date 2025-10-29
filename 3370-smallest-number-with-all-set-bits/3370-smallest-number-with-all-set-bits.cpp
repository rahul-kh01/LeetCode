class Solution {
public:
    int smallestNumber(int n) {
        int a=1;
        while(n){
            a*=2;
            n/=2;
        }
        return a-1;
    }
};