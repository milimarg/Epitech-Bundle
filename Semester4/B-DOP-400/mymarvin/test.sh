#!/bin/bash

docker rm -f $(docker ps -aq)
docker volume rm marvin_disk
docker volume create marvin_disk
docker build -t marvin_image .
docker run -p 8080:8080 -v marvin_disk:/var/jenkins_home marvin_image
