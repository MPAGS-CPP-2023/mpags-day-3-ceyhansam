# - Build sub-script for the MPAGSCipher Library

# - Declare the build of the static MPAGSCipher library
add_library(MPAGSCipher STATIC
    CipherMode.hpp
    CeaserCipher.hpp
    CeaserCipher.cpp
    ProcessCommandLine.hpp
    ProcessCommandLine.cpp
    TransformChar.hpp
    TransformChar.cpp
    )

target_include_directories(MPAGSCipher
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(MPAGSCipher
    PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization
)