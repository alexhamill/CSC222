#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& nums) {
    string s = "";
    for(int i=0;i<nums.size();i++){
        s.append(std::to_string(nums[i]));
        if(i != nums.size()-1){
            s.append(" ");
        }
    }
    
    return s;
}

int num_vector_sum(const vector<int>& nums){
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
    }
    return sum;
}
int num_vector_product(const vector<int>& nums){
    int prodct = nums[0];
    for(int i=1;i<nums.size();i++){
        prodct *= nums[i];
    }
    return prodct;
}

vector<int> only_evens(const vector<int>& nums){
    vector<int> final={};
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            final.push_back(nums[i]);
        }
    }
    return final;
}
vector<int> only_odds(const vector<int>& nums){
    vector<int> final={};
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==1){
            final.push_back(nums[i]);
        }
    }
    return final;
}

vector<int> nums_between(const vector<int>& nums, int low, int high){
    vector<int> final={};
    for(int i=0;i<nums.size();i++){
        if(nums[i]<= high && nums[i]>= low){
            final.push_back(nums[i]);
        }
    }
    return final;
}

double nums_mean(const vector<int>& nums){
    double mean=0;
    for(int i=0;i<nums.size();i++){
        mean += nums[i];
    }
    if (nums.size() != 0){
        mean/nums.size();
    }
    return mean;
}