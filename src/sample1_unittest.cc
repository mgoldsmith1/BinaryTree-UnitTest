
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "sample1.h"
#include "gtest/gtest.h"

namespace {

  // Tests Binary Tree for the maximum distinct path value from root to leaf
  TEST(BinartTreeTest, Trivial) {
    EXPECT_EQ(4, solution());
  }
  
}
