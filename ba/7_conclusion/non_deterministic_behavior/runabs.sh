#!/bin/bash

echo 'removing old erlang files'
rm -r gen/
echo 'removed'

echo 'compiling...'
#./absc -erlang $1
java -jar frontend.jar -v -erlang $1
echo 'compiled'

echo 'start: '
gen/erl/run


