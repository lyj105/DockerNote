> 下载kibana6.4.0的docker镜像：
>
> ```shell
> docker pull kibana:6.4.0
> ```
>
> 使用docker命令启动：
>
> ```shell
> docker run --name kibana -p 5601:5601 \
> --link elasticsearch:es \
>-e "elasticsearch.hosts=http://es:9200" \
> -d kibana:6.4.0
>```
> 
> 开启防火墙：
> 
> ```shell
> firewall-cmd --zone=public --add-port=5601/tcp --permanent
> firewall-cmd --reload
> ```
> 
>访问地址进行测试：http://192.168.3.101:5601
