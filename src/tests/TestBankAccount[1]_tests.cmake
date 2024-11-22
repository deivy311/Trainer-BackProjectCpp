add_test( StudentCodeTest.PlaceholderTest /home/latifa/projects/Trainer-BackProjectCpp/src/tests/TestBankAccount [==[--gtest_filter=StudentCodeTest.PlaceholderTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( StudentCodeTest.PlaceholderTest PROPERTIES WORKING_DIRECTORY /home/latifa/projects/Trainer-BackProjectCpp/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( TestBankAccount_TESTS StudentCodeTest.PlaceholderTest)
