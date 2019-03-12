#!/bin/bash
as -o resultat.o resultat.s
gcc resultat.o -o resultat.exe
