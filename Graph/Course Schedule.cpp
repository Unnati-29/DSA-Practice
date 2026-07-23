class Solution {
public:
    bool isCycle(int src,vector<bool>& recPath,vector<bool>& vis,vector<vector<int>>& prerequisites){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0;i<prerequisites.size();i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,recPath,vis,prerequisites)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);

        for(int i =0 ;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i, recPath, vis, prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};
