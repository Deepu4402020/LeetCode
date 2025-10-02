class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            empty-=numExchange;
            drunk++;empty++;
            numExchange++;
        }
        return drunk;
    }
};