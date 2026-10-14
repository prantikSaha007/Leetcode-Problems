class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(num>0) {
            if(sum<=9 && sum>0) ans+=to_string(sum);
            else if(sum>9)ans+=to_string(9);
            else  ans+=to_string(0);
            sum=sum-9;
            num--;
        }
        if(sum>0) return "";
        return ans;
    }
};