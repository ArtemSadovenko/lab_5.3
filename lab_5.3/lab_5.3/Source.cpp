#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

double f(double x);

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
		res = f(1.0 + 2.0 * t) + pow(f( f(1.0) + 2.0 * f(2.0 * t)), 2);
		cout << "|" << setw(5) <<   n   << "|" << setw(11) << setprecision(6) << t   << "|" << setw(11) << setprecision(6) <<   f(t)   << "|" << setw(11) << setprecision(6) <<  res  << "|\n" << "-------------------------------------------\n";
		t += dt;
	}

	return 0;
}


double f(double x) {				//main function
	if (abs(x) >= 1) {
		return (pow(sin(x), 2) + sin(x * x)) / (1 + pow(cos(x), 2));
	}
	else {
		double a = 1.;
		double s = a;
		for (int j = 0; j <= 6; j++) {
			double r = pow(x, 4) / (8.0 * j * (32.0 * j * j * j - 16.0 * j * j - 2.0 * j + 1.0));
			a *= r;
			s += a;
		}
		return  1.0 / (1.0 + x * x) * s;
	}
}