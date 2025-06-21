/*
 * codegen.c - Simple code generator for three-address code (TAC)
 * Reads optimized.icg and generates stack-based pseudo-assembly in code.asm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256

void gen_arith(FILE *fout, char *lhs, char *op1, char *op, char *op2) {
    // Push operands
    fprintf(fout, "PUSH %s\n", op1);
    fprintf(fout, "PUSH %s\n", op2);

    // Arithmetic operation
    if (strcmp(op, "+") == 0)
        fprintf(fout, "ADD\n");
    else if (strcmp(op, "-") == 0)
        fprintf(fout, "SUB\n");
    else if (strcmp(op, "*") == 0)
        fprintf(fout, "MUL\n");
    else if (strcmp(op, "/") == 0)
        fprintf(fout, "DIV\n");

    // Store result
    fprintf(fout, "POP %s\n", lhs);
}

void gen_assign(FILE *fout, char *lhs, char *rhs) {
    fprintf(fout, "MOV %s, %s\n", lhs, rhs);
}

void gen_ifgoto(FILE *fout, char *op1, char *relop, char *op2, char *target) {
    // Example: if i < 10 goto 7
    fprintf(fout, "PUSH %s\n", op1);
    fprintf(fout, "PUSH %s\n", op2);
    if (strcmp(relop, "<") == 0)
        fprintf(fout, "JL %s\n", target);
    else if (strcmp(relop, "<=") == 0)
        fprintf(fout, "JLE %s\n", target);
    else if (strcmp(relop, ">") == 0)
        fprintf(fout, "JG %s\n", target);
    else if (strcmp(relop, ">=") == 0)
        fprintf(fout, "JGE %s\n", target);
    else if (strcmp(relop, "==") == 0)
        fprintf(fout, "JE %s\n", target);
    else if (strcmp(relop, "!=") == 0)
        fprintf(fout, "JNE %s\n", target);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <optimized.icg>\n", argv[0]);
        return 1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        perror(argv[1]);
        return 1;
    }
    FILE *fout = fopen("code.asm", "w");
    if (!fout) {
        perror("code.asm");
        fclose(fin);
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fin)) {
        // Remove newline
        size_t len = strlen(line);
        if (len && line[len-1] == '\n') line[len-1] = 0;

        // ------------ LABEL HANDLING ----------
        int labelnum;
        char label_line[MAX_LINE];
        strncpy(label_line, line, MAX_LINE);
        char *colon = strchr(label_line, ':');
        if (colon && (colon - label_line) < 6 && isdigit(label_line[0])) {
            *colon = '\0';
            fprintf(fout, "L%s:\n", label_line);
            // Now process the rest of the line after the colon (if any)
            char *rest = colon + 1;
            while (*rest == ' ') rest++; // skip spaces
            if (!*rest) continue;
            strcpy(line, rest);
        }

        // ---------- if x relop y goto label ----------
        char op1[32], relop[4], op2[32], target[32];
        if (sscanf(line, "if %31s %3s %31s goto %31s", op1, relop, op2, target) == 4) {
            gen_ifgoto(fout, op1, relop, op2, target);
            continue;
        }

        // ---------- goto label ----------
        if (sscanf(line, "goto %31s", target) == 1) {
            fprintf(fout, "JMP %s\n", target);
            continue;
        }

        // ---------- x = y op z ----------
        char lhs[32], eq[4], rhs1[32], op[4], rhs2[32];
        if (sscanf(line, "%31s %3s %31s %3s %31s", lhs, eq, rhs1, op, rhs2) == 5 && strcmp(eq, "=") == 0) {
            gen_arith(fout, lhs, rhs1, op, rhs2);
            continue;
        }

        // ---------- x = y (simple assignment) ----------
        if (sscanf(line, "%31s %3s %31s", lhs, eq, rhs1) == 3 && strcmp(eq, "=") == 0) {
            gen_assign(fout, lhs, rhs1);
            continue;
        }

        // ---------- Handle increment (i++) ----------
        if (sscanf(line, "%31s++", lhs) == 1) {
            fprintf(fout, "INC %s\n", lhs);
            continue;
        }

        // ---------- Handle exit ----------
        if (strstr(line, "exit")) {
            fprintf(fout, "HLT\n");
            continue;
        }

        // ---------- Handle array assignment: j = arr[7] ----------
        // Note: This is a simple parse; adapt as needed for your ICG style.
        if (sscanf(line, "%31s = %31[^[][%d]", lhs, rhs1, &labelnum) == 3) {
            fprintf(fout, "MOV %s, %s[%d]\n", lhs, rhs1, labelnum);
            continue;
        }

        // ---------- Fallback: comment unrecognized lines ----------
        fprintf(fout, "; %s\n", line);
    }

    fclose(fin);
    fclose(fout);
    printf("Code generation complete. Output: code.asm\n");
    return 0;
}