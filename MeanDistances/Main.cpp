#include <iostream>

inline long long int Floor(long double number) {
	return (long long int)(number);
}


// suma kolejnych kwadratów
inline long double ArithmeticSeries1(long long int l) {
	return (l * (l + 1) * (2 * l + 1)) / 6.0f;
}
// suma kolejnych szescianów
long double ArithmeticSeries2(long long int l) {
	long long int l2 = l * l;

	return l2 * l2 / 4.0f + l2 * l / 2.0f + l2 / 4.0f;
}
//suma kolejnych liczb
inline long double ArithmeticSeries3(long long int l) {
	return ((l + 1) / 2.0f) * l;
}
//suma kolejnych czwartych potêg
inline long double ArithmeticSeries4(long long int l) {
	return l * (l + 1) * (2 * l + 1)  *(3 * l * l + 3 * l - 1) / 30.0f;
}
long long int foo1(int n) {
	int first_row = 2 * (n / 2) * (n / 2 + 1);
	int actual_row = first_row;
	int total_sum = 0;
	int actual_sum = 0;
	int first_r = 1;
	int r = first_r;
	for (int i = 0; i < n; i++) {
		actual_sum += actual_row;
		actual_row += r;
		if (i % 2 == 1) r += 2;
	}
	actual_row -= r;
	r -= 2;
	first_row += first_r;
	total_sum += actual_sum;

	for (int i = 0; i < n / 2; i++) {
		actual_sum += first_row;
		actual_sum -= actual_row;
		total_sum += actual_sum;
		first_row += first_r;
		actual_row -= r;
		if (i % 2 == 0) first_r += 2;
		else         r += 2;
	}
	return 2 * total_sum - actual_sum;
}

long long int foo2(int n) {

	int mid = (n / 2) * (n / 2 + 1); // 12
	int last = mid + (n / 2) * (n / 2);
	int sum = n * mid + ((n / 2) * (n / 2 + 1) * (2 * (n / 2) + 1)) / 3;
	int total = 0;
	int actual_sum = sum;
	int actual_last = last;
	int diffrence = n - 2;

	for (int i = 0; i < n / 2 + 1; i++) {
		total += actual_sum;
		actual_sum += last + (i + 1)*n - actual_last;
		actual_last -= diffrence;
		diffrence -= 2;
	}

	total *= 2;
	total -= sum;
	return total;

}

long long int foo3(int l)
{
	int sum = l * (13 * l * l - 9 * l + 2) / 24;
	int total = 0;
	int diffrence = 1;
	int beg = (l / 2) * (l / 2) + diffrence;
	int end = l * (l - 1);
	for (int i = 0; i < l / 2; i++) {
		total += sum;
		sum -= end;
		sum += beg;
		diffrence += 2;
		beg += diffrence;
		end -= l;
	}

	return total * 2;
}

