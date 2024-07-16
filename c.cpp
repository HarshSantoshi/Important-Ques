class Solution {
public:
bool able(string s,string t){
    int c=0;
    for(int i=0;i<s.length();i++)
        c+=(s[i]!=t[i]);
    return c==1;
}
void dfs(vector<vector<int>> &paths, vector<int> &path, vector<vector<int>> parent,int node){
    if(node==-1){
        paths.push_back(path);
        return ;
    }
    for(auto u:parent[node]){
        path.push_back(u);
        dfs(paths,path,parent,u);
        path.pop_back();
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int n=wordList.size(),start=-1,end=-1;
    vector<vector<string>> ans;
    for(int i=0;i<n;i++){
        if(wordList[i]==beginWord)
            start=i;
        if(wordList[i]==endWord)
            end=i;
    }
    
    if(end==-1)
        return ans;
    
    if(start==-1){
        wordList.emplace(wordList.begin(),beginWord);
        start=0;
        end++;
        n++;
    }
    vector<vector<int>> adj(n,vector<int>());
    vector<vector<int>>paths;
    
    vector<vector<int>> parent(n);
    vector<int>path;
    
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(able(wordList[i],wordList[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    
    vector <int> dist(n,INT_MAX);
    queue <int> q;
    q.push(start);
    parent[start]={-1};
    dist[start]=0;
    while(!q.empty()){
        int currIdx=q.front();
        q.pop();
        for(int neigh:adj[currIdx]){
            if(dist[neigh]>dist[currIdx]+1){
                dist[neigh]=dist[currIdx]+1;
                q.push(neigh);
                parent[neigh].clear();
                parent[neigh].push_back(currIdx);
            }
            else if(dist[neigh]==dist[currIdx]+1)
                parent[neigh].push_back(currIdx);
        }
    }
    
    dfs(paths,path,parent,end);
    for(auto it:paths){
        vector <string> curr;
        for(int i=0;i<it.size()-1;i++){
            curr.push_back(wordList[it[i]]);
        }
        reverse(curr.begin(),curr.end());
        curr.push_back(wordList[end]);
        ans.push_back(curr);
    }
    return ans;
}
}; 