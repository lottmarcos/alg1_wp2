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
class MSS
{
public:
   int left;
   int right;
   double sum;

   MSS();
   MSS(int l, int r, double s);
};

// aux methods
double max(double a, double b, double c);
bool is_valid(double value, string operation);

// algorithm methods
MSS max_intersection(vector<double> arr, int l, int m, int h);
MSS max_subarray(vector<double> arr, int l, int r);