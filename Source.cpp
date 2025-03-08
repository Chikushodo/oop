#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cout << "������� ������ ������� ����� �����: ";
    cin >> N;

    vector<int> numbers; 
    numbers.reserve(N);  

    cout << "������� " << N << " �����:" << endl;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num); 
    }

    cout << "����� � �������� �������: ";
    for (int i = numbers.size() - 1; i >= 0; --i) {
        cout << numbers[i] << " "; 
    }
    cout << endl;

    cout << "\n������� ������ ������� �����: ";
    cin >> N;
    cin.ignore();

    vector<string> strings;
    strings.reserve(N);

    cout << "������� " << N << " �����:" << endl;
    for (int i = 0; i < N; ++i) {
        string str;
        getline(cin, str); 
        strings.push_back(str); 
    }

    cout << "������� �������� ��� ���� �������..." << endl;
    string extraString;
    cout << "������� �������������� ������: ";
    getline(cin, extraString);
    strings.push_back(extraString); 

    cout << "���������� ������� �����:" << endl;
    for (const string& s : strings) { 
        cout << s << endl;
    }
}

