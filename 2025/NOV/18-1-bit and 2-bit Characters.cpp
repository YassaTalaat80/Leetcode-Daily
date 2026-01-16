class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int last=bits[0];
        bool ok=true;
        for(int i=1;i<n;i++){
            if(last==0) last=bits[i];
            else{
                if(i+1<n) last=bits[i+1],i++;
                else last=1;
            }
        }
        return last==0;
    }
};
