#! /bin/bash

test_passed=0
test_fail=0
echo -e "Integration tests by mariusvnh, zuldruck, simontraww"
echo -e "\n\nTESTS\n"

#simple exit
echo "exit" | ./mysh &> log.txt
if [ $? != 0 ]; then
	echo -e "simple exit: Return value was $?\nExpected 0\n"
else {
	echo -e "simple exit: PASSED\n"
	((test_passed++))
}
fi

DIFF=$(diff <(cat log.txt) <(echo "exit"))
if [ "$DIFF" != "" ]; then
	echo -e "simple exit: Got: $DIFF\nExpected: \"\"\n"
else
	echo -e "simple exit [2]: PASSED\n"
	((test_passed++))
fi

#exit 43
echo "exit 43" | ./mysh &> log.txt
if [ $? != 43 ]; then
	echo -e "exit 43: Return value was $?\nExpected 43\n"
else {
	echo -e "exit 43: PASSED\n"
	((test_passed++))
}
fi

DIFF=$(diff <(cat log.txt) <(echo "exit"))
if [ "$DIFF" != "" ]; then
	echo -e "exit 43: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "exit 43 [2]: PASSED\n"
	((test_passed++))
}
fi

#exit test
echo "exit test" | ./mysh &> log.txt
echo "exit test" | tcsh &> tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "exit test: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "exit test: PASSED\n"
	((test_passed++))
}
fi

#exit 42test
echo "exit 42test" | ./mysh &> log.txt
echo "exit 42test" | tcsh >& tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "exit 42test: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "exit 42test: PASSED\n"
	((test_passed++))
}
fi

#exit badly [SIMONTRAWW]
echo "exit -77j" | ./mysh &> log.txt
echo "exit -77j" | tcsh &> tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "exit -77j: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "exit -77j: PASSED\n"
	((test_passed++))
}
fi

#pwd
echo -e "cd ..\npwd" | ./mysh &> log.txt
echo -e "cd ..\npwd" | tcsh &> tcsh.txt

