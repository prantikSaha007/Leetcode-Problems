class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1;
        int curr=n;
        while(n>0) {
            int a=n%10;
            sum+=a;
            prod*=a;
            n=n/10;
        }
        int ans=sum+prod;
        if(curr%ans==0) return true;
        return false;
    }
};