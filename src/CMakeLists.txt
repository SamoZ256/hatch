add_library(hatch-lib
    builder.cpp
    parser.cpp
)

target_include_directories(hatch-lib PUBLIC ../include)
target_link_libraries(hatch-lib PRIVATE toml11::toml11)

add_executable(hatch-cli
    cli/main.cpp
)

target_link_libraries(hatch-cli PRIVATE hatch-lib)
