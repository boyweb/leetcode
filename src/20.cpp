#include "leetcode_header.h"

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        string::iterator it = s.begin();

        while (it != s.end())
        {
            switch (*it)
            {
            case '(':
            case '{':
            case '[':
                stack.push(*it);
                break;
            case ')':
                if (stack.size() == 0 || stack.top() != '(')
                {
                    return false;
                }
                stack.pop();
                break;
            case '}':
                if (stack.size() == 0 || stack.top() != '{')
                {
                    return false;
                }
                stack.pop();
                break;
            case ']':
                if (stack.size() == 0 || stack.top() != '[')
                {
                    return false;
                }
                stack.pop();
                break;
            }
            it++;
        }

        return stack.size() == 0;
    }
};