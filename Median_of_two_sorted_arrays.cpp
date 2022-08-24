class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(size_t i=0 ; i<nums1.size(); i++){
            if(smalls.empty() || nums1[i] < smalls.top()){
                smalls.push(nums1[i]);
            }else{
                bigs.push(nums1[i]);
            }
            if(smalls.size() > bigs.size()+1){
                bigs.push(smalls.top());
                smalls.pop();
            }
            if(bigs.size() > smalls.size()+1){
                smalls.push(bigs.top());
                bigs.pop();
            }
        }
        for(size_t i=0 ; i<nums2.size(); i++){
            if(smalls.empty() || nums2[i] < smalls.top()){
                smalls.push(nums2[i]);
            }else{
                bigs.push(nums2[i]);
            }
            if(smalls.size() > bigs.size()+1){
                bigs.push(smalls.top());
                smalls.pop();
            }
            if(bigs.size() > smalls.size()+1){
                smalls.push(bigs.top());
                bigs.pop();
            }
        }
        return Median();
    }
    double Median(){
        if(bigs.size() > smalls.size())
            return (double)bigs.top();
        else if(bigs.size() < smalls.size())
            return (double)smalls.top();
        else
            return ((double)(bigs.top()+smalls.top()))/2;
    }
    priority_queue<int, vector<int>, greater<int>> bigs;
    priority_queue<int> smalls;
};
