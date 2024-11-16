#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

void buildMap(int level, string filename, map<string, vector<char>> &markovMap)
{
    ifstream f(filename);
    string fl;
    char ch;
    while(f>>noskipws>>ch) {
        ch = toupper(ch);
        if(isprint(ch)) {
            fl +=ch;
        }
    }
    for(int i=0;i<fl.length()-level;i++) {
            string temp = fl.substr(i,level);
            markovMap[temp].push_back(fl[i+level]);
        }
}
string getText(const map<string, vector<char>> &markovMap, int numchar)
{
    string key;
    string total;
    string champ = markovMap.begin()->first;
    for(auto iter = markovMap.begin();iter!= markovMap.end();iter++) {
        if(iter->second.size() > markovMap.at(champ).size()) {
            champ = iter->first;
        }
    }
    total+= champ;
    key = champ;
    for(int i=0;i<numchar;i++) {
        int random = rand()%markovMap.at(key).size();
        char temp = markovMap.at(key).at(random);
        key += temp;
        total += temp;
        key.erase(0,1);
    }
    return total;
}

int main() {
    srand(time(0));
    cout << "Hello, Markov Chain!" << endl;
    cout << "Enter level (1-10): ";
    int level;
    cin >> level;
    int numchar;
    cout<< " How many charectars would you like to create?";
    cin>>numchar;
    cout << "Enter file name: ";
    string filename;
    cin >> filename;

    // finish this up

    map<string, vector<char>> markovMap;
    buildMap(level, filename, markovMap);
    string  text = getText(markovMap, numchar);
    cout<<text<<endl;
    return 0;
}
