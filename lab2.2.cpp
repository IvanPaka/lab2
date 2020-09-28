#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-5;

double f(double x){
	return pow(7, x) - 6*x - 2;
}

double df(double x){
	return pow(7, x)*log(7) - 6;
}

void prost_iter(double x){
	int iter = 0;
	double a = x;
	double l = 0.1;
	while(abs(f(a)) > eps){
		a -= l*f(a);
		iter++;
	}
	cout << "Метод простой итерации:\n";
    cout << "x = " << a << endl;
    cout << "f(x) = " << f(a) << endl;
    cout << "it: " << iter << endl;
}

void nm(double x){
	int iter = 0;
	double a = x;
	while(abs(f(a)) > eps){
		a -= f(a)/df(a);
		iter++;
	}
	cout << "Метод Ньютона:\n";
    cout << "x = " << a << endl;
    cout << "f(x) = " << f(a) << endl;
    cout << "it: " << iter << endl;
}
int main(){
	prost_iter(0);
	nm(1.5);
	return 0;
}
