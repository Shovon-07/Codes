/***
 * একটি ক্লাসে ৫ জন ছাত্র আছে: S1, S2, S3, S4, S5। প্রত্যেক ছাত্র ৫টি কোর্সে (C1, C2, C3, C4, C5) বিভিন্ন গ্রেড (A+, A, B+, B, C ইত্যাদি) পেয়েছে।
সি প্রোগ্রাম লিখতে হবে যেখানে:

সকল ছাত্রের ৫টি কোর্সের গ্রেড সংরক্ষণ করা হবে।
ব্যবহারকারী একটি ছাত্র নম্বর এবং একটি কোর্স নম্বর ইনপুট দিবে।

প্রোগ্রামটি সেই নির্দিষ্ট ছাত্রের নির্দিষ্ট কোর্সের গ্রেড দেখাবে।

উদাহরণ:
যদি ইনপুট হয় Student = 2 এবং Course = 4
তাহলে আউটপুট হবে: S2 got A in C4
***/

//=>>> Grade system
// #include <stdio.h>

// int main()
// {
//     char courseWiseGrade[5][5][3] = {
//         {"A+", "A", "B+", "A", "B"},
//         {"B+", "A+", "A", "A", "C"},
//         {"A", "B+", "A+", "B", "C"},
//         {"B", "A", "B+", "A+", "A"},
//         {"A+", "B", "A", "B+", "A"}};

//     int studentNo, courseNo;

//     printf("Enter student number : ");
//     scanf("%d", &studentNo);
//     printf("Enter course number : ");
//     scanf("%d", &courseNo);

//     printf("S%d got %s in C%d\n", studentNo, courseWiseGrade[studentNo - 1][courseNo - 1], courseNo);

//     return 0;
// }

//=>>> Cgpa system
#include <stdio.h>

int main()
{
    float marks[5][5] = {
        {80, 60, 90, 70, 50},
        {60, 30, 80, 90, 50},
        {80, 30, 70, 60, 40},
        {90, 60, 30, 80, 50},
    };

    int studentNo, courseNo, flag = 0;

    printf("Enter student number : ");
    scanf("%d", &studentNo);
    printf("Enter course number : ");
    scanf("%d", &courseNo);

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (marks[r][c] >= 80 && marks[r][c] <= 100)
            {
                flag = 1;
                break;
            }
            else if (marks[r][c] >= 70 && marks[r][c] < 80)
            {
                flag = 2;
                break;
            }
            else if (marks[r][c] >= 60 && marks[r][c] < 70)
            {
                flag = 3;
                break;
            }
            else if (marks[r][c] >= 50 && marks[r][c] < 60)
            {
                flag = 4;
                break;
            }
            else if (marks[r][c] >= 40 && marks[r][c] < 50)
            {
                flag = 5;
                break;
            }
        }
    }

    if (flag == 1)
    {
        printf("S%d got A+ in C%d\n", studentNo, courseNo);
    }
    else if (flag == 2)
    {
        printf("S%d got A in C%d\n", studentNo, courseNo);
    }
    else if (flag == 3)
    {
        printf("S%d got A- in C%d\n", studentNo, courseNo);
    }
    else if (flag == 4)
    {
        printf("S%d got B in C%d\n", studentNo, courseNo);
    }
    else if (flag == 5)
    {
        printf("S%d got C in C%d\n", studentNo, courseNo);
    }

    return 0;
}
