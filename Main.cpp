#include <locale>
#include <string>
#include "List.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	List list1, list2, list3;
	string in;
	bool active = false;

	while (true) {
		while (in.empty()) {
			system("cls");
			cout << "����� \"���������������� ����������� ������\"\n";
			cout << "�������� ������, ��� ������� ����� ����������� ��������\n";
			cout << " 1 � list1\n";
			cout << " 2 � list2\n";
			cout << " 3 � ����� �� ���������\n";
			cout << "\n > ";
			cin >> in;
			if (in[0] == '1') active = true;
			else if (in[0] == '2') active = false;
			else if (in[0] == '3')  {
				system("cls");
				return 0;
			}
			else {
				cout << "\n ���-�� �� �� . . .\n ���������� ��� ���\n ";
				system("pause");
				in.clear();
			}
		}
		in.clear();

		while (in.empty()) {
			system("cls");
			cout << "����� \"���������������� ����������� ������\"\n";
			cout << " 1 � ��������� ������� ��������� �������\n";
			cout << " 2 � ���������� �������� � ������ ������\n";
			cout << " 3 � ���������� �������� � ����� ������\n";
			cout << " 4 � �������� �������� �� ������ ������\n";
			cout << " 5 � �������� �������� �� ����� ������\n";
			cout << " 6 � ������� ����� ������\n";
			cout << " 7 - �������� ������ � ������ ������\n";
			cout << " 8 � �������� ������� ������\n";
			cout << " 9 � �������� ���������\n";
			cout << " + � ������� ������ �����������\n";
			cout << " - � ������� ������ �����������\n";
			cout << " * � �������� ������ �����������\n";
			cout << " / � ��������� ������ �����������\n";
			cout << " a � ������� ������ �� �����\n";
			cout << " b � �������� ������ ������� ������\n";
			cout << " c � �������� ��������� ������� ������\n";
			cout << " d � �������� ������\n";
			cout << " e � ������� ������\n";
			cout << " f � ����� �� ���������\n";
			cout << "\n > ";
			cin >> in;
			switch (in[0]) {
			default:
				cout << " ���-�� �� �� . . .\n ���������� ��� ���\n ";
				in.clear();
				break;
			// ��������� ������� ��������� �������
			case '1': {
				system("cls");
				cout << "��������: " << (active ? "list1" : "list2") << ".random()" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				active ? list1.random() : list2.random();
				cout << "���������: " << (active ? list1 : list2) << endl;
				} break;
			// ���������� �������� � ������ ������
			case '2': {
				system("cls");
				cout << "��������: ++" << (active ? "list1" : "list2") << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? ++list1 : ++list2;
				cout << "���������: " << (active ? list1 : list2) << endl;
				} break;
			// ���������� �������� � ����� ������
			case '3': {
				system("cls");
				cout << "��������: " << (active ? "list1" : "list2") << "++" << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? list1++ : list2++;
				cout << "���������: " << (active ? list1 : list2) << endl;
				} break;
			// �������� �������� �� ������ ������
			case '4': {
				system("cls");
				if ((active ? list1.isEmpty() : list2.isEmpty())) {
					cout << "������ ����, �������� ����������!" << endl;
					break;
				}
				cout << "��������: --" << (active ? "list1" : "list2") << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? --list1 : --list2;
				cout << "���������: " << (active ? list1 : list2) << endl;
				} break;
			// �������� �������� �� ����� ������
			case '5': {
				system("cls");
				if ((active ? list1.isEmpty() : list2.isEmpty())) {
					cout << "������ ����, �������� ����������!" << endl;
					break;
				}
				cout << "��������: " << (active ? "list1" : "list2") << "--" << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? list1-- : list2--;
				cout << "���������: " << (active ? list1 : list2) << endl;
				} break;
			// ������� ����� ������
			case '6': {
				system("cls");
				cout << "��������: list3 = " << (active ? "list1" : "list2") << endl;
				cout << (active ? "list1: " : "list2 : ") << (active ? list1 : list2) << endl;
				active ? list3 = list1 : list3 = list2;
				cout << "���������:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// �������� ������ � ������ �������
			case '7': {
				system("cls");
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				cout << "���������" << endl;
				cout << "list1 == list2 " << boolalpha << (list1 == list2) << endl;
				cout << "list1 != list2 " << boolalpha << (list1 != list2) << endl;
				cout << "list1 >= list2 " << boolalpha << (list1 >= list2) << endl;
				cout << "list1 <= list2 " << boolalpha << (list1 <= list2) << endl;
				cout << "list1 > list2 " << boolalpha << (list1 > list2) << endl;
				cout << "list1 < list2 " << boolalpha << (list1 < list2) << endl;
				} break;
			// �������� ������� ������
			case '8': {
				system("cls");
				if ((active ? list1.isEmpty() : list2.isEmpty())) {
					cout << "������ ����, �������� ����������!" << endl;
					break;
				}
				cout << "��������: " << (active ? "list1" : "list2") << "[ ]" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				cout << "������� ������ � ������: ";
				int index;
				cin >> index;
				if (index < 0) {
					cout << "�������� ������ ������ ���� �� �������������!" << endl;
					break;
				}
				if (index > (active ? list1.size() : list2.size()) - 1) {
					cout << "�������� ������ ������ ������� ������!" << endl;
					break;
				}
				cout << "���������: " << (active ? "list1[" : "list2[") << index << "] = "
					 << (active ? list1[index] : list2[index]) << endl;
				} break;
			// �������� ���������
			case '9': {
				system("cls");
				if ((active ? list1.isEmpty() : list2.isEmpty())) {
					cout << "������ ����, �������� ����������!" << endl;
					break;
				}
				cout << "��������: list3 = " << (active ? "list1" : "list2") << "( , )" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				int index1, index2;
				cout << "������� ����� ������ � ������: ", cin >> index1;
				cout << "������� ������ ������ � ������: ", cin >> index2;
				if (index1 < 0 || index2 < 0 || index1 > index2) {
					cout << "��������� �������� ������ ���� �� �������������,"<< endl
						<< "��� ���� ��������� ������ ������ ���� ������ ��������� �������!" << endl;
					break;
				}
				if (index1 > (active ? list1.size() : list2.size()) - 1) {
					cout << "�������� ���������� ������� ������ ������� ������!" << endl;
					break;
				}
				active ? list3 = list1(index1, index2) : list3 = list2(index1, index2);
				cout << "���������:\nlist3: " << list3 << endl;
				} break;
			// ������� ������ �����������
			case '+': {
				system("cls");
				cout << "��������: list3 = list1 + list2" << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				list3 = list1 + list2;
				cout << "��������:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// ������� ������ �����������
			case '-': {
				system("cls");
				cout << "��������: list3 = " << (active ? "list1 - " : "list2 - ") << (active ? "list2" : "list1") << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				active ? list3 = list1 - list2 : list3 = list2 - list1;
				cout << "���������:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// �������� ������ �����������
			case '*': {
				system("cls");
				cout << "��������: list3 = list1 * list2" << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				list3 = list1 * list2;
				cout << "��������:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// ��������� ������ �����������
			case '/': {
				system("cls");
				cout << "��������: list3 = " << (active ? "list1 / " : "list2 / ") << (active ? "list2" : "list1") << endl;
				cout << "list1: " << list1 << endl << "list2: " << list2 << endl;
				active ? list3 = list1 / list2 : list3 = list2 / list1;
				cout << "��������:\nlist3: " << list3 << endl;
				list3.clear();
				} break;
			// ������� ������ �� �����
			case 'a': {
				system("cls");
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				} break;
			// �������� ������ ������� ������
			case 'b': {
				system("cls");
				if ((active ? list1.isEmpty() : list2.isEmpty())) {
					cout << "������ ����, �������� ����������!" << endl;
					break;
				}
				cout << "��������: " << (active ? "list1" : "list2") << ".front()" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				cout << "���������: " << (active ? list1.front() : list2.front()) << endl;
				} break;
			// �������� ��������� ������� ������
			case 'c': {
				system("cls");
				if ((active ? list1.isEmpty() : list2.isEmpty())) {
					cout << "������ ����, �������� ����������!" << endl;
					break;
				}
				cout << "��������: " << (active ? "list1" : "list2") << ".back()" << endl;
				cout << (active ? "list1: " : "list2: ") << (active ? list1 : list2) << endl;
				cout << "���������: " << (active ? list1.back() : list2.back()) << endl;
				} break;
			// �������� ������
			case 'd': {
				system("cls");
				cout << "��������: " << (active ? "list1" : "list2") << ".clear()" << endl;
				active ? list1.clear() : list2.clear();
				} break;
			// ������� ������
			case 'e': {
			} break;
			// ����� �� ���������
			case 'f': {
				system("cls");
				return 0;
				} break;
			}
			system("pause");
		}
		in.clear();
	}
}