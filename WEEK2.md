# WEEK 2

本周学习的内容不多，主要分为三部分

- 对vim的继续了解
- 基于c学习Java & basic syntax in Java
- STACK

## 对vim的继续了解

之前了解到的一些文本编辑内容都是vim最基础最基础的功能，通过阅读官方的tutorial我发现vim有非常多的plugin，几乎支持全部语言，可以在vim中做出一个类似ide的界面，在linux terminal中使用会非常方便。所以在接下来一段时间我会更深入的去了解这部分的知识，来更好地去掌握vim这个高效工作的工具。

> [顺便贴上我学习用的pdf链接](ftp://ftp.vim.org/pub/vim/doc/book/vimbook-OPL.pdf)
> （感觉自己深深的爱上vim和命令行了（IDE是什么，要用鼠标那么麻烦的吗？（这个时候应该装傻.jpg

------

## 基于c学习Java & basic syntax in Java

### C and Java

- pointer and referrence

> 在C中pointer是一个十分常用且可以高效处理问题的工具，使用它来结合struct可以很方便的来实现ADT的定义blah blah balh，还可以很方便的直接通过地址来修改一些东西。
> 但是在Java里面是没有pointer的，取而代之的是referrence，这是一个类似于pointer但又不同于pointer的东西，referrrence是直接指向object而不是地址，不能进行各种运算操作，如ptr++之类

- error handling in c and Java

> 在c里面处理方法主要有：
>
> 1. A function may return a special value to indicate that an error has occurred, e.g. -1 instead of a count;
> 2. A function's return value may serve only to indicate error status;
> 3. The function itself may not indicate whether an error occurred or not, and the caller may have to call some separate function to find out whether an error occurred.

> 但是在Java这一类高级语言中就要方便的多，可以直接使用try{ }; catch( ){ };（这一点和python是相似的）然后再加上循环体，可以让一段代码执行成功之后再进入到下面的代码，而不是在执行失败的时候直接报错然后推出程序

### basic in Java

#### basic term

- object
- class 
- method 
- instance variables

#### basic syntax

------

## Stack

> 目前只了解了一些基础知识，稍稍做一下总价，下周将结合作业做更加详细的归纳

- 操作

> - push
> - pop
> - is Empty
> - getTop
> - init
> - destroy
> - clear
> - lenth

分类

- Order stack
- link stack 