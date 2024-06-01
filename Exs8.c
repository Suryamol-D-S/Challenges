// Implement some computations using a 24-hour clock, such as 3 hours after 10:00 and 8 hours after 20:00
# include <stdio.h>
int main() {
    int hour1 = 3;
    int time1 = 10;
    int hour2 = 8;
    int time2 = 20;

    int newTime1=(hour1+time1)%24;
    int newTime2=(hour2+time2)%24;

    printf("3 hours after 10:00 is %2d:00\n", newTime1);
    printf("8 hours after 20:00 is %2d:00\n", newTime2);
}