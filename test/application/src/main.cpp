#include <three/three.h>

int main() {

    double b = 1.0;
    three::add(&b, 2.0);

    return b == 3 ? 0 : 1;

}