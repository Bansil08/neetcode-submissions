class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        int p1=0;
        int p2=n-1;
        while(1){
            if(numbers[p1]+numbers[p2]>target)p2--;
            else if(numbers[p1]+numbers[p2]<target)p1++;
            else return {p1+1,p2+1};
        }
        return {};
    }
};
