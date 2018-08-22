
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "sample1.h"
#include "gtest/gtest.h"

namespace {

  // Tests Binary Tree for Max Distinct Path Value
  TEST(BinartTreeTest, Trivial) {
    
    EXPECT_EQ(4, solution());
    
  }

}


// TO DO:
// isEmpty() 

// Larger Data Sets

 //EXPECT_FALSE((1) == (solution()));
 //EXPECT_FALSE((2) == (solution()));
 //EXPECT_FALSE((3) == (solution()));

 //EXPECT_FALSE((5) == (solution()));

