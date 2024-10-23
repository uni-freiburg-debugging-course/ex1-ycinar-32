

## Make File

First, run make fuzzer command on your terminal.

Output should look like this.


```bash
yilmaz@fp-10-126-155-166 debugging_and_fuzzing_lecture % make fuzzer
g++ -std=c++17 -Wall -Wextra -c Fuzzer.cpp -o Fuzzer.o
g++ -std=c++17 -Wall -Wextra -o fuzzer Fuzzer.o
```


Then, run make main command on your terminal.

```bash
yilmaz@fp-10-126-155-166 debugging_and_fuzzing_lecture % make main
g++ -std=c++17 -Wall -Wextra -c main_ex1.cpp -o main_ex1.o
g++ -std=c++17 -Wall -Wextra -c Lexer.cpp -o Lexer.o
g++ -std=c++17 -Wall -Wextra -c Parser.cpp -o Parser.o
g++ -std=c++17 -Wall -Wextra -o main main_ex1.o Lexer.o Parser.o
```

## Usage

To update fuzzing elements run the fuzzer first.
```bash
yilmaz@fp-10-126-155-166 debugging_and_fuzzing_lecture % ./fuzzer
2(simplify (* -508692209 -684637316))
2(simplify (* -902913870 2138364455))
0(simplify (+ -1260628803 -2015393194))
0(simplify (+ 925589080 -367692300))
0(simplify (+ -300866327 144131259))
1(simplify (- -719141517 -135503838))
1(simplify (- -2076349673 1551611738))
1(simplify (- 819521693 608029044))
0(simplify (+ -1743655740 1058509005))
1(simplify (- 757087945 348777956))
Data successfully written to output.txt!
```
After makefile processes you can run the program like as you see below.

```bash
yilmaz@fp-10-126-155-166 debugging_and_fuzzing_lecture % ./main
(- 1104081680236062780)
(- 315800697)
3184828252
2944187992
(- 492379597)
(- 1349795811206292835)
(- 92085407878966637)
(- 280765545200036514)
(- 203485932015933336)
793263972
```

## Comparison with Z3 Solver

```bash
yilmaz@fp-10-126-155-166 debugging_and_fuzzing_lecture % z3 -smt2 output.txt  >res1 && ./main > res2 && cmp res1 res2; echo $?
0
```

