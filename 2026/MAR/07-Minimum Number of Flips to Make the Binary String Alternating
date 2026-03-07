class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
	string t= s + s;
	int dif1 = 0 ,dif2 = 0;
	int ans = 1e9;
	for (int i = 0;i < 2*n; i++) {
		
		char c1 = (i % 2 == 0)? '0' : '1';
		char c2 = (i % 2 == 0) ? '1' : '0';

		if(t[i] != c1) dif1++;
		if(t[i] != c2 ) dif2++;

		if(i >= n){
			char c11=((i-n)%2==0)?'0':'1';
			char c21 =((i-n)%2==0)?'1':'0';

			if(t[i-n]!=c11) dif1--;
			if(t[i-n]!=c21) dif2--;
		}

		if(i >= n-1) 
			 ans = min(ans, min(dif1, dif2 ));
	}
    return ans;
    }
};
