#!/bin/bash
make mrproper
make
./exec index.c
as -o resultat.o resultat.s
gcc resultat.o -o resultat.exe
echo $?
