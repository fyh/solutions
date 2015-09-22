class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> V;
        for (int i = 0; i < nums1.size(); ++i) V.push_back(nums1[i]);
        for (int i = 0; i < nums2.size(); ++i) V.push_back(nums2[i]);
        sort(V.begin(), V.end());
        if (V.empty()) return 0.0;
        if (V.size()%2 == 0) return (V[V.size()/2] + V[V.size()/2-1]) * 0.5;
        return V[V.size()/2];
    }
};
