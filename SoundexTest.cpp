#include <gmock/gmock.h>
#include "Soundex.h"
using ::testing::Eq;

class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    // Arrange

   // Act

   // Assert
   ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroesToEnsureThreeDigits)
{
    // Arrange

    // Act

    // Assert
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    // Arrange

    // Act

    // Assert
    ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}

