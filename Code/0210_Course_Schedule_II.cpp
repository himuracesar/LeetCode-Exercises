class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        vector<int> finalOrder;

        //0 = no visited, 1 = exploring, 2 = visited
        vector<int> status(numCourses, 0);

        stack<int> order;

        for(auto i = 0; i < prerequisites.size(); i++){
            int c1 = prerequisites[i][1];
            int c2 = prerequisites[i][0];
            graph[c1][c2] = 1;
        }

        for(auto i = 0; i < numCourses; i++){
            if(status[i] == 2)
                continue;

            if(!travel(graph, status, order, i))
                return finalOrder;
        }

        while(!order.empty()){
            finalOrder.push_back(order.top());
            order.pop();
        }

        return finalOrder;
    }

    bool travel(vector<vector<int>>& graph, vector<int>& status, stack<int>& order, int numCourse){
        if(status[numCourse] == 1)
            return false;

        status[numCourse] = 1;

        for(auto i = 0; i < graph.size(); i++){
            if(graph[numCourse][i] == 0)
                continue;
            
            if(status[i] != 2)
                if(!travel(graph, status, order, i))
                    return false;
        }

        status[numCourse] = 2;
        order.push(numCourse);

        return true;
    }   
};