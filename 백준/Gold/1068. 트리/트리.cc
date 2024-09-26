#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
public:
    int id;
    vector<Node*> children;
    Node* parent;

    bool hasParent() {
        return parent != nullptr;
    }

    bool isLeaf() {
        return children.size() == 0;
    }

    void appendChild(Node* child) {
        children.push_back(child);
    }

    bool removeChild(Node* child) {
        int index = -1;

        for (int i = 0; i < children.size(); i++) {
            Node* node = children[i];
            if (node == child) {
                index = i;
                break;
            }
        }

        if (index == -1) return false;

        children.erase(children.begin() + index);

        return true;
    }
};

int main() {
    int rootIndex;
    int numberOfNodes;
    cin >> numberOfNodes;

    vector<Node> nodes;

    for (int i = 0; i < numberOfNodes; i++) {
        nodes.push_back(Node{ i });
    }

    for (int i = 0; i < numberOfNodes; i++) {
        int parentIndex;
        cin >> parentIndex;

        if (parentIndex == -1) {
            rootIndex = i;
            continue;
        }

        Node& node = nodes[i];
        Node& parent = nodes[parentIndex];

        node.parent = &parent;
        parent.appendChild(&node);
    }

    int cutNodeIndex;
    cin >> cutNodeIndex;

    Node& cutNode = nodes[cutNodeIndex];
    if (cutNode.parent == nullptr) {
        cout << 0;
        return 0;
    }
    cutNode.parent->removeChild(&cutNode);

    int numberOfLeafNodes = 0;
    Node& startNode = nodes[rootIndex];
    stack<Node*> dfs;
    dfs.push(&startNode);

    while (!dfs.empty()) {
        Node* node = dfs.top();
        dfs.pop();

        if (node->isLeaf()) {
            numberOfLeafNodes++;
        }
        else {
            for (auto child : node->children) {
                dfs.push(child);
            }
        }
    }

    cout << numberOfLeafNodes;
}