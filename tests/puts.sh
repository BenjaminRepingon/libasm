#!/bin/zsh

cd tests

gcc -Wl,-no_pie -I.. -L.. -lfts ft_puts.c -o ft_puts
gcc -Wl,-no_pie -I.. -L.. -lfts puts.c -o puts

# TEST1
./puts > puts1.out
./puts > ft_puts1.out

if diff -q puts1.out ft_puts1.out > /dev/null; then
	echo OK
else
	echo KO
	diff -q puts1.out ft_puts1.out
fi

# TEST2
./puts "~!@#$%^&*()_+\`1234567890-=qwertyuiop[]QWERTYUIOP{}\|ASDFGHJKL:\"asdfghjkl\;'ZXCVBNM<>?zxcvbnm,./741852=/*-+963" > puts2.out
./puts "~!@#$%^&*()_+\`1234567890-=qwertyuiop[]QWERTYUIOP{}\|ASDFGHJKL:\"asdfghjkl\;'ZXCVBNM<>?zxcvbnm,./741852=/*-+963" > ft_puts2.out

if diff -q puts2.out ft_puts2.out > /dev/null; then
	echo OK
else
	echo KO
	diff -q puts2.out ft_puts2.out
fi

# TEST3
./puts "" > puts3.out
./puts "" > ft_puts3.out

if diff -q puts3.out ft_puts3.out > /dev/null; then
	echo OK
else
	echo KO
	diff -q puts3.out ft_puts3.out
fi

# TEST4
STR=`cat /dev/urandom | head -n 100`
./puts "$STR" > puts4.out
./puts "$STR" > ft_puts4.out

if diff -q puts4.out ft_puts4.out > /dev/null; then
	echo OK
else
	echo KO
	diff -q puts4.out ft_puts4.out
fi

cd -
