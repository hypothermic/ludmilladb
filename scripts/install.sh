#!/bin/sh

################################################
### This file is part of the CCBU buildtools ###
###   Is it licensed under the MIT License   ###
###                                          ###
###         Author: hypothermic              ###
###         Date: 10 AUG 2018                ###
################################################

# Modified for FoscamControl, 14 OKT 2018

if [ "$(id -u)" != "0" ]; then
   echo "This script must be run as root" 1>&2
   exit 1
fi
cd "$(dirname "$0")" && cd "../build/src/"
printf "\Compiling...\n"
../../scripts/build.sh
printf "\nInstalling...\n"
cp ../build/a.out /usr/bin/foscamcontrol
printf "\Cleaning up...\n"
../../scripts/clean.sh
printf "\n>> Completed.\n\n"