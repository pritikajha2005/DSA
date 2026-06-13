#include <iostream>
#include <vector>
using namespace std;

vector<int> find_union(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        int val;

        if (a[i] < b[j]) val = a[i++];
        else if (a[i] > b[j]) val = b[j++];
        else {
            val = a[i];
            i++;
            j++;
        }

        if (result.empty() || result.back() != val)
            result.push_back(val);
    }

    while (i < a.size()) {
        if (result.empty() || result.back() != a[i])
            result.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        if (result.empty() || result.back() != b[j])
            result.push_back(b[j]);
        j++;
    }

    return result;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4, 5};
    vector<int> b = {2, 3, 5, 6};

    vector<int> ans = find_union(a, b);

    for (int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
}