DIFF=$(diff <(cat log.txt) <(cat tcsh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "cd .. --> pwd: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "cd .. --> pwd: PASSED\n"
	((test_passed++))
}
fi

#env path presence
echo -e "env" | ./mysh &> log.txt

DIFF=$(cat log.txt | grep "^PATH=" | wc -l)
if [ "$DIFF" != "1" ]; then
	echo -e "env PATH check: Got: $DIFF\nExpected: \"1\"\n"
else {
	echo -e "env PATH check: PASSED\n"
	((test_passed++))
}
fi

#setenv
echo -e "setenv SALUT PUTE\nenv" | ./mysh &> log.txt

DIFF=$(cat log.txt | grep "^SALUT=PUTE" | wc -l)
if [ "$DIFF" != "1" ]; then
	echo -e "setenv test: Got: $DIFF\nExpected: \"1\"\n"
else {
	echo -e "setenv test: PASSED\n"
	((test_passed++))
}
fi

#setenv
echo -e "unsetenv PATH\nenv" | ./mysh &> log.txt

DIFF=$(cat log.txt | grep "^PATH" | wc -l)
if [ "$DIFF" != "0" ]; then
	echo -e "unsetenv test: Got: $DIFF\nExpected: \"1\"\n"
else {
	echo -e "unsetenv test: PASSED\n"
	((test_passed++))
}
fi

#setenv
mkdir lstest
mkdir lstest/plouplou
touch lstest/salut.txt
touch lstest/lala.txt
touch lstest/plouplou/yop.txt
cd lstest

echo -e "cd plouplou\nls" | ./../mysh &> log.txt
echo -e "cd plouplou\nls" | tcsh &> tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "ls: Got: $DIFF\n"
else {
	echo -e "ls: PASSED\n"
	((test_passed++))
}
fi


#TEST LONG SPACES [SIMONTRAWW]
echo "ls		 " | ./../mysh &>log.txt
echo "ls		 " | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST LONG WHITESPACES : Got: $DIFF\n"
else {
	echo -e "TEST LONG WHITESPACES : PASSED\n"
	((test_passed++))
}
fi

#TEST WITH TAB [SIMONTRAWW]
echo "ls		" | ./../mysh &>log.txt
echo "ls		" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST WITH TAB : Got: $DIFF\n"
else {
	echo -e "TEST WITH TAB : PASSED\n"
	((test_passed++))
}
fi
cd ..
rm -rf lstest


#TEST WITH spaces [SIMONTRAWW]
echo "cd	../" | ./mysh &>log.txt
echo "cd	../" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST CD ../ WITH SPACES : Got: $DIFF\n"
else {
	echo -e "TEST CD ../ WITH SPACES : PASSED\n"
	((test_passed++))
}
fi



#TEST WITH TAB [SIMONTRAWW]
echo -e "\t\tcd\t" | ./mysh &>log.txt
echo -e "\t\tcd\t" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST CD WITH tab : Got: $DIFF\n"
else {
	echo -e "TEST CD WITH tab : PASSED\n"
	((test_passed++))
}
fi

#execute non executable file
echo -e "./Makefile" | ./mysh &> log.txt
echo -e "./Makefile" | tcsh &> tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "ls: Got: $DIFF\n"
else {
	echo -e "ls: PASSED\n"
	((test_passed++))
}
fi

#TEST CHMOD -x [SIMONTRAWW]
touch foobar
echo "echo \"fail\"" | > foobar
echo -e "chmod -x ./foobar\n./foobar" |./mysh &> log.txt
echo -e "chmod -x ./foobar\n./foobar" | tcsh &> tcssh.txt
rm -rf foobar

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST CHMOD: Got: $DIFF\n"
else {
	echo -e "TEST CHMOD: PASSED\n"
	((test_passed++))
}
fi

#TEST ERROR + one or two letter after word [SIMONTRAWW]
echo -e "exitt" | ./mysh &> log.txt
echo -e "exitt" | tcsh  &> tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST EXITT (one two letter at the end of word): Got: $DIFF\n"
else {
	echo -e "TEST EXITT (one two letter at the end of word): PASSED\n"
	((test_passed++))
}
fi

#TEST CHMOD +x on picture [SIMONTRAWW]
wget http://convertir-une-image.com/frontframe/images/cute_ball_info.png &> /dev/null
mv cute_ball_info.png test.png &> /dev/null
echo -e "chmod +x test.png\n./test.png" | ./mysh &> log.txt
echo -e "chmod +x test.png\n./test.png" | tcsh &> tcssh.txt
rm -rf test.png

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST EXEC IMG: Got: $DIFF\n"
else {
	echo -e "TEST EXEC IMG: PASSED\n"
	((test_passed++))
}
fi

#TEST programm segfault [SIMONTRAWW]
mkdir tests
cd tests
wget http://epi2022.fr/neo/PSU/PSU_minishell1_2017/segfault.c &> /dev/null
echo -e "gcc segfault.c\n./a.out" | ./../mysh &> log.txt
echo -e "gcc segfault.c\n./a.out" | tcsh &> tcssh.txt
rm -rf segfault.c &> /dev/null
rm -rf a.out &> /dev/null

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST SEGFAULT: Got: $DIFF\n"
else {
	echo -e "TEST SEGFAULT: PASSED\n"
	((test_passed++))
}
fi


#TEST programm floating point exeception [SIMONTRAWW]
wget http://epi2022.fr/neo/PSU/PSU_minishell1_2017/floating.c &> /dev/null
echo "gcc floating.c -lm" | ./../mysh &> /dev/null
echo "gcc floating.c -lm" | tcsh &> /dev/null
echo -e "gcc floating.c -lm\n./a.out" | ./../mysh &> log.txt
echo -e "gcc floating.c -lm\n./a.out" | tcsh &> tcssh.txt
rm -rf floating.c
rm -rf a.out

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST FLOATING point exception: Got: $DIFF\n"
else {
	echo -e "TEST FLOATING point exception: PASSED\n"
	((test_passed++))
}
fi
cd ..
rm -rf tests


#TEST ERROR + one or two letter after word [SIMONTRAWW]

echo -e "unsetenvv" | ./mysh &> log.txt
echo -e "unsetenvv" | tcsh  &> tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST unsetenvv (one two letter at the end of word): Got: $DIFF\n"
else {
	echo -e "TEST unsetenvv (one two letter at the end of word): PASSED\n"
	((test_passed++))
}
fi

#TEST ERROR + one or two letter after word [SIMONTRAWW]
echo -e "setenvi" | ./mysh &> log.txt
echo -e "setenvi" | tcsh  &> tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST setenvi (one two letter at the end of word): Got: $DIFF\n"
else {
	echo -e "TEST setenvi (one two letter at the end of word): PASSED\n"
	((test_passed++))
}
fi

#TEST cd [SIMONTRAWW]
echo -e "cd\npwd" | ./mysh &>log.txt
echo -e "cd\npwd" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST cd : Got: $DIFF\n"
else {
	echo -e "TEST cd : PASSED\n"
	((test_passed++))
}
fi

#TEST cd ../ [SIMONTRAWW]
echo -e "cd ../\npwd" | ./mysh &>log.txt
echo -e "cd ../\npwd" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST cd ../ : Got: $DIFF\n"
else {
	echo -e "TEST cd ../ : PASSED\n"
	((test_passed++))
}
fi

#TEST cd /dev [SIMONTRAWW]
echo -e "cd /dev\npwd" | ./mysh &>log.txt
echo -e "cd /dev\npwd" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST cd /dev : Got: $DIFF\n"
else {
	echo -e "TEST cd /dev : PASSED\n"
	((test_passed++))
}
fi

#TEST cd NULL [SIMONTRAWW]
echo -e "cd NULL" | ./mysh &>log.txt
echo -e "cd NULL" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST cd NULL directory : Got: $DIFF\n"
else {
	echo -e "TEST cd NULL directory : PASSED\n"
	((test_passed++))
}
fi

#TEST cd random dirr [SIMONTRAWW]
echo -e "cd ../../../../../../../../\npwd" | ./mysh &>log.txt
echo -e "cd ../../../../../../../../\npwd" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST random dirr : Got: $DIFF\n"
else {
	echo -e "TEST random dirr : PASSED\n"
	((test_passed++))
}
fi


#TEST cd moins without any OLDPWD [SIMONTRAWW]
echo -e "cd ../\ncd -\npwd" | ./mysh &>log.txt
echo -e "cd ../\ncd -\npwd" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST cd moins without OLDPWD : Got: $DIFF\n"
else {
	echo -e "TEST cd moins without OLDPWD: PASSED\n"
	((test_passed++))
}
fi

#TEST NAME TOO LONG [SIMONTRAWW]
echo "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" | ./mysh &>log.txt ./mysh &> /dev/null
echo "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" | tcsh &>tcssh.txt tcsh &> /dev/null

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST CD NAME TOO LONG: Got: $DIFF\n"
else {
	echo -e "TEST CD NAME TOO LONG : PASSED\n"
	((test_passed++))
}
fi

#TEST /bin/ls [SIMONTRAWW]
echo -e "/bin/ls" | ./mysh &>log.txt
echo -e "/bin/ls" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST /bin/ls: Got: $DIFF\n"
else {
	echo -e "TEST /bin/ls: PASSED\n"
	((test_passed++))
}
fi

#TEST /bin/ls [SIMONTRAWW]
echo -e "/bin/ls" | ./mysh &>log.txt
echo -e "/bin/ls" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST /bin/ls: Got: $DIFF\n"
else {
	echo -e "TEST /bin/ls: PASSED\n"
	((test_passed++))
}
fi

#TEST cd bin/pwd [SIMONTRAWW]
echo -e "cd /bin/pwd" | ./mysh &>log.txt
echo -e  "cd /bin/pwd" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST cd /bin/pwd directory : Got: $DIFF\n"
else {
	echo -e "TEST cd /bin/pwd directory : PASSED\n"
	((test_passed++))
}
fi

#TEST cd bin/pwd [SIMONTRAWW]
echo -e "env -i ./mysh" | ./mysh &>log.txt
echo -e	"env -i ./mysh" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "TEST env -i directory : Got: $DIFF\n"
else {
	echo -e "TEST env -i directory : PASSED\n"
	((test_passed++))
}
fi

#setenv A 2
echo -e "setenv A 2\nenv" | ./mysh &> log.txt

DIFF=$(cat log.txt | grep "^A=2" | wc -l)
if [ "$DIFF" != "1" ]; then
	echo -e "setenv A 2: Got: $DIFF\nExpected: \"1\"\n"
else {
	echo -e "setenv A 2: PASSED\n"
	((test_passed++))
}
fi

#TEST setenv A 2[SIMONTRAWW]
echo "setenv 2 A" | ./mysh &>log.txt
echo "setenv 2 A" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "SETENV 2 A error msg : Got: $DIFF\n"
else {
	echo -e "SETENV 2 A error msg : PASSED\n"
	((test_passed++))
}
fi

#TEST setenv A/ 2[SIMONTRAWW]
echo "setenv A/ 2" | ./mysh &>log.txt
echo "setenv A/ 2" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "SETENV A/ 2 error msg : Got: $DIFF\n"
else {
	echo -e "SETENV A/ 2 error msg : PASSED\n"
	((test_passed++))
}
fi

#TEST setenv A 2[SIMONTRAWW]
echo "setenv SALU/T 2" | ./mysh &>log.txt
echo "setenv SALU/T 2" | tcsh &>tcssh.txt

DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "SETENV SALU/T 2 error msg : Got: $DIFF\n"
else {
	echo -e "SETENV SALU/T 2 error msg : PASSED\n"
	((test_passed++))
}
fi

#CD cd -
echo -e "cd ..\ncd -\npwd" | ./mysh &> log.txt
echo -e "cd ..\ncd -\npwd" | tcsh &> tcsh.txt

DIFF=$(diff <(cat log.txt) <(cat tcsh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "cd .. puis cd - puis pwd --> pwd: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "cd .. puis cd - puis pwd -->  pwd: PASSED\n"
	((test_passed++))
}
fi

#CD cd -
echo -e "cd ..\ncd -\ncd ../\ncd -\ncd ../\ncd -\npwd" | ./mysh &> log.txt
echo -e "cd ..\ncd -\ncd ../\ncd -\ncd ../\ncd -\npwd" | tcsh &> tcsh.txt

DIFF=$(diff <(cat log.txt) <(cat tcsh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "cd .. puis cd - puis cd ../ puis cd - (3fois) puis pwd --> pwd: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "cd .. puis cd - puis cd ../ puis cd - (3fois) puis pwd -->  pwd: PASSED\n"
	((test_passed++))
}
fi

#CD cd -
echo -e "cd ..\ncd -\ncd ../\ncd -\ncd ../\ncd -\npwd" | ./mysh &> log.txt
echo -e "cd ..\ncd -\ncd ../\ncd -\ncd ../\ncd -\npwd" | tcsh &> tcsh.txt

DIFF=$(diff <(cat log.txt) <(cat tcsh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "cd .. puis cd - puis cd ../ puis cd - (3fois) puis pwd --> pwd: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "cd .. puis cd - puis cd ../ puis cd - (3fois) puis pwd -->  pwd: PASSED\n"
	((test_passed++))
}
fi

#CD cd -
echo "setenv 2/A" | ./mysh &> log.txt
echo "setenv 2/A" | tcsh &> tcsh.txt

DIFF=$(diff <(cat log.txt) <(cat tcsh.txt))
if [ "$DIFF" != "" ]; then
	echo -e "setenv 2/A --> pwd: Got: $DIFF\nExpected: \"\"\n"
else {
	echo -e "setenv 2/A -->  pwd: PASSED\n"
	((test_passed++))
}
fi

echo "####################################"
echo "SUCCESS TEST --> " $test_passed
test_fail=$(echo "42-$test_passed" |bc )
echo "FAIL TEST --> " $test_fail
echo "####################################"

# IL FAUT TROUVER UNE SOLUTION POUR CES TESTS..
#######################################################################################################################################################
# CE TEST EST PROBLEMATIQUE --> il aura toujours un soucis au niveaux du level du shell dans le system ! SHLVL. mais s'il y a que Ã§a, le test passed !#
#######################################################################################################################################################
#echo -e "setenv" | ./mysh &> log.txt
#echo -e "setenv" | tcsh  &> tcssh.txt
#
#DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
#if [ "$DIFF" != "" ]; then
#	echo -e "TEST setenv : Got: $DIFF\n"
#else
#	echo -e "TEST setenv : PASSED\n"
#fi

#######################################################################################################################################################
# CE TEST EST PROBLEMATIQUE --> il aura toujours un soucis au niveaux du level du shell dans le system ! SHLVL. mais s'il y a que Ã§a, le test passed !#
#######################################################################################################################################################
#TEST ERROR + one or two letter after word
#
#echo -e "env" | ./mysh &> log.txt
#echo -e "env" | tcsh  &> tcssh.txt
#
#DIFF=$(diff <(cat log.txt) <(cat tcssh.txt))
#if [ "$DIFF" != "" ]; then
#	echo -e "TEST PRINT env: Got: $DIFF\n"
#else
#	echo -e "TEST PRINT env: PASSED\n"
#fi
rm -rf log.txt
rm -rf tcsh.txt
rm -rf tcssh.txt
echo -e "\nEND OF TESTS\n"
