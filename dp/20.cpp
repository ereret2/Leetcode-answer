class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                    st.push(s[i]);
                else if (s[i] == '}' || s[i] == ']' || s[i] == ')'){
                    if (st.empty())
                        return false;
                    char tmp = st.top();
                    if (transform(s[i]) != tmp)
                        return false;
                    else
                        st.pop();
                }
            }
        }
        if (st.empty())
            return true;
        return false;
    }

    char transform(char a) {
        if (a == '}')
            return '{';
        if (a == ']')
            return '[';
        if (a == ')')
            return '(';
        return ' ';
    }
};