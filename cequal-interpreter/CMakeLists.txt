cmake_minimum_required(VERSION 3.12)
project(CEqual)

set(CMAKE_CXX_STANDARD 14)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(CequalParser ${CMAKE_SOURCE_DIR}/src/parsers/cequal.y ${CMAKE_CURRENT_BINARY_DIR}/cequal.tab.cpp
        DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/cequal.tab.h VERBOSE)
FLEX_TARGET(CequalScanner ${CMAKE_SOURCE_DIR}/src/parsers/cequal.l  ${CMAKE_CURRENT_BINARY_DIR}/cequal.lex.cpp)

ADD_FLEX_BISON_DEPENDENCY(CequalScanner CequalParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(CEqual ${BISON_CequalParser_OUTPUTS} ${FLEX_CequalScanner_OUTPUTS} src/util.cpp src/include/util.hpp src/classes/ast/AST.cpp src/classes/ast/include/AST.hpp src/classes/ast/ASTArrayInit.cpp src/classes/ast/include/ASTArrayInit.hpp src/classes/ast/ASTBlock.cpp src/classes/ast/include/ASTBlock.hpp src/classes/ast/ASTCmdWrite.cpp src/classes/ast/include/ASTCmdWrite.hpp src/classes/ast/ASTDecVar.cpp src/classes/ast/include/ASTDecVar.hpp src/classes/ast/ASTExpression.cpp src/classes/ast/include/ASTExpression.hpp src/classes/ast/ASTListSpecVar.cpp src/classes/ast/include/ASTListSpecVar.hpp src/classes/ast/ASTLiteral.cpp src/classes/ast/include/ASTLiteral.hpp src/classes/ast/ASTSpecVar.cpp src/classes/ast/include/ASTSpecVar.hpp src/classes/ast/ASTVarUse.cpp src/classes/ast/include/ASTVarUse.hpp src/classes/symbol/Scope.cpp src/classes/symbol/include/Scope.hpp src/classes/symbol/Symbol.cpp src/classes/symbol/include/Symbol.hpp src/classes/value/Literal.cpp src/classes/value/include/Literal.hpp src/classes/value/LiteralBool.cpp src/classes/value/include/LiteralBool.hpp src/classes/value/LiteralInt.cpp src/classes/value/include/LiteralInt.hpp src/classes/value/LiteralStr.cpp src/classes/value/include/LiteralStr.hpp src/classes/value/include/Value.hpp src/classes/ast/ASTListDec.cpp src/classes/ast/include/ASTListDec.hpp src/classes/ast/ASTCmds.cpp src/classes/ast/include/ASTCmds.hpp src/classes/ast/ASTParamSpec.cpp src/classes/ast/include/ASTParamSpec.hpp src/classes/ast/ASTParamList.cpp src/classes/ast/include/ASTParamList.hpp src/classes/ast/ASTDecSub.cpp src/classes/ast/include/ASTDecSub.hpp src/classes/ast/ASTExpList.cpp src/classes/ast/include/ASTExpList.hpp src/classes/ast/ASTCallProc.cpp src/classes/ast/include/ASTCallProc.hpp src/classes/ast/ASTCmdAtrib.cpp src/classes/ast/include/ASTCmdAtrib.hpp src/classes/ast/ASTCmdRead.cpp src/classes/ast/include/ASTCmdRead.hpp src/classes/ast/ASTCmdIf.cpp src/classes/ast/include/ASTCmdIf.hpp src/classes/ast/ASTCmdWhile.cpp src/classes/ast/include/ASTCmdWhile.hpp src/classes/ast/ASTCmdFor.cpp src/classes/ast/include/ASTCmdFor.hpp src/classes/value/StopType.cpp src/classes/value/include/StopType.hpp src/classes/ast/ASTStopType.cpp src/classes/ast/include/ASTStopType.hpp)