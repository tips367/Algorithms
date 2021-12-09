/* Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths 
of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code 
and the least frequent character gets the largest code.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>


class MinHeapNode 
{
public:
    char data;
    int freq;
    MinHeapNode* left, * right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

class compare 
{
public:
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode* root, std::string& str)
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

void HuffmanCodes(std::vector<std::pair<char, int>>& characters)
{
    int n = size(characters);

    MinHeapNode* left, * right, * top;
    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> pq;
    for (int i = 0; i < n; ++i)
    {
        MinHeapNode* node = new MinHeapNode(characters[i].first, characters[i].second);
        pq.push(node);
    }

    while (pq.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies. 
        // Make the two extracted node as left and right children of this new node. 
        // Add this node to the min heap, '$' is a special value for internal nodes, not used
        top = new MinHeapNode('#', left->freq + right->freq);

        top->left = left;
        top->right = right;

        pq.push(top);

    }

    std::string str = "";
    printCodes(pq.top(), str);
}

int main()
{
    std::vector<std::pair<char, int>> characters = { {'a', 5}, {'b',9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45} };

    HuffmanCodes(characters);

    return 0;
}

