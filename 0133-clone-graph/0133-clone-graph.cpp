/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> mp;
    unordered_map<int, bool> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        Node* n;
        if (mp.find(node->val) == mp.end()) {
            n = new Node(node->val);
            mp[node->val] = n;
        } else {
            n = mp[node->val];
        }
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* nn = node->neighbors[i];
            Node* cn;
            if (mp.find(nn->val) == mp.end()) {
                cn = new Node(nn->val);
                mp[nn->val] = cn;
            } else {
                cn = mp[nn->val];
            }
            n->neighbors.push_back(cn);
        }
        visited[node->val] = true;
        cout << node->val << " ";
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* nn = node->neighbors[i];
            if (visited.find(nn->val) == visited.end())
                cloneGraph(nn);
        }
        return n;
    }
};