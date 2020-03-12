/*  76. Minimum Window Substring
 *
 *	Given a string S and a string T, find the minimum window in S 
 *	which will contain all the characters in T in complexity O(n).
 *
 * 	Example:
 *
 * 	Input: S = "ADOBECODEBANC", T = "ABC"
 *	Output: "BANC"
 *
 * 	Note:
 *
 * 	If there is no such window in S that covers all characters in T, 
 * 	return the empty string "".
 *	If there is such window, you are guaranteed that there will always 
 *	be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> req;
        for (char ch : t)
            req[ch]++;
        int n = s.size();
        int memo_size = req.size();
        int sastified = 0;
        int first_taken = 0, next_to_take = 0;
        pair<int, int> answer{INT_MAX, 0};

        while (true) {
            if (sastified != memo_size) {
                if (next_to_take == n)
                    break;
                if (--req[s[next_to_take++]] == 0)
                    sastified++;
            }
            else if (req[s[first_taken++]]++ == 0)
                sastified--;
            if (sastified == memo_size)
                answer = min(answer, make_pair(next_to_take - first_taken, first_taken));
        }
        if (answer.first == INT_MAX)
            return "";
        return s.substr(answer.second, answer.first);
    }
};
