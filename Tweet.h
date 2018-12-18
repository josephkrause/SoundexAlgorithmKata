//
// Created by josephkrause on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_TWEET_H
#define FIRSTEXAMPLE_TWEET_H

#include <iostream>
using namespace std;

class InvalidUserException : public std::invalid_argument
{
public:
    InvalidUserException(const string& user) : invalid_argument(user){}
};

class Tweet
{
    string message_;
    string user_;
public:
    static const string NULL_USER;
    Tweet(const string& msg = "", const string& user = Tweet::NULL_USER);
    bool operator<(const Tweet &rhs) const;
    bool operator==(const Tweet &rhs) const;
    bool operator!=(const Tweet &rhs) const;
    const string &getUser() const;

    bool isValid(const string& user) const;
};


#endif //FIRSTEXAMPLE_TWEET_H
