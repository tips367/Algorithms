/* Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths 
of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code 
and the least frequent character gets the largest code.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>


class QueueNode
{
public:
    char data;
    int freq;
    QueueNode* left, * right;

    QueueNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

void printCodes(QueueNode* root, std::string& str)
{
    if (!root)
        return;

    if (root->data != '#')
        std::cout << root->data << ": " << str << "\n";

    str.push_back('0');
    printCodes(root->left, str);
    str.pop_back();
    str.push_back('1');
    printCodes(root->right, str);
    str.pop_back();
}

QueueNode* getMin(std::queue<QueueNode*>& q1, std::queue<QueueNode*>& q2)
{
    if (q1.empty())
    {
        QueueNode* m = q2.front();
        q2.pop();
        return m;
    }
    if (q2.empty())
    {
        QueueNode* m = q1.front();
        q1.pop();
        return m;
    }

    QueueNode* m = q2.front(); 
    QueueNode* n = q1.front();
    if (m->freq < n->freq)
    {
        q2.pop();
        return m;
    }
    q1.pop();
    return n;
}

// Time complexity : O(n)
void HuffmanCodes(std::vector<std::pair<char, int>>& characters)
{
    int n = size(characters);

    QueueNode* left, * right, * top;
    std::queue<QueueNode* > q1, q2;

    // Create a leaf node for each unique character and Enqueue it to the first queue in non-decreasing
    // order of frequency. Initially second queue is empty
    for (int i = 0; i < n; ++i)
    {
        q1.push(new QueueNode(characters[i].first, characters[i].second));
    }

    // Run while Queues contain more than one node. Finally, first queue will be empty and second queue will
    // contain only one node
    while (!(q1.empty() && q2.size() == 1) )  
    {
        // Dequeue two nodes with the minimum frequency by examining the front of both queues
        left = getMin(q1, q2);
        right = getMin(q1, q2);

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies. 
        // Make the two extracted node as left and right children of this new node. 
        // Add this node to the second queue, '#' is a special value for internal nodes, not used
        top = new QueueNode('#', left->freq + right->freq);

        top->left = left;
        top->right = right;

        q2.push(top);
    }

    std::string str = "";
    printCodes(q2.front(), str);
}

int main()
{
    std::vector<std::pair<char, int>> characters = { {'a', 5}, {'b',9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45} };

    HuffmanCodes(characters);

    return 0;
}

