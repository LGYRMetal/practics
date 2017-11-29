#!/bin/bash
for((i=59900; i<60000; i++))
do
#	firewall-cmd --zone=public --add-port=$i/tcp --permanent
	echo $i;firewall-cmd --zone=public --query-port=$i/tcp
done
