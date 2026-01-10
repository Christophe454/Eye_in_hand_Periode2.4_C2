# Fysieke UR-robot

In dit hoofdtuk wordt beschreven hoe je een verbinding kunt opzetten tussen de development-computer en de fysieke robot.

## Netwerkverbinding verbinding
De robot en development-computer worden met elkaar verbonden door middel van een router.

### Configuratie router
De router dient geconfigureerd te worden zodat het subnet `192.168.1.0' wordt. Je krijgt hierdoor een afzonderlijk netwerk waarin je ook je andere robot-cel devices kunt opnemen zals b.v. camera's of de teachbot. Tevens voorkom je inteferenties met andere sub-netten.
>Het instellen van de router valt buiten het deze bsachrijving en is router-type afhankelijk.

### Netwerk configuratie development-computer
Verbind je developmen computer met het netwerk van de router, bij voorkeur met een `cat5-kabel`. Een wifi verbinding kan een minder betrouwbare communicatie met de robot teweeg brengen.

Schakel je netwerkverbindingen in op je development-computer.
Test of de development-computer het juiste ip-adres krijgt

```bash
ifconfig | grep broadcast
```
dit zal ongeveer dit resultaat opleveren:
```bash
    inet 192.168.1.150  netmask 255.255.255.0  broadcast 192.168.1.255
```


>Controleer of het ip-adress in het juiste subnet opgenomen is `192.168.1.x`

Noteer dit ip-adres, je jult het nodig hebben bij de configuratie van de UR-robot.

## Starten van de robot
```
ros2 launch my_ur_bringup real_robot.launch.py robot_ip:=<robot_ip>
```

`Start op teachdendant van de UR-robot de applicatie`

Volg de output in de terminal en evalueer of er een goede connectie met de robot tot stand is gekomen.

>Je kunt ook in het bestand /<workspace>/src/my_ur_ROS2/my_ur_bringup/launch/real_robot.launch.py het ip-adres wijzigen op regel 45.Daarna hoef je de robot_ip argument niet meer aan bovenstaande commando toe te voegen.

## Testen van de robot
```
ros2 launch my_ur_bringup movegroup.launch.py 
```


### Netwerk configuratie UR-robot



## Netwerksetup in VMWare