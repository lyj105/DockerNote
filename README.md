# DockerNote
every day,learning learing..docker
# Deployment in Linux environment baseed on Docker container[]
>Docker containers are installed with Mysql,Redis,Nginx,RabbitMQ,Monggodb,ElasticSearch,And SpringBoot application deployment based on CenterOS7.6

- [Docker](#Docker environment installation)
    - [Examples](#examples)
- [Mysql](# Mysql Install)

- [Docker](#docker)
    - [Docker environment installation](#Docker environment installation)


# docker
## Docker environment installation
- 1:Install yum-utils:
```shell
yum install -y yum-utils device-mapper-persistent-data lvm2
```
- 2:Add docker repository location for yum source:
```shell
yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo
```
- 3:Install Docker:
```shell
yum install docker-ce
yum install docker-ce
```
-4: start Docker:
```shell
systemctl start docker
```
## Mysql Install
- 1:Download the docker image for mysql5.7:
```shell
docker push mysql:5.7
```
- 2:Start with docker command:
```shell
  docker run -p 3306:3306 --name mysql -v /mydata/mysql/log:/var/log/mysql -v /mydata/mysql/data:/var/lib/mysql -v /mydata/mysql/conf:/etc/mysql -e MYSQL_ROOT_PASSWORD=root -d mysql:5.7
```
- 3:Install the upload and download plugin:
```shell
  yum -y install lrzsz
```
- 4:Copy the *.sql file to the /directory of the mysql container:
```shell
  docker copy /*/*.sql mysql:/
```
- 5:Enter the docker container running mysql:
```shell
  docker exec -it mysql /bin/bash
```
- 6:Opne the clinet using the mysql command:
```shell
  mysql -uroot -p@jism9201020 --default-character-set=utf8
```
- 7:Create the mysql database:
```shell
  create database mysql character set utf8
```
- 8:Import the sql file into the database;
```shell
  show database;
  use mysql;
  source /mysql.sql
```
- 9:Create a jim account and modify permissions so that any IP can access:
grant all privileges on *.* to 'jim' @'%' identified by '123456';

