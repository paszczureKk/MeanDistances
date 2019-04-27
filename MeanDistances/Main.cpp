#include <iostream>

inline int Floor(float number) {
	return (int)(number);
}

//zlicza pozycje po przejœciu krawêdzi skojarzonej - podstawa
inline float H2K1ArithmeticSeries1(int l) {
	return (l - 1) * ( ((l / 2 + 1) + (l - 1)) / 2.0f) * (l / 2);
}
//zlicza pozycje po przejœciu krawêdzi skojarzonej - reszta
inline float H2K1ArithmeticSeries2(int l) {
	return 2 * ( ((l / 2 + 2) + (l - 1)) / 2.0f) * (l / 4);
}
//zlicza pozycje po przejœciu krawêdzi skojarzonej - baza
float H2K1ArithmeticSeries3(int l) {
	int base = ( ((l + 1) / 2) % 2 == 0) ? (l + 1) : (l - 1);

	return l * base / 2;
}


// suma kolejnych kwadratów
inline float ArithmeticSeries1(int l) {
	return (l * (l + 1) * (2 * l + 1)) / 6.0f;
}
// suma kolejnych szescianów
float ArithmeticSeries2(int l) {
	int l2 = l * l;

	return l2 * l2 / 4.0f + l2 * l / 2.0f + l2 / 4.0f;
}
//zlicza podstawe serii
inline float H2ArithmeticSeries2(int l) {
	return 2 * ((l + 1) / 2.0f)*(l / 2);
}
//zwraca inkrementacje serii
int H2K1ThrowSerie(int l, int n, int prev) {
	if (n == 1) {
		return ( ((l + 1) / 2) % 2 == 1) ? (l + 1) / 2 : (l - 1) / 2;
	}

	if (n == 2) {
		return 8;
	}
	
	if (n == l / 2) {
		return l - 1;
	}

	return prev + 2;
}

//zlicza podstawe dla np
inline float H1K1ArithmeticSeries1(int l) {
	return ((1 + l / 2) / 2.0f) * (l - 1);
}
//zlicza podstawe serii dla np
inline float H1K1ArithmeticSeries2 (int l, int s) {
	return l * l * s;
}
//zlicza inkrementacje
inline float H1K1ArithmeticSeries3(int l) {
	return l * ((l / 2 + l) / 2.0f)*(l / 2 - 1);
}

int H1ThrowSerie(int l) {
	if (l == 2) {
		return 0;
	}
	else {
		return H1K1ArithmeticSeries3(l)+(l/2)*(l/2)-ArithmeticSeries1(l - 1);
	}
}

//zlicza sume nadmiaru szeregu
inline float H1ArithmeticSeries1(int l) {
	return 2 * (2 * l * ((1 + l / 2) / 2.0f) * l / 2);
}

void D2K0(int h, int l) {

	int div = l * l - 1;
	int sum = 0;

	if (h == 2) {

		std::cout << "Inf" << std::endl;

	}

	if (h == 1) {

		if (l % 2 == 1) {

			int base = (l / 2 + 1) * (l / 2 + 1) * H1ArithmeticSeries1(l);

			sum = base + ((l / 2 + 1)*ArithmeticSeries1(l / 2) - ArithmeticSeries2(l / 2))*(l + 1);
			
			sum = Floor(sum / div / (l / 2 + 1) / (l / 2 + 1));

		}
		else {

			int base = l * l * (l / 2);
			sum = (l / 2) * (l / 2) * base + l * H1ThrowSerie(l);

			sum = Floor(div / (l / 2) / (l / 2));
			std::cout << sum << std::endl;

		}

	}

	if (h == 0) { std::cout << -1 << '\n'; }
}

void D2K1(int h, int l) {

	int div = l * l - 1;
	int sum = 0;

	if (h == 2) {

		if (l % 2 == 0) {

			std::cout << "Inf" << std::endl;

		}
		else {
			
			int base = H2K1ArithmeticSeries1(l) + H2K1ArithmeticSeries2(l) + H2K1ArithmeticSeries3(l) + 4 * ArithmeticSeries1(l);
			sum = base;
			int prev = 0;
			int basePrev = 0;

			for (int i = 1; i <= l / 2; i++) {
				basePrev = H2K1ThrowSerie(l, i, basePrev);
				prev += basePrev;
				base += prev;

				sum += 2 * (base);
			}

			sum = Floor(sum / div / l);
			std::cout << sum << std::endl;

		}

	}
	
	if (h == 1) {

		if (l % 2 == 1) {

			sum = l  * H1ArithmeticSeries1(l) + 2 * l * ArithmeticSeries1(l/2);

			sum = Floor(sum / div / l);
			std::cout << sum << std::endl;
		}
		else {

			int base = l * l * l / 2;
			sum = base * l / 2 + H1ThrowSerie(l) * l;

			sum = Floor(sum / div / (l / 2));
			std::cout << sum << std::endl;

		}
	}

	if (h == 0) {
		// if(l%2 == 1) { int sum = hZeroOdd(l)/l;   std::cout << sum/div << '\n'; }
		// else         { int sum = hZeroEven(l)/l;  std::cout << sum/div << '\n'; }
		std::cout << -1 << '\n';
	}
	
	
}

void D2K2(int h, int l) {

	int div = l * l - 1;
	int sum = 0;

	if (h == 2) {

		if (l % 2 == 0) {
			
			std::cout << "Inf" << std::endl;

		}
		else {

			int base = H2ArithmeticSeries2(l);

			sum *= l;

			sum = Floor(base / div);
			std::cout << sum << std::endl;

		}
	}

	if (h == 1) {

		if (l % 2 == 1) {

			sum = H1ArithmeticSeries1(l);

			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
		else {

			sum = l * l * (l / 2);

			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
	}

	if (h == 0) {
		// if(l%2 == 1) { int sum = (l/2) * (l/2 + 1) * (l + (2 * (l/2) + 1)/3); std::cout << sum/div << '\n'; }
		// else         { int sum = (2 * l * l * l + l)/6;                       std::cout << sum/div << '\n'; }
		std::cout << -1 << '\n';
	}
	
}

void DMean(int k, int h, int l) {

	std::cout << h << std::endl;

}

void D2Mean(int k, int h, int l) {

	switch (k) {
		case 0:
			D2K0(h, l);
			break;
		case 1:
			D2K1(h, l);
			break;
		case 2:
			D2K2(h, l);
			break;
	}

}

int main() {

	int n, d, l, k, h;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> d >> l >> k >> h;

		if (d == 2) {
			D2Mean(k, h, l);
		}
		else {
			DMean(k, h, l);
		}
	}

	system("pause");

}