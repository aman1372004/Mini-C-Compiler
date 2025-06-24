# Compiler Design Lab - Project 3

## Semantic Analyzer for a Subset of the C Language

This module builds upon the parser developed in **Project 2**, and adds semantic analysis features to ensure the correctness of the program beyond syntax.

Semantic analysis ensures that the program follows the rules of the language like type compatibility, function usage, and more.

---

### 🧑‍💻 Team Members

1. Aman Singh  
2. Anurag Pundir  
3. Ayush Rana  
4. Abhishek Bhatt  



---

### ⚙️ Installation & Running Instructions

1. Make sure **Lex/Flex** and **Yacc/Bison** are installed  
2. Run the following commands:

```bash
$ lex lexer.l
$ yacc -d parser.y -v
$ gcc -w -g y.tab.c -ll -o semantic_analyzer
$ ./semantic_analyzer testcases/test-case-1.c
