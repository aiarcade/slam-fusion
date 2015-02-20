#include <iostream>
#include "csvreader.h"

using namespace std;

int main()
{

    CSVReader testreader;
    string file="/tmp/hello.csv";
    string sep=",";
    testreader.readFile(file,sep);
    vector<string> head=testreader.getHead();
    vector <string> row;
    cout<<"Headers are"<<endl;
    for( std::vector<string>::const_iterator i = head.begin(); i != head.end(); ++i)
           std::cout << *i << '!';
    cout<<endl<<"Data is"<<endl;

    while(1)
    {
        row=testreader.next();
        if(row.empty())
            break;
        for( std::vector<string>::const_iterator i = row.begin(); i != row.end(); ++i)
               std::cout << *i << '-';
        cout <<endl;

    }
    return 0;
}

