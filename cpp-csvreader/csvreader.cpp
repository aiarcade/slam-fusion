#include "csvreader.h"

CSVReader::CSVReader()
{
}

void CSVReader::readFile(string fname,string sep_chars)
{
   inputFile.open(fname.c_str(),ios_base::in);
   delimiters=sep_chars;
   //Get the header
   string line;
   getline(inputFile,line);
   split (line,delimiters,head);

//   vector<string>path;
//   const string sepr=",";
//
//   for( std::vector<string>::const_iterator i = path.begin(); i != path.end(); ++i)
//       std::cout << *i << '!';

}

vector<string> CSVReader::getHead()
{
    return head;
}

//http://stdcxx.apache.org/doc/stdlibug/12-3.html
void CSVReader::split (const string& text, const string& separators,vector <string>& words) {

    size_t n     = text.length ();
    size_t start = text.find_first_not_of (separators);

    while (start < n) {
        size_t stop = text.find_first_of (separators, start);
        if (stop > n) stop = n;
        words.push_back (text.substr (start, stop-start));
        start = text.find_first_not_of (separators, stop+1);
    }
}

vector<string> CSVReader::next()
{
    string line;
    vector<string> data;
    if(getline(inputFile,line)){

        split(line,delimiters,data);
    }
    return data;
}
