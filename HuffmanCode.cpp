#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return (a.second < b.second);
}

int main(){
    string sentence;
    cout << "String to encode: ";
    getline(cin, sentence);
    set<char> wordSet(sentence.begin(), sentence.end());
    map<string, int> freqTable;
    map<char, string> codeTable;

    for(auto i = wordSet.begin(); i != wordSet.end(); i++){
        string s;
        freqTable.emplace(s+=*i, int(count(sentence.begin(), sentence.end(), *i)));
        codeTable.emplace(*i, "");
    }

    cout << "Frequency: " << endl;
    for(auto i:freqTable){
        cout << i.first << " : " << i.second << endl;
    }

    for(int i = 1; i < wordSet.size(); i++){
        auto min1 = min_element(freqTable.begin(), freqTable.end(), comp);
        for(auto j:min1->first){
            codeTable[j].insert(0,"0");
        }
        string sMin = min1->first;
        int fMin = min1->second;
        freqTable.erase(min1);

        auto min2 = min_element(freqTable.begin(), freqTable.end(), comp);
        for(auto j:min2->first){
            codeTable[j].insert(0,"1");
        }
        sMin += min2->first;
        fMin += min2->second;
        freqTable.erase(min2);
        freqTable.emplace(sMin, fMin);
    }

    cout << "mapping result: " << endl;
    for(auto i:codeTable){
        cout << i.first << " : " << i.second << endl;
    }

    cout << "encoded string: ";
    for(auto i:sentence){
        cout << codeTable[i];
    }

    cout << endl;
    return 0;
}