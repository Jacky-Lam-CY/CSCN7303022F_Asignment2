#include<iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

typedef struct STUDENT_DATA {
	string firstName;
	string lastName;
}STUDENT_DATA;

int main() {
	string fileName = "StudentData.txt";
	vector<STUDENT_DATA> studentDataList;

	ifstream myFile(fileName);
	while (!myFile.eof()) {
		string student;
		getline(myFile, student);

		size_t pos = student.find(",");
		if (pos != string::npos) {
			studentDataList.push_back({ student.substr(pos + 1, student.length() - pos) , student.substr(0,pos) });
		}
	}

	myFile.close();
}