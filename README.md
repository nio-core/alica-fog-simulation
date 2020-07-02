# fog-simulation

## necessary programs:
install some necessary programs with

apt-get install -y libsfml-dev

apt install -y libzmq3-dev

apt install -y net-tools openjdk-11-jdk myrepos autoconf automake libtool cmake bison re2c build-essential g++ gitk uuid-dev capnproto libcapnp-dev python-catkin-tools qtscript5-dev

https://github.com/potassco/clingo.git (master)

https://github.com/dasys-lab/alica.git (newPD)

https://github.com/dasys-lab/alica-plan-designer-fx.git (master)

https://github.com/dasys-lab/alica-supplementary.git (CapnZero)

https://github.com/dasys-lab/aspsuite.git (srg_dev)

https://github.com/dasys-lab/capnzero.git (master)

https://github.com/dasys-lab/essentials.git (CapnZero)

https://github.com/dasys-lab/service-robot-grid-simulation.git (master)

https://github.com/dasys-lab/tmxparser.git (master)

build with catkin build

shell script for dataProvider:
```
#!/bin/bash

export ROBOT=dataProvider
cd srai_ws
source ./devel/setup.bash
cd src/service-robot-ai/
rosrun srg_base srg_base -m "ZMQAgentPair"
cd
```

shell script for fog:
```
#!/bin/bash

export ROBOT=fog
cd srai_ws
source ./devel/setup.bash
cd src/service-robot-ai/
rosrun srg_base srg_base -m "ZMQAgentFog"
cd
```

