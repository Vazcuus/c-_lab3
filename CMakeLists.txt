cmake_minimum_required(VERSION 3.15)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(lab3 VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(lab3_c ListTypeContainer.cpp)
add_executable(lab3_c2 SequenceContainer.cpp)
add_library(lab3 lib.cpp)
add_executable(test_version test_version.cpp)

set_target_properties(lab3_c lab3 lab3_c2 test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(lab3
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(lab3_c PRIVATE
    lab3
)
target_link_libraries(lab3_c2 PRIVATE
    lab3
)
target_link_libraries(test_version
    ${Boost_LIBRARIES}
    lab3
)




install(TARGETS lab3_c RUNTIME DESTINATION bin)
install(TARGETS lab3_c2 RUNTIME DESTINATION bin)

if (APPLE)
    set(CPACK_GENERATOR ZIP)
else()
    set(CPACK_GENERATOR DEB)
endif()



set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

add_test(test_version test_version)
