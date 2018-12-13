//
// Created by josephkrause on 12/13/2018.
//

#include "Soundex.h"

string Soundex::zeroPad(const string& word)const
{
    auto zeroesNeeded = 4 - word.length();
    return word + string(zeroesNeeded, '0');
}

string Soundex::encode(const string& word) const
{
    return zeroPad(head(word) + encodeDigits(word));
}

string Soundex::head(const string &word) const
{
    return word.substr(0, 1);
}

string Soundex::encodeDigits(const string &word) const
{
    if(word.length() > 1)
        return "1";

    return "";
}
