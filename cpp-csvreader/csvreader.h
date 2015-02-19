#ifndef CSVREADER_H
#define CSVREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CSVReader
{
public:
    CSVReader();
    void readFile(string *name);
    vector<string> getHead();
private:
    ofstream inputFile;
    vector<string>head;



};

#endif // CSVREADER_H
