#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"

//=========Question 1==================================
void TestQ1_add(CuTest *tc) {

	int n = 5;
	double input1[5] = { 3.60, 4.78, 6.00, 10.00, 0.01 };
	double input2[5] = { 1.50, 2.00, 3.30, 9.90, 1.00 };
	double actual[5];
	double expected[5] = { 5.10, 6.78, 9.30, 19.90, 1.01 };
	add_vectors(input1, input2, actual, n);
	int i;
	for (i = 0; i < n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i], 0.009);
}

void TestQ1_add_zero(CuTest *tc) {

	int n = 5;
	double input1[5] = { 3, 4, 6, 10, 9 };
	double input2[5] = { -3, -4, -6, -10, -9 };
	double actual[5];
	double expected[5] = { 0, 0, 0, 0, 0 };
	add_vectors(input1, input2, actual, n);
	int i;
	for (i = 0; i < n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i], 0.009);
}

void TestQ1_scalar_prod(CuTest *tc) {

	int n = 5;
	double input1[5] = { 3.60, 4.78, 6.00, 10.00, 0.01 };
	double input2[5] = { 1.50, 2.00, 3.30, 9.90, 1.00 };
	double expected = 133.770;
	double actual = scalar_prod(input1, input2, n);

	CuAssertDblEquals(tc, expected, actual, 0.009);
}

void TestQ1_scalar_prod_zero(CuTest *tc) {

	int n = 5;
	double input1[5] = { 0, 0, 0, 0, 0 };
	double input2[5] = { 0, 0, 0, 0, 0 };
	double expected = 0;
	double actual = scalar_prod(input1, input2, n);

	CuAssertDblEquals(tc, expected, actual, 0.009);
}

void TestQ1_norm(CuTest *tc) {

	int n = 5;
	double input1[5] = { 3.60, 4.78, 6.00, 10.00, 0.01 };
	double expected = 13.108;
	double actual = norm2(input1, n);

	CuAssertDblEquals(tc, expected, actual, 0.009);
}

void TestQ1_norm_small(CuTest *tc) {

	int n = 5;
	double input1[5] = { 0.001, 0.002, 0.0001, 0.009, 0.0007 };
	double expected = 0.009;
	double actual = norm2(input1, n);

	CuAssertDblEquals(tc, expected, actual, 0.009);
}
//===========================================================
//=================Question 2================================
void TestQ2_false(CuTest *tc) {

	int input[3][3] = { { 6, 2, 5 }, { 6, 8, 0 }, { 3, 5, 9 } };
	int actual = is_diag_dom(input);
	int expected = 0;
	CuAssertIntEquals(tc, expected, actual);
}

void TestQ2_true(CuTest *tc) {

	int input[3][3] = { { 8, 2, 5 }, { 6, 8, 0 }, { 3, 5, 9 } };
	int actual = is_diag_dom(input);
	int expected = 1;
	CuAssertIntEquals(tc, expected, actual);
}

void TestQ2_false_neg(CuTest *tc) {

	int input[3][3] = { { 6, -2, 5 }, { 6, 8, 0 }, { 3, 5, 9 } };
	int actual = is_diag_dom(input);
	int expected = 0;
	CuAssertIntEquals(tc, expected, actual);
}

void TestQ2_true_neg(CuTest *tc) {

	int input[3][3] = { { -8, 2, 5 }, { 6, 8, 0 }, { 3, 5, 9 } };
	int actual = is_diag_dom(input);
	int expected = 1;
	CuAssertIntEquals(tc, expected, actual);
}

