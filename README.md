# DockerNote
every day,learning learing..docker
# Deployment in Linux environment baseed on Docker container
>Docker containers are installed with Mysql,Redis,Nginx,RabbitMQ,Monggodb,ElasticSearch,And SpringBoot application deployment based on CenterOS7.6
## Docker environment installation
- Install yum-utils:
```shell
yum install -y yum-utils device-mapper-persistent-data lvm2
```
- Add docker repository location for yum source:
```shell
yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo
```
- Install Docker:
```shell
yum install docker-ce
yum install docker-ce
```

- start Docker:
```shell
systemctl start docker
```
