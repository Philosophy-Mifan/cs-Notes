## Chapter 1 总览

(注1：这一章只是让自己有个概念，基本上都在后面的章节中会有更详细的说明)	//全是坑

(注2：大纲中出现*的内容为非当前章节内容但应有所了解)

(注3：在本文中出现的代码块，除特别的明确要求以外均只作为参考查阅)

高级语言往操作系统迈进的一个过程：以C语言为例(hello.c)

1、预处理过程：将我们需要引用的所有内容插入到源文件  `hello.c gcc -E xxx.c -o xxxx.i`

2、编译阶段：将.i文件翻译成汇编程序  `gcc -S xxxx.i -o xxxxx.s`

3、汇编阶段：汇编器将.s文件翻译成机器语言指令  `gcc -c xxx.s -o xxx.o`

4、链接阶段



操作系统的任务就是建立一个和计算机硬件一一对应的模型，为了1.提供更简单、清晰的模型；2.在一定程度上保护硬件

操作系统能够直接夺取机器的控制权

常见的图形用户界面（GUI）:Windows OS、Mac OS等

基于命令行的(只能通过命令行的)：一般统称为Shell文件，我们输入的命令行就是Shell

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-1 操作系统与硬件.png" style="zoom:75%;" />

操作系统将硬件做了抽象，建立起来的一个模型，以软件的形式表达这些硬件；应用程序是以软件的形式对外在的表达



### 1.1 简单现代计算机的硬件

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-2 一个典型系统的硬件组成.jpg" style="zoom:67%;" />

寄存器：用于存储指向下一条指令的地址

程序计数器：记的就是多线程（详见《计算机组成原理》- 线程）（注：在Pentium 4之后出现了多线程的概念）

线程是一个轻量级的进程

指令集架构：人为编写的一套处理指令的规则

在现代计算机中，将指令集和处理器的微体系结构做了区分，指令集架构：用来描述机器代码的执行效果；处理器的微体系结构：描述处理器的具体实现（详见《计算机组成原理》）

通用寄存器：用于保存变量或者临时结果、保存堆栈指针

程序状态寄存器：由操作系统维护的一个long型(8字节、64位)的数据集合，跟踪当前系统的状态，在系统调用和I/O中非常重要

流水线：取指单元--->解码单元--->执行单元，(解耦合)

超标量流水线（下图所示）：为了无序执行

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-3 超标量流水线.png" style="zoom:67%;" />

存储层次结构（如下图所示）

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-4 存储层次结构.png" style="zoom:67%;" />

时间局部性：某一个内存块的重复性；空间局部性：内存位置及其周边位置的重复性

Q1：什么时候我们要把新的内容存放进缓存？

Q2：新的内容应该存放在缓存的哪一个行？

Q3：当需要新的空间的时候，应该把哪一块内容移出？

Q4：移除的这个内容又需要放到哪里去？

（以上四个基础问题衍生出了各种缓存）



现代CPU当中共有两种缓存：第一级放在CPU内部，用来将已经解码的指令调入到CPU的执行引擎中，第二级缓存是用来存放最近使用过的关键字，有一定的延迟



磁盘驱动器的构造（如下图所示）

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-5 磁盘驱动器的构造.jpg" style="zoom:25%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-6 盘面.jpg" style="zoom:25%;" />

存储器管理单元MMU：内存地址映射；控制器：屏蔽一些物理上的一些细节，加代理



#### 实现输入和输出的方式

忙等待、中断机制(见下图)、直接存储器访问(Direct Memory Access，DMA)芯片

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-7 启动设备并发出中断的过程.jpg" style="zoom:25%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-8 中断过程.jpg" style="zoom:25%;" />



#### 将设备驱动程序装入操作系统

第一个途径是将内核与设备启动程序重新连接，然后重启系统；

第二个途径是在一个操作系统文件中设置一个入口，通知该文件需要一个设备驱动程序，然后重新启动系统。在重启系统时，操作系统会寻找有关的设备启动程序并把它装载；

第三个途径是操作系统能够在运行时接收新的设备驱动程序并立刻安装，无需重启操作系统，这种方式采用的少，但正在普遍起来。(热插拔)



总线（Bus）：就跟公共汽车一样

公共汽车的站点——多个设备或者接入点

乘客——传输的数据包

车是有容量的，所以传输的信息也是有容量的——字节块

车辆谁先走谁后走，走哪站，需要有顺序，有规定的——控制器

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-9 一个大型的x86系统的结构.jpg" style="zoom:35%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-10 硬件结构.jpg" style="zoom:30%;" />

### 1.2 操作系统部分

**硬件支持系统，系统管理硬件**

操作系统其实就是一个建立在应用程序和硬件之间的一道桥梁

基本功能：

1、防止硬件被滥用，尤其是一些失控程序

2、通过一种比较简单的机制匹配对应的应用程序，进而控制复杂的硬件

对硬件进行的抽象：进程、虚拟内存、文件

#### 1.2.1 进程

进程的本质就是操作系统执行的一个程序

与进程相关：地址空间——从某个最小值的存储位置(通常是0)到某个最大值的存储位置的列表

资源集——通常包括寄存器(registers)（寄存器一般包括程序计数器(PC)和堆栈指针(stack pointer)）、打开文件的清单、突发的报警、有关的进程清单和其他需要执行程序的信息

一个挂起的进程包括：进程的地址空间——磁盘映像 + 进程表项

与进程管理有关的最关键的系统调用往往是决定着进程的创建和终止的系统调用

进程间通信：合作完成某写作业的相关进程经常需要彼此通信完成作业



##### 多个进程的执行

我们需要运行的进程大多都是要多余CPU个数的，而每个不同的进程都可以看做是在独占一个硬件设备



##### 并发技术

