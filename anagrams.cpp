#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>

using namespace std;

int vocabularyCreator(istream& dictfile, string dict[]);
int potentialSequences(string word, const string dict[], int size, string results[]);
void outcomeDisclosure(const string results[], int size);
void checkPermutations(string rest, string prefix, const string dict[], int& temp, string results[]);
bool checkDuplicate(string prefix, string results[], int& temp);
void duplicateLoop(int i, int max, string prefix, string results[], bool& dup);
void Loop(int i, int max, string& prefix, string& rest, const string dict[], int& temp, string results[]);
void checkDict(int start, int end, string prefix, const string dict[], int& temp, string results[]);

const int MAXRESULTS = 20;      // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int main()
{
    return 0;
}
//good!
int vocabularyCreator(istream& dictfile, string dict[])
{
    if (dictfile.eof())
    {
        return 0;
    }
    dictfile >> dict[0];
    int wordCount = vocabularyCreator(dictfile, dict + 1);
    if (wordCount >= MAXDICTWORDS)
    {
        return MAXDICTWORDS;
    }
    else
    {
        ++wordCount;
        return wordCount;
    }
}
// words = 25144
//good!
int potentialSequences(string word, const string dict[], int size, string results[])
{
    int resultsize = 0;

    checkPermutations(word, "", dict, resultsize, results);

    return resultsize;
}
//good!
void outcomeDisclosure(const string results[], int size)
{
    if (size == 0)
    {
        return;
    }
    cout << "Matching word " << results[size - 1] << endl;
    outcomeDisclosure(results, size - 1);
}
//good!
void checkPermutations(string rest, string prefix, const string dict[], int& temp, string results[])
{
    if (rest.length() == 0)
    {
        checkDict(0, MAXDICTWORDS - 1, prefix, dict, temp, results);
        return;
    }
    Loop(0, rest.length(), prefix, rest, dict, temp, results);
}
//good!
void checkDict(int start, int end, string prefix, const string dict[], int& temp, string results[])
{
    if (start > end || start >= MAXDICTWORDS)
    {
        return;
    }

    if (prefix == dict[start] && !checkDuplicate(prefix, results, temp))
    {
        results[temp] = dict[start];
        temp += 1;
    }

    int middle = (start + end) / 2;
    if (prefix == dict[middle] && !checkDuplicate(prefix, results, temp))
    {
        results[temp] = dict[middle];
        temp += 1;
    }


    checkDict(start + 1, middle - 1, prefix, dict, temp, results);
    checkDict(middle + 1, end, prefix, dict, temp, results);
}
//good!
bool checkDuplicate(string prefix, string results[], int& temp)
{
    bool dup = false;
    duplicateLoop(0, temp, prefix, results, dup);
    return dup;
}
//good!
void duplicateLoop(int i, int max, string prefix, string results[], bool& dup)
{
    if (i >= max)
    {
        return;
    }
    if (prefix == results[i])
        dup = true;
    duplicateLoop(i + 1, max, prefix, results, dup);
}
//good!
void Loop(int i, int max, string& prefix, string& rest, const string dict[], int& temp, string results[])
{
    if (i >= max)
    {
        return;
    }
    else
    {
        char ch = rest[i];
        string left_substr = rest.substr(0, i);
        string right_substr = rest.substr(i + 1);
        string x = left_substr + right_substr;
        checkPermutations(x, prefix + ch, dict, temp, results);
        Loop(i + 1, max, prefix, rest, dict, temp, results);
    }
}