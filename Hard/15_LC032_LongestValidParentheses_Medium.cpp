class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indices;
        indices.push(-1);

        int longest = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                indices.push(i);
            } else {
                indices.pop();

                if (indices.empty()) {
                    // This ')' cannot be matched; start after it.
                    indices.push(i);
                } else {
                    longest = max(longest, i - indices.top());
                }
            }
        }

        return longest;
    }
};
