
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
        Node* p1 = new Node(-1);
        Node* p2 = new Node(-1);
        Node* rootReversed = new Node(root->data);
        int h1, h2;
        stack<pair<pair<Node*, Node*>, int>> st;

        st.push({{root, rootReversed}, 0});
        while (!st.empty()) {
            Node* curr = st.top().first.first;
            Node* currReversed = st.top().first.second;
            int currH = st.top().second;

            st.pop();

            if (curr->data == v1) {
                p1 = currReversed;
                h1 = currH;
            }
            if (curr->data == v2) {
                p2 = currReversed;
                h2 = currH;
            }

            if (curr->right) {
                Node* newRightReversed = new Node(curr->right->data);
                newRightReversed->left = currReversed;
                st.push({{curr->right, newRightReversed}, currH + 1});
            }

            if (curr->left) {
                Node* newLeftReversed = new Node(curr->left->data);
                newLeftReversed->left = currReversed;
                st.push({{curr->left, newLeftReversed}, currH + 1});
            }
        }

        if (h1 < h2) {
            swap(h1, h2);
            swap(p1, p2);
        }

        while (h1 > h2) {
            h1--;
            p1 = p1->left;
        }

        while (p1 != p2) {
            p1 = p1->left;
            p2 = p2->left;
        }

        return p1;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    
    int v1, v2;
    std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
    std::cout << ans->data;

    return 0;
}
