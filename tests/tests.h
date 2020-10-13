#ifndef DEMO_TESTS_H
#define DEMO_TESTS_H
#include <gtest/gtest.h>
#include "antlr4-runtime.h"
#include "JavaScriptLexer.h"
#include "../src/Visitor.h"
#include <string>

using namespace antlr4;

const std::string str = "test_";
int startTests();
#endif
