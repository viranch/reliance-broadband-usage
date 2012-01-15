mkdir build
cd build
x=$(cat /proc/cpuinfo|grep processor|wc -l)
qmake .. && make -j$((x+1))

