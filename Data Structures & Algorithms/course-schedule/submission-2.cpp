class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> link(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < (int)prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            link[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> sol;
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            sol.push_back(c);

            for(int i = 0; i < (int)link[c].size(); i++) {
                int lc = link[c][i];

                indegree[lc]--;
                if(indegree[lc] == 0)
                    q.push(lc);
            }
        }

        if((int)sol.size() == numCourses)
            return true;
        

        return false;
    }
};
