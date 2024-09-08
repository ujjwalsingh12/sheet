    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        stack<int> st;
        vector<bool> visited(V,0);
        vector<int> ans;
        st.push(0);
        while(!st.empty()){
            int t = st.top();
            if(!visited[t])
            ans.push_back(t);
            visited[t] = 1;
            st.pop();
            for(int i=adj[t].size()-1;i>=0;i--){
                    if(!visited[adj[t][i]])
                    st.push(adj[t][i]);
                }
            }
        return ans;
        
        
    }
};