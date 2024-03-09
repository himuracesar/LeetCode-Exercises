class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> names;

        map<string, priority_queue<int, vector<int>, greater<int>>> access;

        for(auto i = 0; i < access_times.size(); i++){
            access[access_times[i][0]].push(stoi(access_times[i][1]));
        }
        for(auto el : access){
            auto q = el.second;

            //cout << el.first << " -- " << el.second.size() << endl;

            int counter = 0;
            int hr = -1;
            int hr_aux = -1;
            while(!q.empty()){
                //cout << "q:: " << q.top() << endl;
                if(hr == -1){
                    counter = 1;
                    hr = q.top();
                } else {
                    if(q.top() - hr < 100){
                        counter++;
                        hr_aux = q.top();
                        if(counter == 3){
                            names.push_back(el.first);
                            break;
                        }
                    } else {
                        if(hr_aux > -1 && q.top() - hr_aux < 100){
                            counter = 2;                            
                            hr = hr_aux;
                            hr_aux =  q.top();
                        } else {
                            hr = q.top();
                            hr_aux = -1;
                            counter = 1;
                        }
                    }
                }

                q.pop();
            }
        }

        return names;
    }
};