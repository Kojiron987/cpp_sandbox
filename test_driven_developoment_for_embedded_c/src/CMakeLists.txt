add_library(MyLib STATIC
  zune/RtcTime.cc
)

add_executable(MyApp main.cc)

target_link_libraries(MyApp MyLib)
