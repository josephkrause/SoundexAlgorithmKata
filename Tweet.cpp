//
// Created by josephkrause on 12/17/2018.
//

#include "Tweet.h"

const std::string Tweet::NULL_USER("@null");

Tweet::Tweet(const string &msg, const string &user)
{
    message_ = msg;
    user_ = user;

    if(!isValid(user_))
    {
        throw InvalidUserException(user_);
    }
}

bool Tweet::operator<(const Tweet &rhs) const
{
    if(message_ < rhs.message_)
        return true;
    if(rhs.message_ < message_)
        return false;

    return user_ < rhs.user_;
}

const string &Tweet::getUser() const
{
    return user_;
}

bool Tweet::operator==(const Tweet &rhs) const
{
    return message_ == rhs.message_ &&
           user_ == rhs.user_;
}

bool Tweet::operator!=(const Tweet &rhs) const
{
    return !(rhs == *this);
}

bool Tweet::isValid(const string& user) const
{
    return '@' == user[0];
}
