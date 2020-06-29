#!/bin/bash

touch /home/erkka/Desktop/loki.testi

time="wupwup"

timestamp() {
	time=$(date +"%d.%m.%y  %T")
}

#check users
user() {
	users=$(awk -F'[/:]' '{if ($3 >= 1000 && $3 != 65534) print $1}' /etc/passwd)

}

timestamp
user

echo "$time users: $users"  >> /home/erkka/Desktop/loki.testi
