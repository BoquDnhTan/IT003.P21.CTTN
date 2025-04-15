
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

/* you only have to complete the function given below.  
Node is defined as  

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

*/

    void inOrder(Node *root) {
    	stack<pair<Node*, int>> st;
    	st.push({root, -1});
    	stack<int> outputBuffer;
    	outputBuffer.push(-1);

    	while (!st.empty()) {
    		Node* curr = st.top().first;
    		int t = st.top().second;

    		st.pop();

    		if (~t) {
    			cout << outputBuffer.top() << ' ';
    			outputBuffer.pop();
    		}

    		if (!curr) continue;

    		if (curr->right) {
    		}
    		st.push({curr->right, 0});

    		if (curr->left) {
    			st.push({curr->left, -1});
    		}

    		outputBuffer.push(curr->data);
    	}
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
  
    myTree.inOrder(root);

    return 0;
}