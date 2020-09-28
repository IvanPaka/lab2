#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-6;

double f(double x){
	return pow(x, 4) + 18*pow(x, 3) - 6*x*x  + x - 10;
}

void dihot(double x, double y){//Метод дихотомии
	int iter = 0;
	double a = x, b = y;
	double c;
	while (abs(f((a + b) / 2)) > eps){
        c = (a + b) / 2;
        if(f(b) * f(c) < 0)
            a = c;
        else
            b = c;
        iter++;
    }
    cout << "Метод дихотомии:\n";
    cout << "x = " << (a + b) / 2 << endl;
    cout << "f(x) = " << f((a + b) / 2) << endl;
    cout << "it: " << iter << endl;
}

void hord(double x, double y){//Метод хорд
	int iter = 0;
	double a = x, b = y;
    while(abs(b - a) > eps) {
		b -= f(b)*(b-a)/(f(b)-f(a));
		a -= f(a)*(a-b)/(f(a)-f(b));
        iter++;
    }
    cout << "Метод хорд:\n";
    cout << "x = " << b << endl;
    cout << "f(x) = " << f(b) << endl;
    cout << "it: " << iter << endl;
}

int main(){
	double a = 0, b = 1;
	int i = 1;
	while (f(a)*f(b) > 0){//Отделение корней
		a += i;
		b += i;
		if (a > 10000){
			a = -1;
			b = 0;
			i = -1;
		}else if (a < -10000) {
			cout << "Нет корней на отрезке (-10000, 10000)" << endl;
			break;
		}
	}
	
    dihot(a, b);
    hord(a, b);
    
	return 0;
}
