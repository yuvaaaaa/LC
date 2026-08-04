class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int count =0;
        int n = s.size()-1;
        unordered_map<char,int>mp;

        for(int r=0;r<s.size();r++){

            mp[s[r]]++ ;

            if(mp.size()==3){
                count += n-r+1 ;

                while(mp.size()==3){
                    mp[s[l]]-- ;
                    if(mp[s[l]]==0) mp.erase(s[l]);

                    if(mp.size()==3 ) count += n-r+1 ;

                    l++ ;
                }
            }

        }
        return count ;
    }
};