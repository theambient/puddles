#!/bin/bash

set -e

bin=$1
input=$2

function cleanup
{
	:
}

trap cleanup ERR

! $bin $2 /dev/null

