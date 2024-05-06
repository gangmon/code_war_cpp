cmake_minimum_required(VERSION 3.17)
project(codeWar)

set(CMAKE_CXX_STANDARD 17)

include_directories(/Users/kemi/cpp/bandit)  # 请修改为Bandit的实际路径
include_directories(/Users/kemi/cpp/igloo)
include_directories(/Users/kemi/cpp/snowhouse/include)
#add_subdirectory(snowhouse)
#add_executable(app main.cpp)
#target_link_libraries(app snowhouse)

add_executable(
        codeWar
        main.cpp
        header/duplicate_encoder.h
        header/vowel_count.h
        header/digital_root.h
        header/convert_string_to_camel_case.h
        header/calc.h
        header/common_denominators.h
        header/counting_deplicates.h header/which_are_in.h header/parse_int_reload.h header/rand.h)
