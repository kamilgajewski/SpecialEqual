/*
#include <gtest/gtest.h>
#include <optional>

TEST(Tristate_Test, CreateEmptySet) {
  // Expect two strings not to be equal.
  OptionalSet setA = {};
  EXPECT_EQ(setA, std::nullopt);
}

TEST(Tristate_Test, CreateSetWithOneValidElement) {
  OptionalSet setA = {"A"};
  EXPECT_EQ(setA.value(), "A");
  EXPECT_EQ(setA.size(), 1);
}

TEST(Tristate_Test, CreateSetWithTwoValidElements){
  OptionalSet setA = {"A","B"};
  EXPECT_EQ(setA.value(), {"A","B");
  EXPECT_EQ(setA.size(), 2);
}

TEST(Tristate_Test, TaskTestCase_1){
  OptionalSet setA = {"A"};
  OptionalSet setB = {"B"};
  OptionalSet setC = {"B","A"};
  EXPECT_EQ(SpecialEqual(setA,setB,setC), FALSE)
}

TEST(Tristate_Test, TaskTestCase_2){
  OptionalSet setA = {"A","B",std::nullopt};
  OptionalSet setB = {"A"};
  OptionalSet setC = {"A",std::nullopt};
  EXPECT_EQ(SpecialEqual(setA,setB,setC), TRUE)
}

TEST(Tristate_Test, TaskTestCase_3){
  OptionalSet setA = {"A","B",std::nullopt};
  OptionalSet setB = {"A"};
  OptionalSet setC = {"B",std::nullopt};
  EXPECT_EQ(SpecialEqual(setA,setB,setC), UNDETERMINED)
}
TEST(Tristate_Test, TaskTestCase_4){
  OptionalSet setA = {"A"};
  OptionalSet setB = {"B"};
  OptionalSet setC = {"B",std::nullopt};
  EXPECT_EQ(SpecialEqual(setA,setB,setC), FALSE)
}
*/
