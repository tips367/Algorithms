/* Given a sorted dictionary (array of words) of an alien language, find order of characters in the language. 
Examples:

Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input:  words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b'

*/

#include <iostream>
#include <list>
#include <stack>

class Graph
{
    int V;    
    std::list<int>* adj;
    void topologicalSortUtil(int v, bool visited[], std::stack<int>& st);
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}

void Graph::topologicalSortUtil(int v, bool visited[], std::stack<int>& st)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, st);

    // Push current vertex to stack which stores result
    st.push(v);
}

void Graph::topologicalSort()
{
    std::stack<int> st;

    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, st);

    // Print contents of stack
    while (!st.empty())
    {
        std::cout << (char)('a' + st.top()) << " ";
        st.pop();
    }
}

void printOrder(std::string words[], int n, int alpha)      // n is size of words[]. alpha is set of possible alphabets.
{
    // Create a graph with 'alpha' edges
    Graph g(alpha);

    // Process all adjacent pairs of words and create a graph
    for (int i = 0; i < n - 1; i++)
    {
        std::string word1 = words[i], word2 = words[i + 1];
        for (int j = 0; j < std::min(word1.length(), word2.length()); j++)
        {
            // If we find a mismatching character, then add an edge from character of word1 to that of word2
            if (word1[j] != word2[j])
            {
                g.addEdge(word1[j] - 'a', word2[j] - 'a');
                break;
            }
        }
    }

    g.topologicalSort();
}

int main()
{
    std::string words[] = { "baa", "abcd", "abca", "cab", "cad" };
    printOrder(words, 5, 4);
    return 0;
}


