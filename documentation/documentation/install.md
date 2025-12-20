# Installatie van de UR-template


Voor dat je begint dien je een clone van de `my_ur_ROS2` repository te maken.


Voor dat je begint dien je een clone van de `my_ur_ROS2` repository te maken.


## Cloning de ROS2 Universal Robots template
Voor het maken van de ROS2 Universal Robots template maak je gebruik van een Github clone die is voorbereid. Je kunt er voor kiezen om deze clone onder een eigen account van Github te plaatsen (1e keuze hieronder). Je kunt daarna eenvoudig backup's van je werk maken naar je eigen Github account.

> we maken gebruik van een prefix my_ur in de packages van de repository om onderscheid te maken met de standaard Universal Robots packages.



## Installatie van Universal Robot support packages

```bash
cd ~/my_ur_ws/src/my_ur_ROS2/install
./install
```

## Bouwen van de workspace
> Dit is al gebeurd in de installatie. Wijzig je iets in de workspace dan kun je als volgt bouwen
```bash
# Build the workspace
cd ~/my_ur_ws
colcon build --symlink-install
source install/setup.bash

```