通过指令的交错执行，进程来回切换，一个进程的指令和另一个进程的指令交错执行的过程叫做并发运行。在每个任务运行前，CPU都需要知道任务从哪里加载和运行(CPU寄存器 + 程序计数器)



##### CPU上下文切换

先把前一个任务的CPU上下文（也就是CPU寄存器和程序计数器）保存起来，然后加载新任务的上下文到这些寄存器和程序计数器，最后再跳转到程序计数器所指的新位置，运行新任务。而这些保存下来的上下文，会存储在系统内核中，并在任务重新调度执行时再次加载进来，这样就能保证任务原来的状态不受影响，让任务看起来还是连续运行。



#### 1.2.2 线程

线程是操作系统能够进行运算、调度的最小单位，它被包含在进程中，是进程中的实际运作单位。进程和线程就是CPU工作时间段的描述，其区别就是颗粒度不一样。线程主要共享的是进程的地址空间。



##### 地址空间

在一个非常简单的操作系统中，仅仅有一个应用程序运行在内存中，为了运行第二个应用程序，需要把第一个应用程序移除才能把第二个应用程序装入内存。复杂一些的操作系统会允许多个应用程序同时装入内存中运行，为了防护应用程序之间相互干扰(包括操作系统)，需要有某种保护机制。

##### 虚拟内存

把部分地址空间留在内存，还有一部分留在磁盘内，在必要的时候对其进行交换，将两部分地址空间统称为虚拟内存

会产生的问题：进程直接访问物理地址会带来不可预估的风险；物理内存资源是宝贵的且非常有限；内存分配时，连续内存分配会产生很多难以分配的内存碎片

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-11 进程虚拟空间地址.png" style="zoom:80%;" />

#### 1.2.3 文件 

几乎所有操作系统都支持的另一个关键概念就是文件系统

操作系统的一项主要功能是屏蔽磁盘和其他I/O设备的细节特性，给程序员提供一个良好、清晰的独立于设备的抽象文件模型

目录和目录是可以互相套用的，进程树和目录树的区别在于进程树一般仅有3层，而目录树可以很深，且进程树保存时间很短

##### 特殊文件

提供特殊文件是为了使I/O设备看起来像文件一样

块特殊文件：由可随机存取的块组成的设备

字特殊文件：字符特殊文件用于打印机、调制解调器和其他接受或输出字符流的设备

##### 管道

是一种虚文件



#### 1.2.4 并发和并行

并行是指两个或者多个时间在同一时刻发生

并发是指两个或多个事件在同一时间间隔内发生

上述两个概念是趋势计算机不断进步的动力，即如何让计算机做更多的事情，以及如何让计算机运行的更快。从概念可知，并发可以让系统同时具有多个活动，并发可以让系统变得更快。



#### 1.2.5 系统调用 

操作系统提供两种功能：为用户提供应用程序抽象、管理计算机资源

只有系统调用能够进入内核态而过程调用则不能进入内核态



#### 1.2.6 操作系统结构

##### 单体结构

整个操作系统是以程序集合来编写的

优点：调用以任何一个所需要的程序都非常高效

缺点：上千个不受限制的彼此调用往往非常臃肿和笨拙；只要系统发生故障，任何系统和应用程序将不可用，这往往是灾难性的

需要有一个主程序，用来调用请求服务程序；一套服务过程，用来执行系统调用；一条服务程序，用来辅助服务过程调用。

##### 分层结构

每一层只与

##### 微内核

传统上，所有的层都在内核中，但不是必要的，尽可能的减少内核态中功能可能是更好的做法，只有一个模块——微内核——运行在内核态，其余模块可以作为普通用户进程运行。

##### 客户-服务器模式

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\1-12 客户-服务器模式.jpg" style="zoom:35%;" />



## Chapter 2 进程和线程

### 2.1 进程模型

#### 2.1.1 定义

进程是对正在运行中的程序的一个抽象

支持多进程的多道程序系统，严格意义上来说，在某一个瞬间CPU只能运行一个进程

伪并行：指单核或多核处理器同时执行多个进程，从而使程序更快。

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-1 程序计数器.jpg" style="zoom:20%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-2 四个程序计数器.jpg" style="zoom:25%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-3 进程与时间关系图.jpg" style="zoom:25%;" />

#### 2.1.2 进程的创建

1.系统的初始化（initial）
2.正在运行的程序执行了创建进程的系统调用
3.用户请求一个新进程
4.初始化一个批处理工作

##### 系统初始化

启动操作系统时，通常会创建若干个进程：前台进程、守护进程（一个大型的系统会有很多很多的守护进程）

##### 系统调用创建

处理在启动阶段创建进程之外，一些新的进程也可以在后面创建。通常，一个正在运行的进程会发出系统调用用来创建一个或多个进程来帮助其完成工作

##### 用户请求创建

输入一个命令或者双击图标就可以启动程序

##### 批处理创建

会在大型机的批处理系统中应用，用户在这种系统中提交批处理作业，当操作系统决定它有资源来运行另一个任务时，他将创建一个新进程并从其中的输入队列中运行下一个作业。



#### 2.1.3 进程的终止

正常退出(自愿的)

错误退出(自愿的)

严重错误(非自愿的)-->由程序引发的（如：数组越界等）

被其他进程杀死(非自愿的)



#### 2.1.4 进程的层次结构

Unix的进程体系就是一棵树的形式

Windows是所有的进程都是平等的(众生平等)，唯一类似于层次结构的是在创建进程的时候，父进程得到一个特别的令牌（称为句柄），该句柄可以用来控制子进程。



#### 2.1.5 进程的状态

尽管每个进程是一个独立的实体，有其自己的程序计数器和内部状态，但是进程之间仍需要相互帮助。

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-4 进程的状态.png" style="zoom:50%;" />

1：进程等待输入而阻塞，进程由运行态变为阻塞态

2：调度程序选择另一个进程比本身的进程先运行时，本身的进程会由运行态变成就绪态

