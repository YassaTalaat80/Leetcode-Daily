class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char tar) {
        char ans=v[0];
            for(int i=0;i<v.size();i++){
                if(v[i]>tar){
                    ans=v[i];
                    break;
                }
            }
            return ans;
    }
};
