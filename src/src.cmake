# Copyright (c) 2025 Z·Math
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
list(APPEND INCPATH "${CMAKE_CURRENT_LIST_DIR}")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/Headers_Lib.h")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/Parser.c")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/Parser.h")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/Printer.c")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/Printer.h")

list(APPEND INCPATH "${CMAKE_CURRENT_LIST_DIR}/model")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/model/_Derivative.c")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/model/_Derivative.h")

list(APPEND INCPATH "${CMAKE_CURRENT_LIST_DIR}/utils")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/node.c")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/node.h")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/node_type.c")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/node_type.h")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/trans.c")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/trans.h")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/variable.c")
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/utils/variable.h")
