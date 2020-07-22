class parenthesesString {
 public:
  string str;
  int openCount = 0;   // open parentheses count
  int closeCount = 0;  // close parentheses count

  parenthesesString(const string &s, int openCount, int closeCount) {
    this->str = s;
    this->openCount = openCount;
    this->closeCount = closeCount;
  }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        queue<parenthesesString> queue;

        queue.push(parenthesesString("(", 1, 0));
        while (!queue.empty()) {
            parenthesesString tmp = queue.front();
            queue.pop();

            if (tmp.openCount == n && tmp.closeCount == n) {
                res.push_back(tmp.str);
            }
            else {
                if (tmp.openCount < n) {
                    queue.push(parenthesesString(tmp.str + "(", tmp.openCount + 1, tmp.closeCount));
                }

                if (tmp.openCount > tmp.closeCount) {
                    queue.push(parenthesesString(tmp.str + ")", tmp.openCount, tmp.closeCount + 1));
                }
            }
        }
        return res;
    }
};