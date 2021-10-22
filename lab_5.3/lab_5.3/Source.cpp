#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

double f(double x);
double u(int y);

int main() {
	int n, n1;
	double tp, t, tk, dt, res;

	cout << "tp = "; cin >> tp;
	cout << "tk = "; cin >> tk;
	cout << "n = "; cin >> n;

	cout << "-------------------------------------------\n";
	cout << "|" << setw(5) << "  n  " << "|" << setw(11) << "t  " << "|" << setw(11) << "  f(t) " << "|" << setw(11) << " res " << "|\n" << "-------------------------------------------\n";
	
	dt = (tk - tp) / n;
	t = tp;
	n1 = n;

	for (n = 0 ; n <= n1; n++) {
		res = f(1.0 + 2 * t) + pow(f( f(1) + 2 * f(2 * t)), 2);
		cout << "|" << setw(5) <<   n   << "|" << setw(11) << setprecision(6) << t   << "|" << setw(11) << setprecision(6) <<   f(t)   << "|" << setw(11) << setprecision(6) <<  res  << "|\n" << "-------------------------------------------\n";
		t += dt;
	}



	return 0;
}

double u(int y){					//factorial function
	double fact = 1.0;
	double tt = 4.0*y + 1.0;
	while (tt > 0) {
		fact *= 4 * tt + 1;
		tt--;
	}
	return fact;
}


double f(double x) {				//main function
	if (abs(x) >= 1) {
		return (pow(sin(x), 2) + sin(x * x)) / (1 + pow(cos(x), 2));
	}
	else {
		double sp = 0.0;
		double s = 0.0;
		for (int n = 0; n <= 6; n++) {
			sp += pow(x, 4 * n + 1)/u(n);  
		}
		return  1.0 / (1 + x * x) * sp;
	}
}