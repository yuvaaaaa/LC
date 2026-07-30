class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans =0 ;

        // set<char>st ;
        // for(int i=0;i<n;i++){
        //     st.insert(word[i]);
        // }

        int size =n;
        int rem = size%8 ;
        int loop = size/8 ;
        int i=0;
        for(i=1;i<=loop;i++){
            ans += i * 8 ;
        }

        ans += rem *i ;
        return ans ;

        // const int n = word.size();
        // return n + max(n - 8, 0) + max(n - 16, 0) + max(n - 24, 0);
    }
};