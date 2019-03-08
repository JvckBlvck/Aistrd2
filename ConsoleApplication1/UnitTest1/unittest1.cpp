#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/equal.h"
#include "../ConsoleApplication1/tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(equal_arrays_int_size_0)
		{
			int*array1 = new int[0];
			int*array2 = new int[0];
			Assert::IsTrue(equal_arrays(array1, 0, array2, 0));
		}
		TEST_METHOD(equal_arrays_char_size_5)
		{
			int*array1 = new int[5];
			array1[0] = 'a';
			array1[1] = 'b';
			array1[2] = 'c';
			array1[3] = 'd';
			array1[4] = 'e';
			int*array2 = new int[5];
			array2[0] = 'a';
			array2[1] = 'b';
			array2[2] = 'c';
			array2[3] = 'd';
			array2[4] = 'e';
			Assert::IsTrue(equal_arrays(array1, 5, array2, 5));
		}
		TEST_METHOD(insert_int_size_3)
		{
			tree<int> mytree;
			mytree.insert(13, 13);
			mytree.insert(8, 8);
			mytree.insert(17, 17);
			int*array1data = new int[3];
			array1data[0] = 13;
			array1data[1] = 8;
			array1data[2] = 17;
			size_t*array1key = new size_t[3];
			array1key[0] = 13;
			array1key[1] = 8;
			array1key[2] = 17;
			char*array1color = new char[3];
			array1color[0] = 'b';
			array1color[1] = 'r';
			array1color[2] = 'r';
			size_t i = 0;
			int*array2data = new int[3];
			size_t*array2key = new size_t[3];
			char*array2color = new char[4];
			for (Iterator<int> *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					array2data[i] = tmp->current_data();
					array2key[i] = tmp->current_key();
					array2color[i] = tmp->current_color();
					i++;
				}
			Assert::IsTrue(equal_arrays(array1key, 3, array2key, 3) && equal_arrays(array1color, 3, array2color, 3) && equal_arrays(array1data, 3, array2data, 3));
		}
		TEST_METHOD(inseret_int_size_4)
		{
			tree<int> mytree;
			mytree.insert(13, 13);
			mytree.insert(8, 8);
			mytree.insert(17, 17);
			mytree.insert(18, 18);
			int*array1data = new int[4];
			array1data[0] = 13;
			array1data[1] = 8;
			array1data[2] = 17;
			array1data[3] = 18;
			size_t*array1key = new size_t[4];
			array1key[0] = 13;
			array1key[1] = 8;
			array1key[2] = 17;
			array1key[3] = 18;
			char*array1color = new char[4];
			array1color[0] = 'b';
			array1color[1] = 'b';
			array1color[2] = 'b';
			array1color[3] = 'r';
			size_t i = 0;
			int*array2data = new int[4];
			size_t*array2key = new size_t[4];
			char*array2color = new char[4];
			for (Iterator<int> *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					array2data[i] = tmp->current_data();
					array2key[i] = tmp->current_key();
					array2color[i] = tmp->current_color();
					i++;
				}
			Assert::IsTrue(equal_arrays(array1key, 4, array2key, 4) && equal_arrays(array1color, 4, array2color, 4) && equal_arrays(array1data, 4, array2data, 4));
		}
		TEST_METHOD(inseret_int_size_7)
		{
			tree<int> mytree;
			mytree.insert(13, 13);
			mytree.insert(9, 9);
			mytree.insert(15, 15);
			mytree.insert(8, 8);
			mytree.insert(10, 10);
			mytree.insert(12, 12);
			mytree.insert(11, 11);
			int*array1data = new int[7];
			array1data[0] = 13;
			array1data[1] = 9;
			array1data[2] = 15;
			array1data[3] = 8;
			array1data[4] = 11;
			array1data[5] = 10;
			array1data[6] = 12;
			size_t*array1key = new size_t[7];
			array1key[0] = 13;
			array1key[1] = 9;
			array1key[2] = 15;
			array1key[3] = 8;
			array1key[4] = 11;
			array1key[5] = 10;
			array1key[6] = 12;
			char*array1color = new char[7];
			array1color[0] = 'b';
			array1color[1] = 'r';
			array1color[2] = 'b';
			array1color[3] = 'b';
			array1color[4] = 'b';
			array1color[5] = 'r';
			array1color[6] = 'r';
			size_t i = 0;
			int*array2data = new int[7];
			size_t*array2key = new size_t[7];
			char*array2color = new char[7];
			for (Iterator<int> *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					array2data[i] = tmp->current_data();
					array2key[i] = tmp->current_key();
					array2color[i] = tmp->current_color();
					i++;
				}
			Assert::IsTrue(equal_arrays(array1key, 7, array2key, 7) && equal_arrays(array1color, 7, array2color, 7) && equal_arrays(array1data, 7, array2data, 7));
		}
		TEST_METHOD(remove_char_head)
		{
			tree<char> mytree;
			mytree.insert(13, 'a');
			mytree.insert(9, 'b');
			mytree.remove(13);
			char*array1data = new char[1];
			array1data[0] = 'b';
			size_t*array1key = new size_t[1];
			array1key[0] = 9;
			char*array1color = new char[1];
			array1color[0] = 'b';
			size_t i = 0;
			char*array2data = new char[1];
			size_t*array2key = new size_t[1];
			char*array2color = new char[1];
			for (Iterator<char> *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					array2data[i] = tmp->current_data();
					array2key[i] = tmp->current_key();
					array2color[i] = tmp->current_color();
					i++;
				}
			Assert::IsTrue(equal_arrays(array1key, 1, array2key, 1) && equal_arrays(array1color, 1, array2color, 1) && equal_arrays(array1data, 1, array2data, 1));
		}
		TEST_METHOD(remove_char_size_5)
		{
			tree<char> mytree;
			mytree.insert(13, 'a');
			mytree.insert(9, 'b');
			mytree.insert(12, 'c');
			mytree.insert(14, 'd');
			mytree.insert(8, 'e');
			mytree.remove(9);
			char*array1data = new char[4];
			array1data[0] = 'c';
			array1data[1] = 'e';
			array1data[2] = 'a';
			array1data[3] = 'd';
			size_t*array1key = new size_t[4];
			array1key[0] = 12;
			array1key[1] = 8;
			array1key[2] = 13;
			array1key[3] = 14;
			char*array1color = new char[4];
			array1color[0] = 'b';
			array1color[1] = 'b';
			array1color[2] = 'b';
			array1color[3] = 'r';
			size_t i = 0;
			char*array2data = new char[4];
			size_t*array2key = new size_t[4];
			char*array2color = new char[4];
			for (Iterator<char> *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					array2data[i] = tmp->current_data();
					array2key[i] = tmp->current_key();
					array2color[i] = tmp->current_color();
					i++;
				}
			Assert::IsTrue(equal_arrays(array1key, 4, array2key, 4) && equal_arrays(array1color, 4, array2color, 4) && equal_arrays(array1data, 4, array2data, 4));
		}
		TEST_METHOD(remove_many_nodes_char)
		{
			tree<char> mytree;
			mytree.insert(13, 'a');
			mytree.insert(9, 'b');
			mytree.insert(12, 'c');
			mytree.insert(14, 'd');
			mytree.insert(7, 'f');
			mytree.insert(11, 'g');
			mytree.insert(23, 'h');
			mytree.insert(19, 'i');
			mytree.insert(1, 'j');
			mytree.insert(4, 'k');
			mytree.insert(6, 'l');
			mytree.remove(4);
			mytree.remove(9);
			mytree.remove(7);
			mytree.remove(19);
			mytree.remove(23);
			mytree.remove(11);
			char*array1data = new char[5];
			array1data[0] = 'c';
			array1data[1] = 'l';
			array1data[2] = 'd';
			array1data[3] = 'j';
			array1data[4] = 'a';
			size_t*array1key = new size_t[5];
			array1key[0] = 12;
			array1key[1] = 6;
			array1key[2] = 14;
			array1key[3] = 1;
			array1key[4] = 13;
			char*array1color = new char[5];
			array1color[0] = 'b';
			array1color[1] = 'b';
			array1color[2] = 'b';
			array1color[3] = 'r';
			array1color[4] = 'b';
			size_t i = 0;
			char*array2data = new char[5];
			size_t*array2key = new size_t[5];
			char*array2color = new char[5];
			for (Iterator<char> *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					array2data[i] = tmp->current_data();
					array2key[i] = tmp->current_key();
					array2color[i] = tmp->current_color();
					i++;
				}
			Assert::IsTrue(equal_arrays(array1key, 5, array2key, 5) && equal_arrays(array1color, 5, array2color, 5) && equal_arrays(array1data, 5, array2data, 5));
		}
		TEST_METHOD(finding_double_contains)
		{
			tree<double> mytree;
			mytree.insert(1, 5.2);
			mytree.insert(2, 6.2);
			mytree.insert(3, 7.2);
			mytree.insert(4, 8.2);
			int check;
			double finded;
			mytree.finding(&check, &finded, 3);
			Assert::AreEqual(7.2, finded);
		}
		TEST_METHOD(finding_double_dont_contains)
		{
			tree<double> mytree;
			mytree.insert(1, 5.2);
			mytree.insert(2, 6.2);
			mytree.insert(3, 7.2);
			mytree.insert(4, 8.2);
			int check;
			double finded;
			mytree.finding(&check, &finded, 5);
			Assert::AreEqual(-1, check);
		}
		TEST_METHOD(clear_double)
		{
			tree<double> mytree;
			mytree.insert(1, 5.2);
			mytree.insert(2, 6.2);
			mytree.insert(3, 7.2);
			mytree.insert(4, 8.2);
			mytree.clear();
			double*array1data = new double[0];
			double*array2data = new double[0];
			char*array1color = new char[0];
			char*array2color = new char[0];
			size_t i = 0;
			size_t*array1key = new size_t[0];
			size_t*array2key = new size_t[0];
			for (Iterator<double> *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					array2data[i] = tmp->current_data();
					array2key[i] = tmp->current_key();
					array2color[i] = tmp->current_color();
					i++;
				}
			Assert::IsTrue(equal_arrays(array1key, 0, array2key, 0) && equal_arrays(array1color, 0, array2color, 0) && equal_arrays(array1data, 0, array2data, 0));
		}
		TEST_METHOD(get_keys_int)
		{
			tree<int> mytree;
			mytree.insert(13, 13);
			mytree.insert(9, 9);
			mytree.insert(15, 15);
			mytree.insert(8, 8);
			mytree.insert(10, 10);
			mytree.insert(12, 12);
			mytree.insert(11, 11);
			list<size_t> list1 = mytree.get_keys();
			list<size_t> list2;
			list2.push_back(13);
			list2.push_back(9);
			list2.push_back(15);
			list2.push_back(8);
			list2.push_back(11);
			list2.push_back(10);
			list2.push_back(12);
			Assert::IsTrue(equal_lsits(list1, list2));
		}
		TEST_METHOD(get_values_int)
		{
			tree<int> mytree;
			mytree.insert(13, 15);
			mytree.insert(9, 11);
			mytree.insert(15, 17);
			mytree.insert(8, 10);
			mytree.insert(10, 12);
			mytree.insert(12, 14);
			mytree.insert(11, 13);
			list<int> list1 = mytree.get_values();
			list<int> list2;
			list2.push_back(15);
			list2.push_back(11);
			list2.push_back(17);
			list2.push_back(10);
			list2.push_back(13);
			list2.push_back(12);
			list2.push_back(14);
			Assert::IsTrue(equal_lsits(list1, list2));
		}
	};
}