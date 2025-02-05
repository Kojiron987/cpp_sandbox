add_executable(MyTest
  AllTests.cc
  main_test.cc
)

target_include_directories(MyTest
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MyTest PRIVATE 
  CppUTest
  MyLib
)

enable_testing()
add_test(MyTest MyTest)
