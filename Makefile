##############################################################################
# Makefile for Lab 12
# CMP_SC 2050
# Summer 2024
# By Jim Ries (RiesJ@missouri.edu)
##############################################################################
CC = gcc
CPP = g++
CFLAGS = -Wall -Werror -c -g -std=c11 -I. -I/cluster/pixstor/class/include 
CPPFLAGS = -Wall -Werror -c -g -I. -I/cluster/pixstor/class/include
LDFLAGS = -lm -lMUCSSeg -L. -L/cluster/pixstor/class/lib 

default: a.out

%.o : %.c 
	@echo Compiling $^ 
	@$(CC) $(CFLAGS) $^

%.o : %.cc
	@echo Compiling $^ 
	@$(CPP) $(CPPFLAGS) $^

a.out : lab12main.o lab12.o
	@echo Linking $@ 
	@$(CC) $^ $(LDFLAGS) -o $@

clean : 
	@rm -rf *.o
	@rm -rf a.out
	@echo All Clean!
