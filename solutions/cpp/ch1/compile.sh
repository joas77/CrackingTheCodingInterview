SRC=$1;
EXE_NAME=`echo $SRC | cut -d'.' -f 1`;


g++ -Wall -g -o $EXE_NAME $SRC;
