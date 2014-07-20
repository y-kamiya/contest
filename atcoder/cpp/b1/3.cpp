#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int calcW(int dis);
string calcDir(int deg);

static float dir[16] = {
    112.5,337.5,562.5,787.5,1012.5,1237.5,1462.5,1687.5,1912.5,2137.5,2362.5,2587.5,2812.5,3037.5,3262.5,3487.5
};
string dirStr[16] = {
    "N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"
};
static float array[12] = {0.2,1.5,3.3,5.4,7.9,10.7,13.8,17.1,20.7,24.4,28.4,32.6};

int main() {
    int deg, dis, ret, w;
    string dir;

    ret = scanf("%d %d", &deg, &dis);
    w = calcW(dis);
    dir = calcDir(deg);
    if (w == 0) {
        printf("C %d\n", w);
    } else {
        printf("%s %d\n", dir.c_str(), w);
    }


    return 0;
}

int calcW(int dis) {
    float v = round(dis * 10 / 60.0) / 10;
    int length = sizeof(array) / sizeof(array[0]);
    int i;
    for (i = 0; i < length; i++) {
        if (v <= array[i]) {
            return i;
        }
    }
    return i;

}

string calcDir(int deg) {
    for (int i = 0; i < 16; i++) {
        if (deg < dir[i]) {
            return dirStr[i];
        }
    }
    return dirStr[0];
}

