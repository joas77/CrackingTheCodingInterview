SRC=$1;
EXE_NAME=`echo $SRC | cut -d'.' -f 1`;


g++ -Wall -o $EXE_NAME $SRC;
