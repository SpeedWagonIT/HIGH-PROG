//
//Worker: ������� � ��������, ���������, ��� ����������� �� ������, ��������. ������� ������ ��������. �������:
//�) ������ ����������, ���� ������ ������� �� ������ �������-���� ��������� �������� ����� ���;
//�) ������ ����������, �������� ������� ������ ��������;
//�) ������ ����������, ���������� �������� ���������.

#include <iostream>
#include <fstream>//�������� �����
#include <ctime>
#include <locale>
using namespace std;
ifstream fin("worker.txt"); // ������� ���� ��� ������

class Worker {
private:
	char name[30];
	char position[30]; //���������
	int joiningYear;   //��� ����������� �� ������
	int salary;        //��������
public:
	Worker();
	int getSalary();
	int getJoiningYear();
	char* getPosition();
	void show();

};

Worker::Worker()// ����������� ������ ������� ��������� ������
{
	char temp[1];
	fin.getline(name, 50);
	fin.getline(position, 30);
	fin >> joiningYear;
	fin >> salary;
	fin.getline(temp, 1);//��� �������� �� ����� ������

}
void Worker::show()
{
	cout << "**********************************" << endl;
	cout << "������� � ��������: " << name << endl;
	cout << "���������: " << position << endl;
	cout << "��� ����������� �� ������: " << joiningYear << endl;
	cout << "��������: " << salary << "$" << endl;

}

int Worker::getSalary()
{
	return salary;
}

int Worker::getJoiningYear()
{
	return joiningYear;
}

char* Worker::getPosition()
{
	return position;
}

void showAll(Worker worker_spis[], int n)
{
	for (int i = 0; i < n; i++) {
		worker_spis[i].show();
	}
	cout << endl;
}

void sortBySeniority(Worker worker_spis[], int n)
{
	struct tm nowLocal;//������� ��� ��������� ����������� ����
	__time64_t long_time;
	_time64(&long_time);
	_localtime64_s(&nowLocal, &long_time);
	int year = nowLocal.tm_year + 1900;
	int month = nowLocal.tm_mon + 1;

	int seniority; //����
	cout << "������� ����: ";
	cin >> seniority;
	for (int i = 0; i < n; i++) {
		if (year - worker_spis[i].Worker::getJoiningYear() >= seniority) {
			worker_spis[i].Worker::show();
		}
	}
}

void sortBySalary(Worker worker_spis[], int n)
{
	int salary;
	cout << "������� ��������: ";
	cin >> salary;
	for (int i = 0; i < n; i++) {
		if (worker_spis[i].Worker::getSalary() >= salary) {
			worker_spis[i].Worker::show();
		}
	}
}

void sortByPosition(Worker worker_spis[], int n)
{
	char position[30];
	cout << "������� ���������: ";
	cin.get();
	cin.getline(position, 30);
	for (int i = 0; i < n; i++) {
		if (!_stricmp(worker_spis[i].Worker::getPosition(), position)) {//��������� ����� ��� ����� ��������
			worker_spis[i].Worker::show();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Worker* worker_spis; // ��������� �� ��� Worker
	int n = 8;
	worker_spis = new Worker[n]; // ��������� ������ N �������� ������ worker (�������� new ������������ ��������� ������������ ������ � ����)

	int pick;
	do {
		cout << endl << "1. �������� ���� ������\n";
		cout << "2. ������������� �� �����\n";
		cout << "3. ������������� �� ��������\n";
		cout << "4. ������������� �� ���������\n";
		cout << "0. �����\n";
		cin >> pick;
		switch (pick) {
		case 0: {return 1; }
		case 1: {
			system("cls");
			showAll(worker_spis, n);
			break;
		}
		case 2: {
			system("cls");
			sortBySeniority(worker_spis, n);
			break;
		}
		case 3: {
			system("cls");
			sortBySalary(worker_spis, n);
			break;
		}
		case 4: {
			system("cls");
			sortByPosition(worker_spis, n);
			break;
		}
		default: {cout << "������! ���������� �����\n"; break; }
		}
	} while (pick != 0);
	/*cin.get();*/
	return 0;
}
