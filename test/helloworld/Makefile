#
# you need to run build/setenv before building this
# in rjsc root folder
# $ . ./build/setenv
# $ cd (to this folder)
# $ make
# 
# send to rpi with scp
# $ scp helloworld rpi@IP_ADDRESS_RPI:/home/pi/.
# 
# login to your RPi and run
# $ ./helloworld hello raspberry pi world
#
helloworld: helloworld.cpp
	$(CXX) -o helloworld helloworld.cpp
