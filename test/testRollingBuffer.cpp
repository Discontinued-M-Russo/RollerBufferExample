//
// Created by Russo, Michelangelo (GE Global Research) on 3/18/18.
//

#define BOOST_TEST_MODULE ExampleTestModule
#define BOOST_TEST_DYN_LINK

#include <iostream>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include "extendedRollingBuffer.h"

using namespace std;
using namespace boost;
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(ExampleTestSuite)

    struct TestFixture
    {
        TestFixture() : i( 0 ) {
            cout << "Initialize Test" << endl;
        }

        ~TestFixture() {
            cout << "Cleanup Test" << endl;
        }
        int i ;
    };


    BOOST_FIXTURE_TEST_CASE(BoostCheckTest, TestFixture)
    {
        // Provide a test predicate (i.e. a conditional statement) that evaluates
        // to true to allow the test to pass and will not indicate a failed test.

        extendedRollingBuffer rollBuffTest(3);

        rollBuffTest.insertNewItem(2);
        // rollBuffer = [2]
        BOOST_CHECK(rollBuffTest.getCurrSize()==1);
        BOOST_CHECK(rollBuffTest.getAverage()==2);

        rollBuffTest.insertNewItem(3);
        //rollBuffer = [2,3]
        BOOST_CHECK(rollBuffTest.getCurrSize()==2);
        BOOST_CHECK(rollBuffTest.getAverage()==2.5);

        rollBuffTest.insertNewItem(1);
        //rollBuffer = [2,3,1]
        BOOST_CHECK(rollBuffTest.getCurrSize()==3);
        BOOST_CHECK(rollBuffTest.getAverage()==2);

        rollBuffTest.insertNewItem(5);
        //rollBuffer = [5,3,1]
        BOOST_CHECK(rollBuffTest.getCurrSize()==3);
        BOOST_CHECK(rollBuffTest.getAverage()==3);
    }

BOOST_AUTO_TEST_SUITE_END()

// More test suites
