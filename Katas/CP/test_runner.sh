#!/bin/bash

rootdir=$1
echo "Compile..."
g++ -O3 $rootdir/src/solution.cpp -o $rootdir/src/solution

if [ $? -ne 0 ]; then
	echo "❌ Error compiler"
	exit 1
fi

PASSED=0
FAILED=0

for input_file in $rootdir/test/input*.txt; do
	num=$(echo $input_file | grep -o '[0-9]\+')
	expected_file="${rootdir}/test/expected${num}.txt"
	echo -n "Run Test $num... "

	$rootdir/src/./solution <"$input_file" >$rootdir/test/output_tmp.txt

	if diff -w $rootdir/test/output_tmp.txt "$expected_file" >/dev/null; then
		echo "✅ PASSED"
		PASSED=$((PASSED + 1))
	else
		echo "❌ FAILED"
		echo "--- Waiting ---"
		cat "$expected_file"
		echo "--- get ---"
		cat ./$rootdir/test/output_tmp.txt
		FAILED=$((FAILED + 1))
	fi
done

rm -f $rootdir/src/solution $rootdir/test/output_tmp.txt

echo "----------------------------"
echo "Ok: $PASSED, $FAILED failed."

if [ $FAILED -ne 0 ]; then
	exit 1
fi