void TestQ2_zero(CuTest *tc) {

	int input[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	int actual = is_diag_dom(input);
	int expected = 0;
	CuAssertIntEquals(tc, expected, actual);
}
//===========================================================
//=================Question 3================================  

void TestQ3(CuTest *tc) {
	int n = 3;
	int input[3][3] = { { 1, 2, 3 }, { 5, 8, 9 }, { 0, 3, 5 } };
	int expected[9] = { 1, 5, 2, 0, 8, 3, 3, 9, 5 };
	int actual[9];
	diag_scan(input, actual);

	int i;
	for (i = 0; i < n * n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ3_2(CuTest *tc) {
	int n = 3;
	int input[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int expected[9] = { 1, 4, 2, 7, 5, 3, 8, 6, 9 };
	int actual[9];
	diag_scan(input, actual);

	int i;
	for (i = 0; i < n * n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

//===========================================================
//=================Question 4================================ 
void TestQ4_empty(CuTest *tc) {

	const char input[] = "";
	int actual[26] = { 0 };

	letter_freq(input, actual);
	int expected[26] = { 0 };

	for (int i = 0; i < 26; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ4_allSame(CuTest *tc) {

	const char input[] = "aaaaa";
	int actual[26] = { 0 };

	letter_freq(input, actual);
	int expected[26] = { 0 };
	expected[0] = 5;

	for (int i = 0; i < 26; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ4_generalMix(CuTest *tc) {

	const char input[] = "McMaster University";
	int actual[26] = { 0 };
	int expected[26] = { 1, 0, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 0, 0, 0, 2,
			2, 2, 1, 1, 0, 0, 1, 0 };

	letter_freq(input, actual);

	int i;
	for (i = 0; i < 26; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ4_num(CuTest *tc) {

	const char input[] = "000123";
	int actual[26] = { 0 };

	letter_freq(input, actual);
	int expected[26] = { 0 };

	for (int i = 0; i < 26; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

//===========================================================
//=================Question 5================================ 
void TestQ5_shorter(CuTest *tc) {

	const char input[] = "McMasterUniversity";
	char actual[20] = { 0 };
	string_copy(input, actual, 9);
	char expected[20] = "McMaster";
	CuAssertStrEquals(tc, expected, actual);
}
void TestQ5_same(CuTest *tc) {

	const char input[] = "McMasterUniversity";
	char actual[20] = { 0 };
	string_copy(input, actual, 19);
	char expected[20] = "McMasterUniversity";
	CuAssertStrEquals(tc, expected, actual);
}
void TestQ5_longer(CuTest *tc) {

	const char input[] = "McMasterUniversity";
	char actual[20] = { 0 };
	string_copy(input, actual, 20);
	char expected[20] = "McMasterUniversity";
	CuAssertStrEquals(tc, expected, actual);
}
void TestQ5_zero(CuTest *tc) {

	const char input[] = "McMasterUniversity";
	char actual[20] = { 0 };
	string_copy(input, actual, 0);
	char expected[20] = "";
	CuAssertStrEquals(tc, expected, actual);
}

//===========================================================
//=================Question 6================================   
void TestQ6_1(CuTest *tc) {
	int n = 8;
	int input[] = { 0, 0, 23, 0, -7, 0, 0, 48 };
	int actual_output_val[8] = { 0 };
	int actual_output_pos[8] = { 0 };
	efficient(input, actual_output_val, actual_output_pos, n);
	int expected_output_val[8] = { 23, -7, 48, 0, 0, 0, 0, 0 };
	int expected_output_pos[8] = { 2, 4, 7, 0, 0, 0, 0, 0 };

	for (int i = 0; i < n; i++) {
		CuAssertIntEquals(tc, expected_output_val[i], actual_output_val[i]);
		CuAssertIntEquals(tc, expected_output_pos[i], actual_output_pos[i]);
	}
}

void TestQ6_zeros(CuTest *tc) {
	int n = 8;
	int input[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int actual_output_val[8] = { 0 };
	int actual_output_pos[8] = { 0 };
	efficient(input, actual_output_val, actual_output_pos, n);
	int expected_output_val[8] = { 0 };
	int expected_output_pos[8] = { 0 };

	for (int i = 0; i < n; i++) {
		CuAssertIntEquals(tc, expected_output_val[i], actual_output_val[i]);
		CuAssertIntEquals(tc, expected_output_pos[i], actual_output_pos[i]);
	}
}

void TestQ6_combined(CuTest *tc) {
	int n = 8;
	int input[] = { 0, 0, 23, 0, -7, 0, 0, 48 };
	int actual_output_val[8] = { 0 };
	int actual_output_pos[8] = { 0 };
	int actual_output[8] = { 0 };
	efficient(input, actual_output_val, actual_output_pos, n);
	reconstruct(actual_output, 8, actual_output_val, actual_output_pos, 3);
	int expected_output[8] = { 0, 0, 23, 0, -7, 0, 0, 48 };

	for (int i = 0; i < n; i++) {
		CuAssertIntEquals(tc, expected_output[i], actual_output[i]);

	}
}

void TestQ6_one(CuTest *tc) {
	int n = 8;
	int input[] = { 0, 0, 0, 0, 0, 0, 0, 1 };
	int actual_output_val[8] = { 0 };
	int actual_output_pos[8] = { 0 };
	int actual_output[8] = { 0 };
	efficient(input, actual_output_val, actual_output_pos, n);
	reconstruct(actual_output, 8, actual_output_val, actual_output_pos, 1);
	int expected_output[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };

	for (int i = 0; i < n; i++) {
		CuAssertIntEquals(tc, expected_output[i], actual_output[i]);

	}
}

//===========================================================
//=================Question 7================================  
void TestQ7_equalSizeInputs(CuTest *tc) {

	// HARDCODED testcases
	int input_val1[] = { 11, 22, 33 };
	int input_pos1[] = { 1, 2, 7 };
	int input_val2[] = { 44, 55, 66 };
	int input_pos2[] = { 2, 4, 6 };

	// initialization
	int size_val1 = 3;
	int size_val2 = 3;
	int actual_output_val[6] = { 0 };
	int actual_output_pos[6] = { 0 };

	// addEff()
	addEff(input_val1, input_val2, actual_output_val, input_pos1, input_pos2,
			actual_output_pos, size_val1, size_val2);

	int expected_output_val[6] = { 11, 66, 55, 66, 33, 0 };
	int expected_output_pos[6] = { 1, 2, 4, 6, 7, 0 };

	for (int i = 0; i < 6; i++) {
		CuAssertIntEquals(tc, expected_output_val[i], actual_output_val[i]);
		CuAssertIntEquals(tc, expected_output_pos[i], actual_output_pos[i]);
	}
}

void TestQ7_difSizeInputs(CuTest *tc) {

	// HARDCODED testcases
	int input_val1[] = { 11, 22 };
	int input_pos1[] = { 1, 2 };
	int input_val2[] = { 44, 55, 66 };
	int input_pos2[] = { 2, 4, 6 };

	// initialization
	int size_val1 = 2;
	int size_val2 = 3;
	int actual_output_val[5] = { 0 };
	int actual_output_pos[5] = { 0 };

	// addEff()
	addEff(input_val1, input_val2, actual_output_val, input_pos1, input_pos2,
			actual_output_pos, size_val1, size_val2);

	int expected_output_val[5] = { 11, 66, 55, 66, 0 };
	int expected_output_pos[5] = { 1, 2, 4, 6, 0 };

	for (int i = 0; i < 5; i++) {
		CuAssertIntEquals(tc, expected_output_val[i], actual_output_val[i]);
		CuAssertIntEquals(tc, expected_output_pos[i], actual_output_pos[i]);
	}
}

CuSuite* Lab2GetSuite() {
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestQ1_add);
	SUITE_ADD_TEST(suite, TestQ1_add_zero);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod_zero);
	SUITE_ADD_TEST(suite, TestQ1_norm);
	SUITE_ADD_TEST(suite, TestQ1_norm_small);

	SUITE_ADD_TEST(suite, TestQ2_false);
	SUITE_ADD_TEST(suite, TestQ2_true);
	SUITE_ADD_TEST(suite, TestQ2_true_neg);
	SUITE_ADD_TEST(suite, TestQ2_false_neg);
	SUITE_ADD_TEST(suite, TestQ2_zero);

	SUITE_ADD_TEST(suite, TestQ3);
	SUITE_ADD_TEST(suite, TestQ3_2);

	SUITE_ADD_TEST(suite, TestQ4_empty);
	SUITE_ADD_TEST(suite, TestQ4_allSame);
	SUITE_ADD_TEST(suite, TestQ4_generalMix);
	SUITE_ADD_TEST(suite, TestQ4_num);

	SUITE_ADD_TEST(suite, TestQ5_shorter);
	SUITE_ADD_TEST(suite, TestQ5_same);
	SUITE_ADD_TEST(suite, TestQ5_longer);
	SUITE_ADD_TEST(suite, TestQ5_zero);

	SUITE_ADD_TEST(suite, TestQ6_1);
	SUITE_ADD_TEST(suite, TestQ6_zeros);
	SUITE_ADD_TEST(suite, TestQ6_combined);
	SUITE_ADD_TEST(suite, TestQ6_one);

	SUITE_ADD_TEST(suite, TestQ7_equalSizeInputs);
	SUITE_ADD_TEST(suite, TestQ7_difSizeInputs);

	return suite;
}

