#!/bin/sh

if [ -z "$1" ]; then
	echo "～～～～～通常ビルド～～～～～"
	make -f Makefile.EventContainer
	make -f Makefile.EventRouter
	make -f Makefile.FunctionNode
	make -f Makefile.MouseSoulApps
	make -f Makefile
fi

if [ "clean" = "$1" ]; then
	echo "～～～～～クリーン～～～～～"
	make -f Makefile.EventContainer clean
	make -f Makefile.EventRouter clean
	make -f Makefile.FunctionNode clean
	make -f Makefile.MouseSoulApps clean
	make -f Makefile clean
fi




