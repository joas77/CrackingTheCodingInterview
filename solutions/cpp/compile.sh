SRC=$1;
EXE_NAME=`echo $SRC | cut -d'.' -f 1`;


g++ -std=c++17 -Wall -g -o $EXE_NAME $SRC;
