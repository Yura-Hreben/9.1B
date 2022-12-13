//B
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Spec { ME , MF, FI, In, KN };
string specStr[] = { "Математика та економіка", "Трудове навчання", "Фізика та інформатика", "Інформатика" ,"Комп'ютерні науки"};
struct Student
{
	string prizv;
	unsigned kurs;
	Spec spec;
	unsigned markPh;
	unsigned markMath;

	union {
		unsigned markProg;
	

		unsigned markChM;
	
	
		unsigned markPed;
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student * p, const int N);



int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	double proc = LineSearch(p, N);
	cout << "Процент студентів, що вчаться на відмінно:" << endl;
	cout << proc << "%" << endl;
	return 0;
}

void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync();

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спеціальність ( 0 - Математика та економіка, 1 - Трудове навчання, 2 - Фізика та інформатика, 3 - інформатика , 4 - комп'ютерні науки): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		

		switch (p[i].spec) {

		case 3:
			cout << " фізика : "; cin >> p[i].markPh;
			cout << " математика : "; cin >> p[i].markMath;
			cout << " чисельні методи : "; cin >> p[i].markChM;
			break;
		case 4:
			cout << " фізика : "; cin >> p[i].markPh;
			cout << " математика : "; cin >> p[i].markMath;
			cout << " програмування : "; cin >> p[i].markProg;
			break;

		default: 
			cout << " фізика : "; cin >> p[i].markPh;
			cout << " математика : "; cin >> p[i].markMath;
			cout << " педагогіка : "; cin >> p[i].markPed;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "=============================================================================================================================="
		<< endl;
	cout << "| № |     Прізвище     | курс |       спеціальність     | фізика | математика | програмування | чисельні методи | педагогіка |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		switch (p[i].spec) {

		case 3:
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(17) << left << p[i].prizv
				<< "| " << setw(4) << right << p[i].kurs << " "
				<< "| " << setw(24) << left << specStr[p[i].spec] << "| " << setw(7) << right << p[i].markPh << "| " << setw(11) << right << p[i].markMath << "|" << setw(16) << "|" << setw(17) << right << p[i].markChM << "|" << setw(13) << "|" << endl;
			break;
		case 4:
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(17) << left << p[i].prizv
				<< "| " << setw(4) << right << p[i].kurs << " "
				<< "| " << setw(24) << left << specStr[p[i].spec] << "| " << setw(7) << right << p[i].markPh << "| " << setw(11) << right << p[i].markMath << "|" << setw(15) << p[i].markProg << "|" << setw(18) << right << "|" << setw(13) << "|" << endl;
			break;

		default:
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(17) << left << p[i].prizv
				<< "| " << setw(4) << right << p[i].kurs << " "
				<< "| " << setw(24) << left << specStr[p[i].spec] << "| " << setw(7) << right << p[i].markPh << "| " << setw(12) << right  << "|" << setw(16) << "|" << setw(18) << right << "|" << setw(12) << p[i].markPed << "|" << endl;
			break;
		}

		
		

	}
	cout << "=============================================================================================================================="
		<< endl;
		cout << endl;
}

double LineSearch(Student* p, const int N)
{
	cout << "Прізвища студентів, що отримали з фізики 5:" << endl;

	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (true)
		{
			n++;
			if (p[i].markMath == 5 && p[i].markPh == 5 && p[i].markProg == 5 || p[i].markMath == 5 && p[i].markPh == 5 && p[i].markChM == 5 || p[i].markMath == 5 && p[i].markPh == 5 && p[i].markPed == 5)
			{
				k++;
			}
			if (p[i].markPh == 5) {
				cout << setw(3) << right
					<< " " << p[i].prizv << endl;
			}
		}
	}
	return 100.0 * k / n;
}
