#! /bin/bash

# TODO: Check to parameter list

# Convert the directory name to UPPERCASE
DIRNAME=$(echo $1 | tr '[:lower:]' '[:upper:]')
# And to lowercase
dirname=$(echo $1 | tr '[:upper:]' '[:lower:]')

# Create a directory
mkdir -v $DIRNAME
CODE=$?
if [ $CODE -ne 0 ]
	then
		exit $CODE
fi

# Copy the skeleton to the directory
cp -v skeleton.cc $DIRNAME/$dirname".cc"