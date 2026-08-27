class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> arr(26, 0);

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            arr[c]++;
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            int c = target[i] - 'a';

            if (arr[c] > 0) {
                ans.push_back(c + 'a');
                arr[c]--;
            }
            else {
                // Find smallest character greater than target[i]
                c++;

                while (c < 26) {
                    if (arr[c] > 0) {
                        ans.push_back(c + 'a');
                        arr[c]--;
                        
                        // Fill remaining characters in sorted order
                        for (int x = 0; x < 26; x++) {
                            while (arr[x] > 0) {
                                ans.push_back(x + 'a');
                                arr[x]--;
                            }
                        }

                        return ans;
                    }
                    c++;
                }

                // No greater character at this position.
                // We need to backtrack.
                break;
            }
        }

        // Backtracking
        for (int i = ans.size() - 1; i >= 0; i--) {

            // Return the character we used at position i
            int current = ans[i] - 'a';
            arr[current]++;

            // Find smallest character greater than target[i]
            int c = target[i] - 'a' + 1;

            while (c < 26) {

                if (arr[c] > 0) {

                    string result = ans.substr(0, i);

                    result.push_back(c + 'a');
                    arr[c]--;

                    // Fill remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        while (arr[x] > 0) {
                            result.push_back(x + 'a');
                            arr[x]--;
                        }
                    }

                    return result;
                }

                c++;
            }
        }

        return "";
    }
};