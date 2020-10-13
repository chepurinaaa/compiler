#include "tests.h"

std::string getResult(std::string path, std::string file_name) {
    ANTLRFileStream input(path + file_name);
    antlrcpptest::JavaScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    JavaScriptParser parser(&tokens);
    Visitor visitor;
    tree::ParseTree* tree = parser.statementList();
    visitor.visit(tree);
    std::string res = visitor.getTree().str();
    std::ofstream f(path + "result_" + file_name.erase(file_name.size() - 2) + "txt");
    f << res;
    f.close();
    return res;
}

std::string getTestResult(std::string file_name) {
    std::ifstream f(file_name);
    std::string s = "", result = "";
    while (getline(f, s)) {
        result += s + "\n";
    }
    return result;
}

TEST(declarationTest, constTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/declaration/const/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/declaration/const/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "constTest" << i << "failed!";
    }
}

TEST(declarationTest, functionTest) {
    for (int i = 1; i <= 16; i++) {
        std::string res1 = getResult("../tests/meta/declaration/function/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/declaration/function/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "functionTest" << i << "failed!";
    }
}

TEST(declarationTest, letTest) {
    for (int i = 1; i <= 4; i++) {
        std::string res1 = getResult("../tests/meta/declaration/let/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/declaration/let/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "letTest" << i << "failed!";
    }
}

TEST(expressionTest, additiveTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/expression/additive/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/additive/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "additiveTest" << i << "failed!";
    }
}

TEST(expressionTest, assignmentTest) {
    for (int i = 1; i <= 13; i++) {
        std::string res1 = getResult("../tests/meta/expression/assignment/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/assignment/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "assignmentTest" << i << "failed!";
    }
}

TEST(expressionTest, binaryTest) {
    for (int i = 1; i <= 18; i++) {
        std::string res1 = getResult("../tests/meta/expression/binary/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/binary/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "binaryTest" << i << "failed!";
    }
}

TEST(expressionTest, binaryBitTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/expression/binary-bitwise/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/binary-bitwise/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "binaryBitTest" << i << "failed!";
    }
}

TEST(expressionTest, binaryLogicalTest) {
    for (int i = 1; i <= 6; i++) {
        std::string res1 = getResult("../tests/meta/expression/binary-logical/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/binary-logical/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "binaryLogicalTest" << i << "failed!";
    }
}

TEST(expressionTest, bitShiftTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/expression/bitwise-shift/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/bitwise-shift/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "bitShiftTest" << i << "failed!";
    }
}

TEST(expressionTest, complexTest) {
    for (int i = 1; i <= 2; i++) {
        std::string res1 = getResult("../tests/meta/expression/complex/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/complex/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "complexTest" << i << "failed!";
    }
}

TEST(expressionTest, conditionalTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/expression/conditional/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/conditional/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "conditionalTest" << i << "failed!";
    }
}

TEST(expressionTest, equalityTest) {
    for (int i = 1; i <= 4; i++) {
        std::string res1 = getResult("../tests/meta/expression/equality/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/equality/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "equalityTest" << i << "failed!";
    }
}

TEST(expressionTest, groupingTest) {
    for (int i = 1; i <= 2; i++) {
        std::string res1 = getResult("../tests/meta/expression/grouping/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/grouping/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "groupingTest" << i << "failed!";
    }
}

TEST(expressionTest, leftHandSideTest) {
    for (int i = 1; i <= 15; i++) {
        std::string res1 = getResult("../tests/meta/expression/left-hand-side/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/left-hand-side/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "leftHandSideTest" << i << "failed!";
    }
}

TEST(expressionTest, multiplicativeTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/expression/multiplicative/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/multiplicative/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "multiplicativeTest" << i << "failed!";
    }
}

TEST(expressionTest, postfixTest) {
    for (int i = 1; i <= 6; i++) {
        std::string res1 = getResult("../tests/meta/expression/postfix/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/postfix/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "postfixTest" << i << "failed!";
    }
}

TEST(primaryTest, arrayTest) {
    for (int i = 1; i <= 13; i++) {
        std::string res1 = getResult("../tests/meta/expression/primary/array/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/primary/array/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "primaryArrayTest" << i << "failed!";
    }
}

TEST(primaryTest, literalNumericTest) {
    for (int i = 1; i <= 18; i++) {
        std::string res1 = getResult("../tests/meta/expression/primary/literal/numeric/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/primary/literal/numeric/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "primaryLiteralTest" << i << "failed!";
    }
}

TEST(primaryTest, literalRegExpTest) {
    for (int i = 1; i <= 13; i++) {
        std::string res1 = getResult("../tests/meta/expression/primary/literal/regular-expression/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/primary/literal/regular-expression/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "primaryLiteralRegExpTest" << i << "failed!";
    }
}

TEST(primaryTest, literalStringTest) {
    for (int i = 1; i <= 8; i++) {
        std::string res1 = getResult("../tests/meta/expression/primary/literal/string/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/primary/literal/string/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "primaryLiteralStringTest" << i << "failed!";
    }
}

TEST(primaryTest, objectTest) {
    for (int i = 1; i <= 30; i++) {
        std::string res1 = getResult("../tests/meta/expression/primary/object/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/primary/object/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "primaryObjectTest" << i << "failed!";
    }
}

TEST(primaryTest, otherTest) {
    for (int i = 1; i <= 4; i++) {
        std::string res1 = getResult("../tests/meta/expression/primary/other/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/primary/other/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "primaryOtherTest" << i << "failed!";
    }
}

TEST(expressionTest, relationalTest) {
    for (int i = 1; i <= 6; i++) {
        std::string res1 = getResult("../tests/meta/expression/relational/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/relational/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "relationalTest" << i << "failed!";
    }
}

TEST(expressionTest, unaryTest) {
    for (int i = 1; i <= 10; i++) {
        std::string res1 = getResult("../tests/meta/expression/unary/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/expression/unary/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "unaryTest" << i << "failed!";
    }
}

TEST(statementTest, blockTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/statement/block/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/statement/block/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "blockTest" << i << "failed!";
    }
}

TEST(statementTest, breakTest) {
    for (int i = 1; i <= 4; i++) {
        std::string res1 = getResult("../tests/meta/statement/break/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/statement/break/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "breakTest" << i << "failed!";
    }
}

TEST(statementTest, continueTest) {
    for (int i = 1; i <= 5; i++) {
        std::string res1 = getResult("../tests/meta/statement/continue/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/statement/continue/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "continueTest" << i << "failed!";
    }
}

TEST(statementTest, ifTest) {
    for (int i = 1; i <= 7; i++) {
        std::string res1 = getResult("../tests/meta/statement/if/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/statement/if/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "ifTest" << i << "failed!";
    }
}

TEST(statementTest, labelledTest) {
    for (int i = 1; i <= 3; i++) {
        std::string res1 = getResult("../tests/meta/statement/labelled/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/statement/labelled/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "labelledTest" << i << "failed!";
    }
}

TEST(statementTest, returnTest) {
    for (int i = 1; i <= 4; i++) {
        std::string res1 = getResult("../tests/meta/statement/return/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/statement/return/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "returnTest" << i << "failed!";
    }
}

TEST(statementTest, variableTest) {
    for (int i = 1; i <= 7; i++) {
        std::string res1 = getResult("../tests/meta/statement/variable/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/statement/variable/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "variableTest" << i << "failed!";
    }
}

TEST(tokenTest, tokenTest) {
    for (int i = 1; i <= 2; i++) {
        std::string res1 = getResult("../tests/meta/tokenize/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/tokenize/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "tokenTest" << i << "failed!";
    }
}

TEST(tokenTest, whitespaceTest) {
    for (int i = 1; i <= 2; i++) {
        std::string res1 = getResult("../tests/meta/whitespace/", str + std::to_string(i) + ".js"), res2 = getTestResult("../tests/meta/whitespace/" + str + std::to_string(i) + ".txt");
        ASSERT_EQ(res1, res2) << "whitespaceTest" << i << "failed!";
    }
}

int startTests() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

