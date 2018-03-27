# C++ 开发web服务（使用xml-rpc协议）

#### 项目介绍
这是一个使用xmlrpc-c库进行开发的web服务，其提供的服务十分简单基础，就是一个数据库的增删查改。  
xmlrpc-c是一个xml-rpc协议的一个C/C++实现库。  
下载地址：[https://sourceforge.net/projects/xmlrpc-c/](https://sourceforge.net/projects/xmlrpc-c/)  

本项目使用的仅仅是xmlrpc-c库中的最简单的功能进行实现的。具体示例可以参考xmlrpc-c库的源代码中的 `example/cpp/xmlrpc_samlple_add_client.cpp` 和 `example/cpp/xmlrpc_samlple_add_server.cpp` 中的代码。  

#### 项目依赖的环境
本项目是在Linux系统下进行开发的，如果想在windows下进行开发的同学可以借鉴此项目。  

| 依赖的环境 | 版本 |
|------|----------------------|
| 操作系统 | Ubuntu（版本 16.04） |
| 数据库 | MySQL（版本 5.7.21） |
| 编程语言 | C++ |
| 编译器 | gcc（版本 5.4.0） |
| IDE | CLion |
| C++对MySQL的操作库 | libmysqlclient-dev |

> 在安装libmysqlclient-dev库的时候可能会遇到无法找到libmysqlclient.so链接库的问题，详情请看[我的这篇博文](https://ison-laihus.github.io/2018/03/26/Linux-%E4%B8%8B%E5%AE%89%E8%A3%85libmysqlclient-dev%E6%89%BE%E4%B8%8D%E5%88%B0%E9%93%BE%E6%8E%A5%E5%BA%93/)

#### 项目的目录结构
┠ web_service_xmlrpc	项目目录
┗┏ client	客户端代码
  ┠ Makefile	编译
  ┠ MysqlManager.cpp	数据库操作类实现
  ┠ MysqlManager.h	数据库操作类定义头文件
  ┠ README.md	项目介绍文件
  ┠ server.cpp	服务器端代码
  ┠ Services.h	定义所有提供的服务的头文件
  ┠ UserOperation.cpp	操作数据表user的类实现
  ┗ UserOperation.h	操作数据表user的类定义头文件

#### 项目的数据库
user表结构：  

| 字段 | 数据类型 | 是否是主键 | 能否为NULL |
|------|---------|------------|------------|
| id | int(11) | YES | NO |
| name | varchar(16) | | NO |
| age | int(3) | | NO |
| sex | enum('male', 'female') | | NO |


#### 项目提供的服务
1. sample.add：原有的示例服务，求两个整数的和
2. get.all.user：获取user表中的所有用户信息
3. get.one.user：获取user表某个用户的信息
4. add.user：向user表中添加用户
5. update.user：更新user表中的数据
6. delete.user：删除user表中的记录

#### 编译执行前的操作
1. 创建数据表并导入数据到本地数据库
2. 修改UserOperation.cpp文件中的下列信息
		string UserOperation::host = "localhost";
		string UserOperation::user = "root";
		string UserOperation::pwd = "lyk";
		string UserOperation::db = "test_xmlrpc";
		int UserOperation::port = 3306;

#### 编译执行
	make
	./server
	./client


