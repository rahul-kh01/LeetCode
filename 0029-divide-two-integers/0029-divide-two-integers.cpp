class Solution {
public:
    int divide(int dividend, int divisor) {
        
        //Handling corner cases
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        
        //Converting divisors and dividend to their positive values
        long int b = abs(dividend), a = abs(divisor);
        
        //Result Variables
        int res=0;
        while(a<=b) {
            long int mul=a, tmp=1;
            while(mul<=b-mul) {
                mul+=mul;
                tmp+=tmp;
            }
            res+=tmp;
            b-=mul;
        }
        
        //If either of dividend or divisor is negative our result will be negative
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -res;
        
        return res;
        
    }
};