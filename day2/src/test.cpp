#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {23, 67, 86, 1, 45};
    vector<int> v2 = {0, 23, 71};
    vector<int> v3 = {46, 2, 1, 420};
    vector<int> v4 = {4};
    vector<vector<int>> vv = {v1, v2, v3, v4};

    sort(vv.begin(), vv.end(), [&](const vector<int>& a,\
         const vector<int>& b){
                return a.size() < b.size();
         });

    for(const auto& v: vv)
    {
        for(const auto& e: v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}
