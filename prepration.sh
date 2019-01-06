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

while IFS='' read -r line || [[ -n "$line" ]]; do

flttr=${line:0:1}

flttrAsci=$(printf "%d\n" \'$flttr)
fldrName=`expr $flttrAsci - 96`

slttr=${line:1:1}

slttrAsci=$(printf "%d\n" \'$slttr)
fileName=`expr $slttrAsci - 96`

cd $fldrName
if [ ${#line} -gt 2 ]
then
echo $line >> $fileName
fi
cd ..


done < "./DictionaryMain.txt"
