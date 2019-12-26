
#!/bin/bash

gcc -fPIC -shared -ldl -o libfcg.so main.c

#export LD_PRELOAD=`pwd`\libfcg.so
