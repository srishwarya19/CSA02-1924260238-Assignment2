
#include <stdio.h>

int main(void) {
    double balance = 10000;
    double rate = 0.02;
    double repayment = 2000;
    double interest, paid;
    double total_interest = 0;
    int month = 0;
    int limit = 360;

    while (balance > 0 && month < limit) {
        month++;

        interest = balance * rate;
        total_interest += interest;
        balance += interest;

        paid = (balance < repayment) ? balance : repayment;
        balance -= paid;

        printf("Month %d: Interest = %.2f, Paid = %.2f, Balance = %.2f\n",
               month, interest, paid, balance);
    }

    if (balance <= 0)
        printf("Loan completed in %d months\n", month);
    else
        printf("Maximum month limit reached\n");

    printf("Total interest = %.2f\n", total_interest);

    return 0;
}
