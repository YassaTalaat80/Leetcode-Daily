class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c);
        for(auto &a : connections){
            int u = a[0]-1, v = a[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(c,0);
        vector<int> comp_id(c); 
        vector<set<int>> comp_nodes; 
        int cnt = 0;

        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            comp_id[u] = cnt;
            comp_nodes[cnt].insert(u);
            for(auto v : adj[u]){
                if(!vis[v]) dfs(v);
            }
        };

        comp_nodes.resize(c);
        for(int i=0;i<c;i++){
            if(!vis[i]){
                dfs(i);
                cnt++;
            }
        }
        vector<bool> online(c, true);
        vector<int> ans;
        for(auto &q : queries){
            int op = q[0], x = q[1]-1; 
            if(op == 1){
                if(online[x]){
                    ans.push_back(x+1); 
                } else {
                    int cid = comp_id[x];
                    if(comp_nodes[cid].empty()){
                        ans.push_back(-1); 
                    } else {
                        ans.push_back(*comp_nodes[cid].begin()+1); 
                    }
                }
            } else {
                online[x] = false;
                int cid = comp_id[x];
                comp_nodes[cid].erase(x); 
            }
        }

        return ans;
    }
};
