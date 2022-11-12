FLAGS=-Wall -Wextra -Werror
OPT=

output:
	cd src/v3 && make genso GCCFLAGS=$(FLAGS)$(OPT)
	cd src/v3 && make mvso
	cd src/v2 && make genso GCCFLAGS=$(FLAGS)$(OPT)
	cd src/v2 && make mvso
	cd src/v3 && make clear
	cd src/v2 && make clear