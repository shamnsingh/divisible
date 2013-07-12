#i /bin/bash

MAXCOUNT=$1
count=1

while [ "$count" -le $MAXCOUNT ]
do
	number=$(($RANDOM % 2))
	echo -n $number
	let "count += 1"
done

echo -n 'b' 
