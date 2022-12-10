# XDU-Compilers--Principles
 xdu编译原理大作业

# 前言

本项目基于C++语言，linux平台，采用面向对象思想设计实现。相对以往版本代码，本项目具有以下显著特点

- 基于linux平台开发
- 基于opencv实现画图
- 基于cmake，逻辑结构更加清晰
- 采用现代化c++编程，运用c++11及以上特性



## 1. 开发相关

### 1.1 开发环境

- Ubuntu 22.04
- clion + cmake + opencv



### 1.2 开发说明

执行根目录下的main中输入文件路径，执行main函数

更改代码后在根目录下创建build文件夹，并进入build文件夹下，shell执行以下命令

```shell
cmake ..
make .
sudo make install
```

## 2、系统架构

### 2.1 模块目录

| 目录名       | 描述         |
| ------------ | ------------ |
| Scanner      | 词法分析模块 |
| Parser       | 语法分析模块 |
| Semantic     | 语义分析模块 |
| ExceptionLog | 异常处理模块 |
| headers      | 头文件       |
| lib          | 动态库       |



## 2.2 模块关系

模块关系图如下，其中箭头代表依赖关系，指向被依赖方。

![](/home/littlechai/University/XDU-Compilers--Principles/assets/系统架构.png)

项目采用增量开发的模式，即词法分析、语法分析、语义分析、整体视为四个项目，采用动态库链接和cmake配置的方法实现项目依赖。

main函数依赖词法、语法、语义分析三个模块，并未在图中标出，且为了方便环境配置，所依赖模块全部生成的动态库`allalllib.so`和`libopencv_highgui.so`，但语义分析模块单独运行仍依赖opencv环境。

异常处理函数采用**中断执行**的策略，当错误发生时，在中断中输出错误行数及错误信息，并停止运行程序，以下不再提及异常处理。

## 2.3 可执行程序

本文家共有四个可执行程序，即根目录、词法分析、语法分析、语义分析下的main函数，分别单独测试相应模块功能，其中语义分析依赖opencv环境。

### 2.3.1 词法分析

该程序在终端输出识别出记号的种类，字符串，值。

### 2.3.2 语法分析

该程序仅检测是否具有语法错误，若有则报错。该部分代码中含有**语法树输出**的功能，需要时可在代码相应位置进行修改。

### 2.3.3 语义分析

该程序对输入文本进行分析，输出对应图像，异常交由词法分析和语法分析处理。

### 2.3.4 根目录程序

该程序为对词法分析、语法分析、语义分析的包装，输入输出同语义分析。目的是增强移植性，减少环境依赖。

## 3 模块具体架构

### 3.1 词法分析 Scanner

#### 3.1.1 源文件

| h/cpp   | 描述                           |
| ------- | ------------------------------ |
| Scanner | 词法分析的实现                 |
| Token   | 定义了记号的种类及相关数据结构 |
| Func    | 抽象类，定义了不同函数的实现   |
| main    | 用于测试                       |

#### 3.1.2 Token.h/cpp 记号数据结构

共有22种记号，为了逻辑清晰，将其大致划分成了五类，保留字、常量|变量|函数、分隔符、运算符、特殊记号。在实际判断过程中根据字母、数字、符号分为三类判断，将保留字、变量、函数三种类型预存入记号表中，实时判断数字和操作符。

对于每个记号，用（记号种类，字符串，值，函数指针）的数据结构存储，便于后续匹配记号与计算表达式。

#### 3.1.3 Func.h 函数

Func作为抽象类，通过构建不同子类的实例，对不同的函数进行绑定。

| Class  | Description                        |
| ------ | ---------------------------------- |
| Func   | 抽象类，根据不同Func类型记号实例化 |
| Cos    | 实现cos运算                        |
| Sin    | 实现sin运算                        |
| Tan    | 实现tan运算                        |
| Ln     | 实现ln运算                         |
| Exp    | 实现exp运算                        |
| Sqrt   | 实现sqrt运算                       |
| NoFunc | 非函数类                           |

#### 3.1.3 异常种类

1、文件打开失败时，报告文件打开异常

2、记号错误时，报告ErrorToken异常
