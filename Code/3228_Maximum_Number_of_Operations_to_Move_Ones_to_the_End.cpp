class Solution {
public:
    int maxOperations(string s) {
        vector<int> c1 = {INT_MAX, INT_MAX};
        vector<int> c0 = {-1, -1};

        int moves = 0;

        for(auto i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                if(c1[0] == INT_MAX){
                    c1[0] = i;
                    c1[1] = i;
                } else if(i - c1[1] == 1)
                    c1[1] = i;
                else {
                    moves += getMovesAndSwap(s, c0, c1, i);
                }
            } else if(s[i] == '0'){
                if(i - c0[1] == 1){
                    c0[1] = i;
                } else {
                    c0[0] = i;
                    c0[1] = i;
                }
            }
        }

        if(c0[1] > c1[0])
            moves += getMovesAndSwap(s, c0, c1, c0[1]);

        return moves;
    }

    int getMovesAndSwap(string& s, vector<int>& c0, vector<int>& c1, int currentInx){
        int move1 = c1[1] - c1[0] + 1;
        int move0 = c0[1] - c0[0] + 1;
        int minMoves = min(move1, move0);

        /*cout << "****" << endl;
        cout << "c1[1]:: " << c1[1] << " c1[0]:: " << c1[0] << endl;*/

        for(auto i = 0; i < minMoves; i++){
            s[c1[0] + i] = '0';
            s[c0[1] - i] = '1';
        }

        c1[0] = (move0 < move1) ? c1[0] + minMoves : c0[1] - (minMoves - 1);
        c1[1] = currentInx;
        //cout << "c1[0]:: " << c1[0] << " c1[1]:: " << c1[1] << endl;

        c0[0] = -1;
        c0[1] = -1;

        //cout << "s:: " << s << " moves:: " << move1 << endl;
        return move1;
    }
};