3：调度程序选择进程运行，进程由就绪态变为运行态

4：出现有效的输入，进程就会由阻塞态变为就绪态



操作系统的本质(最底层)就是调度程序，调度程序之上就是一个个的进程



### 2.2 线程模型

Q：为什么要在进程的基础上再创建一个线程的概念？

A：多线程之间会共享同一块地址空间和所有可用数据的能力，这是进程所不具备的；线程要比进程更轻量级，它会更容易创建和撤销，也更容易去操作；如果多个线程都是CPU密集型的，那么并不能获得性能上的增强，但是如果存在着大量的计算和大量的I/O处理，拥有多个线程能在这些活动中彼此重叠进行，从而会加快应用程序的执行速度



#### 2.2.1 线程的使用

##### 多线程解决方案

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-5 Web服务器(线程).jpg" style="zoom:25%;" />

高速缓存对所有线程都开放

##### 状态机解决方案

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-6 状态机.png" style="zoom:67%;" />



#### 2.2.2 特性对比

单线程：无并行性，性能较差，阻塞系统调用

多线程：有并行性，阻塞系统调用

有限状态机：并行性，非阻塞系统调用、中断，状态机的编程会很困难



#### 2.2.3 经典的线程模型

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-7 经典的线程模型.jpg" style="zoom:25%;" />

线程和线程之间可以相互干扰



#### 2.2.4 线程的系统调用

单线程（通过某个库函数）->新的线程（Exit Join yield）->线程消失（类似于进程的创建和终止）

##### POSIX线程

为了使编写可移植线程程序称为可能，IEEE在IEEE标准1003.1c中定义了线程标准

在Linux中有pthreads.h这个包，常见调用与描述见下图

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-8 pthreads.h线程包.jpg" style="zoom:33%;" />



#### 2.2.5 线程实现

##### 在用户空间中实现线程



<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-9 用户空间的线程实现.jpg" style="zoom:25%;" />

##### 用户空间实现优势与弊端

优势：启动他们比进行内核调用效率更高。因而不需要切换到内核，也就不需要上下文切换，也不需要对内存高速缓存进行刷新，因为线程调度非常便捷，因此效率比较高；它允许每个进程有自己定制的调度算法

弊端：如何实现阻塞系统调用？不可能使用轮转调度的方式调度线程



##### 在内核空间中实现线程

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-10 内核空间的线程实现.jpg" style="zoom:25%;" />





##### 在用户和内核空间中混合实现线程

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-11 混合实现.jpg" style="zoom:25%;" />

多路复用技术(后面详细讲)



### 2.3 进程间通信

Q1：一个进程如何传递消息给其他进程

Q2：如何确保两个或多个线程之间不会相互干扰，例如，两个航空公司都试图为不同的顾客抢购飞机上的最后一个座位

Q3：数据的先后顺序问题，如果进程A产生数据并且进程B打印数据。则进程B打印数据之前需要先等A产生数据后才能够进行打印



#### 2.3.1 后台目录

一个后台打印程序，当一个进程需要打印某个文件时，它会将文件名放在一个特殊的后台目录(spooler directory)中。另一个进程打印后台进程(printer daemon)会定期的检查是否需要文件被打印，如果有的话，就打印并将改文件名从目录下删除。

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-12 后台目录.jpg" style="zoom:25%;" />

out变量代表指向下一个需要打印的文件，in变量代表指向下一个空闲的槽位



#### 2.3.2 竞态条件

两个或多个线程同时对一个共享数据进行修改，从而影响程序运行的正确性时，这种就被称为竞态条件(race condition)

Q：如何解决？

A：禁止一个或多个进程在同一时刻对共享资源（包括共享内存、共享文件等）进行读写，这种被称之为互斥。



#### 2.3.3 临界区

我们将这种对于共享内存进行访问的一个程序片断称为临界区，所以临界区并不是一个区域，而是一个程序片断或者说为解决问题的方法

临界区应满足以下条件：

1.任何时候两个进程不能同时处于临界区
2.不应对CPU的速度和数量做任何假设
3.位于临界区外的进程不得阻塞其他进程
4.不能使任何进程无限等待进入临界区

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-13 临界区.jpg" style="zoom:25%;" />

#### 2.3.4 忙等互斥

##### 屏蔽中断

在单处理器系统上，最简单的解决方案是让每个进程在进入临界区后立即屏蔽所有中断

Q：这个方案是否可行？进程进入临界区域是由谁决定的呢？不是用户进程吗？当进程进入临界区域后，用户进程关闭中断，如果经过一段较长时间后进程没有离开，那么中断不就一直启用不了，会导致整个系统的崩溃。所以在单处理器系统上使用要谨慎，在多处理器系统上它会单独的针对某一个核心。对内核来说，当它执行更新变量或列表的几条指令期间将中断屏蔽是很方便的。

##### 锁变量

寻找一种在软件层面解决方案，如果锁的值为0，进程设为1即可，锁为1的时候直接阻塞进程即可，加上锁变量就是为了空出时间

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-14 锁变量.jpg" style="zoom:30%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-15 锁变量的问题.jpg" style="zoom:25%;" />



##### 严格轮询法

```c
while(TRUE)
{
    while(turn == 0)	//turn的初始值是0，用于记录哪一个进程进入到了临界区
    {
		/* 进入关键区域 */
    	critical_region();
    	turn = 1;
    	/* 离开关键区域 */
    	noncritical_region();
    }
}
```

```c
while(TRUE)
{
    while(turn == 1)
    {
        critical_region();
        turn = 0;
        noncritical_region();
    }
}
```

对于上述不断检查的过程，称为忙等待，但是这种方法浪费CPU的时间，所以要避免使用忙等待的解决方案，只有认为忙等待所耗费的时间是较短的，才可以使用这个解决方案。用于忙等待的锁也被称为**自旋锁**。且其违反了临界区的第3条：位于临界区外的进程不得阻塞其他进程，所以这个方案也不是一个很好的解决方案



