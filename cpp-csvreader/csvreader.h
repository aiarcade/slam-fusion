#ifndef CSVREADER_H
#define CSVREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <alloca.h>


using namespace std;

class CSVReader
{
public:
    CSVReader();
    void readFile(string name,string delimiters);
    vector<string> getHead();
    void split(const string& text, const string& separators,vector <string>& words);
    vector<string> next();
private:
    ifstream inputFile;
    vector<string>head;
    vector<int>::iterator fileIter;
    string delimiters;



};

#endif // CSVREADER_H
