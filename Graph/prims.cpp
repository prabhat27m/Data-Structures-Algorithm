# include<iostream>
# include<vector>
# include<queue>
// **** ========Minimum cost to make all points connected (Greedy)======****
using namespace std;

int Prims(vector<pair<int,int>>adj[], int src, int V) {

    int sum=0;
    vector<int>vis(V,0);

    // priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>>pq;
    priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int>>> pq;

    pq.push({0,src});
    
    while(!pq.empty()){
        auto curr = pq.top();

        pq.pop();

        int weight = curr.first;
        int node = curr.second;

        if(vis[node]==1) continue;
        
        vis[node]=1;
        sum+=weight;
        for(auto it : adj[node]){
            int edgeNode = it.first;
            int edW = it.second;
            if(!vis[edgeNode]){
                pq.push({edW,edgeNode});
            }
        }
    }
    return sum;
}

void addEdge(int v1, int v2, int w, vector<pair<int,int>>adj[]){
    adj[v1].push_back({v2, w});
    adj[v2].push_back({v1,w});
}

int main(){
    int V =5;
    vector<pair<int,int>>adj[V];

    addEdge(0,1,2, adj);
    addEdge(0,2,1, adj);
    addEdge(1,2,1, adj);
    addEdge(2,3,2, adj);
    addEdge(3,4,1, adj);
    addEdge(4,2,2, adj);

    cout<<Prims(adj,0,V)<<endl;
    return 0;
}