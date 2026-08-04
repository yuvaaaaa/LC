class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int count =0;

        int fl =0;
        int fr = s.size() +2;

        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++ ;
        }

        for(r=0;r<s.size();r++){
            if(mp[s[r]]>0){
                count ++ ;
            }
                mp[s[r]]-- ;

            while(count == t.size()){
                if(fr-fl+1 > r-l+1){
                    fr= r;
                    fl = l;
                }

                mp[s[l]]++ ;
                if(mp[s[l]]>0) count -- ;
                l++ ;

            }
        }
        if(fr >s.size() ){
            string h = "";
            return h;
        }
        string ans = s.substr(fl, fr-fl+1);
        return ans ;
    }
};