##### Peterson算法

```C
#define FALSE 0
#define TRUE 1
#define N 2 //进程数量

int turn;//现在轮到谁了
//在使用临界区之前，各个进程使用各自的进程号来作为参数调用，在需要时将进程等待，一直直到能够安全的进入临界区为止

//一开始初始化为FALSE
int interested[N];

//进程是0或者是1
void enter_region(int process)
{
    int other = 1 - process;//另一个进程号

    interested[process] = TRUE;
    turn = process;

    //空循环

    while (turn == process && interested[other] == TRUE)
    {
        //如果是1进入，且0未退出临界区，进程1就一直在此处空循环（被挂起）
    }
}

void leave_region(int process)
{
    interested[process] == FALSE;
}
```



##### TSL指令

需要硬件帮助的一种解决方案

测试并加锁：TSL RX,LOCK 执行TSL指令的CPU将会锁住内存总线，用来禁止其他CPU在这个指令结束之前访问内存

锁住内存总线和禁用中断不一样

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-16 TSL指令.jpg" style="zoom:40%;" />

附：Inter x86

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-17 Inter x86.jpg" style="zoom:50%;" />

上述解法都有可能产生忙等待，实际上就是浪费CPU的时间，且会有意想不到的情况出现



#### *2.3.5 优先级反转

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-18 优先级反转问题.png" style="zoom:60%;" />

在某一时刻，L已经处于临界区，但是H处于就绪态，H就会忙等待，L又不会被调度，操作系统认知得让H运行起来，同时会屏蔽其他所有的调度，L已经在临界区运行中，且L不会被调度。H就会永远变成死循环，L进程永远不会退出临界区（因为无法被调度），这种现象叫做优先级反转问题



#### *2.3.6 原语

计算机进程的控制通常由原语完成。一般是指由若干条指令组成的程序段，用来实现某个特定功能，在执行过程中不可被中断。



#### 2.3.7 睡眠与唤醒

忙等待的本质：先检查是否能够进入临界区，若不允许，则该进程将原地等待，直到允许为止；为了不允许他们进入关键区域之间会阻塞而不是浪费CPU的时间，最简单的是sleep和wakeup；sleep是一个能够造成调用者阻塞的系统调用，也就是说，这个系统调用会直到其他进程唤醒它；wakeup调用有一个参数，即将要唤醒进程。



#### 2.3.8 生产者-消费者问题

两个进程共享一个公共的固定大小的缓冲区。其中一个是生产者(producer)，将信息放入缓冲区，另一个是消费者(consumer)，会从缓冲区中取出；多个进程共享一个公共的固定大小的缓冲区。

```c
/*定义一个缓冲区 slot->槽的数量*/
#define N 100
/*监视变量 缓冲区的数据变量*/
int count = 0;
//只能监视一个进程，尝试睡眠的时候，如果检测到位1，则清除为0
//当wakeup信号发送给没有在睡眠的进程，等待位置为1
int wakeup_count = 0;//但这种方法治标不治本，没办法从根本上解决问题，迪杰斯特拉便想出了另一个更好的解决方案——信号量
/*
当缓冲区为空，刚好消费者读取count是0
暂停消费者，启用生产者
生产者放入一条数据 count增加
消费者在下一次启动之前还要查看count的值，在此之后生产者会将所有的数据都填满后进行睡眠，就会导致生产者和消费者都进入永久休眠状态
*/
/*生产者*/
void producer()
{
	int item;
	/*无限循环*/
	while (1)
	{
		item = prodece_item();
		if (count == N)
		{
			sleep();//数据满了，生产者就要休眠
		}
        insert_item(item);
		count = count + 1;
		if (count == 1)//看是否有数据
		{
			wakeup(consumer);//一旦有数据就唤醒消费者；这条指令会与count产生竞争关系
		}
	}
}

void consumer()
{
	int item;

	while (1)
	{
		if (count == 0)
		{
			sleep();//数据为空则消费者休眠
		}
        //从缓冲区取数据
		item = remove_item();
		count = count - 1;
		if (count == N - 1)//数据是否为满
		{
			wakeup(producer);//有空位就唤醒生产者
		}
	}
}
```

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-19-1 生产者-消费者模型过程1.png" style="zoom:67%;" /><img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-19-2 生产者-消费者模型过程2.png" style="zoom:67%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-19-3 生产者-消费者模型过程3.png" style="zoom:67%;" /><img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-19-4 生产者-消费者模型过程4.png" style="zoom:67%;" />

在wake up的过程中，count的值更新为0，此时消费者被唤醒去查看count更新后的值发现为0，继续休眠，而生产者会一直将整个缓冲区填满后休眠，形成永久休眠。产生上述情况的原因是：消费者和生产者是两个单独的进程，且数据是从寄存器中读取(也就是之前的值)，这样就会导致生产者使得消费者的wake up丢失，消费者无法被唤醒继续休眠，而生产者也会在缓冲区填满之后永久休眠

唤醒一个尚未睡眠的进程，唤醒信号就丢了-->解决方法：再增加一个变量(唤醒等待位)



#### 2.3.9 信号量

使用一个整型变量来累计唤醒次数，以供之后使用；一个信号量的取值可以是0，或是任意正数。0表示的不需要任何唤醒，其余任意正数表示的就是唤醒次数。

信号量有两个操作：Down(sleep)、Up(wakeup)

