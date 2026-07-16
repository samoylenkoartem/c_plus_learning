#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int M = 10;
const int N = 10;
const int B = 10;
int Ar[M][N];
int Br[M][N];
//координаты для скана области
int Dx[4] = { 1,-1,0,0 };
int Dy[4] = { 0,0,1,-1 };
// ввод ограничений
int inBounds(int y, int x) {
    return y >= 0 && y < M && x >= 0 && x < N;
}

//генератор случайных значений
typedef long long int ll;
void init_rny(void) {
    time_t curtime;
    time(&curtime);
    srand((unsigned int)curtime);
    rand(); rand(); rand();
}
//случайный генератор координат
int gen_cood(void) {
    ll t = ((ll)rand() * B) / RAND_MAX;
    return (int)t;
}
//случайный генератор препятствий
int gen_mina(void) {
    ll t = ((ll)rand() * B * 1.5) / RAND_MAX;
    return (int)t;
}
int main(void) {
    init_rny();

    //расположение мин
    int n = gen_mina();
    for (int i=0; i <= n; i++) {
        int y = gen_cood();
        int x = gen_cood();
        Ar[y][x] = 111;
        Br[y][x] = 111;
    }
    // координаты для старта и финиша
reset:
    int st = gen_cood();
    int fn = gen_cood();
    if (Ar[st][0] == 111 || Ar[fn][N - 1] == 111) goto reset;
    //printf("%d, 9\n",fn);
    Ar[st][0] = 1;

    //заполненная матрица
    int f = 1;
    while (Ar[fn][N - 1] == 0) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (Ar[i][j] == f) {
                    for (int d = 0; d < 4; d++) {
                        int dx = Dx[d];
                        int dy = Dy[d];
                        if (Ar[i + dy][j + dx] == 0 && inBounds(i + dy, j + dx)) {
                            Ar[i + dy][j + dx] = f + 1;
                        }
                    }
                }
            }
        }
        f++;
    }
    //вывод матрицы
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%03d ", Ar[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //eсли нет пути
    if (Ar[fn][N - 1] == 0) {
        printf("Path was not founded");
        // если есть путь
    }
    else {
        int c = Ar[fn][N - 1];
        int Y = fn;
        int X = N - 1;
        Br[Y][X] = c;
        while (Br[st][0] != 1) {
            for (int d = 0; d < 4; d++) {
                int dx = Dx[d];
                int dy = Dy[d];
                if (Ar[Y - dy][X - dx] == c - 1) {
                    Br[Y - dy][X - dx] = c - 1;
                    c--;
                    Y = Y - dy;
                    X = X - dx;
                    break;
                }
            }
        }
    }
    //вывод пути
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%03d ", Br[i][j]);
        }
        printf("\n");
    }
    return 0;
}