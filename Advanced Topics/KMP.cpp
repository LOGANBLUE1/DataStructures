#include<bits/stdc++.h>
using namespace std;
vector<int> computeTemporaryArray(const string& pattern) {
    vector<int> lps(pattern.size());
    int index = 0;
    for (int i=1;i < pattern.size();) {
        if (pattern[i] == pattern[index]) {
            lps[i++] = ++index;
        } else {
            if (index != 0) {
                index = lps[index - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

bool KMP(const string& text, const string& pattern) {
    vector<int> lps = computeTemporaryArray(pattern);
    int i = 0;
    int j = 0;
    while (i < text.size() && j < pattern.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return j == pattern.size();
}


int main(){
    string str = "abcxabcdabcdabcy";
    string pattern = "abcdabcy";
    bool result = KMP(str, pattern);
    cout << (result ? "true" : "false") << endl;
    return 0;
}