// LongestCommonPrefix.cpp : 
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

string longestCommonPrefix(vector<string>& strs)
{
    sort(strs.begin(), strs.end());
    if (strs.size() > 0) {
        string start = strs[0];
        string tmp = start;
        int l = 0;
        while (tmp != "") {
            auto start_it = 1;
            bool shorten = false;
            for (; start_it < strs.size(); start_it++) {
                size_t found = strs[start_it].find(tmp);
                if (string::npos == found or found>0) {
                    shorten = true;
                    break;
                }
            }
            if (shorten) {
                l++;
                tmp=start.substr(0, start.size() - l);
            }
            else {
                return tmp;
            }
          
        }
    }
    return "";
}

int main()
{

    vector<string> strs{ "reflower","flow","flight" };
    cout << longestCommonPrefix(strs) << endl;
}