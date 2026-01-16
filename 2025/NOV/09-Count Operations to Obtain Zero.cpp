class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1==num2&&num1!=0) return 1;

        int ans=0,x=0;
        if(num1>num2) swap(num1,num2);
        while(num1>0&&num2>0){
            if(num1>num2) swap(num1,num2);
            int x=num2/num1;
            num2-=num1*x;
            ans+=x;
        }
        return ans;
    }
};
