project(interpreter)
# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 11)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE /home/arina/CLionProjects/antlr-4.8-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(SampleGrammarLexer grammar/JavaScriptLexer.g4 LEXER
        PACKAGE antlrcpptest)
antlr_target(SampleGrammarParser grammar/JavaScriptParser.g4 PARSER
        PACKAGE antlrcpptest
        DEPENDS_ANTLR SampleGrammarLexer
        COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})
include_directories(${GTEST_INCLUDE_DIRS})
# add generated grammar to interpreter binary target
add_executable(interpreter src/main.cpp
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptParser/JavaScriptParser.h
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptParser/JavaScriptParser.cpp
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptLexer/JavaScriptLexer.h
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptLexer/JavaScriptLexer.cpp
        generated/JavaScriptParser.cpp
        generated/JavaScriptParser.h
        generated/JavaScriptParserBaseVisitor.cpp
        generated/JavaScriptParserBaseVisitor.h
        generated/JavaScriptParserBaseListener.cpp
        generated/JavaScriptParserBaseListener.h
        generated/JavaScriptParserListener.cpp
        generated/JavaScriptParserListener.h
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptLexer/JavaScriptLexerBase.h
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptLexer/JavaScriptLexerBase.cpp
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptParser/JavaScriptParserBase.cpp
        cmake-build-debug/antlr4cpp_generated_src/JavaScriptParser/JavaScriptParserBase.h
        ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
        ${ANTLR_SampleGrammarParser_CXX_OUTPUTS}
        src/Visitor.h src/Visitor.cpp
        tests/tests.cpp tests/tests.h
        )

target_link_libraries(interpreter antlr4_static)
target_link_libraries(interpreter ${GTEST_LIBRARIES} pthread)