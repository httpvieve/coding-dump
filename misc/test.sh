#!/bin/bash

# THIS IS A COMMENT OK
message="LMAO IT WORKS"
# echo "i like stupid looking animals"
ID_NUMBER=12108254
#echo $message

# $# -> number of arguments
# $0 -> file name of script
# $1..$n -> script arguments
# ourfilename=$0
# echo $ourfilename

# arguments_no=$#
# echo "The first three arguments are ${1}, ${2}, and ${3}"
# echo $5
PROMPT=$1
GREETING="HELLO SIR"
BOOLETS="I NEED MORE BOOLETS"
WEAPONS="BIGGER WEAPONGS BIGGER WEAPONMS"

if [ "$PROMPT" = "hi" ]; then 
        echo $GREETING
elif [ "$PROMPT" = "bullets" ]; then 
        echo $BOOLETS 
elif [ "$PROMPT" = "weapons" ]; then 
        echo $WEAPONS 
        
fi
# if [ "$NAME" = "Codu" ]; then
#         echo "henlo codu hehehe"
# elif [ "$NAME" = "Tom"]; then
#         echo "
# fi
# exit $?