```c
/*定义一个缓冲区 slot->槽的数量*/
#define N 100
typedef int semaphore;//信号量：一种比较特殊的int类型

//控制关键区域访问
semaphore mutex = 1;//互斥信号量
//统计缓冲区中空槽的数量
semaphore empty = N;
//统计缓冲区中满槽的数量
semaphore full = 0;

/*监视变量 缓冲区的数据变量*/
int count = 0;

/*
当缓冲区为空，刚好消费者读取count是0
暂停消费者，启用生产者
生产者放入一条数据 count增加
消费者在下一次启动之前还要查看count的值，在此之后生产者会将所有的数据都填满后进行睡眠，就会导致生产者和消费者都进入永久休眠状态
*/

//down会先检查是否大于0，如果>0就进行-1，如果是0就休眠
//此时down操作会继续执行

//up操作会使得信号量+1

//检查信号量 更新 必要时进行进程的休眠，如果是多个处理器则需要对信号量加锁
//防止多个进程对一个信号量访问，应该使用TSL互斥

/*生产者*/
void producer()
{
	int item;
	/*无限循环*/
	while (1)
	{
		item = prodece_item();
		//空槽数量-1
		down(&empty);
		/*进入关键区域*/
		down(&mutex);
		//数据放入到缓冲区中
		insert_item(item);
		/*离开关键区域*/
		up(&mutex);
		/*将缓冲区满槽的数量+1*/
		up(&full);


		if (count == N)
		{
			sleep();//数据满了，生产者就要休眠
		}
		insert_item(item);
		count = count + 1;
		if (count == 1)//看是否有数据
		{
			wakeup(consumer);//一旦有数据就唤醒消费者；这条指令会与count产生竞争关系
		}
	}
}

void consumer()
{
	int item;

	while (1)
	{
		/*缓冲区满槽-1*/
		down(&full);
		/*进入关键区域*/
		down(&mutex);
		//缓冲区取出数据
		remove_item(item);
		/*离开关键区域*/
		up(&mutex);
		/*将缓冲区空槽的数量+1*/
		up(&mutex);
		//从缓冲区取数据
		item = remove_item();
		count = count - 1;
		if (count == N - 1)//数据是否为满
		{
			wakeup(producer);//有空位就唤醒生产者
		}
	}
}
```

对于一个中断而言
1、硬件压入堆栈程序计数器等等
2、从中断向量装入新的程序计数器
3、保存寄存器的值
4、设置新的堆栈
5、中断服务期运行
6、调度器来决定哪个程序先执行
7、返回到汇编代码
8、汇编语言开始执行新的程序

synchronization也是信号量，只是用于同步



#### 2.3.10 互斥量

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-20 互斥量.jpg" style="zoom:40%;" />

FUTEXES（快速用户空间互斥）：同步(synchronization) + 互斥(locking) ====> Futex

由两部分组成：内核服务 + 用户库，在用户空间之中，这些进程共享一个锁变量，同时避免自旋现象

##### Pthread互斥量

|       线程调用        |          描述          |
| :-------------------: | :--------------------: |
|  Pthread_mutex_init   |     创建一个互斥量     |
| Pthread_mutex_destroy | 撤销一个已存在的互斥量 |
|  Pthread_mutex_lock   |    获得一个锁或阻塞    |
| Pthread_mutex_trylock |    获得一个锁或失败    |
| Pthread_mutex_unlock  |       释放一个锁       |

##### 条件变量

1、一个线程将东西放入缓冲区，另一个线程取出，如果生产者发现缓冲区没有空槽位，生产者阻塞直到有空槽位可以使用；使用mutex主要是为了不受其p他的线程干扰，当发现满了以后，需要一种方法来阻塞自己并且在以后要被唤醒

|        线程调用        |              描述              |
| :--------------------: | :----------------------------: |
|   Pthread_cond_init    |        创建一个条件变量        |
|  Pthread_cond_destroy  |        销毁一个条件变量        |
|   Pthread_cond_wait    |       阻塞以等待一个信号       |
|  Pthread_cond_signal   |    向另一个线程番号来唤醒它    |
| Pthread_cond_broadcast | 向多个线程发信号让它们全部唤醒 |

##### 互斥量和条件变量同时使用的生产者-消费者模型

```c
#include <stdio.h>
#include <pthread.h>
//互斥量和条件变量
/*需要生产的数量*/
#define MAX 10000000

pthread_mutex_t the_mutex;
//使用信号量
pthread_cond_t condc, condp;

int buffer = 0;

/*生产数据*/
void producer(void* ptr)
{
	for (int i = 0; i <= MAX; i++)
	{
		//临界区需要独占，使用mutex获取锁
		pthread_mutex_lock(&the_mutex);
		while (buffer != 0)
		{
			pthread_cond_wait(&condp, &the_mutex);
		}
		//把他们放在缓冲区中
		buffer = i;
		/*唤醒消费者*/
		pthread_cont_signal(&condc);
		//释放缓冲区
		pthread_mutex_unlock(&the_mutex);
	}
	pthread_exit(0);
}

/*消费数据*/
void producer(void* ptr)
{
	for (int i = 0; i <= MAX; i++)
	{
		//临界区需要独占，使用mutex获取锁
		pthread_mutex_lock(&the_mutex);
		while (buffer == 0)
		{
			pthread_cond_wait(&condc, &the_mutex);
		}
		//把他们放在缓冲区中
		buffer = i;
		/*唤醒生产者*/
		pthread_cont_signal(&condp);
		//释放缓冲区
		pthread_mutex_unlock(&the_mutex);
	}
	pthread_exit(0);
}
```



#### 2.3.11 管程

管程是程序、变量和数据结构等组成的一个集合，它们组成一个特殊的模块或者是包；是一种编程语言的概念

管程有一个很重要的特性，即在任何时候管程中只能有一个活跃的进程，这一特性使管程能够很方便的实现互斥操作

