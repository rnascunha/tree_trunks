#/bin/bash
#########################################################
# Script will build/compile/execute ALL examples		#
#########################################################

example_list=(tt_default modules custom_type custom_config eol);

if [ $# -ne 1 ]
then
	echo "You must inform the project directiory";
	exit 1;
fi

RET=$(cd $1 2> /dev/null)
if [ $? -ne 0 ]
then
	echo "Invalid PATH informed";
	exit 1;
fi

examples_path="${1}/examples"
build_path="${1}/build"

if [ ! -d $examples_path ]
then
	echo "Examples path not found";
	exit 1;
fi

if [ ! -d $build_path ]
then
	echo "Creating build path"
	mkdir -p $build_path
fi

cd $build_path

make clean 1>&- 2>&-

for exp in ${example_list[*]}; 
do 
	if [ ! -f ${examples_path}/${exp}.cpp ]
	then 
		echo "${exp} example NOT found";
		exit 1;
	fi 
	echo "----------------"
	echo "Building ${exp} example..."
	cmake -Dexample=${exp} .. 1>&- 2>&-
	if [ $? -ne 0 ]
	then
		echo "ERROR building ${exp} example..."
		exit 1;
	fi
	echo "Compiling ${exp} example..."
	make 1>& /dev/null 2>&1
	if [ $? -ne 0 ]
	then
		echo "ERROR compiling ${exp} example..."
		exit 1;
	fi
	echo "Executing ${exp} example..."
	./${exp}
	if [ $? -ne 0 ]
	then
		echo "ERROR building ${exp} example..."
		exit 1;
	fi
done

echo -e "-------------------\nEvertything running OK";
exit 0;