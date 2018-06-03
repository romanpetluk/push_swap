#!/bin/zsh

count=${argv[1]}

if ! [[ -n $count ]] || ! [[ $count == <-> ]]
then
	echo "Using: zsh rand.zsh [<count>]"
	exit 1
fi

nums=()

# Generate list of numbers sequence list or random list
for ((i=0;i<$count;i++))
do
    cur_rand="$(( ${RANDOM} ))"
    while [[ ${nums[(ie)${cur_rand}]} -le ${#nums} ]]
    do
        cur_rand="$(( ${RANDOM} ))"
    done
    nums+="$cur_rand"
    dublicate+="$cur_rand"
done

./push_swap ${nums} | ./checker -s -c ${nums}

echo "\n${nums}"
