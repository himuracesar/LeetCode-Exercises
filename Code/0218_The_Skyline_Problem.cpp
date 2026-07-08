class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> points;

        priority_queue<vector<int>> pq;

        points.push_back({ buildings[0][0], buildings[0][2] });
        pq.push({ buildings[0][2], buildings[0][1] });

        bool openEntry = true;

        for(auto i = 1; i < buildings.size(); i++){
            while(!pq.empty() && pq.top()[1] < buildings[i][0]){
                vector<int> pqe = pq.top();
                pq.pop();

                int size = points.size();
                if(points[size-1][0] < pqe[1]){
                    if(!openEntry){
                        points[size-1][1] = pqe[0];
                    }

                    points.push_back({ pqe[1], pqe[0] });
                    openEntry = false;
                }
            }

            int size = points.size();

            if(openEntry && points[size-1][0] == buildings[i][0] && buildings[i][2] > points[size-1][1]){
                points[size-1][1] = buildings[i][2];
            } else if(openEntry && buildings[i][2] > points[size-1][1]){
                points.push_back({ buildings[i][0], buildings[i][2] });
            } else if(!openEntry){
                int space = buildings[i][0] - points[size-1][0];
                if(space == 0){
                    points[size-1][1] = buildings[i][2];
                } else {
                    points[size-1][1] = (pq.empty()) ? 0 : pq.top()[0];
                }
                
                if(points[size-1][1] < buildings[i][2])
                    points.push_back({ buildings[i][0], buildings[i][2] });
            }

            pq.push({ buildings[i][2], buildings[i][1] });
            openEntry = true;
        }

        while(!pq.empty()){
            vector<int> pqe = pq.top();
            pq.pop();
            
            int size = points.size();
            if(points[size-1][0] < pqe[1]){
                if(!openEntry){
                    points[size-1][1] = pqe[0];
                }

                points.push_back({ pqe[1], pqe[0] });
                openEntry = false;
            }
        }

        points[points.size()-1][1] = 0;

        return points;
    }
};