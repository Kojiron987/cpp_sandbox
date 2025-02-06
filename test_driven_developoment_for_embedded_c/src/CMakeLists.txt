add_library(MyLib STATIC
  zune/RtcTime.cc
  led_driver/LedDriver.cc
)

target_include_directories(MyLib PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(MyApp main.cc)

target_link_libraries(MyApp MyLib)
