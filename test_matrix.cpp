#define BOOST_TEST_MODULE test_ip_filter

#include "matrix.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_matrix)

BOOST_AUTO_TEST_CASE(test_value)
{
    Matrix<int, -1> matrix;

    matrix[0][0] = -1;
    matrix[0][1] = 1;
    matrix[0][2] = 100;

    BOOST_CHECK(matrix[0][0] == -1);
    BOOST_CHECK(matrix[0][1] == 1);
    BOOST_CHECK(matrix[0][2] == 100);
    BOOST_CHECK(matrix[0][3] == -1);
    BOOST_CHECK(matrix.size() == 2);
}

BOOST_AUTO_TEST_CASE(test_size)
{
    Matrix<int, -1> matrix;

    BOOST_CHECK(matrix.size() == 0);

    matrix[1][1] = 1;
    matrix[1][2] = 1;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;

    BOOST_CHECK(matrix.size() == 5);
    BOOST_CHECK(matrix[1].size() == 2);
    BOOST_CHECK(matrix[2].size() == 3);
}

BOOST_AUTO_TEST_CASE(test_op_eq)
{
    Matrix<int, -1> matrix;
    ((matrix[100][100] = 314) = 0) = 217;

    BOOST_CHECK(matrix.size() == 1);
    BOOST_CHECK(matrix[100][100] == 217);
}

BOOST_AUTO_TEST_SUITE_END()
