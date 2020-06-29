#!/bin/bash
echo "Hello World!"

basename -- "$0"

#Time getter function
timestamp() {
	time=$(date +"%d.%m.%Y  %T")
}

time="0"

timestamp

echo $time

num1="-1"
num2="-1"

#check for positive integer
until [ "$num1" -ge "0" ] && [ "$num1" -eq "$num1" ]
do
	echo "Syötä ensimmäinen luku: "
	read num1
done

until [ "$num2" -ge "0" ]  && [ "$num2" -eq "$num2" ]
do
	echo "Syötä toinen luku: "
	read num2
done

num3=$((num1 + num2))

echo "Vastaus on: $num3"
