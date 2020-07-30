# LinuxInstallNginx
**1：Download the installation file path address**
nginx official download address:http://nginx.org/en/download.html
fileName:nginx-1.14.2
**2：After the download is complete, upload it to the server, where I upload it to the location of the server /usr/local.**
usr/local/#
**3:Start nginx install**
* 1、Enter /usr/local and use the command tar -zxvf nginx-1.14.2.tar.gz to decompress nginx to get
* 2、Enter /usr/local/nginx-1.14.2
* 3、The next command: ./configure --prefix=/usr/local/nginx-1.14.2 It means to tell where to put the files that will be installed. (You don't need to set it, just ./configure)
mark:
   BUG: checking for in ///// not found 
   Makfile
* 4、170217. An error was reported during nginx installation: make: *** No rule to make target `build', needed by `default'. Stop.
http://www.cnblogs.com/chenxiaochan/p/7253407.html
https://www.cnblogs.com/zrbfree/p/6419043.html（install）
4.1, GCC-GNU compiler collection
      ubuntu: apt-get install gcc
      linux: yum install gcc-c++
4.2, PCRE library
         ubuntu:apt-get install libpcre3 libpcre3-dev
         linux: yum install -y pcre pcre-devel
4.3, zlib library
         ubuntu: apt-get install zlib1g zlib1g-dev
         linux: yum install -y zlib zlib-devel
OpenSSL library
         ubuntu:apt-get install openssl openssl-dev
         linux: yum install -y openssl openssl-devel