```Java
public class ProducerConsumer
{
    static final int N = 100;//定义缓冲区数组长度
    //初始化一个生产者代码
    static Producer p = new Producer();
    static consumer c = new consumer();
    static Our_monitor mon = new Our_monitor();


    //生产者代码  run里面包含了各种线程需要执行的代码
    static class Producer extends Thread
    {
        @Override
        public void run()
        {
            int item;
            //生产者循环
            while (true)
            {
                item = produce_item();
                mon.insert(item);
            }
        }
        //生产的代码
        private int produce_item()
        {
            //......此处为代码程序
        }
    }

    //消费者代码  run里面包含了各种线程需要执行的代码
    static class consumer extends Thread
    {
        @Override
        public void run()
        {
            int item;
            while (true)
            {
                item = mon.remove();
                //继续运行消费者代码
                consumer_item();
            }
        }
        //消费的代码
        private int consumer_item()
        {
            //......此处为代码程序
        }
    }

    //这是管程
    static class Our_monitor
    {
        private int buffer[] = new int[N];
        //计数器和索引
        private int count = 0,lo = 0,hi = 0;

        private synchronized void insert(int val)
        {
            if (count == N)
            {
                //如果缓冲区满，进入休眠
                go_to_sleep();
            }
            //向缓冲区插入数据
            buffer[hi] = val;
            hi = (hi + 1) % N;
            count = count + 1;
            if (count == 1)
            {
                notify();
            }
        }

        private synchronized int remove()
        {
            int val;

            if (count == 0)
            {
                go_to_sleep();
            }
            //从缓冲区取数据
            val = buffer[lo];
            lo = (lo + 1) % N;
            count = count - 1;
            if (count == N - 1)
            {
                notify();
            }
            return val;
        }


        private void go_to_sleep()
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}
```

通过临界区自动的互斥，管程会比临界区更容易保证并行编程的正确性，这个互斥是编译器给的，它给某种互斥做出了保证，但这是Java支持同步、管程才能使用

如果在分布式系统之中，多个CPU有自己的私有内存，他们之间通过网络相连，此时信号量不管用了；而管程只有少数的编程语言能够使用



#### 2.3.12 消息传递

send(destination, &message);

receive(source, &message);

##### 消息传递的设计要点

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-21 消息传递的设计要点.jpg" style="zoom:35%;" />

接收方不知道发送方第二次发送的消息是新的消息还是之前发送给的消息，这也是操作系统中需要思考的问题

如何给这些进程命名，也就是身份验证的问题

消息传递的本质是网络(详见《Computer Networking》)

```c
//定义buffer中槽的数量
#define N 100

//假设所有的消息都有相同的大小，并且还没有有接受到发出的消息的时候，操作系统自动进行缓冲

void producer()
{
	int item;
	message message;//消息的内容，不局限于字符串也有可能是其他类型

	while (1)
	{
		item = produce_item();//生产者将生成即将放入缓冲区的数据
		//等待消费者来发送空的缓冲区
		receive(consumer, &message);
		//建立一个待发送的消息
		build_message(&message, item);
		/*发送给消费者*/
		send(consumer, &message);
	}
}

void consumer()
{
	int item;
	message message;//消息的内容，不局限于字符串也有可能是其他类型
	for (int i = 0; i < N; i++)
	{
		//发送N个缓冲区
		send(producer, *message);
	}
	while (1)
	{
		//接受包含数据的消息
		receive(producer, &message);
		//将数据从消息系统中提取出来
		item = extract_item(&message);
		//再把空的缓冲区发送给消费者
		send(producer, &message);
		//对数据进行处理
		//......
	}
}
```

信箱：对于一定的数据进行缓冲，是一种数据结构，类似于缓存的作用，更加的保证了数据的同步，是一种间接通信方式



#### 2.3.13 屏障

屏障适用于进程组，是一组进程的同步；某些应用中划分了若干阶段，并且规定，除非所有的进程都就绪准备着手下一个阶段，否则任何进程都不能进入下一个阶段

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-22 屏障.jpg" style="zoom:33%;" />

```c
//互斥量、自旋锁是用来保护临界区的
//屏障类似于条件变量，是用来做协同的
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <WinBase.h>
#include <pthread.h>
#pragma comment(lib,"pthreadVC2.lib")

/*设置屏障总数*/
#define PTHREAD_BARRIER_SIZE 4
//定义一个屏障
pthread_barrier_t barrier;

void err_exit(const char* err_msg)
{
	printf("error:%s\n", err_msg);
	exit(1);
}

void* thread_fun(void* arg)
{
	int result;
	char* thr_name = (char*)arg;
	printf("线程%s工作完成了......\n", thr_name);
	/*等待屏障*/
	result = pthread_barrier_wait(&barrier);
	if (result == PTHREAD_BARRIER_SERIAL_THREAD)//代表返回成功
	{
		printf("线程%s，wait后第一个返回\n", thr_name);
	}
	else if (result == 0)
	{
		printf("线程%s，返回后为0", thr_name);
	}
	return NULL;
}

int main()
{
	pthread_t tid_1, tid_2, tid_3;
	int result;
	pthread_barrier_init(&barrier, NULL, PTHREAD_BARRIER_SIZE);

	if (pthread_create(&tid_1, NULL, thread_fun, "1") != 0)
	{
		err_exit("Creat thread 1\n");
	}
	if (pthread_create(&tid_2, NULL, thread_fun, "1") != 0)
	{
		err_exit("Creat thread 2\n");
	}
	if (pthread_create(&tid_3, NULL, thread_fun, "1") != 0)
	{
		err_exit("Creat thread 3\n");
	}
	//主线程等待工作完成
	result = pthread_barrier_wait(&barrier);
	printf("所有的工作已完成...\n");
	if (result == PTHREAD_BARRIER_SERIAL_THREAD)//代表返回成功
	{
		printf("主线程wait后第一个返回\n");
	}
	else if (result == 0)
	{
		printf("主线程wait返回后为0");
	}
	Sleep(1);
	return NULL;
}
```



#### 2.3.14 避免锁

（无招胜有招）其应用场景是比较特殊的，它也是一种数据结构，可以去书写的一种方案 (貌似是RCU算法？)

