add_executable(MyTest
  AllTests.cc
  main_test.cc

  led_driver/LedDriverTest.cc
  stdio/SprintfTest.cc
)

target_include_directories(MyTest
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(MyTest PRIVATE 
  CppUTest
  MyLib
)

enable_testing()
add_test(MyTest MyTest)

