/*
 * optimizer.c - Improved Optimizer for your ICG format
 * Performs constant folding, preserves labels/control flow/arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256

// Helper: Checks if string is an integer constant
int is_int(const char *s) {
    if (!*s) return 0;
    while (*s) {
        if (!isdigit(*s) && !((*s == '-') && (s == s))) return 0;
        s++;
    }
    return 1;
}

// Try to fold simple binary ops with integer constants
int try_constant_folding(const char *line, char *out) {
    // Example: t0 = 2 + 3
    char lhs[32], eq[4], op1[32], op[4], op2[32];
    // Only match lines like: tX = INT OP INT
    int n = sscanf(line, "%31s %3s %31s %3s %31s", lhs, eq, op1, op, op2);
    if (n == 5 && strcmp(eq, "=") == 0 && is_int(op1) && is_int(op2)) {
        int a = atoi(op1), b = atoi(op2), res;
        if (strcmp(op, "+") == 0) res = a + b;
        else if (strcmp(op, "-") == 0) res = a - b;
        else if (strcmp(op, "*") == 0) res = a * b;
        else if (strcmp(op, "/") == 0 && b != 0) res = a / b;
        else return 0;
        sprintf(out, "%s = %d", lhs, res);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <icg_file>\n", argv[0]);
        return 1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        perror(argv[1]);
        return 1;
    }
    FILE *fout = fopen("optimized.icg", "w");
    if (!fout) {
        perror("optimized.icg");
        fclose(fin);
        return 1;
    }

    char line[MAX_LINE], folded[MAX_LINE];
    while (fgets(line, sizeof(line), fin)) {
        // Remove newline
        size_t len = strlen(line);
        if (len && line[len-1] == '\n') line[len-1] = 0;
        if (try_constant_folding(line, folded)) {
            fprintf(fout, "%s\n", folded);
        } else {
            // Write all lines as-is if not foldable
            fprintf(fout, "%s\n", line);
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Optimization complete. Output: optimized.icg\n");
    return 0;
}