# P4-network-slices-B
Fuzhou University SDN Lab | P4language

**This repo is building now.**

One major function of this repo is giving a demo that connected the P4switches to the SDN controller. We rewrited the script named `p4_mininet` which is offered by barefoot into `p4ovs_mininet` by moving the script slightly. 

Another major function of this repo is starting a openflow agent for the connecting between the data plane that composed of P4switches and the control plane(in other words, Ryu Controller in our implementation). We are fighting for this.

To get start, copy the dir named `Demo` which is based on the `slices_demo5` to the `bmv2/target`, then change the path in the file `env.sh`. Everything is ready as soon as you finished these steps. 

One thing should be noticed that you should try the [slices_demo5](https://github.com/Emil-501/P4-network-slices-A/tree/master/slices_demo5) in our repo `P4-network-slices-A` first before you start the work in this repo.

### History:

see [README in Emil-501/p4factory](https://github.com/Emil-501/p4factory#fzu)