#pragma once
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class TestFileReader {
public:
	TestFileReader(string Adress);
	pair<string, vector<double>> getData();
	bool eof();
	bool is_open();

private:
	string testFileName;
	ifstream test;
	
};
