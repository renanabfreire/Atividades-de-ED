g++ -c ./src/*.cpp
g++ main.o

k=1

echo "Tempo para cada instância" $'\n' >> ./output.txt

for instance in instancias-num/*; do
	
	echo "Processando $instance"
	echo "Instance $k of 12"
	
    echo $instance >> ./output.txt
	./a.out ${instance} >> ./output.txt
	
	k=$(($k+1))
done

echo "-" >> ./output.txt