#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "TP2.hpp"

int main()
{
  // pick up the inputs
  int friends = 0, shows = 0;
  cin >> friends >> shows;
  if (!(is_valid(friends, "friends") && is_valid(shows, "shows")))
  {
    cout << "invalid inputs " << friends << " " << shows << endl;
    return 1;
  }

  // make the main loop of the program
  while ((friends > 0) && (shows > 0))
  {
    // storing the rates values
    vector<double> rates = vector<double>(shows, 0);
    for (int i = 0; i < friends; ++i)
    {
      for (int j = 0; j < shows; ++j)
      {
        double rate = 0;
        cin >> rate;
        rates[j] += rate;
        if (!is_valid(rate, "rate"))
        {
          cout << "invalid rate " << rates[j] << endl;
          return 1;
        }
      }
    }

    // run maximum subarray sum algorithm
    MSS max_sum = max_subarray(rates, 0, (rates.size()) - 1);

    // print results
    cout << (max_sum.left + 1) << " " << (max_sum.right + 1) << endl;

    // restart the cycle
    cin >> friends >> shows;
  }

  return (0);
}