在某些情况下，我们可以允许写操作来更新数据结构，即便还有其他的进程正在使用；确保每个读操作要么读取旧的版本，要么获取读的新版本，但是对于写操作来说就是必须要锁

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-23 避免锁的添加.jpg" style="zoom:33%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-24 避免锁的删除.jpg" style="zoom:33%;" />

对于移除节点操作需要注意B、D的释放必须要十分谨慎



### 2.4 进程调度

#### 2.4.1 调度

当一个计算机是多道程序设计系统时，会频繁的有很多进程或者线程来同时竞争CPU时间片

当两个或两个以上的进程/线程处于就绪态时，就会发生这种情况。如果只有一个CPU可用，那么必须选择接下来那个进程/线程可以运行

操作系统中有一个叫做调度程序(scheduler)的角色存在，它就是做这事儿的，该程序使用的算法叫做调度算法(scheduling algorithm)

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-25 调用.jpg" style="zoom:25%;" />

上图中a代表的是CPU密集型，b代表的是I/O密集型

#### 2.4.2 计算机上执行任务的两种策略

##### CPU密集型

一般是指服务器的硬盘、内存硬件性能相对CPU好很多，或者使用率低很多。系统运行CPU读写I/O(硬盘/内存)是可以在很短的时间内完成，几乎没有阻塞（等待I/O的实时间）时间，而CPU一直有大量的运算需要处理。因此CPU负载长期过高。

适合多进程，不适合线程，也叫计算密集型，这种情况更希望自己的硬盘比CPU更好，使得I/O阻塞更少；适合在多核的CPU中使用

##### I/O密集型

一般是指服务器CPU的性能相对于硬盘、内存硬件好很多，或者使用率低很多。系统运行多是CPU在等I/O（银盘/内存）的读写操作，此类场景下CPU负载并不高

与CPU密集型相反，适用于多线程，一般来说CPU的时间较短，有大量的I/O操作，；随着CPU越来越快，会倾向于I/O密集型



##### Q：何时调度？

- 第一个和调度有关的问题是何时进行调度决策。存在着需要调度处理的各种情形。首先，在创建一个新的进程后，需要决定是运行父进程还是子进程

- 第二，在进程退出时需要做出调度决定。因为此进程不再运行（它将不再存在），因此必须从就绪进程中选择其他程序运行

- 第三，当进程阻塞在I/O、信号量或其他原因时，必须选择另外一个进程来运行

- 第四，当I/O中断发生时，可以做出调度决策

  

#### 2.4.3 调度算法的分类

根据如何处理时钟中断可以把调度算法分为两类

##### 非抢占式

挑选一个进程，让该进程运行知道被阻塞（阻塞在I/O上或等待另一个进程），或者知道该进程自动释放CPU

##### 抢占式

选择一个进程，并使其在最大固定时间内运行。如果在时间间隔结束后仍在运行，这个进程就会被挂起，调度程序会选择其他进程来运行（前提是存在就绪进程）



#### 2.4.4 调度系统的环境

批处理、交互式、实时



#### 2.4.5 调度算法的目标 

对于所有系统：公平、策略强制执行、平衡

对于批处理系统：吞吐量、周转时间（也是平均时间）、CPU利用率(非重要的指标，但有一定的参考)

对于交互式系统：响应时间（能够让交互式首先运行就是一个好的服务）、均衡性

对于实时系统：满足截止时间、可预测性



#### 2.4.6 批处理中的调度

##### 先来先服务（FCFS）

一个链表记录了所有的进程，按照队列的模式进行调度，当一个进程被调整为阻塞状态时，将这个进程放置一旁，从队列中拿出另一个进程继续作业；若阻塞的进程恢复到就绪态，则将其重新入队，继续排队。优点：易于了解；缺点：无法确定优先级

##### 最短作业优先

一家保险公司，因为每天要做类似的工作，所以人们可以相当精确地预测处理1000个索赔的一批作业需要多长时间。

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-26 最短作业优先.jpg" style="zoom:33%;" />

如上图，有四个作业ABCD，其上方的数字代表利用CPU的时间

那么a的周转时间(平均时间)就应该是(8+12+16+20)/4 = 14

b的周转时间就应该是(4+8+12+20)/4 = 11

但最短作业优先不太允许排队中的进程出现阻塞状态的情况



##### 最短剩余时间优先

是最短作业优先的抢占版本

当一个新的作业进入，需要将这个新作业所需的时间与当前进程里所有的作业进行比较，如果新作业的时间比进程里所有的作业用时都短，就把当前作业直接挂起，运行新作业



#### 2.4.7 交互式系统中的调度

##### 轮询调度

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-27 轮询.jpg" style="zoom:33%;" />

在Linux在，将进程间的切换定在了20~50ms，具体的要根据具体的操作系统来看，轮询调度的前提是所有的进程都是平等的（无优先级），但事实很明显不是这样的。



##### 优先级调度

为每一个进程都赋予一个优先级，优先级高的进程优先运行，运行优先级最低的就是空闲进程（PID：1），调度程序会在每个时钟中断期间降低当前运行进程的优先级。

优先级可以通过动态分配或者是静态分配

静态分配：在一开始就把所有的优先级设定好了；自愿降级：为了照顾某一种场景，允许降低自己的优先级，其指令名为nice

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-28 优先级.jpg" style="zoom:33%;" />

如果优先级固定了以后（如上图）优先级最低的（优先级1）会出现永远无法运行的情况，这种现象被称为饥饿现象，所以要对优先级进行一系列调整



##### 多级队列

该算法将系统中的进程就绪队列从一个拆分为若干个，将不同类型或性质的进程固定分配在不同的就绪队列，不同的就绪队列采用不同的调度算法，一个就绪队列中的进程可以设置不同的优先级，不同的就绪队列本身也可以设置不同的优先级。



