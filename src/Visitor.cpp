#include "Visitor.h"
#include "antlr4-runtime.h"

antlrcpp::Any Visitor::visitProgram(JavaScriptParser::ProgramContext *ctx) {
    auto vc = visitChildren(ctx);
    return vc;
}

antlrcpp::Any Visitor::visitBlock(JavaScriptParser::BlockContext *ctx) {
    tab++;
    printTab();
    if (ctx->OpenBrace()){
        tree << ctx->OpenBrace()->getText() << std::endl;
    }
    auto vc = visitChildren(ctx);
    if (ctx->CloseBrace()) {
        printTab();
        tree << ctx->OpenBrace()->getText() << std::endl;
    }
    //std::ccout << __FUNCTION__ << std::endl;
    //tree << ctx->getText() << std::endl;
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitImportStatement(JavaScriptParser::ImportStatementContext *ctx) {
    tab++;
    printTab();
    tree << "Import is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitExportDeclaration(JavaScriptParser::ExportDeclarationContext *ctx) {
    tab++;
    printTab();
    tree << "Export is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitExportDefaultDeclaration(JavaScriptParser::ExportDefaultDeclarationContext *ctx) {
    tab++;
    printTab();
    tree << "Export is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext *ctx) {
    tab++;
    printTab();
    tree << "VariableDeclarationList" << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitEmptyStatement(JavaScriptParser::EmptyStatementContext *ctx) {
    tab++;
    printTab();
    tree << "EmptyStatement" << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitExpressionStatement(JavaScriptParser::ExpressionStatementContext *ctx) {
    tab++;
    printTab();
    tree << "ExpressionStatement" << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitIfStatement(JavaScriptParser::IfStatementContext *ctx) {
    tab++;
    printTab();
    tree << "IfStatement " << ctx->If()->getText() << " " << ctx->OpenParen()->getText() << std::endl;
    if (ctx->expressionSequence()) {
        visitExpressionSequence(ctx->expressionSequence());
    }
    ////////////////////////please, check me!!!
    for (int i = 0; i < ctx->statement().size(); i++) {
        visitStatement(ctx->statement(i));
    }
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitDoStatement(JavaScriptParser::DoStatementContext *ctx) {
    tab++;
    printTab();
    tree << "DoStatement " << ctx->Do()->getText() << " " << ctx->OpenParen()->getText() << std::endl;
    bool f = false;
    if (ctx->statement()) {
        visitStatement(ctx->statement());
    }
    if (ctx->While()){
        printTab();
        tree << ctx->While()->getText() << " " << ctx->OpenParen()->getText() << std::endl;
        f = true;
    }
    if (ctx->expressionSequence()) {
        visitExpressionSequence(ctx->expressionSequence());
    }
    if (f && ctx->CloseParen()){
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    printTab();
    tree << ctx->CloseParen()->getText() << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitWhileStatement(JavaScriptParser::WhileStatementContext *ctx) {
    tab++;
    printTab();
    tree << "WhileStatement " << ctx->While()->getText() << " " << ctx->OpenParen()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitForStatement(JavaScriptParser::ForStatementContext *ctx) {
    tab++;
    printTab();
    tree << "ForStatement " << ctx->For()->getText() << " " << ctx->OpenParen()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitForInStatement(JavaScriptParser::ForInStatementContext *ctx) {
    tab++;
    printTab();
    tree << "ForInStatement " << ctx->For()->getText() << " " << ctx->OpenParen()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitForOfStatement(JavaScriptParser::ForOfStatementContext *ctx) {
    tab++;
    printTab();
    tree << "ForOfStatement " << ctx->For()->getText() << " " << ctx->OpenParen()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitVarModifier(JavaScriptParser::VarModifierContext *ctx) {
    tab++;
    printTab();
    if (ctx->let()) {
        tree << ctx->let()->getText() << " is not implemented"<< std::endl;
    }
    if (ctx->Var()) {
        tree << ctx->Var()->getText() << std::endl;
    }
    if (ctx->Const()) {
        tree << ctx->Const()->getText() << std::endl;
    }
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitContinueStatement(JavaScriptParser::ContinueStatementContext *ctx) {
    tab++;
    printTab();
    tree << "ContinueStatement " << ctx->Continue()->getText() <<  std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitBreakStatement(JavaScriptParser::BreakStatementContext *ctx) {
    tab++;
    printTab();
    tree << "BreakStatement " << ctx->Break()->getText() <<  std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitReturnStatement(JavaScriptParser::ReturnStatementContext *ctx) {
    tab++;
    printTab();
    tree << "ReturnStatement " << ctx->Return()->getText() <<  std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitYieldStatement(JavaScriptParser::YieldStatementContext *ctx) {
    tab++;
    printTab();
    tree << "Yield is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitWithStatement(JavaScriptParser::WithStatementContext *ctx) {
    tab++;
    printTab();
    tree << "With is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitSwitchStatement(JavaScriptParser::SwitchStatementContext *ctx) {
    tab++;
    printTab();
    tree << "Switch is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitThrowStatement(JavaScriptParser::ThrowStatementContext *ctx) {
    tab++;
    printTab();
    tree << "Throw is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitTryStatement(JavaScriptParser::TryStatementContext *ctx) {
    tab++;
    printTab();
    tree << "Try is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitDebuggerStatement(JavaScriptParser::DebuggerStatementContext *ctx) {
    tab++;
    printTab();
    tree << "Debbuger is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext *ctx) {
    tab++;
    printTab();
    if (ctx->Async()) {
        tree << "FunctionDeclaration " << ctx->Async()->getText() << " is not implemented" << std::endl;
    }
    if (ctx->Function()) {
        tree << "FunctionDeclaration " << ctx->Function()->getText() << std::endl;
    }
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitClassDeclaration(JavaScriptParser::ClassDeclarationContext *ctx) {
    tree << "Class is not implemented" << std::endl;
    return 1;
}

antlrcpp::Any Visitor::visitFormalParameterArg(JavaScriptParser::FormalParameterArgContext *ctx) {
    tab++;
    std::string data;
    printTab();
    if (ctx->Assign()) {
        data = ctx->Assign()->getText();
    }
    tree << "FormalParameterArg " << data << std::endl;
    printTab();
    auto vc = visitChildren(ctx);
    tree << std::endl;
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitFunctionBody(JavaScriptParser::FunctionBodyContext *ctx) {
    tab++;
    printTab();
    tree << "FunctionBody " << std::endl;
    auto vc = visitChildren(ctx);
    printTab();
    tree << std::endl;
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitElementList(JavaScriptParser::ElementListContext *ctx) {
    tab++;
    printTab();
    tree << "ElementList " << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->children.empty()) {
        tab++;
        printTab();
        tree << "null" << std::endl;
        tab--;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPropertyExpressionAssignment(JavaScriptParser::PropertyExpressionAssignmentContext *ctx) {
    tab++;
    printTab();
    tree << "PropertyExpressionAssignment " << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitComputedPropertyExpressionAssignment(JavaScriptParser::ComputedPropertyExpressionAssignmentContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->OpenBracket()) {
        data = ctx->OpenBracket()->getText();
    }
    tree << "ComputedPropertyExpressionAssignment " << data << std::endl;
    auto vc = visitChildren(ctx);
    data = ctx->CloseBracket()->getText();
    if (ctx->CloseBracket()) {
       printTab();
       tree << " " << data << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitFunctionProperty(JavaScriptParser::FunctionPropertyContext *ctx) {
    tab++;
    printTab();
    tree << "FunctionProperty" << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPropertySetter(JavaScriptParser::PropertySetterContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->OpenParen()) {
        data = ctx->OpenParen()->getText();
    } else if (ctx->OpenBrace()) {
        data = ctx->OpenBrace()->getText();
    }
    tree << "PropertySetter " << data << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    } else if (ctx->CloseBrace()) {
        printTab();
        tree << ctx->CloseBrace()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPropertyName(JavaScriptParser::PropertyNameContext *ctx) {
    tab++;
    printTab();
    tree << "PropertyName" << std::endl;
    if (ctx->OpenBracket()) {
        tree << ctx->OpenBracket()->getText() << std::endl;
    }
    if (ctx->StringLiteral()) {
        tree << ctx->StringLiteral()->getText() << std::endl;
    }
    auto vc = visitChildren(ctx);
    if (ctx->CloseBracket()) {
        tree << ctx->CloseBracket()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitArguments(JavaScriptParser::ArgumentsContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->OpenParen()) {
        data = ctx->OpenParen()->getText();
    }
    tree << "Arguments " << data << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitTernaryExpression(JavaScriptParser::TernaryExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "TernaryExpression is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "BitLogicalAndExpression " << ctx->And()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPowerExpression(JavaScriptParser::PowerExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "PowerExpression " << ctx->Power()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "PreIncrementExpression " << ctx->PlusPlus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitObjectLiteralExpression(JavaScriptParser::ObjectLiteralExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "ObjectLiteralExpression" << std::endl;
    auto vc = visitChildren(ctx);
    printTab();
    tree << std::endl;
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitInExpression(JavaScriptParser::InExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->In()) {
        data = ctx->In()->getText();
    }
    tree << "InExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "BitLogicalOrExpression " << ctx->Or()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitNotExpression(JavaScriptParser::NotExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "NotExpression " << ctx->Not()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "PreDecreaseExpression " << ctx->MinusMinus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitAwaitExpression(JavaScriptParser::AwaitExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "Await is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitThisExpression(JavaScriptParser::ThisExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->This()) {
        data = ctx->This()->getText();
    }
    tree << "ThisExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "UnaryMinusExpression " << ctx->Minus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitAssignmentExpression(JavaScriptParser::AssignmentExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "AssigmentExpression " << ctx->Assign()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "PostDecreaseExpression " << ctx->MinusMinus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitTypeofExpression(JavaScriptParser::TypeofExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "TypeOf is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitInstanceofExpression(JavaScriptParser::InstanceofExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "Instanceof is not implemented" << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitUnaryPlusExpression(JavaScriptParser::UnaryPlusExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "UnaryPlusExpression " << ctx->Plus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitDeleteExpression(JavaScriptParser::DeleteExpressionContext *ctx) {
    tree << "Delete is not implemented" << std::endl;
    return 1;
}

antlrcpp::Any Visitor::visitImportExpression(JavaScriptParser::ImportExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "Import is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitEqualityExpression(JavaScriptParser::EqualityExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->Equals_()) {
        data = ctx->Equals_()->getText();
    }
    if (ctx->NotEquals()) {
        data = ctx->NotEquals()->getText();
    }
    if (ctx->IdentityNotEquals()) {
        data = ctx->IdentityNotEquals()->getText();
    }
    if (ctx->IdentityEquals()) {
        data = ctx->IdentityEquals()->getText();
    }
    tree << "EqualityExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitBitXOrExpression(JavaScriptParser::BitXOrExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "BitXOrExpression " << ctx->BitXOr()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->Multiply()) {
        data = ctx->Multiply()->getText();
    }
    if (ctx->Modulus()) {
        data = ctx->Modulus()->getText();
    }
    if (ctx->Divide()) {
        data = ctx->Divide()->getText();
    }
    tree << "MultiplicativeExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitBitShiftExpression(JavaScriptParser::BitShiftExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->LeftShiftArithmetic()) {
        data = ctx->LeftShiftArithmetic()->getText();
    } else if (ctx->RightShiftArithmetic()) {
        data = ctx->RightShiftArithmetic()->getText();
    } else {
        data = ctx->RightShiftLogical()->getText();
    }
    tree << "BitShiftExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->OpenParen()) {
        data = ctx->OpenParen()->getText();
    }
    tree << "ParenthesizedExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitAdditiveExpression(JavaScriptParser::AdditiveExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->Plus()) {
        data = ctx->Plus()->getText();
    } else {
        data = ctx->Minus()->getText();
    }
    tree << "AdditiveExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitRelationalExpression(JavaScriptParser::RelationalExpressionContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->LessThan()) {
        data = ctx->LessThan()->getText();
    } else if (ctx->LessThanEquals()) {
        data = ctx->LessThanEquals()->getText();
    } else if (ctx->MoreThan()) {
        data = ctx->MoreThan()->getText();
    } else if (ctx->GreaterThanEquals()) {
        data = ctx->GreaterThanEquals()->getText();
    }
    tree << "RelationalExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "PostIncrementExpression " << ctx->PlusPlus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitBitNotExpression(JavaScriptParser::BitNotExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "BitNotExpression " << ctx->BitNot()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitNewExpression(JavaScriptParser::NewExpressionContext *ctx) {
    tree << "New is not implemented" << std::endl;
    return 1;
}

antlrcpp::Any Visitor::visitMemberDotExpression(JavaScriptParser::MemberDotExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "Arguments " << ctx->Dot()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitClassExpression(JavaScriptParser::ClassExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "Class is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitMemberIndexExpression(JavaScriptParser::MemberIndexExpressionContext *ctx) {
    tab++;
    printTab();
    if (ctx->OpenBracket()) {
        tree << ctx->OpenBracket()->getText() << std::endl;
    }
    auto vc = visitChildren(ctx);
    printTab();
    if (ctx->CloseBracket()){
        printTab();
        tree << " " + ctx->CloseBracket()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitBitAndExpression(JavaScriptParser::BitAndExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "BitAndExpression " << ctx->BitAnd()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitBitOrExpression(JavaScriptParser::BitOrExpressionContext *ctx) {
    tab++;
    printTab();
    tree << "BitOrExpression " << ctx->BitOr()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitVoidExpression(JavaScriptParser::VoidExpressionContext *ctx) {
    tree << "Void is not implemented" << std::endl;
    return 1;
}

antlrcpp::Any Visitor::visitAssignable(JavaScriptParser::AssignableContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitAnoymousFunctionDecl(JavaScriptParser::AnoymousFunctionDeclContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->OpenParen()) {
        data = ctx->OpenParen()->getText();
    } else if (ctx->OpenBrace()) {
        data = ctx->OpenBrace()->getText();
    }
    tree << "AnoymousFunctionDecl " << data;
    if (ctx->Function()) {
        data = ctx->Function()->getText();
    }
    if (ctx->Async()) {
        data = ctx->Async()->getText() + " is not implemented";
    }
    tree << " " << data << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printTab();
        tree << ctx->CloseParen()->getText() << std::endl;
    } else if (ctx->CloseBrace()) {
        printTab();
        tree << ctx->CloseBrace()->getText() << std::endl;
    }
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitArrowFunction(JavaScriptParser::ArrowFunctionContext *ctx) {
    tab++;
    printTab();
    tree << "Arrow is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitArrowFunctionParameters(JavaScriptParser::ArrowFunctionParametersContext *ctx) {
    tab++;
    printTab();
    tree << "ArrowFunction is not implemented" << std::endl;
    tab--;
    return 1;
}

antlrcpp::Any Visitor::visitAssignmentOperator(JavaScriptParser::AssignmentOperatorContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->PowerAssign()) {
        data = ctx->PowerAssign()->getText();
    } else if (ctx->BitOrAssign()) {
        data = ctx->BitOrAssign()->getText();
    } else if (ctx->BitXorAssign()) {
        data = ctx->BitXorAssign()->getText();
    } else if (ctx->BitAndAssign()) {
        data = ctx->BitAndAssign()->getText();
    } else if (ctx->RightShiftLogicalAssign()) {
        data = ctx->RightShiftLogicalAssign()->getText();
    } else if (ctx->RightShiftArithmeticAssign()) {
        data = ctx->RightShiftArithmeticAssign()->getText();
    } else if (ctx->LeftShiftArithmeticAssign()) {
        data = ctx->LeftShiftArithmeticAssign()->getText();
    } else if (ctx->PlusAssign()) {
        data = ctx->PlusAssign()->getText();
    } else if (ctx->ModulusAssign()) {
        data = ctx->ModulusAssign()->getText();
    } else if (ctx->DivideAssign()) {
        data = ctx->DivideAssign()->getText();
    } else if (ctx->MultiplyAssign()) {
        data = ctx->MultiplyAssign()->getText();
    } else if (ctx->MinusAssign()) {
        data = ctx->MinusAssign()->getText();
    }
    tree << "AssignmentExpression " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitLiteral(JavaScriptParser::LiteralContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->NullLiteral()) {
        data = ctx->NullLiteral()->getText();
    }
    if (ctx->BooleanLiteral()) {
        data = ctx->BooleanLiteral()->getText();
    }
    if (ctx->StringLiteral()) {
        data = ctx->StringLiteral()->getText();
    }
    if (ctx->TemplateStringLiteral()) {
        data = ctx->TemplateStringLiteral()->getText();
    }
    if (ctx->RegularExpressionLiteral()) {
        data = ctx->RegularExpressionLiteral()->getText();
    }
    tree << "Literal " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitNumericLiteral(JavaScriptParser::NumericLiteralContext *ctx) {
    tab++;
    printTab();
    tree << "NumericLiteral " << ctx->getText() << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitGetter(JavaScriptParser::GetterContext *ctx) {
    tab++;
    printTab();
    tree << "Getter " << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitSetter(JavaScriptParser::SetterContext *ctx) {
    tab++;
    printTab();
    tree << "Setter " << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitIdentifier(JavaScriptParser::IdentifierContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->NonStrictLet() ) {
        tree << ctx->NonStrictLet()->getText() + " is not implemented"<< std::endl;
    }
    if (ctx->Async()){
        tree << ctx->Async()->getText() + " is not implemented"<< std::endl;
    }
    if (ctx->Identifier()) {
        data = ctx->Identifier()->getText();
    }
    tree << "Identifier " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitReservedWord(JavaScriptParser::ReservedWordContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->BooleanLiteral()) {
        data = ctx->BooleanLiteral()->getText();
    }
    if (ctx->NullLiteral()) {
        data = ctx->NullLiteral()->getText();
    }
    tree << "ReservedWord " << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

antlrcpp::Any Visitor::visitKeyword(JavaScriptParser::KeywordContext *ctx) {
    tab++;
    printTab();
    std::string data;
    if (ctx->If()) {
        data = ctx->If()->getText();
    }
    if (ctx->Break()) {
        data = ctx->Break()->getText();
    }
    if (ctx->Do()) {
        data = ctx->Do()->getText();
    }
    if (ctx->Typeof()) {
        data = ctx->Typeof()->getText();
    }
    if (ctx->Else()) {
        data = ctx->Else()->getText();
    }
    if (ctx->New()) {
        tree << ctx->New()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Void()) {
        tree << ctx->Void()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Continue()) {
        data = ctx->Continue()->getText();
    }
    if (ctx->For()) {
        data = ctx->For()->getText();
    }
    if (ctx->While()) {
        data = ctx->While()->getText();
    }
    if (ctx->Function()) {
        data = ctx->Function()->getText();
    }
    if (ctx->This()) {
        data = ctx->This()->getText();
    }
    if (ctx->Default()) {
        data = ctx->Default()->getText();
    }
    if (ctx->Delete()) {
        data = ctx->Delete()->getText();
    }
    if (ctx->In()) {
        data = ctx->In()->getText();
    }
    if (ctx->Try()) {
        tree << ctx->Try()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Instanceof()) {
        tree << ctx->Instanceof()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Case()) {
        tree << ctx->Case()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Catch()) {
        tree << ctx->Catch()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Finally()) {
        tree << ctx->Finally()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Switch()){
        tree << ctx->Switch()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Debugger()){
        tree << ctx->Debugger()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->With()) {
        tree << ctx->With()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Throw()){
        tree << ctx->Throw()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Class()) {
        data = ctx->Class()->getText();
    }
    if (ctx->Enum()) {
        data = ctx->Enum()->getText();
    }
    if (ctx->Extends()) {
        data = ctx->Extends()->getText();
    }
    if (ctx->Super()) {
        data = ctx->Super()->getText();
    }
    if (ctx->Const()) {
        data = ctx->Const()->getText();
    }
    if (ctx->Export()) {
        data = ctx->Export()->getText();
    }
    if (ctx->Import()) {
        data = ctx->Import()->getText();
    }
    if (ctx->Implements()) {
        data = ctx->Implements()->getText();
    }
    if (ctx->Private()) {
        data = ctx->Private()->getText();
    }
    if (ctx->Public()) {
        data = ctx->Public()->getText();
    }
    if (ctx->Interface()) {
        data = ctx->Interface()->getText();
    }
    if (ctx->Package()) {
        data = ctx->Package()->getText();
    }
    if (ctx->Protected()) {
        data = ctx->Protected()->getText();
    }
    if (ctx->Static()){
        tree << ctx->Static()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Yield()){
        tree << ctx->Yield()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Async()){
        tree << ctx->Async()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->Await()){
        tree << ctx->Await()->getText() + " is not implemented";
        return 1;
    }
    if (ctx->From()) {
        data = ctx->From()->getText();
    }
    if (ctx->As()) {
        data = ctx->As()->getText();
    }
    tree << "Keyword " << data << std::endl;
    auto vc = visitChildren(ctx);
    tab--;
    return vc;
}

void Visitor::printTab() {
    for (int i = 0; i < tab; i++) {
        tree << "  ";
    }
}

std::stringstream& Visitor::getTree() {
    return tree;
}



