debug: generate_question.o display.o option.o main.o solve.o
	g++ -Wall -fexceptions -g generate_question.o display.o option.o main.o solve.o -o Math-Loop-Quiz-Program

release: generate_question.o display.o option.o main.o solve.o
	g++ -fomit-frame-pointer -fexpensive-optimizations -O2 generate_question.o display.o option.o main.o solve.o -o Math-Loop-Quiz-Program

Finalrelease: generate_question.o display.o option.o main.o solve.o
	g++ -fomit-frame-pointer -fexpensive-optimizations -O2 generate_question.o display.o option.o main.o solve.o -o Math-Loop-Quiz-Program
	upx -9 --best --ultra-brute Math-Loop-Quiz-Program.exe

run: 
	Math-Loop-Quiz-Program

clean:
	rm -f *.o *.exe

generate_question.o: generate_question.cpp
	g++ generate_question.cpp -c

display.o: display.cpp
	g++ display.cpp -c

option.o: option.cpp
	g++ option.cpp -c

solve.o: solve.cpp
	g++ solve.cpp -c

main.o: main.cpp
	g++ main.cpp -c