#include "CppUTest/TestHarness.h"
#include "calc_repoBuildTime.h"

TEST_GROUP(calc_repoBuildTime)
{
  calc_repoBuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new calc_repoBuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(calc_repoBuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}

