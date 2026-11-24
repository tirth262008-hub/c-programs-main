
#include <stdio.h>

int main()
{
    int year, i, j;
    int days, day, leap;
    int month_days[12] = {
        31,28,31,30,31,30,
        31,31,30,31,30,31
    };

    char *months[12] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    printf("Enter year: ");
    scanf("%d", &year);

    leap = (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);

    if(leap)
        month_days[1] = 29;

    days = 365 * (year - 1)
         + (year - 1) / 4
         - (year - 1) / 100
         + (year - 1) / 400;

    day = (days + 1) % 7;

    for(i = 0; i < 12; i++)
    {
        printf("\n\n     %s %d\n", months[i], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for(j = 0; j < day; j++)
            printf("    ");

        for(j = 1; j <= month_days[i]; j++)
        {
            printf("%3d ", j);

            day++;

            if(day == 7)
            {
                printf("\n");
                day = 0;
            }
        }
    }

    return 0;
}
