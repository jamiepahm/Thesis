#include "canny.h"

canny::canny(String)
{
}

Mat canny::toGrayScale()
{
	return Mat();
}

vector<vector<double>> canny::createFilter(int, int, double)
{
	return vector<vector<double>>();
}

Mat canny::useFilter(Mat, vector<vector<double>>)
{
	return Mat();
}

Mat canny::nonMaxSupp()
{
	return Mat();
}

Mat canny::threshold(Mat, int, int)
{
	return Mat();
}
