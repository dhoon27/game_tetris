TOP_DIR=$(shell pwd)
SRC_DIR=${TOP_DIR}/src
INC_DIR=${TOP_DIR}/inc
OUT_DIR=${TOP_DIR}/output

# GCC_TOOL_PATH=$(shell which gcc)
CC=gcc
CFLAGS= -Wall -Werror -I${INC_DIR}

