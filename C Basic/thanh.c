#include <stdio.h>
#include <string.h>

int main()
{
    char movie[30], age_class[20], date[30];

    float price;

    printf("Enter the movie you want to see : ");
    scanf("%s", movie);
    printf("Enter your age class : ");
    scanf("%s", age_class);
    printf("Enter the date you want to see the movie : ");
    scanf("%s", date);

    price = ( strncmp(date, "Weekend", 7) == 0) ? (10.0) : (7.0);

    if ( strncmp(age_class, "Child", 5) == 0) {
       price = price * 0.5;
    } else if ( strncmp(age_class, "Senior Citizen", 14) == 0) {
        price = price * 0.7;
    }

    printf("BKCine\n");
    printf("----------------\n");
    printf("-Movie: %s\n", movie);
    printf("-Class: %s\n", age_class);
    printf("-Date: %s\n", date);
    printf("-Price: %.2f$\n", price);

    return 0;
}