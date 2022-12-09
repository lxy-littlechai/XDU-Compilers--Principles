# XDU-Compilers--Principles
 xdu编译原理大作业

## 开发环境

- Ubuntu 22.04
- opencv
- clion

## 使用说明

执行Semantic文件夹下的main中输入文件路径，执行main函数

## 系统架构

- 词法分析 Scanner
- 语法分析 Parser
- 异常处理 ExceptionLog



## Part1 词法分析 Scanner

### 项目Scanner总体架构

| h/cpp   | Description                    |
| ------- | ------------------------------ |
| Scanner | 执行词法分析的入口             |
| Token   | 定义了记号的种类及相关数据结构 |
| Func    | 定义了不同函数的实现           |
| main    | 用于测试                       |

## Func.h/cpp

| Class | Description                        |
| ----- | ---------------------------------- |
| Func  | 抽象类，根据不同Func类型记号实例化 |
| Cos   | 实现cos运算                        |
| Sin   | 实现sin运算                        |
| Tan   | 实现tan运算                        |
| Ln    | 实现ln运算                         |
| Exp   | 实现exp运算                        |
| Sqrt  | 实现sqrt运算                       |

## Token.h/cpp

| 数据结构           | Description             |
| ------------------ | ----------------------- |
| enum TokenType     | 定义声明了各种单词类型  |
| class Token        | 单词数据结构            |
| Token TokenTable[] | 以Token结构存储关键单词 |

