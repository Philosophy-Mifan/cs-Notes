## Part 1 云服务器

如果仅仅只应对一般的博客内容，云服务器的配置为入门级即可（1核CPU、1GB内存、20GB SSD云盘、1-3Mbps带宽）

入门级服务器包括：共享型实例和突发性能实例

### 1.1 共享型实例

多个用户共享同一台物理服务器的计算资源，性能可能会受到其他用户的影响，如果其他用户占用了大量的计算资源，就可能就会影响到自己实例的性能。

### 1.2 突发性能实例

采用CPU积分制，它有一个基准性能，当实例的负载低于基准性能时，会积累CPU积分，当负载高于基准性能时，会消耗CPU积分，如果所有积分用完，会强制降频至基准水平。（偶尔高性能）



1、在服务器中安装必要的一些系统工具（Ubuntu）

```
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg
```

2、信任Docker的GPG公钥

```
sudo install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://mirrors.aliyun.com/docker-ce/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings.docker.gpg
sudo chmod a+r /etc/apt/keyrings.docker.gpg
```

 3、写入软件源信息

```
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://mirrors.aliyun.com/docker-ce/linux/ubuntu \
  "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | \
  sudo tee /etc/apt/source.list.d/docker.list > /dev/null
```

4、安装Docker

```
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

用`sudo docker -v`查看验证docker版本

5、安装Halo

`docker run -it -d --name halo -p 80:8090 -v ~/.hola2:/root/.hola2 -e JVM_OPTS="-Xmx256m -Xms256m" registry.fit2cloud.com/halo/halo:2.20`



Part 2 域名注册和解析



