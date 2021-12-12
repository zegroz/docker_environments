# for building cpp files in container: 
#FROM gcc:7.5
# build from ubuntu and copy files into conatainer:
FROM ubuntu:18.04

RUN apt-get -y update
#RUN apt-get -y upgrade
RUN apt-get install g++ -y

# copy of local files into the container
# From Docker online documentation:
# Although ADD and COPY are functionally similar, generally speaking, COPY is preferred. 
# That’s because it’s more transparent than ADD. COPY only supports the basic copying of local files into the container, 
# while ADD has some features (like local-only tar extraction and remote URL support) that are not immediately obvious. 
# Consequently, the best use for ADD is local tar file auto-extraction into the image, as in ADD rootfs.tar.xz /.
#COPY . /app
COPY . /work_dir_in_container
#ADD . /app


# define work dir
WORKDIR /work_dir_in_container
# debug output of work_dir_in_container dir
RUN ls /work_dir_in_container

#  LD_LIBRARY_PATH is the predefined environmental variable in Linux/Unix
#ENV LD_LIBRARY_PATH=/app/lib
RUN g++ -o ./hello ./hello.cpp

#ENTRYPOINT ["sh","./docker-entrypoint.sh"]
#CMD [ "sh", "./docker-entrypoint.sh" ]
CMD ["./hello"]
