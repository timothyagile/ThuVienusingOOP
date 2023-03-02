#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void input(string &fileName)
{
    ifstream file;
    int sum = 0;
    file.open("Text.txt");
    getline(file, fileName);
    file.close();
    for (int i = 0; i < fileName.size(); i++)
    {
        if (fileName[i] == ' ')
            continue;
        sum += fileName[i] - 48;
    }
    cout << sum;
}
int main()
{
    string fileName;
    input(fileName);
    return 0;
}
