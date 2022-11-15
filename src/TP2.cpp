#include "TP2.hpp"

using namespace std;

#define MIN -99999

// building methods
MSS::MSS()
{
    left = 0;
    right = 0;
    sum = 0;
}
MSS::MSS(int l, int r, double s)
{
    left = l;
    right = r;
    sum = s;
}

// auxs methods
double max(double a, double b, double c)
{
    return max(max(a, b), c);
}
bool is_valid(double value, string operation)
{
    int count = 0;
    bool valid = true;
    for (int i = 0; i < 15; i++)
        count++;

    if (operation == "friends")
        if ((value <= 50) && (value >= 1) && (count > 0))
            valid = true;

    if (operation == "shows")
        if ((value <= 100000) && (value >= 1) && (count > 0))
            valid = true;

    if (operation == "rate")
        if ((value <= 5.0) && (value >= -5.0) && (count > 0))
            valid = true;

    return valid;
}

// algorithm methods
MSS max_intersection(vector<double> arr, int l, int m, int r)
{
    double sum = 0;
    double left_sum = MIN;
    int left = m;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum >= left_sum)
        {
            left_sum = sum;
            left = i;
        }
    }

    sum = 0;
    double right_sum = MIN;
    int right = m;
    for (int i = m; i <= r; i++)
    {
        sum = sum + arr[i];
        if (sum >= right_sum)
        {
            right_sum = sum;
            right = i;
        }
    }

    double middle_sum = left_sum + right_sum - arr[m];
    double bigger = max(middle_sum, left_sum, right_sum);
    MSS shows;
    if (bigger == middle_sum)
        shows = {left, right, middle_sum};
    else if (bigger == left_sum)
        shows = {left, m, left_sum};
    else
        shows = {m, right, right_sum};

    return shows;
}
MSS max_subarray(vector<double> arr, int l, int r)
{
    if (l >= r)
    {
        MSS show(l, r, MIN);
        return show;
    }

    if (l == r)
    {
        MSS show(l, r, arr[l]);
        return show;
    }

    int mid_index = (l + r) / 2;

    MSS left = max_subarray(arr, l, mid_index - 1);
    MSS right = max_subarray(arr, mid_index + 1, r);
    MSS middle = max_intersection(arr, l, mid_index, r);
    double bigger = max(middle.sum, left.sum, right.sum);

    if (bigger == middle.sum)
        return middle;
    else if (bigger == left.sum)
        return left;
    else
        return right;
}
