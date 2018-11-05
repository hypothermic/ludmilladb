#!/bin/sh

cd "$(dirname "$0")" && cd "../build/"

nm "$1.o"