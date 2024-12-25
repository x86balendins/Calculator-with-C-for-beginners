#include <stdio.h>

int main() {
    int num1, num2;
    char op;
    float total;

    printf("Enter the first operation in this format: number1 operator number2 (e.g., 5 + 3)\n");
    scanf("%d %c %d", &num1, &op, &num2);

    // Perform the first operation
    switch (op) {
        case '+':
            total = num1 + num2;
            break;
        case '-':
            total = num1 - num2;
            break;
        case '*':
            total = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                total = (float)num1 / num2;
            else {
                printf("Error: Division by zero is not allowed!\n");
                return 0;
            }
            break;
        case '%':
            if (num2 != 0)
                printf("= %d\n", num1 % num2);
            else {
                printf("Error: Modulus operation with divisor zero is not allowed!\n");
                return 0;
            }
            return 0; // Modulus operation is one-time only
        default:
            printf("Invalid operator!\n");
            return 0;
    }

    printf("= %.2f\n", total);

    // Loop for subsequent operations
    while (1) {
        printf("Enter the next operation: operator number (e.g., + 2)\n");
        scanf(" %c %d", &op, &num2); // ' ' cleans up previous spaces.

        switch (op) {
            case '+':
                total += num2;
                break;
            case '-':
                total -= num2;
                break;
            case '*':
                total *= num2;
                break;
            case '/':
                if (num2 != 0)
                    total /= num2;
                else {
                    printf("Error: Division by zero is not allowed!\n");
                    return 0;
                }
                break;
            case '%':
                if (num2 != 0)
                    printf("= %d\n", (int)total % num2);
                else {
                    printf("Error: Modulus operation with divisor zero is not allowed!\n");
                    return 0;
                }
                continue; // Do not modify the total
            case 'q': // Exit command
                printf("Program is terminating.\n");
                return 0;
            default:
                printf("Invalid operator!\n");
                continue;
        }
        printf("= %.2f\n", total);
    }

    return 0;
}

