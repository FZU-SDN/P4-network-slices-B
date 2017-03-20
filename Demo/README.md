## Demo 

```
    +------------------+
    |                  |
    |    Controller    |--------+
    |                  |        |
    +------------------+        |
       |      |      |          |
==================================
       |      |      |          |
       |    +===+    |          |
+-+    |    | 2 |    |    +-+   |
|1|---+|+---|   |---+|+---|4|   |
+-+   |||   +===+   |||   +-+   |
     +===+         +===+        |
+-+  | 1 |         | 4 |  +-+   |
|2|--|   |         |   |--|5|   |
+-+  +===+         +===+  +-+   |
      | |           | |         |
+-+   | |   +===+   | |   +-+   |
|3|---+ +---| 3 |---+ +---|6|   |
+-+         |   |         +-+   |
            +===+  +------------+
              |    |
              +----+
```

This repo is based on the [slices_demo5](https://github.com/Emil-501/P4-network-slices-A/tree/master/slices_demo5). The difference between them lies in the file `topo.py` which add SDN controller to this repo. You can change it slightly in your target.

To get start, first start your own controller and record the IP address and its port number(eg.6633 in this target), then add controller to [topo.py](https://github.com/Emil-501/P4-network-slices-B/blob/master/Demo/topo.py#L98) here with using the function `net.addController([controller_name], controller=RemoteController, ip=[yourcontroller_IP], port=[yourcontroller_port])`. We don't recommend to use the original controller that mininet offered because it will mess the table entries.

The controller only manage the OvS, that means it cannot do anything to the features that P4 offered. You can start one runtime_CLI(simple_switch_CLI in our repo) per P4 switch to manage the network. Besides, you can also use the controller to control the behaviors of OvS. So this repo offered two way to change the behaviors of switches at runtime.

Chen, 2017.3.20