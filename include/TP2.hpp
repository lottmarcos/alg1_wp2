#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;
// class implementation
class SSM
{
public:
   int left;
   int right;
   double sum;

   SSM();
   SSM(int l, int r, double s);
};

// aux methods
double max(double a, double b, double c);
bool is_valid(double value, string operation);

// algorithm methods
SSM max_crossing_sum(vector<double> arr, int l, int m, int h);
SSM max_subarray_sum(vector<double> arr, int l, int r);