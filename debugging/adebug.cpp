#include<bits/stdc++.h>
using namespace std;

#define long long int;

void debug(vector<int> &v) {
    for (int i : v) {
        cerr << i << " ";
    }
    cerr << "\n";
}
void debug(vector<int> &v, vector<int> &v2) {
    int a = 0;
    for (int i=0;i<v.size();i++) {
        if(v[i] != v2[i]) {
            cerr << "i=" << i <<  ": "  << v[i] << " != " << v2[i] << "  |  ";
            ++a;
        }
    }
    cerr << "\n";
    cout<< a << " differences found\n";
}

void prettyPrintLinkedList(ListNode* node) {
    while (node && node->next) {
        cout << node->val << "->";
        node = node->next;
    }

    if (node) {
        cout << node->val << endl;
    } else {
        cout << "Empty LinkedList" << endl;
    }
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}


signed main(){
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 0, 4, 5};
    debug(v);
    debug(v, v2);
    return 0;
}