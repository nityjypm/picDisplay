setup: yum groupinstall 'Development Tools'

opencv: opencv-4.0.1

build: clang++ picDisplay.cpp -o picDisplay -L /usr/local/lib/ -I /usr/local/include/  -lopencv_core -lopencv_highgui -lopencv_imgcodecs

run: ./picDisplay /home/liul/lliu/temp/picDisplay/pic 3
