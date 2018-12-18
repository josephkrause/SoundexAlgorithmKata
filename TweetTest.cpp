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