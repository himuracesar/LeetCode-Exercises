class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() <= 1)
            return fruits.size();

        int total = 0;
        int counter = 0;
        int b1 = 0;
        int b2 = 0;
        int p1 = 0;
        int p2 = 1;

        while(p2 < fruits.size()){
            if(fruits[p1] != fruits[p2])
                break;
            p2++;
        }

        p2 = (p2 == fruits.size()) ? p2 - 1 : p2;

        counter = p2 - p1 + 1;
        total = counter;

        b1 = fruits[p1];
        b2 = fruits[p2];

        p1 = p2;
        p2 += 1;

        while(p2 < fruits.size()){
            if(b1 == fruits[p2] || b2 == fruits[p2]){
                counter++;
                if(fruits[p1] != fruits[p2]){
                    p1 = p2;
                }
            } else {
                    b1 = fruits[p1];
                    b2 = fruits[p2];
                    counter = p2 - p1 + 1;

                    p1 = p2;
                }

                p2++;
                total = max(total, counter);
        }

        return total;
    }
};