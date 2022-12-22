#!/bin/sh
#BEGIN="Building and Testing"
#echo $BEGIN

#TESTCOMMAND=cd build;make install
#PYTHONCOMMAND=cd python;python3 ece3210_lab07.py

# -m make install
# -t test with class test
# -p test with personal code
while getopts 'mtpc' OPTION; do
	case "$OPTION" in
	    m)
		(make)
		;;
	    t)
		(./wtf test 10)
		;;
	    p)
		(./wtf test 3)
		;;
		c)
		(make clean)
		;;
	    ?)
	        echo "script usage: $(basename \$0) [-m] Make [-t] Test [-p] Test w/ personal" >&2
		exit 1
		;;
	esac
    done
if [ $OPTIND -eq 1 ]; then
   echo "script usage: $(basename \$0) [-m] Make [-t] Test [-p] Test w/ personal" >&2;
fi

shift $((OPTIND-1))


#echo "[*] Building"
#(cd build;make install)
#echo "[*] Python Testing"
#(cd python;python3 ece3210_lab07.py)