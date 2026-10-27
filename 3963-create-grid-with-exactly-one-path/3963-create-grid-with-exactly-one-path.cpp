class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>s;
        
        for(int i=0;i<m;i++) {
            string st="";
            for(int j=0;j<n;j++) {
                if(i==0) {
                    st+='.';
                }
                else if(i>0 && j<n-1) {
                    st+='#';
                } else {
                    st+='.';
                }
            }
            s.push_back(st);
        }
        return s;
    }
};