#!/bin/bash

set -e

bin=$1
input=$2
reference=$3
tmp=`mktemp temp.XXXX`

function cleanup
{
	rm -f $tmp
}

trap cleanup ERR

$bin $2 $tmp

cmake -E compare_files $tmp $reference
