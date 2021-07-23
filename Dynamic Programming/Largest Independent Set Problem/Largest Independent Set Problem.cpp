/* Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an 
independent set if there is no edge between any two nodes of the subset. 

For example, consider the following binary tree. The largest independent set(LIS) is {10, 40, 60, 70, 80} 
and size of the LIS is 5.

            10
           /  \
        20     30
       / \      \
     40  50     60
         / \
        70  80
*/

#include <iostream>
#include <unordered_map>

class Node
{
public:
    int data;
    Node* left, * right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Method 1: Time complexity : Exponential
/*
int largestIndependentSet(Node* root)
{
    // base case: empty tree
    if (root == NULL) 
    {
        return 0;
    }

    // Case 1: Exclude the current node from the maximum independent set and recur for its left and right child
    int excl = largestIndependentSet(root->left) + largestIndependentSet(root->right);

    // Case 2: Include the current node in the maximum independent set and recur for its grandchildren
    int incl = 1;

    if (root->left) 
    {
        incl += largestIndependentSet(root->left->left) + largestIndependentSet(root->left->right);
    }

    if (root->right) 
    {
        incl += largestIndependentSet(root->right->left) + largestIndependentSet(root->right->right);
    }

    // return the maximum number of nodes possible by either including or excluding the current node
    return std::max(excl, incl);
} */

// Method 2: Dynamic programming [Memoization].....Time complexity : O(n)
int largestIndependentSetUtil(Node* root, std::unordered_map<Node*, int>& map)
{
    // base case: empty tree
    if (root == NULL)
    {
        return 0;
    }

    if (map.find(root) != map.end()) 
    {
        return map[root];
    }

    // Case 1: Exclude the current node from the maximum independent set and recur for its left and right child
    int excl = largestIndependentSetUtil(root->left, map) + largestIndependentSetUtil(root->right, map);

    // Case 2: Include the current node in the maximum independent set and recur for its grandchildren
    int incl = 1;

    if (root->left)
    {
        incl += largestIndependentSetUtil(root->left->left, map) + largestIndependentSetUtil(root->left->right, map);
    }

    if (root->right)
    {
        incl += largestIndependentSetUtil(root->right->left, map) + largestIndependentSetUtil(root->right->right, map);
    }

    // save and return the maximum number of nodes possible by either including or excluding the current node
    map[root] = std::max(excl, incl);
    return map[root];
}

int largestIndependentSet(Node* root)
{
    std::unordered_map<Node*, int> map;
    return largestIndependentSetUtil(root, map);
}

int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->right->right = new Node(60);

    std::cout << "Size of the Largest Independent Set is " << largestIndependentSet(root);

    return 0;
}

