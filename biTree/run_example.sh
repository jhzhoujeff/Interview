
docker run --rm -v $PWD:/source/ gcc bash -ex /source/build.sh
docker run --rm -v $PWD:/source/ gcc ./source/main

