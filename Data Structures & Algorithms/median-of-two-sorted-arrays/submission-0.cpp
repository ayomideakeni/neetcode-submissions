class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double median = 0;
        
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int sumSize = A.size() + B.size();

        int half = (sumSize + 1) /2;

        int left = 0;
        int right = A.size();
        

        while(left <= right){
    /* A */ int i = (left + right) /2;
    /* B */ int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;

            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright){
                if(sumSize % 2){
                    median = max(Aleft, Bleft);
                }else{
                    median = (max(Aleft, Bleft) + min(Aright, Bright)) /2.0;
                }
                return median;
            }else if(Aleft > Bright){
                right = i - 1;
            }else{
                left = i + 1;
            } 
        }

        return median;
    }
};