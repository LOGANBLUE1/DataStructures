#include <bits/stdc++.h>
using namespace std;

class SparseTableRangeMinimumQuery {
private:
    vector<vector<int>> sparse;
    int n;
    vector<int> input;

public:
    SparseTableRangeMinimumQuery(vector<int>& input) : input(input) {
        this->n = input.size();
        this->sparse = preprocess(input, this->n);
    }

    vector<vector<int>> preprocess(vector<int>& input, int n) {
        vector<vector<int>> sparse(n, vector<int>(log2(n) + 1));
        for (int i = 0; i < n; i++) {
            sparse[i][0] = i;
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                if (input[sparse[i][j - 1]] < input[sparse[i + (1 << (j - 1))][j - 1]]) {
                    sparse[i][j] = sparse[i][j - 1];
                } else {
                    sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
                }
            }
        }
        return sparse;
    }

    int rangeMinimumQuery(int low, int high) {
        int l = high - low + 1;
        int k = log2(l);
        if (input[sparse[low][k]] <= input[sparse[low + l - (1<<k)][k]]) {
            return input[sparse[low][k]];
        } else {
            return input[sparse[high - (1<<k) + 1][k]];
        }
    }

private:
    static int log2(int n){
        if(n <= 0) throw invalid_argument("Invalid argument");
        return 31 - __builtin_clz(n);
    }
};

int main() {
    vector<int> input = {2, 5, 3, 6, 4, 1, -1, 3, 4, 2};
    SparseTableRangeMinimumQuery sparseTableRangeMinimumQuery(input);
    for (int i = 0; i < input.size(); i++) {
        for (int j = i; j < input.size(); j++) {
            cout << sparseTableRangeMinimumQuery.rangeMinimumQuery(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}