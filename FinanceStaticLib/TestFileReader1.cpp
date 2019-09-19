#include "pch.h"
#include "TestFileReader1.h"

#include <iostream>
#include <regex>




using namespace std;


TestFileReader::TestFileReader(string address) {
	string testFileName = "C:\\Users\\sam_e\\source\\repos\\Joshi on C++\\FinanceStaticLib\\";
	testFileName += address;
	test.open(testFileName);
	string line;
	getline(test, line);
}

pair<string, vector<double>> TestFileReader::getData() {
	vector<double> data(7);

	

	string line;
	string Type;
	pair<string, vector<double>> s;
	getline(test, line, ',');
	line.erase(remove(line.begin(), line.end(), '\n'), line.end());
	line.erase(remove(line.begin(), line.end(), '\t'), line.end());

	Type = line;
	
	


	getline(test, line, ' ');
	test >> data[0];
	
	
	

	getline(test, line, ' ');
	test >> data[1];
	


	getline(test, line, ' ');
	test >> data[2];
	



	getline(test, line, ' ');
	test >> data[3];
	



	getline(test, line, ' ');
	test >> data[4];
	
	getline(test, line, ' ');
	test >> data[5];

	getline(test, line, ' ');
	test >> data[6];

	s.first = Type;
	s.second = data;

	return s;

}

bool TestFileReader::eof() {
	return test.eof();
}