##### 最短进程优先

交互时间长通常遵循下列模式：等待命令、执行命令、等待命令、执行命令

如果我们把每个命令的执行都看做一个分离的作业，那么我们可以通过首先运行最短的作业来使响应时间最短。

Q：如何从当前可运行进程中找出最短的一个进程？

A：预测：假设每个终端的每条命令是$T_0$，测量到的下一条命令所需的时间为$T_1$，用$aT_0+(1-a)T_1$的加权算法，随着更多指令的加入（这里假设$a=\frac{1}{2}$），前面的所需时间占比会越来越小，其思想类似于降级，在第二轮评估后$T1$的占比为$\frac14$，第三轮评估后$T1$的占比仅为$\frac18$。

Q：P1-P5使用轮询(时间片为7)，P6-P10使用最短进程优先调度，且轮询的优先级大于最短进程优先调度的优先级

![](E:\Typora\Typora Note\Computer\Operation System\Picture\2-29 example.png)

第一类先按照等待时间的长短排序 -> 第一类的时间片开始轮转（若时间片内未能结束，则需要循环处理，直到处理完成） -> 第二类 短进程优先 -> 结束队列



##### 保证调度

- 若用户工作时有$n$个用户登录，则每个用户将会获得CPU处理能力的$\frac1n$

##### 彩票调度

- 为进程提供各种系统资源（例如CPU时间）的彩票。当做出一个调度决策的时候，就随机抽出一张彩票，拥有彩票的进程将获得该资源。
- 具有随机性，不符合稳定的原则，但是可以解决饥饿问题，但是对优先级不好进行操作。应用场景苛刻，对于票数不好分配，对I/O密集型不友好。

##### 公平分享算法

上述调度均是针对于进程的思考，而公平分享调度是针对于持有进程的用户来进行分配的。例如：用户A持有15个进程，用户B持有10个进程，用户C持有8个进程，用户D持有1个进程，此时，每个用户对CPU持有时间都占$1/4$



#### 2.4.8 实时系统中的调度

- 在实时系统中，正确但是响应缓慢比没有响应还要糟糕。
- 大概分为两类：硬实时(hard real time)和软实时(soft real time)系统
- 硬实时：必须要满足绝对的截止时间。
- 软实时：不希望错过截止时间，但可以容忍。
- 在实时系统中，每个进程的行为都必须是可以预测的，而且这些进程较短，且完成速度较快

##### 实时系统中的事件分类

- 周期性（以规则的时间间隔发生）事件
- 非周期性（发生时间不可预知）事件
- 实时系统的调度算法可以是动态的或静态的

$\sum_{i=1}^m\frac{C_i}{P_i}\leq1$：如果它有m个周期性的事件，事件$i$以周期$P_i$，$C_i$为所占时长，如果所有的$C_i$之和≤$P_i$，就可以进行调度

#### 2.4.9 调度策略和机制

- 假设系统中所有进程属于不同的分组用户并且进程间存在相互竞争CPU的情况
- 有时也会发生一个进程会有很多子进程并在其控制下运行的情况

策略和机制一般分离，所有的调度都属于一套机制，但是具体如何做由用户或者调度策略实现。 



### 2.5 线程调度

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-30 用户级线程调度.png" style="zoom:50%;" />

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\2-31 内核级线程调度.png" style="zoom:50%;" />

用户级线程和内核级线程主要的区别就在于性能，用户级切换线程只需要少量的机器指令，但是内核级切换线程就需要完成一个完整的上下文。



## 面试part（unfinished）

1、什么是线程、进程？
2、进程和程序的关系？他们之间又有什么关系？
3、如何创建进程？进程如何终止？如何管理进程？
4、中断



## Chapter 3 内存管理

为什么需要内存管理？

不管存储器有多大，程序大小的增长速度比内存容量的增长速度要快得多

### 3.1 无存储器抽象

- 无存储器抽象是最简单的存储器抽象。
- 早期的大型机、小型机、个人计算机都是直接操控内存
- 不可能会有两个应用程序同时在内存中

<img src="E:\Typora\Typora Note\Computer\Operation System\Picture\3-1 无存储器抽象.png" style="zoom:33%;" />

上图a为大型机，b位小型机，c为个人计算机。
划分了一个内存区，有4位的状态码，被称之为保护键，且保护键只能由操作系统去访问。但这种方式也有很严重的缺陷。

#### 实现并行性

- 在没有存储器抽象的系统中实现并行性的一种方式是使用多线程来编程。
- 人们通常希望能够在同一时间内运行没有关联的程序，而这正是线程抽象所不能提供的。
- 把当前内存中所有内容保存到磁盘文件中，然后再把程序读入内存即可。

<img src="C:\Users\34574\Documents\Tencent Files\3457455583\nt_qq\nt_data\Pic\2024-07\Ori\5034d72196f339ce7a7557fa86522b7f.png" alt="5034d72196f339ce7a7557fa86522b7f" style="zoom:33%;" />

实际装载的程序和单个程序不一样，b的`JMP`指令在连续装载后位置已经失效，这个时候需要再原有位置的基础上+16348才能达到最初的效果，这种操作叫做静态重定位。但也有很大的问题，会导致装载速度变慢以及很多重定位时的一些数据。

#### 物理内存暴露的缺点

- 如果用户程序可以寻址内存的每个字节，它们就可以很容易的破坏操作系统
- 想要运行多个程序是很困难的
- 如果想要使多个应用程序同时运行在内存中，必须要解决两个问题：保护和重定位。



### 3.2 地址空间

- 进程可以用来寻址内存的地址集
- 每个进程都有它自己的地址空间，独立于其他进程的地址空间。
- 最简单的办法是使用动态重定位（dynamic relocation）技术，它就是通过一种简单的方式将每个进程的地址空间映射到物理内存的不同区域。
- 基址寄存器和变址寄存器
