#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    string name;
    bool isLocked = false;
    int id = 0;                  // user ID who locked this node
    TreeNode* parent = nullptr;
    int anc_locked = 0;          // number of locked ancestors
    int des_locked = 0;          // number of locked descendants
    vector<TreeNode*> children;
    
    TreeNode(const string& _name, TreeNode* _parent)
    : name(_name), parent(_parent) {}
};

void informDescendants(TreeNode* node, int delta) {
    if (!node) return;
    // Update ancestor-lock count for this node
    node->anc_locked += delta;
    // Propagate to children
    for (TreeNode* child : node->children) {
        informDescendants(child, delta);
    }
}

bool lockNode(TreeNode* node, int userId) {
    // Cannot lock if already locked or if any ancestor/descendant is locked
    if (node->isLocked) return false;
    if (node->anc_locked > 0 || node->des_locked > 0) return false;

    // Increment des_locked count up the chain of ancestors
    TreeNode* cur = node->parent;
    while (cur) {
        cur->des_locked += 1;
        cur = cur->parent;
    }

    // Increment anc_locked for all descendants
    informDescendants(node, +1);

    node->isLocked = true;
    node->id = userId;
    return true;
}

bool unlockNode(TreeNode* node, int userId) {
    // Can only unlock if this node is locked and owned by the same user
    if (!node->isLocked || node->id != userId) return false;

    // Decrement des_locked count up the chain of ancestors
    TreeNode* cur = node->parent;
    while (cur) {
        cur->des_locked -= 1;
        cur = cur->parent;
    }

    // Decrement anc_locked for all descendants
    informDescendants(node, -1);

    node->isLocked = false;
    node->id = 0;
    return true;
}

bool upgradeNode(TreeNode* node, int userId) {
    // Cannot upgrade if this node is already locked
    // or if any ancestor is locked, or if no locked descendants exist
    if (node->isLocked || node->anc_locked > 0 || node->des_locked == 0) {
        return false;
    }

    // Gather all locked descendants owned by the same user
    vector<TreeNode*> lockedDescendants;
    bool allMatch = getAllLockedDescendants(node, lockedDescendants, userId);
    if (!allMatch) {
        // Found a locked descendant that belongs to a different user
        return false;
    }

    // Lock this node: first update ancestor/descendant counts
    TreeNode* cur = node->parent;
    while (cur) {
        cur->des_locked += 1;
        cur = cur->parent;
    }
    informDescendants(node, +1);

    // Unlock all collected descendants
    for (TreeNode* desc : lockedDescendants) {
        unlockNode(desc, userId);
    }

    node->isLocked = true;
    node->id = userId;
    return true;
}

bool getAllLockedDescendants(TreeNode* node, vector<TreeNode*>& lockedList, int userId) {
    if (!node) return true;

    if (node->isLocked) {
        if (node->id != userId) {
            // Found a locked descendant owned by a different user
            return false;
        } else {
            lockedList.push_back(node);
        }
    }

    // If no locked descendants under this subtree, we can short-circuit
    if (node->des_locked == 0) {
        return true;
    }

    for (TreeNode* child : node->children) {
        if (!getAllLockedDescendants(child, lockedList, userId)) {
            return false;
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> nodeNames(n);
    for (int i = 0; i < n; i++) {
        cin >> nodeNames[i];
    }

    vector<string> queries;
    string line;
    // Read all queries until EOF or newline
    // Each query will be in the form: "<type> <nodeName> <userId>"
    // type = 1 (lock), 2 (unlock), 3 (upgrade)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (std::getline(cin, line)) {
        if (!line.empty()) {
            queries.push_back(line);
        }
    }

    // Build the tree in level-order with branching factor m
    // Root is nodeNames[0]
    unordered_map<string, TreeNode*> nodeMap;
    TreeNode* root = new TreeNode(nodeNames[0], nullptr);
    nodeMap[nodeNames[0]] = root;

    queue<TreeNode*> q;
    q.push(root);
    int idx = 1;

    while (!q.empty() && idx < n) {
        TreeNode* parent = q.front();
        q.pop();

        for (int i = 0; i < m && idx < n; i++) {
            TreeNode* child = new TreeNode(nodeNames[idx], parent);
            parent->children.push_back(child);
            nodeMap[nodeNames[idx]] = child;
            q.push(child);
            idx++;
        }
    }

    // Process each query
    for (const string& qry : queries) {
        stringstream ss(qry);
        int type, userId;
        string nodeName;
        ss >> type >> nodeName >> userId;

        bool result = false;
        TreeNode* target = nodeMap[nodeName];
        if (!target) {
            // Node not found; default to false
            result = false;
        } else {
            if (type == 1) {
                result = lockNode(target, userId);
            } else if (type == 2) {
                result = unlockNode(target, userId);
            } else if (type == 3) {
                result = upgradeNode(target, userId);
            }
        }

        cout << (result ? "true" : "false") << "\n";
    }

    // Cleanup allocated nodes
    for (auto& kv : nodeMap) {
        delete kv.second;
    }
    return 0;
}
