class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0,x=0,a=n;
        while(n){
            x=n%10;
            rev=rev*10+x;
            n/=10;
        }
        return abs(rev-a);
    }
};