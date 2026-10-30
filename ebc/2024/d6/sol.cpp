#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream fin("data.txt");
    string s;
    fin >> s;
    cout << s << endl;
}