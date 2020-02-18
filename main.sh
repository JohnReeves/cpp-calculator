
clear 
echo '+------------------+'
cal
echo '+------------------+'
date +'%d/%m/%Y %H:%M:%S'
echo '+------------------+'
echo ' '

# gcc -o sample sample.c
# including any other gcc flags you like
# ./path-to-sample/sample

echo "building: "
echo '+------------------+'
echo "simple-rpn-calc.cpp"
echo '+------------------+'
echo "binaries in ./Results"
echo '+------------------+'
echo ' '

# g++ -o rpn-calc-regex2 rpn-calc-regex1.cpp
clang++ -std=c++11 -o rpn-calc-regex1 rpn-calc-regex1.cpp
./rpn-calc-regex1 '15 7 3 1 + − ÷ 3 × 3 4 1 + + -' # 20


