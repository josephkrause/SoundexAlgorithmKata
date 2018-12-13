//
// Created by josephkrause on 12/13/2018.
//

#include "Soundex.h"

string Soundex::zeroPad(const string& word)const
{
    return word + "000";
}

string Soundex::encode(const string& word) const
{
    return zeroPad(word);
}