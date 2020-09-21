build:
	gcc conversor.c -o conversor # compila para Linux
	# i686-w64-mingw32-gcc -o conversor.exe conversor.c # compila para Windows
install:
	sudo chmod +x conversor
	sudo mv -v conversor /usr/bin/
