class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0,p=1;
        int temp=n;
        while(temp){
            int digit=temp%10;
            s+=digit;
            p*=digit;
            temp=temp/10;
        }
        //cout<<s<<" "<<p<<'\n';
        if(n%(s+p)==0){
            return true;
        }
        return false;
    }
};
