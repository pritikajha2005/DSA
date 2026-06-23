#include <iostream>
#include <vector>
using namespace std;

int max_profit(vector<int>& price){
    int min_price=price[0];
    int max_profit=0;

    for(int i=0; i<price.size(); i++){

        min_price=min(min_price, price[i]);

        int profit=price[i]-min_price;

        max_profit=max(max_profit, profit);
    }

    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << max_profit(prices);

    return 0;
}