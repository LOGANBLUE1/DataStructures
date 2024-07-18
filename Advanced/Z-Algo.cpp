#include <bits/stdc++.h>
using namespace std;

// Function to calculate the Z-array
vector<int> calculateZ(const string& input) {
    int n = input.size();
    vector<int> Z(n);
    int left = 0, right = 0;
    for (int k = 1; k < n; ++k) {
        if (k > right) {
            left = right = k;
            while (right < n && input[right] == input[right - left]) {
                right++;
            }
            Z[k] = right - left;
            right--;
        } else {
            int k1 = k - left;
            if (Z[k1] < right - k + 1) {
                Z[k] = Z[k1];
            } else {
                left = k;
                while (right < n && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            }
        }
    }
    return Z;
}

// Function to return list of all indices where pattern is found in text
vector<int> matchPattern(const string& text, const string& pattern) {
    string newString = pattern + '$' + text;
    vector<int> Z = calculateZ(newString);
    vector<int> result;
    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == pattern.size()) {
            result.push_back(i - pattern.size() - 1);
        }
    }
    return result;
}

int main() {
    string text = "aaabcxyzaaaabczaaczabbaaaaaabc";
    string pattern = "aaabc";
    vector<int> result = matchPattern(text, pattern);
    for (int idx : result) {
        cout << idx << endl;
    }
    return 0;
}
