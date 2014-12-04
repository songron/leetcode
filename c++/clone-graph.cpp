//https://oj.leetcode.com/problems/clone-graph/

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
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapper;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        mapper[node] = newNode;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for (int i = 0; i < cur->neighbors.size(); i++) {
                UndirectedGraphNode *temp = cur->neighbors[i];
                if (mapper.find(temp) == mapper.end()) {
                    mapper[temp] = new UndirectedGraphNode(temp->label);
                    q.push(temp);
                }
                mapper[cur]->neighbors.push_back(mapper[temp]);
            }
        }

        return newNode;
    }
};
                
