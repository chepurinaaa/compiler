#!/bin/bash
set -o errexit

# Created 2016, Mike Lischke (public domain)

# This script is used to generate source files from the test grammars in the same folder. The generated files are placed
# into a subfolder "generated" which the demo project uses to compile a demo binary.

# 1) Running from jar. Use the given jar (or replace it by another one you built or downloaded) for generation.
LOCATION=/home/arina/CLionProjects/antlr-4.8-complete.jar
java -jar $LOCATION -Dlanguage=Cpp -listener -visitor -o generated/ -package antlrcpptest JavaScriptLexer.g4 JavaScriptParser.g4