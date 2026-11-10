
#include <stdio.h>

int calls = 0;

int verify_card(int card) {
    calls++;
    return card == 1;
}

int main(void) {
    int senior, eligible, card;
    int concession;
    int i;

    printf("Enter senior, eligible, disability card (1/0): ");
    scanf("%d %d %d", &senior, &eligible, &card);

    calls = 0;
    concession = (senior && eligible) || verify_card(card);
    printf("Concession = %d\n", concession);
    printf("Calls = %d\n", calls);

    calls = 0;
    concession = verify_card(card) || (senior && eligible);
    printf("Concession = %d\n", concession);
    printf("Calls = %d\n", calls);

    calls = 0;
    for (i = 0; i < 1000; i++) {
        int s = i % 2;
        int e = (i % 3 == 0);
        int c = (i % 10 == 0);

        concession = (s && e) || verify_card(c);
    }
    printf("1000 passengers calls = %d\n", calls);

    calls = 0;
    for (i = 0; i < 1000; i++) {
        int s = i % 2;
        int e = (i % 3 == 0);
        int c = (i % 10 == 0);

        concession = verify_card(c) || (s && e);
    }
    printf("Reversed order calls = %d\n", calls);

    return 0;
}
