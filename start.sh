#!/bin/bash

#g++ -o ./docker-data/hello ./docker-data/hello.cpp

######## For main.cpp  ./hello test ########
#export IpAddress=0.0.0.0
#export Port=5000
#export IsOk=1
#export MyString=my-string
#./docker-file/hello
######## Mit docker container test ########

docker-compose build
docker-compose up
# remove all the containers, networks, volumes and images
docker-compose down -v --rmi all

