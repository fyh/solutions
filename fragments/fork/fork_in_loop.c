# include <unistd.h>
# include <stdio.h>

int main()
{
    int count = 0;
    for (int i = 0; i < 2; ++i) {
        pid_t fcpid = getpid();
        pid_t fpid = fork();
        ++count;
        printf("%d -> %d\n", fcpid, fpid);
    }
    printf("count = %d\n", count);

    return 0;
}

/*
output:
9034 -> 9036
9034 -> 9037
count = 2
9034 -> 0
9036 -> 9038
count = 2
9034 -> 9036
9034 -> 0
count = 2
9034 -> 0
9036 -> 0
count = 2
*/
