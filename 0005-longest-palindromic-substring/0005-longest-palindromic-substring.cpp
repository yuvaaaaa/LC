// class Solution {
// public:
//     bool ispalin(string s) {
//         int n = s.size();
//         int back = n - 1;

//         for (int i = 0; i < n / 2; i++) {
//             if (s[i] != s[back]) {
//                 return false;
//             }
//             back--;
//         }
//         return true;
//     }

//     string longestPalindrome(string s) {
//         int n = s.size();

//         if (n == 1) {
//             return s;
//         }

//         string res = "";
//         int mx = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = n; j > i; j--) {
//                 string str = s.substr(i, j - i);

//                 if (str.size() > mx && ispalin(str)) {
//                     mx = str.size();
//                     res = str;
//                 }
//             }
//         }

//         return res;
//     }
// };


class Solution {
public:
    string expand(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            
            // odd length
            string odd = expand(s, i, i);

            // even length
            string even = expand(s, i, i + 1);

            if (odd.size() > ans.size()) {
                ans = odd;
            }

            if (even.size() > ans.size()) {
                ans = even;
            }
        }

        return ans;
    }
};
