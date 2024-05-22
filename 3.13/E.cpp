#include <stdio.h>
#include <string.h>
int compareStrings(char *S, char *T) {
    if (strlen(S) > strlen(T))
    {
        return 1;
    }
    if (strlen(S) < strlen(T))
    {
        return -1;
    }
    int boks = 0, bokt = 0;
    while (*S != '\0' && *T != '\0') {
        if (*S > *T) {
            boks++;
        } else if (*S < *T) {
            bokt++;
        }

        S++;
        T++;
    }

    if (boks < bokt) {
        return -1;
    } else if (boks > bokt) {
        return 1;
    }

    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char S[100], T[100];
        scanf("%s%s", S, T);

        int result = compareStrings(S, T);
        printf("%d\n", result);
    }

    return 0;
}
