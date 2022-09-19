#include<iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

#define PRE_RELEASE

#ifdef PRE_RELEASE
#define FILENAME "StudentData_Emails.txt"
#else
#define FILENAME "StudentData.txt"
#endif // PRE_RELEASE

typedef struct STUDENT_DATA {
	string firstName;
	string lastName;
#ifdef PRE_RELEASE
	string email;
#endif
}STUDENT_DATA;

int main() {
#ifdef PRE_RELEASE
	cout << "The program is running in Pre-Release mode." << endl;
#else
	cout << "The program is running in Normal mode." << endl;
#endif

	string fileName = FILENAME;
	vector<STUDENT_DATA> studentDataList;

	ifstream myFile(fileName);
	while (!myFile.eof()) {
		string student;
		getline(myFile, student);

		//if encounter an empty line, skip to next iteration
		if (student.empty()) continue;

		//if a line ends with a ',', we will add an empty column for data later
		bool addEmptyLine = student.back() == ',';

		std::stringstream ss(student);
		std::string item;

		vector<string> data;

		//split a line of the file into vector of strings with the delimitor ','
		while (std::getline(ss, item, ','))
		{
			data.push_back(item);
		}

		//add an empty column if the line is end with ','
		if (addEmptyLine) data.push_back("");


#ifdef PRE_RELEASE
		studentDataList.push_back({ data[1] , data[0] , data[2]});
#else
		studentDataList.push_back({ data[1] , data[0] });
#endif
	}
	myFile.close();

#if _DEBUG
	for (int i = 0; i < studentDataList.size(); i++) {

#ifdef PRE_RELEASE
		cout << studentDataList[i].firstName << " " << studentDataList[i].lastName << " " << studentDataList[i].email << endl;
#else
		cout << studentDataList[i].firstName << " " << studentDataList[i].lastName << endl;
#endif

	}
#endif
}