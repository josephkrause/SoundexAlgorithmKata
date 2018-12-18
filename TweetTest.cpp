//
// Created by josephkrause on 12/18/2018.
//

#include <gmock/gmock.h>
#include "Tweet.h"

using namespace std;
using namespace ::testing;

TEST(ATweet, DefaultUserNotNullWhenNoneProvided)
{
    Tweet tweet("msg");

    ASSERT_THAT(tweet.getUser(), Eq("@null"));
}

TEST(ATweet, IsEqualToAnotherWhenMessageAndUserAreEqual)
{
    Tweet tweet("msg", "@user");
    Tweet duplicate("msg", "@user");

    ASSERT_THAT(tweet, Eq(duplicate));
}

TEST(ATweet, IsNotEqualToAnotherWhenMessageAndUserAreNotEqual)
{
    Tweet tweet("msg", "@user");
    Tweet duplicate("msg1", "@user1");

    ASSERT_THAT(tweet, Ne(duplicate));
}

TEST(ATweet, IsLessThanWhenUserAndMessageAre)
{
    Tweet a("msg1", "@user1");
    Tweet b("msg2", "@user2");

    ASSERT_THAT(a, Lt(b));
}

TEST(ATweet, CanCopyConstructed)
{
    Tweet a("msgA", "@user");
    Tweet b(a);

    ASSERT_THAT(a, Eq(b));
}

TEST(ATweet, RequiresUserToStartWithAtSign)
{
    string invalidUser("notStartingWith@");

    ASSERT_THROW(Tweet tweet("msg", invalidUser), InvalidUserException);
}

TEST(ATweet, RequiresUserToStartWithAtSign2)
{
    string invalidUser("notStartingWith@");

    try
    {
        Tweet tweet("msg", invalidUser);
        FAIL();
    }
    catch(const InvalidUserException& expected){}

    ASSERT_THROW(Tweet tweet("msg", invalidUser), InvalidUserException);
}