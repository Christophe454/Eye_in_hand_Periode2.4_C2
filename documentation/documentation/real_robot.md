# Fysieke UR-robot

In dit hoofdtuk wordt beschreven hoe je een verbinding kunt opzetten tussen de development-computer en de fysieke robot.

## Netwerkverbinding opzetten
De robot en development-computer worden met elkaar verbonden door middel van een router.

::::{grid} 2
:::{grid-item-card} 
![image](../images/router1.jpg)
:::
:::{grid-item-card}
![image](../images/router2.jpg)
:::
::::



### Configuratie router
De router dient geconfigureerd te worden zodat het subnet `192.168.1.0` wordt. Je krijgt hierdoor een afzonderlijk netwerk waarin je ook je andere robot-cel devices kunt opnemen zoals b.v. camera`s of de teachbot. Tevens voorkom je interferenties met andere sub-netten.
>Het instellen van de router valt buiten deze beschrijving en is router-type afhankelijk.

### Netwerk configuratie development-computer
Verbind je development-computer met het netwerk van de router, bij voorkeur met een `cat5-kabel`. Een wifi verbinding kan een minder betrouwbare communicatie met de robot teweeg brengen.

Schakel je netwerkverbindingen in op je development-computer.
Test of de development-computer het juiste ip-adres krijgt

```bash
ifconfig | grep broadcast
```
dit zal ongeveer dit resultaat opleveren:
```bash
    inet 192.168.1.150  netmask 255.255.255.0  broadcast 192.168.1.255
```


>Controleer of het ip-adres in het juiste subnet opgenomen is `192.168.1.x`

Noteer dit ip-adres, je zult het nodig hebben bij de configuratie van de UR-robot.

### Configuratie UR-robot
Verbind de UR-robot met het netwerk van de router met een `cat5-kabel` en voer de volgende handelingen uit op de teachpendant van de UR-robot

### Opvragen IP-adres van de UR-robot
Ga op de teachpendant van de UR-robot naar het Robot Instellen scherm en selecteer Netwerk.

![Screenshot van het UR-robot netwerkconfiguratiescherm](../images/ur1.png)

>Let op: Het IP-adres is niet aan te passen in DHCP-mode. Wijzig deze mode niet, lees alleen de waarde van het IP-adres uit en noteer deze.
Is het IP-adres 0.0.0.0 controleer dan de verbinding tussen de UR-robot en de router en reboot de UR-robot vervolgens.

### Instellen development-computer IP-adres op UR-5 Robot

Open op de teach-pendent van de UR-robot het programma `RosControl.urp`.
    • Gebruik de `Programma Laden` Functie

![image](../images/ur2.png)

Selecteer het tabblad `Installatie` en de functie `External Control`.

Vul op de volgende gegevens in:
* Host IP: 	Ip-adres van de development-computer
* Custom port: 	50002
* Host name:	Development

![image](../images/ur3.png)


## Starten van de robot

```
ros2 launch my_ur_bringup real_robot.launch.py robot_ip:=<robot_ip>
```
Op de teach-pendent van de UR-robot:
* Ga naar programma "Programma Laden"
* Selecteer het programma `RosControl.urp`, zie hierboven.
* Start het programma door op play te toetsen

![image](../images/ur4.png)


Volg de output in de terminal en evalueer of er een goede connectie met de robot tot stand is gekomen.

>Je kunt ook in het bestand /<workspace>/src/my_ur_ROS2/my_ur_bringup/launch/real_robot.launch.py het ip-adres wijzigen op regel 45.Daarna hoef je de robot_ip argument niet meer aan bovenstaande commando toe te voegen.

## Testen van de robot
Je kunt de robot nu laten bewegen door de ` movegroup`-node te starten met:

```
ros2 launch my_ur_bringup movegroup.launch.py 
```
RVIZ zal nu worden opgestart en een virtuele weergave van de robot-opstelling wordt nu zichtbaar. Je kunt de robot nu laten bewegen door het selecteren van een pose met de knop `Goal State` een positie kiezen en de weg naar de positie volgen met de `Plan` knop. Vervolgens kun je `Plan & Execute` of `Execute` bedienen waarna de robot zal bewegen naar de gekozen pose.
> Let op: Zorg ervoor dat de robot vrijelijk kan bewegen en geen obstakels tegen komt.

## Netwerksetup in VMWare
Bij gebruik van virtuele-machine op development-computer, dient het netwerk als `bridge` geconfigureerd te zijn. Glijd met je muis over de icoontjes, linksonder van de virtuele machine, totdat je `Network Adapter` zie verschijnen. Het type dient Bridged te zijn. Zie Afbeelding.

![image](../images/vmware1.png)

Als dit niet het geval is click dan op het Network Adapter icoontje en selecteer `Settings`. Selecteer in het keuzemenu de optie `Bridged`

![image](../images/vmware2.png)