void D2K0(long long int h, long long int l) {

	long long int div = l * l - 1;
	long long int sum = 0;

	/*if (h == 0) {
		if (l % 2 == 1) {

			if (l < 16) { 
				
				sum = (l - 1) / 2;
				std::cout << sum << std::endl;

			}
			else if (l < 46) {
				
				sum = (l - 3) / 2;
				std::cout << sum << std::endl;

			}
			else { 

				sum = (l - 5) / 2;
				std::cout << sum << std::endl;

			}

		}
		else {

			if (l < 32) {
				
				sum = (l - 1) / 2;
				std::cout << sum << std::endl;
				
			}
			else {

				sum = (l - 3) / 2;
				std::cout << sum << std::endl;
				
			}

		}
	}*/
	if (h == 1) {
		if (l % 3 == 2) {
			
			sum = (2 * l - 1) / 3;
			std::cout << sum << std::endl;

		}
		else {

			sum = (2 * l) / 3;
			std::cout << sum << std::endl;

		}
	}
	if (h == 2) {

		std::cout << "Inf" << std::endl;

	}

	/*if (h == 2) {

		std::cout << "Inf" << std::endl;

	}

	if (h == 1) {

		if (l % 2 == 1) {

			long long int base = (l / 2 + 1) * (l / 2 + 1) * H1ArithmeticSeries1(l);

			sum = base + ((l / 2 + 1)*ArithmeticSeries1(l / 2) - ArithmeticSeries2(l / 2))*(l + 1);
			
			sum = Floor(sum / div / (l / 2 + 1) / (l / 2 + 1));   
			std::cout << sum << std::endl;

		}
		else {

			long long int base = l * l * (l / 2);
			sum = (l / 2) * (l / 2) * base + l * H1ThrowSerie(l);

			sum = Floor(div / (l / 2) / (l / 2));
			std::cout << sum << std::endl;

		}

		if (l % 3 == 2) { 

			long long int base = (2 * l - 1) / 3;

			sum += base;

			std::cout << sum << std::endl;

		}
		else { 

			long long int base = (2 * l) / 3;

			sum += base;

			std::cout << sum << std::endl;

		}

	}
	*/
	if (h == 0) {

		long long int base = 8 * ArithmeticSeries1(l / 2);


		if (l % 2 == 1) {

			sum = ((l / 2 + 1) * (l / 2) + 1 / 4.0f) * base;

			base = (l / 2 + 1) * (ArithmeticSeries2(l / 2) - H0K0ArithmeticSeries5(l) * ArithmeticSeries1(l / 2) +
				H0K0ArithmeticSeries6(l) * ArithmeticSeries3(l / 2) + (l / 2) * H0K0ArithmeticSeries7(l));
			sum += base;

			base = H0K0ArithmeticSeries11(l) + H0K0ArithmeticSeries10(l) - H0K0ArithmeticSeries9(l) - H0K0ArithmeticSeries8(l);
			sum += base;

			sum = Floor(sum / div / ((l / 2 + 1) * (l / 2) + 1 / 4.0f));
			std::cout << sum << std::endl;

		}
		else {

			base -= H0ArithmeticSeries1(l);

			sum = l / 2 * l / 2 * base;

			base = (l * l * l / 2.0f) * ArithmeticSeries3(l / 2 - 1) - (l * l / 4.0f) * ArithmeticSeries1(l / 2 - 1) - 2 * l * ArithmeticSeries2(l / 2 - 1) + ArithmeticSeries4(l / 2 - 1);

			sum += base;

			//stare
			base = H0K0ArithmeticSeries1(l) - H0K0ArithmeticSeries2(l) + 3 * ArithmeticSeries2(l / 2 - 1)
				+ H0K0ArithmeticSeries3(l) * ArithmeticSeries1(l / 2 - 1) + H0K0ArithmeticSeries4(l) * ArithmeticSeries3(l / 2 - 1);
			base =  H0K0ArithmeticSeries1(l);

			sum += base;

			sum = Floor(sum / div / (l / 2) / (l / 2) );
			std::cout << sum << std::endl;

		}

	}
	
}

