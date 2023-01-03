#!/bin/bash
echo “Do you want to delete all files in output_file? Y/n”

read response

if [[ $response == "Y"  || $response == "y" ]];
then
echo "Okay, deleting all files in output_file"

rm -rf output_file/*

else
echo "Exiting..."
fi

