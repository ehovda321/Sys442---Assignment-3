#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdlib>

using namespace std;
int main() {
    int i = 0;
    while(i<100){    
        printf("%d \n", i);
        i++;
    }


}