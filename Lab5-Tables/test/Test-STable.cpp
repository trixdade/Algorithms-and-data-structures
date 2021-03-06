#include"../Tables/Table.h"
#include"../gtest/gtest.h"
#include "../Tables/Sorted-table.h"
TEST(STable, can_create_a_table)
{
	ASSERT_NO_THROW(STable A);
}

TEST(STable, can_insert_a_row)
{
	STable H;
	Polynom A;
	row r;
	r.data = &A;
	r.key = "Polynom1";
	ASSERT_NO_THROW(H.Insert(r));
}

TEST(STable, can_find_a_polynom)
{
	struct m* pol;
	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
	for (int i = 0; i < 3; i++) {
		pol[i].c = i + 1;
		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	string s = "Polynom2";
	Polynom A(pol, 3);
	Polynom B;
	B = A;
	row r;
	r.data = &A;
	r.key = s;
	STable H;
	H.Insert(r);
	EXPECT_EQ(B, *H.Search(s));

}

TEST(STable, can_not_find_a_missing_polynom)
{
	struct m* pol;
	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
	for (int i = 0; i < 3; i++) {
		pol[i].c = i + 1;
		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	string s = "Polynom3";
	string s1 = "Polynom4";
	Polynom A(pol, 3);

	row r;
	r.data = &A;
	r.key = s;
	STable H;
	H.Insert(r);
	EXPECT_EQ(NULL, H.Search(s1));
}

TEST(STable, can_delete_a_polynom)
{
	struct m* pol;
	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
	for (int i = 0; i < 3; i++) {
		pol[i].c = i + 1;
		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	string s = "Polynom4";

	Polynom A(pol, 3);
	Polynom B;
	B = A;
	row r;
	r.data = &A;
	r.key = s;
	STable H;
	H.Insert(r);
	EXPECT_EQ(B, *H.Search(s));
	H.Delete(s);
	EXPECT_EQ(NULL, H.Search(s));
}