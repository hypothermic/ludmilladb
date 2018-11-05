#!/bin/sh

################################################
### This file is part of the CCBU buildtools ###
###   Is it licensed under the MIT License   ###
###                                          ###
###         Author: hypothermic              ###
###         Date: 13 AUG 2018                ###
################################################

# Modified for FoscamControl, 14 OKT 2018

printf "\nExecuting hexdump...\n\n"
cd "$(dirname "$0")"

#hexdump -C ../build/src/a.out
xxd -c 44 ../src/a.out

printf "\n\n>> Completed.\n\n"