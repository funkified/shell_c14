# Makefile for building applications

# Edit this file to compo;e extra Cfiles into their own programs.
TARGETS=helloExec test_exec

CROSS_TOOL =
CC_CPP = $(CROSS_TOOL)g++
CC_C = $(CROSS_TOOL)gcc

CFLAGS = -Wall -g -std=99 -Werror

all: clean $(TARGETS)

$(TARGETS):
	$((C_C) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(TARGETS)
