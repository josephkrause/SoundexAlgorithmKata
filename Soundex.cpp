//
// Created by josephkrause on 12/13/2018.
//

#include <unordered_map>
#include "Soundex.h"

string Soundex::zeroPad(const string& word)const
{
    auto zeroesNeeded = MaxCodeLength - word.length();
    return word + string(zeroesNeeded, '0');
}

string Soundex::encode(const string& word) const
{
    return zeroPad(head(word) + encodeDigits(tail(word)));
}

string Soundex::head(const string &word) const
{
    return word.substr(0, 1);
}

string Soundex::tail(const string &word) const
{
    return word.substr(1);
}

string Soundex::encodeDigits(const string &word) const
{
    string encoding;

    for(auto letter : word)
    {
        if(isComplete(encoding))
        {
            break;
        }
        encoding += encodeDigit(letter);
    }

    return encoding;
}

bool Soundex::isComplete(const string &encoding) const
{
    return encoding.length() == MaxCodeLength - 1;
}

string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char, string> encoding
    {
            {'b', "1"},
            {'f', "1"},
            {'p', "1"},
            {'v', "1"},
            {'c', "2"},
            {'g', "2"},
            {'j', "2"},
            {'k', "2"},
            {'q', "2"},
            {'s', "2"},
            {'x', "2"},
            {'z', "2"},
            {'d', "3"},
            {'t', "3"},
            {'l', "4"},
            {'m', "3"},
            {'n', "5"},
            {'r', "6"}
    };

    auto it = encoding.find(letter);
    return it == encoding.end() ? "" : it->second;
}