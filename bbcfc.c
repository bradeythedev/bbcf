#include <stdio.h>


// Type defs
typedef char* string;


// Global variables
// Previous character and the value count, for optimisations
int prevChar = 0;
int prevValue = 0;
char prevSpecial = ' ';
int tabDepth = 0;


void printPrefix() {

    printf("#include <stdio.h>");
    printf("\n\nchar array[1024];");
    printf("\nchar *i;");
    printf("\n\nvoid decPointer() {");
    printf("\n\t// <{1}");
    printf("\n\ti--;");
    printf("\n}");
    printf("\n\nvoid subPointer(int a) {");
    printf("\n\t// <{a}");
    printf("\n\ti -= a;");
    printf("\n}");
    printf("\n\nvoid incPointer() {");
    printf("\n\t// >{1}");
    printf("\n\ti++;");
    printf("\n}");
    printf("\n\nvoid addPointer(int a) {");
    printf("\n\t// >{a}");
    printf("\n\ti += a;");
    printf("\n}");
    printf("\n\nvoid decValue() {");
    printf("\n\t// -{1}");
    printf("\n\t*i -= 1;");
    printf("\n}");
    printf("\n\nvoid subValue(int a) {");
    printf("\n\t// -{a}");
    printf("\n\t*i -= a;");
    printf("\n}");
    printf("\n\nvoid incValue() {");
    printf("\n\t// +{1}");
    printf("\n\t*i += 1;");
    printf("\n}");
    printf("\n\nvoid addValue(int a) {");
    printf("\n\t// +{a}");
    printf("\n\t*i += a;");
    printf("\n}");
    printf("\n\nvoid output() {");
    printf("\n\t// .");
    printf("\n\tprintf(\"%%c\", *i);");
    printf("\n}");
    printf("\n\nvoid input() {");
    printf("\n\t// ,");
    printf("\n\t*i = getchar();");
    printf("\n}");
    printf("\n\nint main() {");
    printf("\n\t// Initialise pointer");
    printf("\n\ti = array;\n\n");

}


// Print extra tabs for while loops
void printTabs() {

    if (tabDepth > 0) {

        for (int i = 0; i < tabDepth; i++) {

            printf("\t");

        }

    }

}


// Print the finalised output
void printOutput(char inChar, int inValue) {

    if (inChar != ' ') {

        printTabs();
        
        switch (inChar) {
            case '<':
                if (inValue > 1) {
                    printf("\tsubPointer(%i);\n", inValue);
                } else {
                    printf("\tdecPointer();\n");
                }
                break;
            case '>':
                if (inValue > 1) {
                    printf("\taddPointer(%i);\n", inValue);
                } else {
                    printf("\tincPointer();\n");
                }
                break;
            case '-':
                if (inValue > 1) {
                    printf("\tsubValue(%i);\n", inValue);
                } else {
                    printf("\tdecValue();\n");
                }
                break;
            case '+':
                if (inValue > 1) {
                    printf("\taddValue(%i);\n", inValue);
                } else {
                    printf("\tincValue();\n");
                }
                break;
            case '.':
                printf("\toutput();\n");
                break;
            case ',':
                printf("\tinput();\n");
                break;
            case '[':
                printf("\twhile (*i != 0) {\n");
                tabDepth++;
                break;
            case ']':
                printf("}\n");
                tabDepth--;
                break;
        }
    }

}


// Processing for each char
void processChar(char inChar) {

    int charType = 0;
    int direction = 0;

    if (inChar == '<' || inChar == '>') {

        charType = 1;

        if (inChar == '>') {

            direction = 1;

        }

    } else if (inChar == '-' || inChar == '+') {

        charType = 2;

        if (inChar == '+') {

            direction = 1;

        }

    }

    if (charType == prevChar && charType != 0) {

        if (direction == 0) {

            prevValue--;

        } else {
        
            prevValue++;

        }

    } else {

        if (prevChar == 1) {

            if (prevValue > 0) {

                printOutput('>', prevValue);


            } else if (prevValue < 0) {

                printOutput('<', -prevValue);

            }

        } else if (prevChar == 2) {

            if (prevValue > 0) {

                printOutput('+', prevValue);

            } else if (prevValue < 0) {

                printOutput('-', -prevValue);

            }

        } else {
        
            printOutput(prevSpecial, 1);

        }

        prevChar = charType;
        if (charType == 0) {

            prevSpecial = inChar;

        }
        
        if (direction == 1) {
            
            prevValue = 1;

        } else {
                
            prevValue = -1;
            
        }

    }

}


// Main method which receives chars and calls processChar()
int main() {

    // Output premade 'prefix'
    printPrefix();

    // Char to store current received char in
    char c;

    // Loop to execute for every char received
    while ((c = getchar()) != EOF) {
        
        processChar(c);

    }

    processChar(' ');
    printf("\n\treturn 0;");
    printf("\n}");

    return 0;
}