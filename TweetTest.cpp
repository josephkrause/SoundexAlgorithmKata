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