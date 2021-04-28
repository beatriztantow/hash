run-test: test
	./build/testHashTable
	valgrind ./build/testHashTable

run: output
	./build/output

output: hash-table
	g++ src/main.cpp build/hashTable -o build/output

hash-table: src/hashTable.cpp src/include/hashTable.hpp
	g++ -c -g src/hashTable.cpp -o build/hashTable

test: hash-table test/testHashTable.cpp
	g++ -g test/testHashTable.cpp build/hashTable -o build/testHashTable

debug-test:
	gdb build/testHashTable

clean:
	rm -rf build/*