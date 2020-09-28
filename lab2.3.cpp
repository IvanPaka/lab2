#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-5;

double f1(double x, double y){
	return pow(x, 3) + pow(y, 3) - 8;
}

double f2(double x, double y){
	return 1 + pow(x, 1.5) - y;
}

double df1dx(double x, double y){
	return 3*x*x;
}

double df1dy(double x, double y){
	return 3*y*y;
}

double df2dx(double x, double y){
	return 1.5*sqrt(x);
}

double df2dy(double x, double y){
	return -1;
}

int main(){
	int iter = 0;
	double x = 0.8;
	double y = 1.8;
	while(abs(f1(x, y) - f2(x, y)) > eps){
		double w = df1dx(x, y)*df2dy(x, y) - df1dy(x, y)*df2dx(x, y);//Определитель якобиана
		x -= (f1(x, y)*df2dy(x, y) - f2(x, y)*df1dy(x, y))/w;
		y -= (-f1(x, y)*df2dx(x, y) + f2(x, y)*df1dx(x, y))/w;
		iter++;
	}
	cout << "Метод Ньютона:\n";
    cout << "x = " << x << ", y = " << y << endl;
    cout << "f1(x, y) = " << f1(x, y) << ", f2(x, y) = " << f2(x, y) << endl;
    cout << "it: " << iter << endl;
	return 0;
}
