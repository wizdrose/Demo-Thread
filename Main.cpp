#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<thread>
#include<list>
using namespace std;
list<string> list_file;
void Write(string path,string s) {
	ofstream f;
	f.open(path, ios::out|ios::app);
	f << s <<endl;
	f.close();
}
void Read()
{
	string path = "C:\\Users\\wizdrose\\Documents\\Visual Studio 2015\\Projects\\TestThread\\TestThread\\Content\\";
	string searchPattern = "*.txt";
	string fullSearchPath = path + searchPattern;
	WIN32_FIND_DATA FindData;
	HANDLE hFind;

	hFind = FindFirstFile(fullSearchPath.c_str(), &FindData);
	string line;
	do
	{
		string filePath = path + FindData.cFileName;
		//for (list<string>::iterator it = list_file.begin(); it != list_file.end(); it++)
		//{
			//if (filePath != (*it))
			//{
				ifstream in;
				in.open(filePath.c_str(), ios::in);
				while (getline(in, line))
				{
					cout << line << endl;
					Write("C:\\Users\\wizdrose\\Documents\\Visual Studio 2015\\Projects\\TestThread\\TestThread\\Result.txt", line);
				}
				//list_file.push_back(filePath);
			//}
		//}
	} while (FindNextFile(hFind, &FindData) > 0);
	Read();
}
int main() {
	thread t1(Read);
	string s;
	do
	{
		cin >> s;
		if (s == "exit")
			break;
		Write("Result.txt",s);
	} while (s!="exit");
	t1.detach();
}