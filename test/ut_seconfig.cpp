#include <gtest/gtest.h>
#include "seconfig.h"

#define TESTFILE_NAME "../../test/res/test.config"

TEST(SEConfig, NormalTestForSomeValue)
{
    SEConfig config(TESTFILE_NAME);
    EXPECT_EQ("123" ,config.stringOf("home"));
    EXPECT_EQ("123" ,config.stringOf("3421"));
    EXPECT_EQ("321" ,config.stringOf("test"));
}

TEST(SEConfig, NormalTestForEmptyValue)
{
    SEConfig config(TESTFILE_NAME);
    EXPECT_EQ("" ,config.stringOf("home123"));
    EXPECT_EQ("123" ,config.stringOf("home"));
    EXPECT_EQ("" ,config.stringOf("home321"));
    EXPECT_EQ("" ,config.stringOf("home32133"));
}

TEST(SEConfig, SecondGlobalCategory)
{
    SEConfig config(TESTFILE_NAME);
    EXPECT_EQ("123" ,config.stringOf("home"));
    EXPECT_EQ("123" ,config.stringOf("3421"));
    EXPECT_EQ("321" ,config.stringOf("test"));


    EXPECT_EQ("555" ,config.stringOf("shit"));
}

TEST(SEConfig, ThirdGlobalCrossNormalCategory)
{
    SEConfig config(TESTFILE_NAME);
    EXPECT_EQ("123" ,config.stringOf("home"));
    EXPECT_EQ("123" ,config.stringOf("3421"));
    EXPECT_EQ("321" ,config.stringOf("test"));


    EXPECT_EQ("555" ,config.stringOf("shit"));
    EXPECT_EQ("444" ,config.stringOf("fuck"));
}

TEST(SEConfig, NormalTestForOverlap)
{
    SEConfig config(TESTFILE_NAME);
    EXPECT_EQ("333" ,config.stringOf("nihao"));
}

TEST(SEConfig, SpecialCategoryGet)
{
    SEConfig config(TESTFILE_NAME);
    EXPECT_EQ("345" ,config.stringOf("nihao", "Test"));
    EXPECT_EQ("333" ,config.stringOf("nihao", "Global"));
    EXPECT_EQ("333" ,config.stringOf("nihao"));
}

TEST(SEConfig, NormalGetInt)
{
    SEConfig config(TESTFILE_NAME);
    EXPECT_EQ(333, config.intOf("nihao"));

}

