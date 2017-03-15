## Install LongStart

Build p4ofagent with repo "switch" and "bmv2". 

### install bmv2(i.e.behavioral-model)

```
./autogen.sh

./configure --with-pdfixed # p4ofagent requires the PD library

make

[sudo] make install  # if you need to install bmv2

sudo ldconfig # refresh the shared library cache
```

### install p4ofagent

```
git submodule update --init --recursive

./autogen.sh

./configure CPPFLAGS=-D_BMV2_

make p4ofagent

make install
```

### install switch

```
git submodule update --init --recursive

./autogen.sh

./configure --with-bmv2 --with-switchsai --with-of

make
```

### install docker

基于你的平台选择对应的docker版本：http://www.7zhang.com/index/cms/read/id/222788.html

Ubuntu 14.04 支持CE和EE。

#### Docker EE customers

To install Docker Enterprise Edition (Docker EE), you need to know the Docker EE repository URL associated with your trial or subscription. To get this information:

    Go to https://store.docker.com/?overlay=subscriptions.
    Choose Get Details / Setup Instructions within the Docker Enterprise Edition for Ubuntu section.
    Copy the URL from the field labeled Copy and paste this URL to download your Edition.

Where the installation instructions differ for Docker EE and Docker CE, use this URL when you see the placeholder text <DOCKER-EE-URL>.

To learn more about Docker EE, see Docker Enterprise Edition.

[Install Docker on Ubuntu](https://docs.docker.com/engine/installation/linux/ubuntu/#install-using-the-repository)

#### Dependencies

```
$ sudo apt-get update

$ sudo apt-get install \
    linux-image-extra-$(uname -r) \
    linux-image-extra-virtual
```

#### Docker CE:

```
$ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common

$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

# Verify that the key fingerprint is 9DC8 5822 9FC7 DD38 854A E2D8 8D81 803C 0EBF CD88.

$ sudo apt-key fingerprint 0EBFCD88

$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
```

#### Docker EE:

```
$ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common

$ curl -fsSL <DOCKER-EE-URL>/gpg | sudo apt-key add -

# Verify that the key fingerprint is DD91 1E99 5A64 A202 E859 07D6 BC14 F10B 6D08 5F96.

$ apt-key fingerprint 0EBFCD88

$ sudo add-apt-repository \
   "deb [arch=amd64] <-DOCKER-EE-URL> \ # replace the directory
   $(lsb_release -cs) \
   stable-17.03"
```

#### Install Docker

```
sudo apt-get update
```

Docker CE:

```
sudo apt-get install docker-ce
```

Docker EE:

```
sudo apt-get install docker-ee
```

choose a version of docker instead of using the latest one:

```
Docker CE: 	sudo apt-get install docker-ce=<VERSION>
Docker EE: 	sudo apt-get install docker-ee=<VERSION>
```

Verify(I installed the Docker CE):

```
docker version

Client:
 Version:      17.03.0-ce
 API version:  1.26
 Go version:   go1.7.5
 Git commit:   3a232c8
 Built:        Tue Feb 28 07:57:58 2017
 OS/Arch:      linux/amd64

Server:
 Version:      17.03.0-ce
 API version:  1.26 (minimum version 1.12)
 Go version:   go1.7.5
 Git commit:   3a232c8
 Built:        Tue Feb 28 07:57:58 2017
 OS/Arch:      linux/amd64
 Experimental: false
```

```
sudo docker run hello-world
```

Exception:

```
docker: Error response from daemon: Get https://...
```

=> [solution](https://github.com/docker/docker/issues/24344)

This is almost always a local access or firewall issue. In the original case it was a local DNS server that wasn't responding. I would recommend changing to a more reliable DNS upstream such as Google (8.8.8.8 and 8.8.4.4).

```
Unable to find image 'hello-world:latest' locally
latest: Pulling from library/hello-world
78445dd45222: Pull complete 
Digest: sha256:c5515758d4c5e1e838e9cd307f6c6a0d620b5e07e6f927b07d05f6d12a1ac8d7
Status: Downloaded newer image for hello-world:latest

Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://cloud.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/engine/userguide/
```

### install docker image

```
cd switch/docker/bmv2
make -f docker.mk base-docker-image
```

after an hour:

```
sudo docker images

REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
p4dockerswitch      latest              65cd67731738        About a minute ago   1.46 GB
ubuntu              14.04               7c09e61e9035        2 weeks ago          188 MB
hello-world         latest              48b5124b2768        2 months ago         1.84 kB
```

## Connect the P4 switch with Ryu

First, start the ryu:

```
cd ryu
ryu-manager ryu/app/simple_switch_13
```

Hint: if occured "pkg_resources.DistributionNotFound: The 'xxx' distribution was not found and is required by ryu", please run `pip install xxx` to solve it.

Then run p4switch using the script "openflow_l2.py":

```
cd switch/docker
./openflow_l2.py
```

