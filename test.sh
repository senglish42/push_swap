#!/bin/bash

norminette

#make
#echo -e '\033[0mТест на диапозон значений от -200 до 299'
#ERR=0
#ERR_ARG=0
#for i in range {1..99}
#	do
#		ARG=`ruby -e "puts (-200..299).to_a.shuffle.join(' ')"`
#		RET=`./push_swap $ARG | ./checker_Mac $ARG`
#		if [ "$RET" != "OK" ];
#			then
#			((ERR++))
#			echo -en '\033[0;31m▩\033[0;0m'
#		else
#			echo -en '\033[0;32m▩\033[0;0m'
#		fi
#done
#
#if [ $ERR -eq 0 ];
#	then
#	echo -e '\033[0;32m Успешно'
#else
#	echo -e "\033[0;31m Ошибок $ERR / 100"
#fi

echo -e '\033[0mТест на диапозон значений от -50 до 49'
ERR=0
ERR_ARG=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker_Mac $ARG`
		if [ "$RET" != "OK" ]
			then
			((ERR++))
			echo -en '\033[0;31m▩\033[0;0m'
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi


echo -e '\033[0mТест на диапозон значений от 0 до 1'
ERR=0
ERR_ARG=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..1).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker_Mac $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			ERR_ARG=$ARG
			echo "   $RET   "
			echo -en '\033[0;31m▩\033[0;0m'
			echo -en " Поданные значения ( $ERR_ARG ) "
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi

echo -e '\033[0mТест на диапозон значений от -1 до 1'
ERR=0
ERR_ARG=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker_Mac $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			ERR_ARG=$ARG
			echo "   $RET   "
			echo -en '\033[0;31m▩\033[0;0m'
			echo -en " ( $ERR_ARG ) "
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi

echo -e '\033[0mТест на диапозон значений от -1 до 2'
ERR=0
ERR_ARG=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (-1..2).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker_Mac $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			ERR_ARG=$ARG
			echo -en '\033[0;31m▩\033[0;0m'
			echo -en " Поданные значения ( $ERR_ARG ) "
			echo " "
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi

echo -e '\033[0mТест на диапозон значений от -2 до 2'
ERR=0
ERR_ARG=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker_Mac $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			ERR_ARG=$ARG
			echo -en '\033[0;31m▩\033[0;0m'
			echo -en " Поданные значения ( $ERR_ARG ) "
			echo " "
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi

echo -e '\033[0mТест на диапозон значений от 0 до 5'
ERR=0
ERR_ARG=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..5).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker_Mac $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			ERR_ARG=$ARG
			echo -en '\033[0;31m▩\033[0;0m'
			echo -en " ( $ERR_ARG ) "
			echo " "
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi

echo -e '\033[0mОбщий тест'
ERR=0
ERR_ARG=0
l=0
for i in range {1..499}
	do 
		ARG=`ruby -e "puts (0..$l).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker_Mac $ARG`
		((l++))
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			ERR_ARG=$ARG
			echo -en '\033[0;31m▩\033[0;0m'
			echo -en " ( $ERR_ARG ) "
			echo " "
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi

echo -e "\033[0mПодсчет движений на сортировку:"

ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
a=`./push_swap $ARG | wc -l`
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
a1=`./push_swap $ARG | wc -l`
ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
a2=`./push_swap $ARG | wc -l`
ARG=`ruby -e "puts (0..3).to_a.shuffle.join(' ')"`
a3=`./push_swap $ARG | wc -l`
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`
a4=`./push_swap $ARG | wc -l`
echo "	На 500 элементов: $a"
echo "	На 100 элементов: $a1"
echo "	На   5 элементов: $a2"
echo "	На   4 элементa : $a3"
echo "	На   3 элементa : $a4"

echo -e '\033[0mТест на кол-во движение с 5-тью элементами, не более 12 движений'
ERR=0
ERR_ARG=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l`
		if [ $RET -gt 12 ];
			then
			((ERR++))
			ERR_ARG=$ARG
			echo -en '\033[0;31m▩\033[0;0m'
			echo -en " Поданные значения ( $ERR_ARG ) "
			echo " "
		else
			echo -en '\033[0;32m▩\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Успешно'
else
	echo -e "\033[0;31m Ошибок $ERR / 100"
fi

echo -e '\033[0mТест валидации поданных аргументов'
echo "./push_swap 0 one 1"
./push_swap 0 one 1
echo "./push_swap \"\""
./push_swap ""
echo "./push_swap --1"
./push_swap --1
echo "./push_swap ++2"
./push_swap ++2
echo "./push_swap 3 2 1 1"
./push_swap 3 2 1 1
echo "./push_swap 1 1"
./push_swap 1 1
echo "./push_swap"
./push_swap
echo "./push_swap 1 2 3 \"6 5 4\""
./push_swap 1 2 3 "6 5 4" |./checker_Mac 1 2 3 "6 5 4"
