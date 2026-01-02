#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_profit(vector<int> &prices)
{
    int min_price = INT_MAX;
    int max_Profit = 0;

    for (int price : prices)
    {
        if (price < min_price)
            min_price = price;
        else
            max_Profit = max(max_Profit, price - min_price);
    }
    return max_Profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "max profit: " << max_profit(prices);
    return 0;
}
