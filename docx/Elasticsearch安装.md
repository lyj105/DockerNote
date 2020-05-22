> 下载elasticsearch6.4.0的docker镜像：
>
> ```shell
> docker pull elasticsearch:6.4.0
> ```
>
> 修改虚拟内存区域大小，否则会因为过小而无法启动:
>
> ```shell
> sysctl -w vm.max_map_count=262144
> ```
>
> 使用docker命令启动：
>
> ```shell
> docker run -p 9200:9200 -p 9300:9300 --name elasticsearch \
> -e "discovery.type=single-node" \
> -e "cluster.name=elasticsearch" \
> -v /mydata/elasticsearch/plugins:/usr/share/elasticsearch/plugins \
> -v /mydata/elasticsearch/data:/usr/share/elasticsearch/data \
> -d elasticsearch:6.4.0
> ```
>
> 启动时会发现/usr/share/elasticsearch/data目录没有访问权限，只需要修改/mydata/elasticsearch/data目录的权限，再重新启动。
>
> ```shell
> chmod 777 /mydata/elasticsearch/data/
> ```
>
> 安装中文分词器IKAnalyzer，并重新启动：
>
> ```shell
> docker exec -it elasticsearch /bin/bash
> #此命令需要在容器中运行
> elasticsearch-plugin install https://github.com/medcl/elasticsearch-analysis-ik/releases/download/v6.4.0/elasticsearch-analysis-ik-6.4.0.zip
> docker restart elasticsearch
> ```
>
> 开启防火墙：
>
> ```shell
> firewall-cmd --zone=public --add-port=9200/tcp --permanent
> firewall-cmd --reload
> ```
>
> 访问会返回版本信息：http://192.168.3.101:9200/
