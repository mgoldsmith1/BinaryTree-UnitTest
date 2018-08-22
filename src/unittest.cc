
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "header.h"
#include "gtest/gtest.h"

namespace {

  // Tests Binary Tree for the maximum distinct path value from root to leaf
  TEST(BinartTreeTest, Trivial) {
    EXPECT_EQ(4, solution());
  }
  
}