void D2K1(long long int h, long long int l) {

	long long int div = l * l - 1;
	long long int sum = 0;

	if (h == 0) {

		if (l % 2 == 1) {
			
			int sum = foo2(l) / l;
			
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}
		else {
			
			int sum = foo3(l) / l;  
			
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}
		
	}
	if (h == 1) {

		if (l % 2 == 1) {

			int sum = (l / 2) * (l / 2 + 1) * (2 * l + (2 * (l / 2) + 1) / 3);

			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
		else {
			
			int sum = (7 * l * l * l - 4 * l) / 12;
		
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}
	}
	if (h == 2) {

		if (l % 2 == 1) {

			int sum = foo1(l);

			sum = Floor(sum / div / l);
			std::cout << sum << std::endl;

		}
		else {

			std::cout << "Inf" << std::endl;

		}

	}

	/*
	if (h == 2) {

		if (l % 2 == 0) {

			std::cout << "Inf" << std::endl;

		}
		else {
			
			long long int base = H2K1ArithmeticSeries1(l) + H2K1ArithmeticSeries2(l) + H2K1ArithmeticSeries3(l) + 4 * ArithmeticSeries1(l);
			sum = base;
			long long int prev = 0;
			long long int basePrev = 0;

			for (long long int i = 1; i <= l / 2; i++) {
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

			long long int base = l * l * l / 2;
			sum = base * l / 2 + H1ThrowSerie(l) * l;

			sum = Floor(sum / div / (l / 2));
			std::cout << sum << std::endl;

		}

		if (l % 2 == 1) { 

			int sum = (l / 2) * (l / 2 + 1) * (2 * l + (2 * (l / 2) + 1) / 3);  

			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
		else { 

			int sum = (7 * l * l * l - 4 * l) / 12;
			
			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
	}

	if (h == 0) {
		
		long long int base = 8 * ArithmeticSeries1(l / 2);


		if (l % 2 == 1) {

			sum = l * base;

			base = H0ArithmeticSeries3(l) - H0K1ArithmeticSeries3(l) - ArithmeticSeries2(l / 2);
			sum += 2 * base;

			sum = Floor(sum / div / l);
			std::cout << sum << std::endl;

		}
		else {

			base -= H0ArithmeticSeries1(l);

			sum = l / 2 * base;

			sum += H0ArithmeticSeries3(l) - H0K1ArithmeticSeries2(l) - ArithmeticSeries2(l / 2 - 1);

			sum = Floor(sum / div / (l / 2));
			std::cout << sum << std::endl;

		}

	}
	*/
	
}

void D2K2(long long int h, long long int l) {

	long long int div = l * l - 1;
	long long int sum = 0;

	if (h == 0) {

		if (l % 2 == 1) { sum = (l / 2) * (l / 2 + 1) * (l + (2 * (l / 2) + 1) / 3);
		
		sum = Floor(sum / div);
		std::cout << sum << std::endl;
		
		}
		else {

			sum = (2 * l * l * l + l) / 6;
		
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}
	}
	if (h == 1) {

		if (l % 2 == 1) { 
			int sum = 2 * l * (l / 2) * (l / 2 + 1); 
			
			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
		else { 
			
			int sum = (l * l * l) / 2;
		
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}

	}
	if (h == 2) {
		if (l % 2 == 1) { 
			
			int sum = 2 * l * (l / 2) * (l / 2 + 1);
		
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}
		else {
			
			std::cout << "Inf" << std::endl;

		}
	}

	/*if (h == 2) {

		if (l % 2 == 0) {
			
			std::cout << "Inf" << std::endl;

		}
		else {

			long long int base = H2ArithmeticSeries2(l);

			sum *= l;

			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
	}

	if (h == 1) {

		/*if (l % 2 == 1) {

			sum = H1ArithmeticSeries1(l);

			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}
		else {

			sum = l * l * (l / 2);

			sum = Floor(sum / div);
			std::cout << sum << std::endl;

		}

		if (l % 2 == 1) { 
			int sum = 2 * l * (l / 2) * (l / 2 + 1);
			
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}
		else {
			int sum = (l * l * l) / 2; 
			
			sum = Floor(sum / div);
			std::cout << sum << std::endl;
		
		}

	}

	if (h == 0) {

		sum = 8 * ArithmeticSeries1(l / 2);

		if (l % 2 == 0) {

			sum -= H0ArithmeticSeries1(l);

		}

		sum = Floor(sum / div);
		std::cout << sum << std::endl;

	}
	*/
}

void DMean(long long int k, long long int h, long long int l) {

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

	long long int n, d, l, k, h;
	std::cin >> n;

	for (long long int i = 0; i < n; i++) {
		std::cin >> d >> l >> k >> h;

		DMean(k, h, l);
	}

	system("pause");

}

//zlicza pozycje po przejœciu krawêdzi skojarzonej - podstawa
inline long double H2K1ArithmeticSeries1(long long int l) {
	return (l - 1) * (((l / 2 + 1) + (l - 1)) / 2.0f) * (l / 2);
}
//zlicza pozycje po przejœciu krawêdzi skojarzonej - reszta
inline long double H2K1ArithmeticSeries2(long long int l) {
	return 2 * (((l / 2 + 2) + (l - 1)) / 2.0f) * (l / 4);
}
//zlicza pozycje po przejœciu krawêdzi skojarzonej - baza
long double H2K1ArithmeticSeries3(long long int l) {
	long long int base = (((l + 1) / 2) % 2 == 0) ? (l + 1) : (l - 1);

	return l * base / 2;
}


/*

//zlicza podstawe serii
inline long double H2ArithmeticSeries2(long long int l) {
	return 2 * ((l + 1) / 2.0f)*(l / 2);
}
//zwraca inkrementacje serii
long long int H2K1ThrowSerie(long long int l, long long int n, long long int prev) {
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

//zlicza podstawe dla stanu nieparzystego
inline long double H1K1ArithmeticSeries1(long long int l) {
	return ((1 + (l / 2)) / 2.0f) * (l - 1);
}
//zlicza podstawe serii dla stanu nieparzystego
inline long double H1K1ArithmeticSeries2 (long long int l, long long int s) {
	return l * l * s;
}
//zlicza inkrementacje
inline long double H1K1ArithmeticSeries3(long long int l) {
	return l * (((l / 2) + l) / 2.0f)*((l / 2) - 1);
}

long long int H1ThrowSerie(long long int l) {
	if (l == 2) {
		return 0;
	}
	else {
		return H1K1ArithmeticSeries3(l)+(l/2)*(l/2)-ArithmeticSeries1(l - 1);
	}
}

//zlicza sume nadmiaru szeregu
inline long double H1ArithmeticSeries1(long long int l) {
	return 2 * (2 * l * ((1 + (l / 2)) / 2.0f) * (l / 2));
}

//zlicza redukcje dla stanu parzystego
inline long double H0K1ArithmeticSeries2(long long int l) {
	return l / 2 * l / 2 * ((l / 2) / 2.0f) * (l / 2 - 1);
}
//zlicza redukcje dla stanu nieparzystego
inline long double H0K1ArithmeticSeries3(long long int l) {
	return ((l / 2) + 1) * (l / 2) * ((l / 2 + 1) / 2.0f) * (l / 2);
}
*/
//zlicza korekte dla stanu parzystego
long double H0K0ArithmeticSeries1(long long int l) {
	long long int l2 = l * l;
	return (ArithmeticSeries3(l / 2 - 1) * (6 * l2 * l - 9 * l2 - l + 2) - ArithmeticSeries1(l / 2 - 1) * (24 * l2 - 27 * l + 2) +
		ArithmeticSeries2(l / 2 - 1) * (34 * l - 20) - ArithmeticSeries4(l / 2 - 1) * 16) / 12.0f;
}
//liczy wielokrotnoœæ kroku 2 dla stanu nieparzystego
inline long double H0K0ArithmeticSeries5(long long int l) {
	return l + 3 * (l / 2) + 3;
}
//liczy wielokrotnoœæ kroku 3 dla stanu nieparzystego
inline long double H0K0ArithmeticSeries6(long long int l) {
	return 4 * (l / 2) * (l / 2) + 7 * (l / 2) + l + 3;
}
//liczy wielokrotnoœæ kroku 4 dla stanu nieparzystego
inline long double H0K0ArithmeticSeries7(long long int l) {
	return -2 * (l / 2) * (l / 2) * (l / 2) + (l / 2) * (l / 2) * (l - 5) + (l / 2) * (l - 4) - 1;
}
//liczy krok 4 korekty dla stanu nieparzystego
long double H0K0ArithmeticSeries8(long long int l) {
	return ArithmeticSeries3(l) * ((l / 2 + 1) * ArithmeticSeries3(l) - ArithmeticSeries1(l));
}
//liczy krok 3 korekty dla stanu nieparzystego
long double H0K0ArithmeticSeries9(long long int l) {
	return ((l / 2 - 1) * (l / 2) * (l / 2) * (l / 2 + 1) - (3 * (l / 2) * (l / 2) + 2 * (l / 2) * ArithmeticSeries3(l / 2 - 1)) +
		(3 * (l / 2) + 1) * ArithmeticSeries1(l / 2 - 1) - ArithmeticSeries2(l / 2 - 1)) / 2.0f;
}
//liczy krok 2 korekty dla stanu nieparzystego
long double H0K0ArithmeticSeries10(long long int l) {
	long long int l2 = (l / 2) * (l / 2);
	return (l2 * (l2 * (l / 2) + 4 * l2 + 5 * (l / 2) + 2) - ArithmeticSeries3(l / 2) * (2 * l2 * (l / 2) + 6 * l2 + 5 * (l / 2) + 1) * 2 +
		ArithmeticSeries1(l / 2) * (6 * l2 + 12 * (l / 2) + 5) - ArithmeticSeries2(l / 2) * ((l / 2) + 1) * 4 + ArithmeticSeries4(l / 2)) / 6.0f;
}
//liczy krok 1 korekty dla stanu nieparzystego
long double H0K0ArithmeticSeries11(long long int l) {
	long long int l2 = (l / 2) * (l / 2);
	return (l / 2) * ((l / 2) * (-2 * l2 * (l / 2) + (l - 5) * l2 + (l - 4) * (l / 2) - 1) + ArithmeticSeries3(l / 2) * (l + 4 * l2 + 7 * (l / 2) + 3) -
		ArithmeticSeries1(l / 2) * (l + 3 * (l / 2) + 3) + ArithmeticSeries2(l / 2));
}

/*
stare
// zlicza pierwszy krok przesuniêæ dla stanu parzystego
inline long double H0K0ArithmeticSeries1(long long int l) {
	return ((l / 2) / 2.0f)*(l / 2 - 1) * (l / 2 - 1) * ((3 * l - 2) / 2.0f);
}*/

//zlicza drugi krok przesuniêæ dla stanu parzystego
inline long double H0K0ArithmeticSeries2(long long int l) {
	return (l / 2 - 1) * ((l*l*l) / 4.0f - (5 * (l*l) / 8.0f) + l / 4.0f);
}
//liczy wielokrotnoœæ kroku 4 dla stanu parzystego
inline long double H0K0ArithmeticSeries3(long long int l) {
	return -5 * l + 9 / 2.0f;
}
//liczy wielokrotnoœæ kroku 5 dla stanu parzystego
inline long double H0K0ArithmeticSeries4(long long int l) {
	return (9 / 4.0f) * l * l - (9 / 2.0f) * l + 3 / 2.0f;
}

//zlicza korekte dla stanu parzystego
inline long double H0ArithmeticSeries1(long long int l) {
	return (2 * l + 1) * (l / 2);
}
//zlicza przyrost kolejnych przesuniêæ
inline long double H0ArithmeticSeries2(long long int l) {
	return l * l * ((l / 2 + l) / 2.0f) * (l / 2 - 1);
}
//zlicza kolejne przesuniêcia
long long int H0ArithmeticSeries3(long long int l) {
	return H0ArithmeticSeries2(l) - l * (ArithmeticSeries1(l - 1) - ArithmeticSeries1(l / 2));
}
