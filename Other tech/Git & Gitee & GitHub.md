## Part I Git的使用

### 概念

- 仓库(Repository)：是Git存储和管理文件的地方，保存了所有的文件、版本记录和历史信息分为本地仓库和远程仓库。
  - 本地仓库：存储着本地对于项目的所有文件和修改历史，每当提交代码时，就会将文件保存到本地仓库中。
  - 远程仓库：存放在服务器上的仓库，通常用于团队合作中的代码共享和同步(Gitee、Github)
- 工作目录：当前正在编辑的文件所在的地方，对文件进行的修改都发生在工作目录中，当文件被修改后，修改只会体现在工作目录中，Git不会立即追踪这些修改，直到你将它们添加到暂存区(Staging Area)并提交(commit)。
- 暂存区：用来记录准备提交的文件修改，当在工作目录中修改文件后，需要通过git add命令将修改添加到暂存区，之后再通过git commit命令提交修改，暂存区的内容就会被保存到本地仓库
- master(main)：默认的主分支
- 分支(branch)：
- head：当前所处的位置，是一个指向你正在工作的分支的最新提交



- git commit:
  - id:采用摘要算法计算出不重复的40位字符，本地指令中可以只用前六位，可通过id找到曾经的任何内容和变动
  - 描述:针对本次提交的描述说明，等同于注释
  - 快照:完整的版本信息，以对象树的结构存在仓库下.git\objects目录里

### 关于版本控制

- 版本控制是一种记录一个或若干文件内容变化，以便将来查阅特定版本修订情况的系统。
- 版本控制系统（VCS）带来的好处

1. 可以将选定的文件回溯到之前的状态，甚至将整个项目都回退到过去某个时间点的状态；
2. 可以比较文件的变化细节，查出最后是谁修改了哪个地方，从而找出导致问题的原因；
3. 就算你把整个项目中的文件改的改删的删，你也照样可以轻松恢复到原先的样子。

- 版本控制系统分类

1. 本地版本控制系统（如:RCS)
2. 集中化的版本控制系统（如:CVS、Subversion）
3. 分布式版本控制系统（如:Git、Mercurial、Bazaar）

### Git的文件状态

- Git有三种状态

1. 已修改（modified）表示修改了文件，但还没保存到数据库中。
2. 已暂存（staged）表示对一个已修改文件的当前版本做了标记，使之包含在下次提交的快照中。
3. 已提交（committed）表示数据已经安全地保存在本地数据库中。

- Git项目拥有三个阶段：工作区、暂存区以及Git目录

1. 工作区是对项目的某个版本独立提取出来的内容。
2. 暂存区是一个文件，保存了下次将要提交的文件列表信息。
3. Git目录是Git用来保存项目的元数据和对象数据库的地方。

- 基本的Git工作流程如下：

1. 在工作区中修改文件。
2. 将你想要提交的更改选择性地暂存，这样只会将更改的部分添加到暂存区。
3. 提交更新，找到暂存区的文件，将快照永久性存储到Git目录。

### Git常用命令——本地操作

1. git init:初始化工作目录
2. git add:添加文件，如git add *.txt git status:跟踪文件状态
3. git rm:从版本库移除文件
4. git mv:移动文件
5. git commit:提交文件，如git commit -m日志信息
6. git log:查看提交日志
7. git reset:取消暂存的文件
8. git checkout:撤消对文件的修改



### Git常用命令——远程操作

1. git remote [-v]:查看你已经配置的远程仓库服务器 
2. git remote add <sname><url>:添加远程仓库
3. git remote rename <oname> <nname>:远程仓库重命名
4. git remote remove <sname>:移除远程仓库
5. git remote show <sname>:查看某个远程仓库
6. git fetch<sname>:从远程仓库中抓取,不影响工作目录
7. git pull <sname><branch>:从远程仓库中拉取到工作目录  --allow-unrelated-histories:
8. git push <sname><branch>:推送到远程仓库
9. git clone <url>:克隆项目

### Git标签

- 使用标签功能来标记发布结点（(v1.0 、v2.0）：git tag

- 标签分类

1. 轻量标签（lightweight）:本质上是将提交校验和存储到一个文件中，没有保存任何其他信息：git tag<标签名>

2. 附注标签（annotated）:是存储在Git数据库中的一个完整对象，它们是可以被校验的。

   ​	git tag -a<标签名>-m<附注描述信息>·共享标签

- 默认情况下，git push命令并不会传送标签到远程仓库服务器上。
- 推送一个标签:git push origin<标签名称>
- 推送所有标签:git push origin --tags

### Git分支概念

- 使用分支意味着你可以把你的工作从开发主线上分离开来，以免影响开发主线。
- 在很多版本控制系统中，完全创建一个源代码目录的副本。
- Git处理分支的方式可谓是难以置信的轻量，创建新分支几乎能在瞬间完成，并且在不同分支之间的切换操作也是一样便捷。
- Git鼓励在工作流程中频繁地使用分支与合并，哪怕一天之内进行许多次。
- Git的默认分支名字是master。在多次提交操作之后，你其实已经有一个指向最后那个提交对象的master分支。

### Git分支命令

创建分支：git branch <name>
Q：Git怎么知道当前在哪一个分支上呢？
A：它有一个名为HEAD的特殊指针，指向当前所在的本地分支
使用git log命令查看各个分支当前所指的对象：git log --oneline --decorate
分支切换：git checkout <name>
分支提交
分支切换回master
可以使用b参数创建并切换分支：git checkout -b <name>
创建并切换问题分支(git checkout -b iss53)
修复过程提交(git commit -m message)
首先切换到合并分支，如主分支：git checkout master
执行分支合并命令：git merge <name>

- 合并冲突解决

1. git status：查看冲突·冲突文件内容
2. git mergetool：启用冲突解决工具

- Git分支管理

​	git branch -v：查看每一个分支的最后一次提交
​	git branch --merged：查看已合并的分支
​	git branch --no-merged：查看未合并的分支
​	git branch -d <name>：删除分支
如果未合并的分支将会删除失败可以使用-D选项来强制删除
执行分支合并命令：git merge <name> 

版本库目录规范
根目录结构
documents:项目相关文档文件夹·
projects:项目代码文件夹
README.md:自读文件
README.en.md:自读文件（英文)·模板参考链接：https://gitee.com/zero-awei/hello-gitee.git

- 编码规范

阿里巴巴Java开发手册
Google开源项目风格指南
编码检查工具

- Java开发规约IDE插件
  使用帮助：https://github.com/alibaba/p3c
   Cpplint
   使用帮助:
   https://github.com/zh-google-styleguide/zh-google-styleguide
   https://cloud.tencent.com/developer/article/1494003

### Git的使用

1.在Gitee或GitHub上面新建仓库
2.初始化仓库
