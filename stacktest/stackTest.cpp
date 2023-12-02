#include <gtest.h>
#include "stack.h"

TEST(TStack, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> a(-5));
}
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> m(5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> v(4);
	v.Push(7);
	TStack<int> v2(v);
	EXPECT_EQ(v, v2);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> v(4);
	TStack<int> v2(v);
	v2.Push(1);
	EXPECT_NE(v, v2);
}

TEST(TStack, can_get_size)
{
	TStack<int> v(4);
	EXPECT_EQ(4, v.GetSize());
}

TEST(TStack, can_get_top)
{
	TStack<int> v(4);
	v.Push(1);
	v.Push(2);
	EXPECT_EQ(2, v.GetTop());
}

TEST(TStack, can_get_top_view)
{
	TStack<int> v(4);
	v.Push(1);
	v.Push(2);
	EXPECT_EQ(2, v.TopView());
}

TEST(TStack, can_push)
{
	TStack<int> v(4);
	v.Push(1);
	EXPECT_EQ(1, v.TopView());
}

TEST(TStack, can_get)
{
	TStack<int> v(4);
	v.Push(1);
	v.Push(2);
	int m = v.Pop();
	if (m != 2) ADD_FAILURE();
	else EXPECT_EQ(1, v.TopView());
}


TEST(TStack, throw_when_empty)
{
	TStack<int> v(4);
	ASSERT_ANY_THROW(v.Get());
}

TEST(TStack, throw_when_full)
{
	TStack<int> v(1);
	v.Push(5);
	ASSERT_ANY_THROW(v.Push(4));
}
