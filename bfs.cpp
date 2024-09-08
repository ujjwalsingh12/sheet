class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        queue<int> q;
        vector<int> v;
        q.push(0);
        while(!q.empty()){
            visited[q.front()] =1 ;
            for(int i: adj[q.front()]){
                if(!visited[i]){
                    visited[i] =1 ;
                    q.push(i);
                }
            }
            v.push_back(q.front());
            q.pop();
            
            
        }
        return v;
    }
};