#include "gtest/gtest.h"
#include <division.h>

#define VI std::vector<int>

class DividerTest : public ::testing::Test {
  protected:
    VI numerators = {5, 9, 17, 9999};
    VI denominators = {2, 3, 19, 10000};
    VI divisions = {2, 3, 0, 0};
    VI remainders = {1, 0, 17, 9999};

    virtual void SetUp(){};

    virtual void TearDown(){};

    virtual void verify(int index) {
        Fraction f = Fraction{numerators.at(index), denominators.at(index)};
        DivisionResult expected = DivisionResult{divisions.at(index), remainders.at(index)};
        DivisionResult result = Division(f).divide();
        EXPECT_EQ(result.division, expected.division);
        EXPECT_EQ(result.remainder, expected.remainder);
    }
};

TEST_F(DividerTest, 5_DivideBy_2) { verify(0); }

TEST_F(DividerTest, 9_DivideBy_3) { verify(1); }

TEST_F(DividerTest, 17_DivideBy_19) { verify(2); }

TEST_F(DividerTest, 9999_DivideBy_10000) { verify(3); }

TEST_F(DividerTest, DivisionByZero) {
    Division d = Division(Fraction{1, 0});
    try {
        d.divide();
        FAIL() << "Expected divide() method to throw DivisionByZeroException";
    } catch (DivisionByZero excp) {
        EXPECT_EQ(excp.what(), "Division by zero is illegal");
    } catch (...) {
        FAIL() << "Expected DivisionByZeroException!";
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}