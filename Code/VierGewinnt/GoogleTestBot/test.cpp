#include "pch.h"
#include "BotHelper.h"

BotHelper bh = BotHelper();

TEST(TestCaseName, TestName) {
	EXPECT_EQ(0, bh.spalteHorizontal());
}
