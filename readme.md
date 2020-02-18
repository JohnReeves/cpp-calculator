
# Making a calculator in cpp

### The Project

We're going to make a calculator in cpp in stages:   
* First look at the RPN algorithm;  
* Then build the calculator till we find the limations, using:    
1. Regexes;   
2. Flex & Bison;   
3. Our own parser;   
4. ...;   

### First, the RPN Algorithm

[Pseudocode taken from the RPN wiki](https://en.wikipedia.org/wiki/Reverse_Polish_notation)

```pseudocode
for each token in the postfix expression:
  if token is an operator:
    operand_2 ← pop from the stack
    operand_1 ← pop from the stack
    result ← evaluate token with operand_1 and operand_2
    push result back onto the stack
  else if token is an operand:
    push token onto the stack
result ← pop from the stack
```

Take some time to understand the pseudocode!

[Also from the RPN wiki](https://en.wikipedia.org/wiki/Reverse_Polish_notation)

```
((15 ÷ (7 − (1 + 1))) × 3) − (2 + (1 + 1))
```
becomes:   
```
15 7 1 1 + − ÷ 3 × 2 1 1 + + −
```

Which has fewer characters to type and is easier to process than the algebraic notation.

`Pro-tip` RPN can also be the basis for your own domain specific language - even NLP where the sentences are arranged as `SOV` and not infixed as `SVO` .  

`Pro-top` The Algebraic Calculator is often made by converting infix to reverse polish notation .  

[Taken from the tree traversal wiki](https://en.wikipedia.org/wiki/Tree_traversal)

.