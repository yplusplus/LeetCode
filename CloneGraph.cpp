/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> que;
        que.push(node);
        map<int, UndirectedGraphNode *> m;
        m[node->label] = root;
        while (!que.empty()) {
            auto u = que.front();
            que.pop();
            auto uu = m[u->label];
            for (auto v : u->neighbors) {
                UndirectedGraphNode *vv = NULL;
                if (m.count(v->label) == 0) {
                    m[v->label] = new UndirectedGraphNode(v->label);
                    que.push(v);
                }
                uu->neighbors.push_back(m[v->label]);
            }
        }
        return root;
    }
};