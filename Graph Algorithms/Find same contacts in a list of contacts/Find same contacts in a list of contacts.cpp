/* Given a list of contacts containing the username, email and phone number in any order. Identify the same contacts (i.e., the same 
person having many contacts) and output the same contacts together. 

Notes: 
1) A contact can store its three fields in any order, i.e., a phone number can appear before username or username can appear before 
the phone number.
2) Two contacts are the same if they have either the same username or email or phone number. 

Input: contact[] =
     { {"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
       { "Lucky", "lucky@gmail.com", "+1234567"},
       { "gaurav123", "+5412312", "gaurav123@skype.com"}.
       { "gaurav1993", "+5412312", "gaurav@gfgQA.com"}
     }
Output:
   0 2 3
   1
contact[2] is same as contact[3] because they both have same contact number.
contact[0] is same as contact[3] because they both have same e-mail address.
Therefore, contact[0] and contact[2] are also same.
*/

#include <iostream>
#include <vector>

struct contact  
{
    std::string field1, field2, field3;
};

void buildGraph(contact arr[], int n, std::vector<std::vector<int>>& adj)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].field1 == arr[j].field1 ||
                arr[i].field1 == arr[j].field2 ||
                arr[i].field1 == arr[j].field3 ||
                arr[i].field2 == arr[j].field1 ||
                arr[i].field2 == arr[j].field2 ||
                arr[i].field2 == arr[j].field3 ||
                arr[i].field3 == arr[j].field1 ||
                arr[i].field3 == arr[j].field2 ||
                arr[i].field3 == arr[j].field3)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

// Method 1: Using DFS
void DFS(int i, std::vector<std::vector<int>>& adj, std::vector<bool>& visited)
{
    visited[i] = true;
    std::cout << i << " ";

    for (auto& neigh : adj[i])
        if (!visited[neigh])
            DFS(neigh, adj, visited);
}

void findSameContacts(contact arr[], int n)
{
    std::vector<std::vector<int>> adj(n);
    buildGraph(arr, n, adj);

    std::vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj, visited);
            std::cout << std::endl;
        }
    }
}

int main()
{
    contact arr[] = { {"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
                     {"Lucky", "lucky@gmail.com", "+1234567"},
                     {"gaurav123", "+5412312", "gaurav123@skype.com"},
                     {"gaurav1993", "+5412312", "gaurav@gfgQA.com"},
                     {"raja", "+2231210", "raja@gfg.com"},
                     {"bahubali", "+878312", "raja"}
    };

    int n = sizeof arr / sizeof arr[0];
    findSameContacts(arr, n);
    return 0;
}


