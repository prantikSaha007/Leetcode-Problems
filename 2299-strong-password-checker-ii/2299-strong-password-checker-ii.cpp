class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n=password.size();
        if(n<8) return false;
        int upper=0,lower=0,digit=0,spe=0;
        string special="!@#$%^&*()-+";
        
        for(int i=0;i<n;i++) {
            if(i>0) {
                if(password[i-1]==password[i]) return false;
            }
            if(password[i]>='a'&& password[i]<='z') lower++;
            if(password[i]>='A' && password[i]<='Z') upper++;
            if(password[i]>='0' && password[i]<='9') digit++;
            for(auto& ch:special) {
                if(ch==password[i]) spe++;
            }
        }
        if(lower>0 && upper>0 &&digit>0 && spe>0) return true;
        return false;
    }
};