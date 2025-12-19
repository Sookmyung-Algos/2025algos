#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node
{
    map<string, Node*> children;
};

void DFS(Node* node, int level)
{
    for (auto child : node->children) 
    {
        for (int i = 0; i < level; ++i) 
            cout << "--";
        
        cout << child.first << '\n';
        DFS(child.second, level + 1);
    }
}

int main() 
{
    int N;
    cin >> N;
    Node* root = new Node();

    while (N--)
    {
        int K;
        cin >> K;
        vector<string> arr(K);

        for (int j = 0; j < K; j++) 
            cin >> arr[j];

        Node* temp = root;

        for (const auto& str : arr) 
        {
            if (temp->children.count(str) == 0) 
                temp->children[str] = new Node();
            
            temp = temp->children[str];
        }
    }

    DFS(root, 0);
}
