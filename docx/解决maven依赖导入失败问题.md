

## 解决maven依赖导入失败问题

1：准备阿里云镜像

```java
<mirror>    
    <id>nexus-aliyun</id>   
    <mirrorOf>*</mirrorOf>    
    <name>Nexus aliyun</name>                		<url>http://maven.aliyun.com/nexus/content/groups/public</url>
</mirror>
    
```

2:idea 配置：

setting.xml

IntelliJ IDEA 2019.3.2\plugins\maven\lib\maven2\conf