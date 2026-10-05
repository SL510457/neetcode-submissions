class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> link(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> order;
        
        for(int i = 0; i < n; i++) {
            indegree[prerequisites[i][0]]++;
            link[prerequisites[i][1]].push_back(prerequisites[i][0]);
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
            order.push_back(c);

            for(int i = 0; i < (int)link[c].size(); i++) {
                indegree[link[c][i]]--;
                if(indegree[link[c][i]] == 0)
                    q.push(link[c][i]);
            }
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] != 0) {
                return {};
            }
        }

        return order;
    }
};
