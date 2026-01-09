# TOS-Teachbot


![image](../images/Logo_TOS_blauw.svg)
**TeleOperation Services B.V.**

Met de TOS-Teachbot kun je met een teleoperatie de joints van de UR robot bewegen.

## Starten van de UR-Robot

Je kunt de teleoperatie op de robot zowel in simulatie als met een fysieke(Realworld) UR robot uitvoeren

:::::{card} 

::::{tab-set}

:::{tab-item} Simulatie

```bash
ros2 launch my_ur_bringup bringup.launch.py
```

Er wordt de Gazebo simulatie omgeving voor een UR5 robot geopend en een RVIZ monitor. Vanuit de RVIZ monitor kun je door middel van de movegroup de robot laten bewegen naar voor ingestelde posities.


:::

:::{tab-item} Realworld

*Under construction*

:::

::::

:::::

## Starten van de TOS-Teachbot
```bash
ros2 launch teachbot_ros teachbot_rviz.launch.py enable_mode:=[button|gui|none]
```
> Er zal een tweede RVIZ-monitor gestart worden met daarin een UR robot welke de stand van de Teachbot representeerd

## Starten van de jointfollower
```bash
ros2 launch my_ur_teachbot teachbot_follower.launch.py
```
Nadat je de Teachbot hebt ge-enabled zal de robot de bewegingen van de Teachbot in real-time volgen en uitvoeren.
