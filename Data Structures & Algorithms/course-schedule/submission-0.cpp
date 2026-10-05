class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> link(numCourses);
        vector<int> indegree(numCourses,0);
        
        for(int i = 0; i < n; i++) {
            indegree[prerequisites[i][1]]++;
            link[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int c = q.front();
            q.pop();


            for(int i = 0; i < (int)link[c].size(); i++) {
                indegree[link[c][i]]--;
                if(indegree[link[c][i]] == 0)
                    q.push(link[c][i]);
            }
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
