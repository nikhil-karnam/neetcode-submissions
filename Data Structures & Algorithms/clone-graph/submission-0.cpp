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
    std::unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        if(copies.count(node)){
            return copies[node];
        }
        
        Node* clone = new Node(node->val);
        copies[node] = clone;

        for(Node* n : node->neighbors){
            clone->neighbors.push_back(cloneGraph(n));
        }

        return clone;
    }
};
