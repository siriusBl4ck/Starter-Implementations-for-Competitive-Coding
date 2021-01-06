#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int tortoise = nums[0], hare = nums[0];
    std::cout << "Phase 1\n";
    while (true){
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
        std::cout << hare << " " << tortoise << "\n";
        if (hare == tortoise){
            break;
        }
    }
    
    tortoise = nums[0];
    std::cout << "Phase 2\n";
    //testcase I forgot about: If nums[0] is the entrance of cycle. no need to run the loop below
    while (tortoise != hare){
        tortoise = nums[tortoise];
        hare = nums[hare];
        std::cout << hare << " " << tortoise << "\n";
    }
        
    return hare;
}