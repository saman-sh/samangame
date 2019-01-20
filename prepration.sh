for i in {1..26}
do
	mkdir $i
	cd $i
	for j in {1..26}
	do
		touch $j
	done
	cd ..
done
