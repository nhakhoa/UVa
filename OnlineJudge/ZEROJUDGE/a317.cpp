#include <stdio.h>
#include <string.h>
char num[10][6][6] = {
    {"###","#.#", "#.#", "#.#", "###"},//0
    {"..#","..#", "..#", "..#", "..#"},//1
    {"###","..#", "###", "#..", "###"},//2
    {"###","..#", "###", "..#", "###"},//3
    {"#.#","#.#", "###", "..#", "..#"},//4
    {"###","#..", "###", "..#", "###"},//5
    {"###","#..", "###", "#.#", "###"},//6
    {"###","#.#", "#.#", "..#", "..#"},//7
    {"###","#.#", "###", "#.#", "###"},//8
    {"###","#.#", "###", "..#", "###"},//9
};
int main() {
    int t, i, j, k, l;
    scanf("%d", &t);
    char g[5][1024];
    while(t--) {
        for(i = 0; i < 5; i++)
            scanf("%s", g[i]);
        int len = strlen(g[0]), res = 0, sum = 0;
        for(i = 0; i < len; i++) {
            for(j = 0; j < 10; j++) {
                for(k = 0; k < 5; k++)
                    for(l = 0; l < 3; l++)
                        if(g[k][i+l] != num[j][k][l])
                            k = 10;
                if(k == 5)
                    sum = sum*10+j, j = 20;
            }
            if(j == 10)
                res += sum, sum = 0;
            i += 3;
        }
        res += sum;
        printf("%d\n", res);
    }
    return 0;
}