#!/bin/bash
echo "Hello World"
touch ECHO.txt
echo "fuck the world" > ECHO.txt
ls -al
var="I am CodeMaster."
echo $var
for file in $(ls ./); do #show all the files under dir one by one
    echo $file
done

param_n=0
echo "param_n",$param_n
if [ $# != 0 ]
then
    param_n=$#
    echo "H","das",$param_n
fi
for i in a b c d
do
    echo $i
done
count=0
while (( $count <= 4 ))
do
    echo "The Count:" $count
    let "count++"
done
echo $(date)
echo $(cal) > cal.md

func()
{
    echo "Hello shell func"
}
func
