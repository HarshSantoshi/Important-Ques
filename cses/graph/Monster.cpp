#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m ;
    cin>>n>>m;
    vector<vector<char>>grid(n , vector<char>(m,'#'));
    vector<vector<int>>monsterTime(n , vector<int>(m,INT_MAX));
    vector<vector<char>>parent(n , vector<char>(m,'.'));
    queue<pair<int,int>>q;
    int posx = 0 , posy= 0 ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'M'){
                q.push({i,j});
                monsterTime[i][j] = 0;
            }
            if(grid[i][j] == 'A'){
                posx = i;
                posy = j;
                parent[i][j] = 's';
            }
        }
    }
    vector<int>dir = {-1,0,1,0,-1};
    vector<char>dirchar = {'U' , 'R' ,'D','L'};

    int time = 0 ; // 0
    while(q.size()){
        int size = q.size();
        // time ++ ;
        while(size--){
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx = currx + dir[i];
                int newy = curry + dir[i+1];
                if(newx >=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]!='#' && monsterTime[newx][newy] > time + 1){
                    monsterTime[newx][newy] = time + 1;
                    q.push({newx,newy});
                }
            }
        }
        time ++ ;
    }

    q.push({posx,posy});
    time = 0 ;
    while(q.size()){
        int size = q.size();
        // time ++ ;
        while(size--){
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();
            if(currx == n-1 || curry == m-1 || currx == 0 || curry == 0){
                cout<<"YES"<<endl;
                cout<<time<<endl;
                string ans = "";
                while(parent[currx][curry]!='s'){
                    ans.push_back(parent[currx][curry]);
                    char ch = parent[currx][curry];
                    if(ch == 'R'){
                        curry -- ;
                    }
                    else if(ch == 'U'){
                        currx ++ ;
                    }
                    else if(ch == 'D'){
                        currx -- ;
                    }
                    else if(ch == 'L'){
                        curry ++ ;
                    }
                }
                reverse(ans.begin() , ans.end());
                cout<<ans<<endl;
                return 0;
            }
            for(int i=0;i<4;i++){
                int newx = currx + dir[i];
                int newy = curry + dir[i+1];
                if(newx >=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]!='#' && monsterTime[newx][newy] > time + 1 && parent[newx][newy] == '.'){
                    parent[newx][newy] = dirchar[i];
                    q.push({newx,newy});
                }
            }
        }
        time ++ ;
    }

    cout<<"NO"<<endl;
    return 0;


}