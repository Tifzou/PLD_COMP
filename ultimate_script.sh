#!/bin/bash
make
./exe index.c
as -o resultat.o resultat.s
gcc resultat.o -o resultat.exe
echo $?
