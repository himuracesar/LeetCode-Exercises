class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> children;

        for(auto i = 0; i < n; i++){
            children.push_back(0);
        }

        for(auto i = 0; i < n; i++){

           if(leftChild[i] > -1){
                children[leftChild[i]]++;

                if(children[leftChild[i]] > 1 || leftChild[leftChild[i]] == i || rightChild[leftChild[i]] == i)
                    return false;
           }
            
            if(rightChild[i] > -1){
                children[rightChild[i]]++;

                if(children[rightChild[i]] > 1 || leftChild[rightChild[i]] == i || rightChild[rightChild[i]] == i)
                    return false;
            }
        }

        int sum = 0;
        int root = -1;
        for(auto i = 0; i < children.size(); i++){
            sum += children[i];

            if(children[i] == 0)
                if(root > -1)
                    return false;
                else
                    root = i;
                
            //cout << "root:: " << root << endl;
        }

        if(sum != children.size() - 1)
            return false;

        queue<int> q;
        map<int,int> nodesVisited;
        int numNodes = 0;

        q.push(root);

        while(!q.empty()){
            int index = q.front();
            q.pop();

            numNodes++;

            if(leftChild[index] > -1)
                q.push(leftChild[index]);
            if(rightChild[index] > -1)
                q.push(rightChild[index]);

            if(nodesVisited.find(index) == nodesVisited.end())
                nodesVisited[index] = index;
            else
                return false;
        }

        if(numNodes < n)
            return false;

        return true;
    }
};