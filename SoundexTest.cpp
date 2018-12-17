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
    EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
    EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
    // Arrange

    // Act

    // Assert
    ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    // Arrange

    // Act

    // Assert
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
    // Arrange

    // Act

    // Assert
    ASSERT_THAT(soundex.encode("Acdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, CombineduplicateEncodings)
{
    // Arrange

    // Act

    // Assert
    ASSERT_THAT(soundex.encodeDigit('b'), Eq(soundex.encodeDigit('f')));
    ASSERT_THAT(soundex.encodeDigit('x'), Eq(soundex.encodeDigit('g')));
    ASSERT_THAT(soundex.encodeDigit('d'), Eq(soundex.encodeDigit('t')));
    ASSERT_THAT(soundex.encode("Abfxgdt"), Eq("A123"));
}