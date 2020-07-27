#!/bin/bash
make
rm -f results.txt
touch results.txt
./asm_test ft_strlen "12345" >> results.txt
./asm_test ft_strlen "a" >> results.txt
./asm_test ft_strlen "" >> results.txt
./asm_test ft_strlen "a@a@a@a" >> results.txt
./asm_test ft_strlen "a#####a" >> results.txt
./asm_test ft_strlen "123456789012345678901234567890123456789012" >> results.txt
./asm_test ft_strcpy "12345" "123" 0 >> results.txt
./asm_test ft_strcpy "12345" "123456789" 0 >> results.txt
./asm_test ft_strcpy "asdfghjkl" "qwerty" 3 >> results.txt
./asm_test ft_strcpy "asdfghjkl" "qwerty@" 5 >> results.txt
./asm_test ft_strcpy "as#dfghjkl" "qwe@rty" 5 >> results.txt
./asm_test ft_strcpy "" "" 0 >> results.txt
./asm_test ft_strcpy "" "" 3 >> results.txt
./asm_test ft_strcpy "" "qwerty" 3 >> results.txt
./asm_test ft_strcpy "" "qw@erty" 3 >> results.txt
./asm_test ft_strcpy "1234567890" "123456789012345678901234567890123456789012" 5 >> results.txt
./asm_test ft_strcmp "12345" "12345" >> results.txt
./asm_test ft_strcmp "12345" "123" >> results.txt
./asm_test ft_strcmp "12345" "12356" >> results.txt
./asm_test ft_strcmp "1" "2" >> results.txt
./asm_test ft_strcmp "12345" "12@45" >> results.txt
./asm_test ft_strcmp "12345" "12@345" >> results.txt
./asm_test ft_strcmp "" "@" >> results.txt
./asm_test ft_strcmp "@@@" "@" >> results.txt
./asm_test ft_strcmp "12345678901234567890123456789012345678901J" "12345678901234567890123456789012345678901 " >> results.txt
./asm_test ft_strdup "12345" >> results.txt
./asm_test ft_strdup "12@34@56" >> results.txt
./asm_test ft_strdup "@" >> results.txt
./asm_test ft_strdup "@12345" >> results.txt
./asm_test ft_strdup "@" >> results.txt
./asm_test ft_strdup "123456789012345678901234567890123456789012" >> results.txt
./asm_test ft_read "Makefile" 10 >> results.txt
./asm_test ft_read "Makefile" 42 >> results.txt
./asm_test ft_read "Makefile" 0 >> results.txt
./asm_test ft_read "Makefile" -1 >> results.txt
./asm_test ft_read "README.md" 42 >> results.txt
./asm_test ft_read "ERROR" 5 >> results.txt
./asm_test ft_read "ERROR" 0 >> results.txt
./asm_test ft_read "ERROR" -1 >> results.txt
./asm_test ft_write "123456789012345" 10 >> results.txt
./asm_test ft_write "1234567890" 42 >> results.txt
./asm_test ft_write "123" 0 >> results.txt
./asm_test ft_write "123" -1 >> results.txt
./asm_test ft_write "1@2@3@" 6 >> results.txt
./asm_test ft_write "123456789012345678901234567890123456789012" 42 >> results.txt
make fclean
cat results.txt