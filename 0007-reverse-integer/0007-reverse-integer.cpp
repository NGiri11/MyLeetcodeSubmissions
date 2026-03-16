class Solution {
public:
    int reverse(int x) {
        long int rem=0,rev=0;
        while(x){
            rem=x%10;
            rev=rev*10+rem;
            x/=10;
            if(rev>2147483647 || rev<-2147483648){
                return 0;
            }
        }
        return rev;
    }
};