## BMV2

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